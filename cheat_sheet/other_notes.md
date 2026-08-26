# Other Notes / Concepts Cheat Sheet

## Table of Contents
- [1. Lexicographical Order (Strings / Alphabets)](#1-lexicographical-order-strings--alphabets)
- [2. Lexicographical Order (Numbers)](#2-lexicographical-order-numbers)
- [3. XOR & Bit Manipulation Properties](#3-xor--bit-manipulation-properties)

---

## 1. Lexicographical Order (Strings / Alphabets)

### Definition
**Dictionary order** — compares two strings letter-by-letter from **left to right**. The first differing letter decides which string is smaller/greater. If one string is a prefix of the other, the **shorter string is smaller**.

### Rules & Examples
- **First Mismatch Decides**:
  - `"apple" < "banana"` (since `'a' < 'b'` at index 0)
- **Prefix Rule**:
  - `"apple" < "applesauce"` (`"apple"` is a prefix, so shorter is smaller)
- **ASCII Case Precedence**:
  - `"Zebra" < "apple"` (uppercase letters have smaller ASCII values than lowercase letters; `'Z'` = 90, `'a'` = 97)

---

## 2. Lexicographical Order (Numbers)

### Definition
Comparing numbers **digit-by-digit as strings**, left to right — **not by their actual numeric value**.

### Core Rules & Traps
- Compare digit by digit, left to right; the first mismatch decides the order.
- **Prefix Rule**: `"9" < "90"` (shorter is smaller if it is a prefix).
- **The Trap (Lexicographical vs. Numeric)**:
  - `"2" < "9"` $\rightarrow$ Matches numeric order ($2 < 9$).
  - **`"10" < "9"`** $\rightarrow$ Lexicographically smaller because `'1' < '9'` at index 0 (even though $10 > 9$ numerically).
  - **`"200" < "9"`** $\rightarrow$ Same trap: `'2' < '9'` at index 0 (even though $200 > 9$ numerically).

---

## 3. XOR & Bit Manipulation Properties

### Core XOR properties:

- `a ^ a = 0` — self-cancel
- `a ^ 0 = a` — identity
- `a ^ b = c ⟺ a ^ c = b ⟺ b ^ c = a` — solve for one variable
  - eg: `5 ^ 3 = 6 → 5 ^ 6 = 3 ✓`
- **Commutative**: `a ^ b = b ^ a`
- **Associative**: `(a ^ b) ^ c = a ^ (b ^ c)` — order/grouping doesn't matter in a chain
- **Pairs cancel, singleton survives**: `[4,1,2,1,2] → XOR all → 4`
  - (`1^1=0, 2^2=0`, leftover is `4`)

Following this noting for now above one r more important

- `a ^ b` has a set bit wherever `a` and `b` differ → used for Hamming distance
  - eg: `5 (101) ^ 3 (011) = 110` → 2 differing bits
- `n & (n-1)` clears the lowest set bit
  - eg: `12 (1100) & 11 (1011) = 1000`
- `n & -n` isolates the lowest set bit
  - eg: `12 (1100) & -12 = 0100`
- XOR from 1 to n follows a pattern by `n % 4`: `0→n, 1→1, 2→n+1, 3→0`
  - eg: `n=5 (5%4=1) → XOR(1..5) = 1`
- Swap without temp: `a ^= b; b ^= a; a ^= b;`

