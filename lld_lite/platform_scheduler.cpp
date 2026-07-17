/*
 * Uber Freight — Fleet Loading Dock / Platform Scheduler
 *
 * Problem:
 *   N loading docks (platforms). Trucks arrive at time A with duration W.
 *   Assign the truck to the platform that becomes free earliest.
 *   If multiple platforms free at the same time -> pick lowest index.
 *   If platform isn't free at arrival -> delay = (platform_free_time - A).
 *   The truck then occupies [A + delay, A + delay + W - 1].
 *
 * API:
 *   assignPlatform(truckId, arrivalTime, waitTime) -> "platformIdx,delay"
 *   getTrainAtPlatform(platformIdx, time)          -> truckId or ""
 *   getPlatformOfTrain(truckId, time)              -> platformIdx or -1
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <sstream>

using namespace std;

// ─────────────────────────────────────────────
// Data model: one reserved slot on a platform
// ─────────────────────────────────────────────
struct Reservation {
    string truckId;
    int start;
    int end;

    bool containsTime(int t) const {
        return t >= start && t <= end;
    }
};

// ─────────────────────────────────────────────
// One physical platform — holds its schedule
// Key insight: map<startTime, Reservation> lets
// us do O(log K) floor lookups for time queries.
// ─────────────────────────────────────────────
class Platform {
public:
    int id;
    map<int, Reservation> schedule;  // startTime -> Reservation

    Platform(int id) : id(id) {}

    // When does this platform become free?
    int nextFreeTime() const {
        if (schedule.empty()) return 0;
        return schedule.rbegin()->second.end + 1;
    }

    void addReservation(const Reservation& r) {
        schedule[r.start] = r;
    }

    // Which truck is here at time t? O(log K) via floor entry.
    string truckAt(int t) const {
        auto it = schedule.upper_bound(t);  // first entry > t
        if (it == schedule.begin()) return "";
        --it;  // last entry with start <= t
        if (it->second.containsTime(t)) return it->second.truckId;
        return "";
    }
};

// ─────────────────────────────────────────────
// Main scheduler
// ─────────────────────────────────────────────
class PlatformScheduler {
private:
    int N;
    vector<Platform> platforms;

    // Global lookup: truckId -> (platformIdx, Reservation)
    // Enables O(1) getPlatformOfTrain
    unordered_map<string, pair<int, Reservation>> truckRegistry;

public:
    PlatformScheduler(int numPlatforms) : N(numPlatforms) {
        for (int i = 0; i < N; i++) {
            platforms.push_back(i);
        }
    }

    /*
     * assignPlatform
     *
     * Scan all N platforms, find the one with minimum delay.
     * Delay for platform i = max(0, platform[i].nextFreeTime() - arrivalTime)
     * Tie-break: lower index wins (loop order handles this naturally).
     *
     * Time: O(N) scan. Can be O(log N) with a priority queue, but O(N)
     * is clean enough for 60 min and still correct.
     */
    string assignPlatform(const string& truckId, int arrivalTime, int waitTime) {
        int bestPlatform = -1;
        int bestDelay = INT_MAX;

        for (int i = 0; i < N; i++) {
            int freeAt = platforms[i].nextFreeTime();
            int delay = max(0, freeAt - arrivalTime);

            // Strict less-than: ties go to lower index (we see lower i first)
            if (delay < bestDelay) {
                bestDelay = delay;
                bestPlatform = i;
            }
        }

        int actualStart = arrivalTime + bestDelay;
        int actualEnd   = actualStart + waitTime - 1;

        Reservation r = { truckId, actualStart, actualEnd };
        platforms[bestPlatform].addReservation(r);
        truckRegistry[truckId] = { bestPlatform, r };

        return to_string(bestPlatform) + "," + to_string(bestDelay);
    }

    /*
     * getTrainAtPlatform
     *
     * Which truck is on platform `platformIdx` at time `t`?
     * Delegates to Platform::truckAt() which does a floor lookup in O(log K).
     */
    string getTrainAtPlatform(int platformIdx, int t) {
        if (platformIdx < 0 || platformIdx >= N) return "";
        return platforms[platformIdx].truckAt(t);
    }

    /*
     * getPlatformOfTrain
     *
     * O(1) via the global truckRegistry map.
     * We stored (platformIdx, Reservation) on assignment.
     */
    int getPlatformOfTrain(const string& truckId, int t) {
        auto it = truckRegistry.find(truckId);
        if (it == truckRegistry.end()) return -1;

        int platformIdx = it->second.first;
        const Reservation& reservation = it->second.second;
        if (reservation.containsTime(t)) return platformIdx;
        return -1;
    }
};

// ─────────────────────────────────────────────
// Driver / test harness
// ─────────────────────────────────────────────
int main() {
    // 3 platforms, same as the doc example
    PlatformScheduler scheduler(3);

    // Assign trucks sequentially
    cout << "=== assignPlatform ===\n";
    cout << scheduler.assignPlatform("T1", 0, 5)  << "\n";  // expect 0,0 -> [0..4]
    cout << scheduler.assignPlatform("T2", 2, 3)  << "\n";  // expect 1,0 -> [2..4]
    cout << scheduler.assignPlatform("T3", 4, 4)  << "\n";  // expect 2,0 -> [4..7]
    cout << scheduler.assignPlatform("T5", 9, 1)  << "\n";  // platform 1 free at 5, delay=0 -> [9..9]
    cout << scheduler.assignPlatform("T6", 9, 2)  << "\n";  // platform 2 free at 8, delay=0 -> [9..10]
    cout << scheduler.assignPlatform("T7", 10, 3) << "\n";  // platform 0 free at 5, delay=0 -> [10..12]

    cout << "\n=== getTrainAtPlatform ===\n";
    cout << scheduler.getTrainAtPlatform(0, 2)  << "\n";  // T1
    cout << scheduler.getTrainAtPlatform(1, 3)  << "\n";  // T2
    cout << scheduler.getTrainAtPlatform(2, 5)  << "\n";  // T3
    cout << scheduler.getTrainAtPlatform(0, 11) << "\n";  // T7
    cout << scheduler.getTrainAtPlatform(0, 5)  << "\n";  // "" (T1 ended at 4)

    cout << "\n=== getPlatformOfTrain ===\n";
    cout << scheduler.getPlatformOfTrain("T1", 3)  << "\n";  //  0
    cout << scheduler.getPlatformOfTrain("T3", 6)  << "\n";  //  2
    cout << scheduler.getPlatformOfTrain("T7", 8)  << "\n";  // -1 (not yet there)
    cout << scheduler.getPlatformOfTrain("T7", 11) << "\n";  //  0

    return 0;
}

