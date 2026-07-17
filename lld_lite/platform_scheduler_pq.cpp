/*
 * Uber Freight — Fleet Loading Dock / Platform Scheduler (Priority Queue Version)
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
 *
 * Priority Queue Design:
 *   We use a min-heap (std::priority_queue) containing:
 *     struct PlatformNode { int nextFreeTime; int platformIdx; }
 *   This allows assignPlatform to run in O(log N) instead of O(N) linear scan.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
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
// ─────────────────────────────────────────────
class Platform {
public:
    int id;
    map<int, Reservation> schedule;  // startTime -> Reservation

    Platform(int id) : id(id) {}

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
// Custom struct for min-heap comparison
// ─────────────────────────────────────────────
struct PlatformNode {
    int nextFreeTime;
    int platformIdx;

    // Overload greater-than operator for min-heap
    // Sorts primarily by nextFreeTime (ascending), and secondarily by platformIdx (ascending)
    bool operator>(const PlatformNode& other) const {
        if (nextFreeTime != other.nextFreeTime) {
            return nextFreeTime > other.nextFreeTime;
        }
        return platformIdx > other.platformIdx;
    }
};

// ─────────────────────────────────────────────
// Priority Queue Scheduler
// ─────────────────────────────────────────────
class PlatformScheduler {
private:
    int N;
    vector<Platform> platforms;

    // Min-heap: top is the platform with earliest nextFreeTime (break ties with lowest platformIdx)
    priority_queue<PlatformNode, vector<PlatformNode>, greater<PlatformNode>> pq;

    // Global lookup: truckId -> (platformIdx, Reservation)
    // Enables O(1) getPlatformOfTrain
    unordered_map<string, pair<int, Reservation>> truckRegistry;

public:
    PlatformScheduler(int numPlatforms) : N(numPlatforms) {
        for (int i = 0; i < N; i++) {
            platforms.push_back(Platform(i));
            pq.push({ 0, i });
        }
    }

    /*
     * assignPlatform
     *
     * Selects the platform that becomes free earliest using the priority queue.
     * Time: O(log N) pop and push operations.
     */
    string assignPlatform(const string& truckId, int arrivalTime, int waitTime) {
        // Pop the platform that becomes free earliest
        PlatformNode earliest = pq.top();
        pq.pop();

        int platformIdx = earliest.platformIdx;
        int freeAt = earliest.nextFreeTime;

        int delay = max(0, freeAt - arrivalTime);
        int actualStart = arrivalTime + delay;
        int actualEnd = actualStart + waitTime - 1;

        Reservation r = { truckId, actualStart, actualEnd };
        platforms[platformIdx].addReservation(r);
        truckRegistry[truckId] = { platformIdx, r };

        // Push the updated platform status back to the priority queue
        pq.push({ actualEnd + 1, platformIdx });

        return to_string(platformIdx) + "," + to_string(delay);
    }

    /*
     * getTrainAtPlatform
     *
     * Time: O(log K) floor lookup via upper_bound on map.
     */
    string getTrainAtPlatform(int platformIdx, int t) {
        if (platformIdx < 0 || platformIdx >= N) return "";
        return platforms[platformIdx].truckAt(t);
    }

    /*
     * getPlatformOfTrain
     *
     * Time: O(1) average lookup in hash map.
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
    PlatformScheduler scheduler(3);

    // Assign trucks sequentially
    cout << "=== assignPlatform ===\n";
    cout << scheduler.assignPlatform("T1", 0, 5)  << "\n";  // expect 0,0 -> [0..4]
    cout << scheduler.assignPlatform("T2", 2, 3)  << "\n";  // expect 1,0 -> [2..4]
    cout << scheduler.assignPlatform("T3", 4, 4)  << "\n";  // expect 2,0 -> [4..7]
    cout << scheduler.assignPlatform("T5", 9, 1)  << "\n";  // platform 0 free at 5, delay=0 -> [9..9]
    cout << scheduler.assignPlatform("T6", 9, 2)  << "\n";  // platform 1 free at 5, delay=0 -> [9..10]
    cout << scheduler.assignPlatform("T7", 10, 3) << "\n";  // platform 2 free at 8, delay=0 -> [10..12] (earliest free!)

    cout << "\n=== getTrainAtPlatform ===\n";
    cout << "P0 at 2: " << scheduler.getTrainAtPlatform(0, 2) << "\n";   // T1
    cout << "P1 at 3: " << scheduler.getTrainAtPlatform(1, 3) << "\n";   // T2
    cout << "P2 at 5: " << scheduler.getTrainAtPlatform(2, 5) << "\n";   // T3
    cout << "P2 at 11: " << scheduler.getTrainAtPlatform(2, 11) << "\n"; // T7
    cout << "P0 at 5: " << scheduler.getTrainAtPlatform(0, 5) << "\n";   // "" (T1 ended at 4)

    cout << "\n=== getPlatformOfTrain ===\n";
    cout << "T1 at 3: " << scheduler.getPlatformOfTrain("T1", 3) << "\n";   //  0
    cout << "T3 at 6: " << scheduler.getPlatformOfTrain("T3", 6) << "\n";   //  2
    cout << "T7 at 8: " << scheduler.getPlatformOfTrain("T7", 8) << "\n";   // -1 (not yet there)
    cout << "T7 at 11: " << scheduler.getPlatformOfTrain("T7", 11) << "\n"; //  2 (since it's on platform 2)

    return 0;
}
