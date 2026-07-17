/*
 * Inventory System
 *
 * Problem:
 *   Manage a product inventory for a freight warehouse.
 *   Support: add stock, remove stock, query stock, reserve stock (soft-hold),
 *   confirm reservation (deduct from reserve), cancel reservation.
 *
 * API:
 *   void   addStock(sku, qty)              → increase available stock
 *   bool   removeStock(sku, qty)           → decrease available (hard remove)
 *   int    getStock(sku)                   → available (not reserved) qty
 *   int    getTotalStock(sku)              → available + reserved qty
 *   string reserve(sku, qty)              → reservationId or "" if insufficient
 *   bool   confirmReservation(reservId)   → finalize: deduct from total
 *   bool   cancelReservation(reservId)    → release: add back to available
 *
 * Data Model:
 *   Per SKU:
 *     available : int  — freely available units
 *     reserved  : int  — units locked by pending reservations
 *   total = available + reserved
 *
 *   Reservations:
 *     unordered_map<reservId, {sku, qty}>
 *
 * Complexity:
 *   All operations O(1)
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <sstream>

using namespace std;

// ─── Inventory Entry ─────────────────────────────────────────────────────────

struct Item {
    int available = 0;
    int reserved  = 0;

    int total() const { return available + reserved; }
};

// ─── Reservation Record ───────────────────────────────────────────────────────

struct Reservation {
    string sku;
    int    qty;
};

// ─── Inventory System ─────────────────────────────────────────────────────────

class InventorySystem {
private:
    unordered_map<string, Item>        inventory;     // sku → Item
    unordered_map<string, Reservation> reservations;  // reservId → Reservation

    // Simple ID generator
    int nextId = 1;

    string newReservationId() {
        return "RES-" + to_string(nextId++);
    }

public:
    /*
     * addStock(sku, qty)
     * Increase available stock. Creates the SKU entry if absent.
     */
    void addStock(const string& sku, int qty) {
        inventory[sku].available += qty;
    }

    /*
     * removeStock(sku, qty)
     * Hard-remove from available (not touching reserved).
     * Returns false if insufficient available stock.
     */
    bool removeStock(const string& sku, int qty) {
        auto it = inventory.find(sku);
        if (it == inventory.end() || it->second.available < qty) return false;
        it->second.available -= qty;
        return true;
    }

    /*
     * getStock(sku)
     * Returns freely available (non-reserved) units.
     */
    int getStock(const string& sku) const {
        auto it = inventory.find(sku);
        return (it == inventory.end()) ? 0 : it->second.available;
    }

    /*
     * getTotalStock(sku)
     * Returns available + reserved (total on-hand).
     */
    int getTotalStock(const string& sku) const {
        auto it = inventory.find(sku);
        return (it == inventory.end()) ? 0 : it->second.total();
    }

    /*
     * reserve(sku, qty)
     *
     * Soft-lock `qty` units:
     *   available -= qty
     *   reserved  += qty
     *
     * Returns a unique reservationId, or "" if insufficient available stock.
     * The units are held until confirmReservation or cancelReservation.
     */
    string reserve(const string& sku, int qty) {
        auto it = inventory.find(sku);
        if (it == inventory.end() || it->second.available < qty) return "";

        it->second.available -= qty;
        it->second.reserved  += qty;

        string id = newReservationId();
        reservations[id] = {sku, qty};
        return id;
    }

    /*
     * confirmReservation(reservId)
     *
     * Finalise the reservation: units were physically shipped/consumed.
     *   reserved -= qty   (total stock decreases, as goods left warehouse)
     *
     * Returns false if reservation not found.
     */
    bool confirmReservation(const string& reservId) {
        auto rit = reservations.find(reservId);
        if (rit == reservations.end()) return false;

        const string& sku = rit->second.sku;
        int qty = rit->second.qty;
        inventory[sku].reserved -= qty;
        reservations.erase(rit);
        return true;
    }

    /*
     * cancelReservation(reservId)
     *
     * Release the soft-hold: units return to available.
     *   reserved  -= qty
     *   available += qty
     *
     * Returns false if reservation not found.
     */
    bool cancelReservation(const string& reservId) {
        auto rit = reservations.find(reservId);
        if (rit == reservations.end()) return false;

        const string& sku = rit->second.sku;
        int qty = rit->second.qty;
        inventory[sku].reserved  -= qty;
        inventory[sku].available += qty;
        reservations.erase(rit);
        return true;
    }

    // ── Debug helper ──
    void printSku(const string& sku) const {
        cout << "[" << sku << "]"
             << "  available=" << getStock(sku)
             << "  total="     << getTotalStock(sku) << "\n";
    }
};

// ─── Driver ───────────────────────────────────────────────────────────────────

int main() {
    InventorySystem inv;

    cout << "=== addStock ===\n";
    inv.addStock("PALLET-A", 100);
    inv.addStock("PALLET-B", 50);
    inv.printSku("PALLET-A");  // available=100, total=100
    inv.printSku("PALLET-B");  // available=50,  total=50

    cout << "\n=== removeStock ===\n";
    cout << inv.removeStock("PALLET-A", 30) << "\n";  // true
    inv.printSku("PALLET-A");                         // available=70, total=70
    cout << inv.removeStock("PALLET-A", 80) << "\n";  // false (only 70 left)

    cout << "\n=== reserve ===\n";
    string r1 = inv.reserve("PALLET-A", 40);
    string r2 = inv.reserve("PALLET-A", 40);          // only 30 left after r1
    cout << "r1: " << r1 << "\n";                     // RES-1 (success)
    cout << "r2: " << r2 << "\n";                     // "" (insufficient)
    inv.printSku("PALLET-A");                         // available=30, total=70

    cout << "\n=== confirmReservation ===\n";
    cout << inv.confirmReservation(r1) << "\n";        // true
    inv.printSku("PALLET-A");                         // available=30, total=30

    cout << "\n=== cancelReservation ===\n";
    string r3 = inv.reserve("PALLET-B", 20);
    inv.printSku("PALLET-B");                         // available=30, total=50
    cout << inv.cancelReservation(r3) << "\n";        // true
    inv.printSku("PALLET-B");                         // available=50, total=50

    cout << "\n=== edge cases ===\n";
    cout << inv.confirmReservation("BAD-ID") << "\n"; // false
    cout << inv.cancelReservation("BAD-ID")  << "\n"; // false
    cout << inv.removeStock("GHOST-SKU", 1)  << "\n"; // false

    return 0;
}
