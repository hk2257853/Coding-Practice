/*
 * Parking Lot Lite
 *
 * Problem:
 *   Multi-floor parking lot. Spots come in 3 sizes: 0=SMALL, 1=MEDIUM, 2=LARGE.
 *   Vehicle parks in its exact size. Always assign the lowest-numbered free spot.
 *
 * API:
 *   park(vehicleId, size)   → "floor,row,col" or "" if full
 *   leave(vehicleId)        → free spot, return true
 *   query(vehicleId)        → current spot or ""
 *   available(size)         → free spots count
 *
 * Data Structure:
 *   freeSpots[3]  : one min-heap per size → always pops the lowest spot   O(log S)
 *   occupied      : unordered_map<vehicleId → {SpotId, size}>            O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int SMALL = 0, MEDIUM = 1, LARGE = 2;

struct SpotId {
    int floor, row, col;

    bool operator>(const SpotId& o) const {
        if (floor != o.floor) return floor > o.floor;
        if (row   != o.row)   return row   > o.row;
        return col > o.col;
    }

    string str() const {
        return to_string(floor) + "," + to_string(row) + "," + to_string(col);
    }
};

// min-heap: smallest SpotId on top
struct MinSpot {
    bool operator()(const SpotId& a, const SpotId& b) { return a > b; }
};

class ParkingLot {
private:
    priority_queue<SpotId, vector<SpotId>, MinSpot> freeSpots[3];
    unordered_map<string, pair<SpotId, int>> occupied;  // vehicleId → (spot, size)

public:
    ParkingLot(int floors, int rows, int spotsPerSize[3]) {
        for (int f = 0; f < floors; f++) {
            for (int r = 0; r < rows; r++) {
                int col = 0;
                for (int c = 0; c < spotsPerSize[SMALL]; c++)  freeSpots[SMALL].push({f, r, col++});
                for (int c = 0; c < spotsPerSize[MEDIUM]; c++) freeSpots[MEDIUM].push({f, r, col++});
                for (int c = 0; c < spotsPerSize[LARGE]; c++)  freeSpots[LARGE].push({f, r, col++});
            }
        }
    }

    string park(const string& id, int size) {
        if (occupied.count(id)) return "ALREADY_PARKED";
        if (freeSpots[size].empty()) return "";

        SpotId spot = freeSpots[size].top();
        freeSpots[size].pop();
        occupied[id] = {spot, size};
        return spot.str();
    }

    bool leave(const string& id) {
        auto it = occupied.find(id);
        if (it == occupied.end()) return false;

        freeSpots[it->second.second].push(it->second.first);
        occupied.erase(it);
        return true;
    }

    string query(const string& id) const {
        auto it = occupied.find(id);
        return (it == occupied.end()) ? "" : it->second.first.str();
    }

    int available(int size) const {
        return (int)freeSpots[size].size();
    }
};

// ─── Driver ───────────────────────────────────────────────────────────────────

int main() {
    int spotsPerSize[3] = {3, 2, 1};  // 3 small, 2 medium, 1 large per row
    ParkingLot lot(2, 2, spotsPerSize);

    cout << "=== Initial availability ===\n";
    cout << "Small:  " << lot.available(SMALL)  << "\n";  // 12
    cout << "Medium: " << lot.available(MEDIUM) << "\n";  // 8
    cout << "Large:  " << lot.available(LARGE)  << "\n";  // 4

    cout << "\n=== park ===\n";
    cout << lot.park("CAR-001", SMALL)  << "\n";  // 0,0,0
    cout << lot.park("CAR-002", SMALL)  << "\n";  // 0,0,1
    cout << lot.park("VAN-001", MEDIUM) << "\n";  // 0,0,3
    cout << lot.park("TRK-001", LARGE)  << "\n";  // 0,0,5

    cout << "\n=== query ===\n";
    cout << lot.query("CAR-001") << "\n";  // 0,0,0
    cout << lot.query("GHOST")   << "\n";  // ""

    cout << "\n=== leave + re-park ===\n";
    lot.leave("CAR-001");
    cout << "Small after leave: " << lot.available(SMALL) << "\n";  // 11
    cout << lot.park("CAR-003", SMALL) << "\n";  // 0,0,0 (re-inserted)

    cout << "\n=== already parked ===\n";
    cout << lot.park("CAR-002", SMALL) << "\n";  // ALREADY_PARKED

    return 0;
}
