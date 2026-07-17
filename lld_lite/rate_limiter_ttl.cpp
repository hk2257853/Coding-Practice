/*
 * Rate Limiter — Sliding Window (TTL-based)
 *
 * Problem:
 *   Allow at most `limit` requests per `windowMs` milliseconds per key.
 *   Requests outside the TTL window are automatically expired.
 *   This is a pure sliding-window (not fixed-bucket) implementation.
 *
 * API:
 *   bool allow(key, now_ms)   → true if request is within rate limit
 *   void reset(key)           → clear all history for a key
 *   int  remaining(key, now_ms) → how many more requests allowed right now
 *
 * Data Structure:
 *   Per-key: deque<long long> of timestamps of accepted requests.
 *   On each call, pop timestamps older than (now - windowMs) from the front.
 *   If deque.size() < limit → allow and push now; else deny.
 *
 * Complexity:
 *   allow      O(E) amortised, where E = number of expired entries evicted
 *              (each timestamp pushed once, popped once → amortised O(1))
 *   Space      O(limit) per key at most
 */

#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>

using namespace std;

class RateLimiter {
private:
    int limit;         // max requests per window
    long long windowMs; // window duration in milliseconds

    // key → sliding window of accepted request timestamps
    unordered_map<string, deque<long long>> windows;

    // Evict timestamps older than the sliding window boundary
    void evictExpired(deque<long long>& dq, long long now) {
        long long cutoff = now - windowMs;
        while (!dq.empty() && dq.front() <= cutoff) {
            dq.pop_front();
        }
    }

public:
    /*
     * limit    : max requests allowed in the window
     * windowMs : size of the sliding window in milliseconds
     */
    RateLimiter(int limit, long long windowMs)
        : limit(limit), windowMs(windowMs) {}

    /*
     * allow(key, now_ms)
     *
     * Atomically:
     *   1. Expire all timestamps outside the window.
     *   2. If current count < limit → record timestamp, return true.
     *   3. Otherwise → return false (rate-limited).
     */
    bool allow(const string& key, long long now) {
        auto& dq = windows[key];
        evictExpired(dq, now);

        if ((int)dq.size() < limit) {
            dq.push_back(now);
            return true;
        }
        return false;  // throttled
    }

    /*
     * remaining(key, now_ms)
     * How many more requests can this key make right now?
     */
    int remaining(const string& key, long long now) {
        auto it = windows.find(key);
        if (it == windows.end()) return limit;

        evictExpired(it->second, now);
        return max(0, limit - (int)it->second.size());
    }

    /*
     * reset(key)
     * Wipe all history — useful for testing or admin override.
     */
    void reset(const string& key) {
        windows.erase(key);
    }
};

// ─── Driver ───────────────────────────────────────────────────────────────────

int main() {
    // 3 requests per 1000 ms per key
    RateLimiter rl(3, 1000);

    cout << "=== Basic allow / deny ===\n";
    // All three within window → allowed
    cout << rl.allow("user1", 100)  << "\n";  // 1 → true
    cout << rl.allow("user1", 300)  << "\n";  // 2 → true
    cout << rl.allow("user1", 500)  << "\n";  // 3 → true
    // 4th within same window → denied
    cout << rl.allow("user1", 700)  << "\n";  // 4 → false

    cout << "\n=== Sliding window expiry ===\n";
    // At t=1200 the t=100 entry has expired (1200-100 = 1100 > 1000)
    // Window now: {300, 500} → 2 live → allow
    cout << rl.allow("user1", 1200) << "\n";  // true  (3 live: 300,500,1200)
    cout << rl.allow("user1", 1250) << "\n";  // false (still 3 live)

    cout << "\n=== Different keys are isolated ===\n";
    cout << rl.allow("user2", 500)  << "\n";  // true (fresh key)
    cout << rl.allow("user2", 600)  << "\n";  // true
    cout << rl.allow("user2", 700)  << "\n";  // true
    cout << rl.allow("user2", 800)  << "\n";  // false (3 used up)

    cout << "\n=== remaining() ===\n";
    cout << rl.remaining("user2", 800)  << "\n";   // 0
    cout << rl.remaining("user2", 1700) << "\n";   // 3 (all expired)
    cout << rl.remaining("user3", 500)  << "\n";   // 3 (new key)

    cout << "\n=== reset() ===\n";
    rl.reset("user1");
    cout << rl.allow("user1", 1300) << "\n";  // true (history cleared)
    cout << rl.allow("user1", 1310) << "\n";  // true
    cout << rl.allow("user1", 1320) << "\n";  // true
    cout << rl.allow("user1", 1330) << "\n";  // false

    return 0;
}
