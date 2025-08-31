# CSES Problem Set Solutions

This repository contains my solutions to the [CSES Problem Set](https://cses.fi/problemset/).  
The focus here is on explaining **how** and **why** each solution works.  

---

## Table of Contents
- [Introductory Problems (24/24)](#introductory-problems)
- [Sorting and Searching (35/35)](#sorting-and-searching)

---

## Introductory Problems

<details>
<summary>Weird Algorithm</summary>



---

### Problem Idea
Start from a number `n` and repeatedly apply the following steps until `n = 1`:
- If `n` is even, divide it by 2.  
- If `n` is odd, multiply it by 3 and add 1.  

### Time Complexity
- O(log n) each operation reduces the number or changes it predictably.

---

</details>

<details>
<summary>Missing Number</summary>

---

### Problem Idea
- The sum of numbers from 1 to n is `total = n*(n+1)/2`.  
- Read the `n-1` numbers from input and calculate their sum.  
- Subtract this sum from the total to find the missing number.

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Repetitions</summary>

---

### Problem Idea
- Iterate through the string while tracking the current run length of identical characters.  
- Update the maximum run length whenever it increases.  
- Reset counter back to 1 when encountering a different character.

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Increasing Array</summary>

---

### Problem Idea
- Iterate through the array, keeping track of the previous element.  
- If the current element is smaller than the previous, increase it and add the difference to the total operations count.

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Permutations</summary>

---

### Problem Idea
- For `n = 2` or `n = 3`, no valid permutation exists because consecutive numbers differ by 1.  
- For `n >= 4`, a valid permutation can be constructed by printing all even numbers first, followed by all odd numbers.  

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Number Spiral</summary>

---

### Problem Idea
- Compare row `r` and column `c` to find the largest value in the spiral for that cell:  
  - If `c >= r`:
    - If `c` is odd: largest value at bottom of column → `c^2 - r + 1`  
    - If `c` is even: largest value at top of column → `(c-1)^2 + r`
  - If `r > c`:
    - If `r` is even: largest value at rightmost of row → `r^2 - c + 1`  
    - If `r` is odd: largest value at leftmost of row → `(r-1)^2 + c`  

### Time Complexity
- O(1)

---

</details>

<details>
<summary>Two Knights</summary>

---

### Problem Idea
- Total ways to place 2 knights on a KxK board: `total = (k^2 * (k^2 - 1)) / 2` (binomial coefficient).  
- Knights attack each other only in `2x3` or `3x2` rectangles. Number of such rectangles: `2*(k-1)*(k-2)`.  
- Each rectangle contains exactly 2 attacking pairs. Total to subtract: `4*(k-1)*(k-2)`.  

### Formula
- `(k^2 * (k^2 - 1))/2 - 4*(k-1)*(k-2)`

### Time Complexity
- O(1)

---

</details>

<details>
<summary>Two Sets</summary>

---

### Problem Idea
- Divide the set `{1, 2, ..., n}` into two sets with equal sum.  

### Total Sum Check
- Total sum `S = n*(n+1)/2`.  
- If `S` is odd → impossible → output `"NO"`.  
- If `S` is even → target sum per set = `S/2`.  

### Algorithm Steps
1. Initialize `left = 1` and `right = n`.  
2. If `n` is odd, place `right` in the first set and decrement `right`.  
3. Symmetrically pair remaining numbers:
   - `printPairs(left+1, right-1)` → first set  
   - `printPairs(left, right)` → second set  

### Key Insight
- Symmetric pairing `(i,n), (i+1,n-1), ...` ensures equal sums in both sets.

### Time Complexity
- O(n)

---

</details>




<details> 

<summary>Bit Strings</summary>

---


### Problem Idea
- Count the number of binary strings of length `n`.  
- Each position can be either `0` or `1`, so total strings = `2^n`.  
- Since the answer can be very large, compute it modulo `10^9 + 7`.

### Algorithm Steps
1. Use **binary exponentiation** to compute `2^n % MOD` efficiently.  
   - Initialize `result = 1` and `base = 2`.  
   - While `n > 0`:
     - If the least significant bit of `n` is 1, multiply `result` by `base` modulo `MOD`.  
     - Square the `base` modulo `MOD`.  
     - Right shift `n` by 1 bit (`n >>= 1`).  

### Key Insight
- Binary exponentiation reduces time complexity from O(n) to O(log n) by squaring the base and using bit manipulation.  

### Time Complexity
- O(log n) each bit of `n` is processed once.  

### Space Complexity
- O(1) only a few variables (`result`, `base`) are used.



---


</details>


<details>
<summary>Trailing Zeros</summary>

---

### Problem Idea
- Count the number of trailing zeros in `n!` (n factorial).  
- Trailing zeros are created by factors of 10 in the factorial.  
- Since `10 = 2 * 5` and there are always more 2s than 5s in `n!`, the number of trailing zeros equals the number of times 5 divides `n!`.

### Algorithm Steps
1. Initialize a counter `count = 0` and a variable `factorial = 5`.  
2. While `factorial <= n`:
   - Add `n / factorial` (integer division) to `cnt`.  
   - Multiply `factorial` by 5 for the next power of 5.  
3. Output `count`.

### Key Insight
- Only powers of 5 matter because 2s are abundant.  
- This requires a **very specific piece of knowledge**: understanding how factorials factor into primes.  
- There’s no need to compute `n!` explicitly, which would overflow quickly.  

### Time Complexity
- O(log_5 n) each power of 5 up to `n` is processed once.  

### Space Complexity
- O(1) only a few variables (`count`, `factorial`) are used.

### Dislike This Problem!!!!!
- Honestly, this problem is a bit *annoying* because it hinges entirely on knowing the 2*5 factorization trick.  
- Without that knowledge there’s no intuitive way to solve it efficiently, making it feel more like a “trivia fact” than a fun challenge.

---

</details>




<details>
<summary>Coin Piles</summary>

---

### Problem Idea
- You are given two piles of coins with `a` and `b` coins.  
- On each move, you can remove either:
  - 2 coins from one pile and 1 coin from the other.  
- Determine if it is possible to empty both piles using these moves.

### Algorithm Steps
1. Ensure `a <= b` (swap if necessary).  
2. If `b > 2 * a`, it is **impossible** to empty both piles output `"NO"`.  
   - Reason: You cannot remove enough coins from the smaller pile to balance the larger.  
3. Compute the difference `diff = b - a`.  
4. Subtract `diff` moves of `(2 from larger, 1 from smaller)` to balance the piles:  
   - `b -= 2 * diff`  
   - `a -= diff`  
5. Now both piles are equal or nearly equal.  
6. Check divisibility conditions:  
   - If `a % 3 == 0` and `b % 3 == 0` → `"YES"`  
   - Or if `a % 3 == 1` and `b % 3 == 2` → `"YES"`  
   - Otherwise → `"NO"`

### Key Insight
- Each move reduces the total number of coins by 3.  
- After removing difference-based moves, the remaining coins must be divisible according to the move rules.  
- This problem boils down to arithmetic reasoning, not simulation.

### Time Complexity
- O(1) per test case only a few arithmetic operations.  
- O(t) overall for `t` test cases.

### Space Complexity
- O(1) only a few variables are used.


---

</details>



<details>

<summary>Palindrome Reorder</summary>

---

### Problem Idea
- Given a string, check if its letters can be rearranged to form a palindrome.  
- A string can form a palindrome if **at most one character has an odd count**.  
- Construct the palindrome by placing letters symmetrically around the center.

### Algorithm Steps
1. Count the frequency of each character in the string.  
2. Count how many characters have an odd frequency.  
   - If more than one, **output `"NO SOLUTION"`** and stop.  
3. Initialize a new string `answer` of the same length as the input.  
4. Use two pointers, `left` and `right`, to place characters symmetrically:  
   - For characters with even counts, place half at the `left` end and half at the `right` end.  
   - Decrement the character count accordingly.  
5. If there is a character with an odd count, place it in the middle (`answer[left]`).  

### Key Insight
- Constructing a new string avoids issues from modifying the original string in place.  
- Symmetric placement ensures the resulting string is a valid palindrome.  

### Time Complexity
- O(n + 26) = O(n) counting characters and placing them takes linear time.  

### Space Complexity
- O(n) for the `answer` string and O(1) for the frequency array.

---

</details>


<details>

<summary>Gray Code</summary>

---

### Problem Idea
- Generate the Gray code sequence of length `n`.  
- Gray code is a binary sequence where two successive numbers differ in exactly one bit.  
- Total number of codes = `2^n`.

### Algorithm Steps
1. Loop through all numbers `i` from `0` to `2^n - 1`.  
2. Convert each number into its Gray code using the formula:  
   - `gray = i ^ (i >> 1)` shifts the number right by one bit.  
   - XOR ensures that only one bit changes between consecutive numbers.  
3. Use a `bitset` to convert the number to a fixed-length binary string.  
4. Print only the last `n` bits to ensure consistent width.

### Key Insight
- The formula `i ^ (i >> 1)` guarantees a Gray code sequence.  
- Using `bitset` simplifies binary formatting and avoids manual padding.  

### Time Complexity
- O(2^n) we must generate and print each of the `2^n` codes.  

### Space Complexity
- O(1) apart from the output string, only a few variables are used.  

---

</details>


<details>

<summary>Tower of Hanoi</summary>

---

### Problem Idea
- The Tower of Hanoi puzzle has three rods and `n` disks of different sizes stacked on one rod in decreasing order (largest at the bottom).  
- The goal is to move all disks from the source rod to the target rod, following these rules:  
  1. Only one disk can be moved at a time.  
  2. Each move takes the top disk from one rod and places it on another.  
  3. No disk may be placed on top of a smaller disk.  


### Algorithm Steps
1. Define a recursive function `solve(from, to, aux, count)` that moves `count` disks:
   - If `count == 0`, return (base case).  
   - Move `count-1` disks from `from → aux` using `to` as helper.  
   - Move the largest disk from `from → to`.  
   - Move `count-1` disks from `aux → to` using `from` as helper.  
2. Read input `n` (the number of disks).  
3. Print the total number of moves: `2^n - 1`.  
4. Call `solve(1, 3, 2, n)` to move all disks from rod 1 → rod 3.  


### Key Insight
- The recursion naturally models the puzzle’s divide-and-conquer structure.  
- The sequence of moves generated by recursion is guaranteed to solve the puzzle in the minimum number of steps.  


### Time Complexity
- O(2^n) each move is printed, and there are `2^n - 1` moves in total.  

### Space Complexity
- O(n) recursion depth is proportional to the number of disks.  

---

</details>
