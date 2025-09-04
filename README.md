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

### Idea
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

### Idea
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

### Idea
- Iterate through the array, keeping track of the previous element.  
- If the current element is smaller than the previous, increase it and add the difference to the total operations count.

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Permutations</summary>

---

### Idea
- For `n = 2` or `n = 3`, no valid permutation exists because consecutive numbers differ by 1.  
- For `n >= 4`, a valid permutation can be constructed by printing all even numbers first, followed by all odd numbers.  

### Time Complexity
- O(n). Space: O(1).

---

</details>

<details>
<summary>Number Spiral</summary>

---

### Idea
- Compare row `r` and column `c` to find the largest value in the spiral for that cell:  
  - If `c >= r`:
    - If `c` is odd: largest value at bottom of column `c^2 - r + 1`  
    - If `c` is even: largest value at top of column `(c-1)^2 + r`
  - If `r > c`:
    - If `r` is even: largest value at rightmost of row `r^2 - c + 1`  
    - If `r` is odd: largest value at leftmost of row `(r-1)^2 + c`  

### Time Complexity
- O(1)

---

</details>

<details>
<summary>Two Knights</summary>

---

### Idea
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

### Idea
- Divide the set `{1, 2, ..., n}` into two sets with equal sum.  

### Total Sum Check
- Total sum `S = n*(n+1)/2`.  
- If `S` is odd, impossible, output `"NO"`.  
- If `S` is even, target sum per set = `S/2`.  

### Algo Steps
1. Initialize `left = 1` and `right = n`.  
2. If `n` is odd, place `right` in the first set and decrement `right`.  
3. Symmetrically pair remaining numbers:
   - `printPairs(left+1, right-1)` first set  
   - `printPairs(left, right)` second set  

### Key Insight
- Symmetric pairing `(i,n), (i+1,n-1), ...` ensures equal sums in both sets.

### Time Complexity
- O(n)

---

</details>




<details> 

<summary>Bit Strings</summary>

---


### Idea
- Count the number of binary strings of length `n`.  
- Each position can be either `0` or `1`, so total strings = `2^n`.  
- Since the answer can be very large, compute it modulo `10^9 + 7`.

### Algo Steps
1. Use binary exponentiation to compute `2^n % MOD` efficiently.  
   - Initialize `result = 1` and `base = 2`.  
   - While `n > 0`:
     - If the least significant bit of `n` is 1, multiply `result` by `base` modulo `MOD`.  
     - Square the `base` modulo `MOD`.  
     - Right shift `n` by 1 bit (`n >>= 1`).  

### Tricks
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

### Idea
- Count the number of trailing zeros in `n!` (n factorial).  
- Trailing zeros are created by factors of 10 in the factorial.  
- Since `10 = 2 * 5` and there are always more 2s than 5s in `n!`, the number of trailing zeros equals the number of times 5 divides `n!`.

### Algo Steps
1. Initialize a counter `count = 0` and a variable `factorial = 5`.  
2. While `factorial <= n`:
   - Add `n / factorial` (integer division) to `cnt`.  
   - Multiply `factorial` by 5 for the next power of 5.  
3. Output `count`.

### Tricks
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

### Idea
- You are given two piles of coins with `a` and `b` coins.  
- On each move, you can remove either:
  - 2 coins from one pile and 1 coin from the other.  
- Determine if it is possible to empty both piles using these moves.

### Algo Steps
1. Ensure `a <= b` (swap if necessary).  
2. If `b > 2 * a`, it is **impossible** to empty both piles output `"NO"`.  
   - Reason: You cannot remove enough coins from the smaller pile to balance the larger.  
3. Compute the difference `diff = b - a`.  
4. Subtract `diff` moves of `(2 from larger, 1 from smaller)` to balance the piles:  
   - `b -= 2 * diff`  
   - `a -= diff`  
5. Now both piles are equal or nearly equal.  
6. Check divisibility conditions:  
   - If `a % 3 == 0` and `b % 3 == 0` = `"YES"`  
   - Or if `a % 3 == 1` and `b % 3 == 2` = `"YES"`  
   - Otherwise = `"NO"`

### Tricks
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

### Idea
- Given a string, check if its letters can be rearranged to form a palindrome.  
- A string can form a palindrome if **at most one character has an odd count**.  
- Construct the palindrome by placing letters symmetrically around the center.

### Algo Steps
1. Count the frequency of each character in the string.  
2. Count how many characters have an odd frequency.  
   - If more than one, **output `"NO SOLUTION"`** and stop.  
3. Initialize a new string `answer` of the same length as the input.  
4. Use two pointers, `left` and `right`, to place characters symmetrically:  
   - For characters with even counts, place half at the `left` end and half at the `right` end.  
   - Decrement the character count accordingly.  
5. If there is a character with an odd count, place it in the middle (`answer[left]`).  

### Tricks
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

### Idea
- Generate the Gray code sequence of length `n`.  
- Gray code is a binary sequence where two successive numbers differ in exactly one bit.  
- Total number of codes = `2^n`.

### Algo Steps
1. Loop through all numbers `i` from `0` to `2^n - 1`.  
2. Convert each number into its Gray code using the formula:  
   - `gray = i ^ (i >> 1)` shifts the number right by one bit.  
   - XOR ensures that only one bit changes between consecutive numbers.  
3. Use a `bitset` to convert the number to a fixed-length binary string.  
4. Print only the last `n` bits to ensure consistent width.

### Tricks
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

### Idea
- The Tower of Hanoi puzzle has three rods and `n` disks of different sizes stacked on one rod in decreasing order (largest at the bottom).  
- The goal is to move all disks from the source rod to the target rod, following these rules:  
  1. Only one disk can be moved at a time.  
  2. Each move takes the top disk from one rod and places it on another.  
  3. No disk may be placed on top of a smaller disk.  


### Algo Steps
1. Define a recursive function `solve(from, to, aux, count)` that moves `count` disks:
   - If `count == 0`, return (base case).  
   - Move `count-1` disks from `from = aux` using `to` as helper.  
   - Move the largest disk from `from = to`.  
   - Move `count-1` disks from `aux = to` using `from` as helper.  
2. Read input `n` (the number of disks).  
3. Print the total number of moves: `2^n - 1`.  
4. Call `solve(1, 3, 2, n)` to move all disks from rod 1 to rod 3.  


### Tricks
- The recursion naturally models the puzzle’s divide-and-conquer structure.  
- The sequence of moves generated by recursion is guaranteed to solve the puzzle in the minimum number of steps.  


### Time Complexity
- O(2^n) each move is printed, and there are `2^n - 1` moves in total.  

### Space Complexity
- O(n) recursion depth is proportional to the number of disks.  

---

</details>



<details>
<summary>Creating Strings</summary>

---

### Idea
- Given a string `s` of length `n`, generate all distinct permutations of its characters.  
- Output the number of unique permutations followed by each permutation in lexicographic order.  

### Algo Steps
1. Define the DFS function:
   - `current_string`: stores the prefix being built.  
   - `remaining_letters`: stores the unused characters.  
   - If `remaining_letters` is empty, insert the constructed string into a set.  
2. For each position, choose one character, append it to `current_string`, and recurse on the reduced `remaining_letters`.  
3. Use a `set<string>` to automatically handle duplicates (important when the input string contains repeated characters).  
4. After DFS finishes, print the set size and each stored permutation in order.  

### Tricks
- DFS explores all possible orderings of characters.  
- Using a set ensures uniqueness and gives automatic lexicographic ordering.  

### Time Complexity
- **O(n · n!)** in the worst case (since there are `n!` permutations and each string construction takes O(n)).  
- With repeated characters, the number of unique permutations is lower.  
- This solution only works because n is no greater than 8 :)

### Space Complexity
- **O(n!)** to store all unique permutations in the set.  
- **O(n)** recursion depth for DFS. 


---
</details>


<details>
<summary>Apple Division</summary>

---

### Idea
- You are given `n` apples with integer weights.  
- Split them into two groups such that the **absolute difference of their total weights** is minimized.  

### Algo Steps
1. Use recursive DFS to try all possible partitions:  
   - At each step, decide whether to place the current apple into the **left group** or the **right group**.  
   - When all apples are assigned, compute the difference `abs(left - right)` and update the minimum.  
2. Start the DFS with the first apple placed in the left group to avoid symmetric duplicates.  
3. After recursion finishes, print the minimal difference.  

### Tricks
- The problem is equivalent to finding a partition of the array into two subsets with the closest possible sums.  
- DFS (brute force) is efficient enough because `n ≤ 20`, meaning at most `2^20 ≈ 1e6` recursive states.  

### Time Complexity
- **O(2^n)** since each apple can go to one of two groups.  
- This is feasible for `n ≤ 20`.  

### Space Complexity
- **O(n)** recursion depth (one function call per apple).  

---
</details>



<details>
<summary>Chessboard and Queens</summary>

---

### Idea
- You have an `8x8` chessboard with some squares blocked (`*`).  
- Place **8 queens** on the board such that no two queens attack each other and no queen is placed on a blocked square.  

### Algo Steps
1. Use **recursive DFS** column by column:  
   - For the current column, try placing a queen in each row.  
   - Skip rows that are blocked or attacked by previously placed queens.  
2. Maintain arrays to quickly check conflicts:  
   - `check_row[row]` whether a row already has a queen.  
   - `check_column[col]` whether a column already has a queen.  
   - `check_diag_left[row+col]` whether the top-left to bottom-right diagonal has a queen.  
   - `check_diag_right[N-1+row-col]` whether the top-right to bottom-left diagonal has a queen.  
3. When placing a queen:  
   - Mark the row, column, and diagonals as occupied.  
   - Recurse to the next column with `queen_count + 1`.  
   - Backtrack by unmarking after recursion.  
4. If `queen_count == 8` (all queens placed), increment the solution count.  
5. At the end, print the total number of valid arrangements.  

### Tricks
- **Column-first DFS** ensures each column has exactly one queen, simplifying conflict checks.  
- Using **precomputed arrays for rows and diagonals** allows O(1) conflict checks per placement.  
- Backtracking guarantees all valid configurations are explored without double counting.  

### Time Complexity
- **O(8!)** roughly 40,000. 
- Efficient enough because `N = 8`.  

### Space Complexity
- **O(N)** recursion depth and arrays for rows, columns, and diagonals (constant size for N=8).  

---
</details>



<details>
<summary>Raab Game</summary>

---

### Idea
- You are given three integers: `n` (number of players), `a` (number of players with low skill), and `b` (number of players with high skill).  
- You need to arrange the players in a line such that:
  - The first group has **strictly increasing numbers** for high-skilled players.  
  - The second group has **strictly decreasing numbers** for low-skilled players.  
  - The arrangement satisfies the Raab game rules, or report `NO` if impossible.

### Algo Steps
1. **Check feasibility**:
   - The total of `a + b` must be ≤ `n`.  
   - Both `a` and `b` must be non-zero if one of them is non-zero (special case `a = b = 0` is allowed).  
2. **Construct the line** based on skill:
   - If `a <= b`:
     - Print **low-skilled players in decreasing order** first.  
     - Print **high-skilled players in increasing order** next.  
   - If `a > b`:
     - Print **high-skilled players in increasing order** first.  
     - Print **low-skilled players in decreasing order** next.  
3. **Handle the remaining players**:
   - Fill remaining positions (`n - (a + b)`) with descending numbers before or after the sequences as required to maintain rules.  

### Tricks
- By arranging the **max-skilled group first or last** and using **decreasing/increasing sequences**, the Raab game constraints are satisfied.  
- Using separate functions for small (`handleSmall`) and big (`handleBig`) sequences simplifies construction.  

### Time Complexity
- **O(n)** to construct and print the line.  

### Space Complexity
- **O(1)** extra space; only a few integers are used.  

---
</details>



<details>
<summary>MEX Grid Construction</summary>

---

### Idea
- You are given an integer `n`.  
- Construct an `n x n` grid of integers such that **every row and every column contains distinct numbers starting from 0**, and each number is the **minimum excluded value (MEX)** for its row and column.  

### Algo Steps
1. Initialize two maps:
   - `row_values[row]` to track numbers already used in each row.  
   - `column_values[col]` to track numbers already used in each column.  
2. Loop through each cell `(row, column)`:
   - Start with `val = 0`.  
   - Increment `val` until it is **not present in the current row or column**.  
   - Assign `val` to the current cell.  
   - Insert `val` into both `row_values[row]` and `column_values[column]`.  
3. Print the grid row by row.  

### Tricks
- By always choosing the **smallest non-used number** for each cell (MEX), the algorithm guarantees that **all row and column constraints are satisfied**.  
- Using unordered sets ensures **O(1) average lookup** for previously used numbers.  

### Time Complexity
- **O(n² * n)** in the worst case, because each cell may need to increment `val` up to `n` times.  
- Practically, the number of increments per cell is small, making it efficient for reasonable `n`.  

### Space Complexity
- **O(n²)** to store used values for rows and columns.  

---
</details>


<details>
<summary>Knight Moves Grid</summary>

---

### Idea
- You are given a chessboard of size `n x n`.  
- Starting from the top-left corner `(0,0)`, fill the grid with the **minimum number of knight moves** required to reach each square.  
- A knight in chess moves in an "L-shape": two squares in one direction and one square perpendicular (8 possible moves).

### Algo Steps
1. Define knight move directions using arrays `dr` and `dc` (8 possibilities).  
2. Initialize:
   - `grid[row][col]` to store the minimum number of moves to reach `(row,col)`.  
   - `seen[row][col]` to mark visited squares.  
   - A BFS queue starting from `(0,0)` with distance `0`.  
3. Run **Breadth-First Search (BFS)**:
   - Pop a cell `(row,col)` from the queue.  
   - For each of the 8 knight moves, compute `(moveRow, moveColumn)`.  
   - If the new cell is within bounds and not visited:  
     - Mark it visited.  
     - Assign `grid[moveRow][moveColumn] = grid[row][col] + 1`.  
     - Push it into the BFS queue.  
4. After BFS completes, print the grid row by row.  

### Tricks
- BFS guarantees the shortest path in an unweighted graph.  
- Treating each square as a graph node and knight moves as edges ensures that the first time a square is reached, it's via the **minimum number of moves**.  

### Time Complexity
- **O(n²)**, since each of the `n²` cells is visited at most once and each cell checks up to 8 moves.  

### Space Complexity
- **O(n²)** for the grid and visited arrays, plus the BFS queue.  

---
</details>



<details>
<summary>Grid Coloring I</summary>

---

### Idea
- You are given an `n x m` grid filled with letters `A, B, C, D`.  
- The task is to **recolor the grid** so that:
  1. Each cell is replaced with the **next letter cyclically** (`A to B to C to D to A`).  
  2. No two adjacent cells (above or left) have the same letter.  
- If it’s not possible (conflict cycles endlessly), output `"IMPOSSIBLE"`.



### Algo Steps
1. **Read input dimensions** `n, m` and the initial grid.  
2. For each cell `(row, column)`:
   - Shift the current character cyclically using:  
     ```
     c = 'A' + (c - 'A' + 1) % 4
     ```
   - Check for adjacency conflicts:
     - If `column > 0` and the new character equals the **left neighbor**.  
     - If `row > 0` and the new character equals the **top neighbor**.  
   - If a conflict occurs, keep shifting forward cyclically.  
   - Track the number of attempts. If more than **4 shifts** are required, print `"IMPOSSIBLE"` and terminate.  
3. Print the modified grid row by row.  


### Tricks
- Since there are only 4 letters (`A-D`), trying at most 4 shifts ensures we cover all possibilities.  
- The `count >= 5` guard ensures we don’t get stuck in an infinite loop where no valid letter can be placed.  


### Time Complexity
- **O(n × m × 4)** ≈ **O(n × m)**, since each cell tries at most 4 shifts.  

### Space Complexity
- **O(n × m)** for storing the grid.  

---
</details>



<details>
<summary>Digit Queries</summary>

---

### Idea
- Imagine concatenating all positive integers into an infinite sequence:  123456789101112131415...
- Given an index `k`, find which **digit** appears at that position.


### Algo Steps
1. **Initialization**  
 - Start with numbers of length `len = 1`.  
 - The total count of digits in this block = `9` (since numbers `1–9` are single-digit).  

2. **Find the block containing `k`**  
 - While `k` is greater than the number of digits in the current block (`total * len`), subtract and move to the next block.  
 - Update:
   - `len` (digit length of numbers in the block).  
   - `total` (number of numbers in this block).  

3. **Locate the exact number and digit**  
 - `start = 10^(len-1)` (first number in this block).  
 - `numberIndex = (k-1) / len` (which number in this block).  
 - `digitIndex = (k-1) % len` (which digit inside that number).  

4. **Extract the digit**  
 - `number = start + numberIndex`.  
 - Convert to string and take `s[digitIndex]`.  


### Example Walkthrough
- Query: `k = 15`  
- Sequence: 123456789101112131415...
- Step 1: len = 1 and digits covered = 9
   - k = 15 > 9, subtract, k = 6, len = 2
- Step 2: len = 2, numbers from 10 to 99
   - Each contributes 2 digits, so block fits.
- Step 3: start = 10, numberIndex = (6-1)/2 = 2, digitIndex = (6-1)%2 = 1
   - number = 10 + 2 = 12, "12"
   - Answer = "12"[1] = 2

So the **15th digit = 2**.


### Complexity
- **Time Complexity**: O(log k), since we jump across digit-length blocks.  
- **Space Complexity**: O(1), only storing small variables and at most one string.  

---
</details>




<details>
<summary>String Reorder</summary>

---

### Idea
- Given a string `s` consisting of uppercase letters (`A–Z`), reorder its characters to form a new string such that:
  - **No two identical characters are adjacent**.  
  - If it is impossible, print `-1`.  


### Algor Steps
1. **Count frequencies**  
   - Use an array `container[26]` to store the frequency of each letter.  
   - Keep a set of characters that still have occurrences left.  

2. **Check feasibility**  
   - If the **most frequent character** occurs more than `ceil(n/2)` times, then it is impossible (output `-1`).  

3. **Greedy construction**  
   - Start with the lexicographically smallest available character.  
   - At each step:
     - Pick a character that is not equal to the previously placed one.  
     - Append it to the result string.  
     - Decrease its frequency.  
     - If the previous character still has remaining count, push it back into the candidate set.  

4. **Handle leftovers**  
   - If at some point one character still remains in large numbers (e.g., too many `T`s compared to others), then interleave it with the remaining different characters to avoid adjacency.  
   - Append them alternately until all are used.  

5. **Output result**  
   - Print the constructed string.  


### Example Walkthrough
Input: AABBB

Steps:  
- Frequencies: A=2, B=3.  
- Max frequency = 3, total = 5 is possible.  
- Build string greedily:  
  - Pick `A "A"`  
  - Pick `B "AB"`  
  - Pick `A "ABA"`  
  - Remaining `B`s trail `"ABABB"`  

Output: ABABB

### Tricks
- The greedy approach works because we always ensure the "most dangerous" character (the one with the highest frequency) is spread out.  
- If at any point it cannot be interleaved, we output `-1`.  

### Complexity
- **Time Complexity**: O(n log 26)  
  - `n` = string length.  
  - alphabet is only 26 characters.  
  - Dominated by set operations and frequency checks.  
- **Space Complexity**: O(26), constant.  



---
</details>



<details>
<summary>Grid Path Description</summary>

---

### Idea
- You are given a **7×7 grid** (49 cells total).  
- Start at the **top-left corner (0,0)** and move step by step according to a string `path` of length **48**.  
- Each character in `path` is either:
  - A fixed direction (`U`, `D`, `L`, `R`)  
  - Or a wildcard `?` (you may choose any direction).  
- You must visit **all 49 cells exactly once** (self-avoiding walk).  
- Count how many valid paths match the description.  


### Algo Steps
1. **State Representation**  
   - Track the current cell `(row, column)`.  
   - Keep `seen[row][column]` to mark visited cells.  
   - Keep `move_count` to track how many steps have been taken.  

2. **Base Case**  
   - If you reach the bottom-left cell `(6,0)` **before 48 moves**, the path is invalid.  
   - If you reach `(6,0)` **exactly at move 48**, increment `result`.  

3. **Pruning (Optimization)**  
   - If the current cell is “boxed in” (surrounded in such a way that it forces a dead-end split), prune early.  
   - Example checks:  
     - If up and down are blocked, but left and right are open, dead end.  
     - If left and right are blocked, but up and down are open, dead end.  

4. **Recursive DFS**  
   - Mark the current cell as visited.  
   - If the next move is a fixed direction:
     - Move only in that direction if possible.  
   - If the next move is `?`:
     - Try all 4 possible directions.  
   - After exploring, backtrack by unmarking the current cell.  

5. **Output**  
   - Print the total count of valid paths.  


### Tricks
- The key is **heavy pruning** — without it, the search space is too large.  
- Ensuring correctness requires careful boundary and dead-end checks.  


### Example Walkthrough
- Input:  ???????????????????????????????????????????????? (all wildcards)

- Steps:  
   - Start at `(0,0)`.  
   - At each step, branch into all possible moves.  
   - Use pruning to avoid exploring dead-end paths.  
   - After full exploration, result = **88418** (the known answer for the CSES problem).  


### Complexity
- **Worst Case**: Naive recursion explores `4^48` paths (impossible to compute).  
- **With pruning**: Reduces drastically, making the solution feasible.  
- **Space Complexity**: O(7×7) = O(49) for the grid.  


---
</details>




## Sorting and Searching

<details>
<summary>Distinct Numbers</summary>

---

### Idea
- You are given **n integers**.  
- The task is to count how many **distinct numbers** appear in the input.  
- For example:  
  - Input: `5` followed by `2 3 2 2 3`  
  - Distinct values are `{2,3}` and Answer: `2`.


### Algo Steps
1. **Input**  
   - Read `n` (the number of integers).  
   - Read the `n` integers into memory.  

2. **Data Structure**  
   - Use a **set** (ordered, unique container) to automatically remove duplicates.  

3. **Insert Elements**  
   - Loop over all input integers and insert each into the set.  
   - Since a set only keeps unique values, duplicates are ignored.  

4. **Result**  
   - The answer is simply the **size of the set**.  

### Complexity
- **Time Complexity**:  
   - Inserting into a set is `O(log n)` per element.  
   - For `n` elements, total = `O(n log n)`.  

- **Space Complexity**:  
   - The set holds at most `n` unique integers `O(n)`.  


### Tricks
- Using a set is the **simplest way** to handle duplicates.  
- Alternatively, an **unordered_set** can reduce time to average `O(n)`, but you run the risk of hash collisions and TLE (which occurs in the last test case!) 

---

</details>



<details>
<summary>Apartments</summary>

---

### Idea
- You are given:  
  - `n` = number of applicants.  
  - `m` = number of available apartments.  
  - `k` = maximum allowed difference in apartment size.  
- Each applicant requests an apartment of a certain size (`desired[i]`).  
- Each available apartment has a given size (`available[j]`).  
- An applicant can take an apartment if the **absolute difference** between the desired size and the apartment size is **≤ k**.  
- Each apartment can be assigned to **at most one applicant**.  
- The task: **maximize the number of applicants who get an apartment**.  


### Algo Steps
1. **Input**  
   - Read integers `n, m, k`.  
   - Read list `desired` of size `n`.  
   - Read list `available` of size `m`.  

2. **Sort Both Lists**  
   - Sort `desired` in ascending order.  
   - Sort `available` in ascending order.  
   - Sorting makes it easier to match applicants with apartments greedily.  

3. **Two-Pointer Matching**  
   - Start from the **largest applicant request** and the **largest apartment**.  
   - While both lists still have elements:
     - If `|available[j] - desired[i]| ≤ k`, assign apartment then increment counter, move both pointers.  
     - If `available[j] > desired[i]`, the apartment is too large so move to a smaller apartment.  
     - Else, the applicant’s request is too large so move to a smaller request.  

4. **Result**  
   - After the loop, `counter` holds the maximum number of successful assignments.  


### Complexity
- **Sorting**: `O(n log n + m log m)`  
- **Two-pointer traversal**: `O(n + m)`  
- **Total**: `O(n log n + m log m)`  

- **Space Complexity**: `O(n + m)` for storing the input arrays.  


### Tricks
- The **two-pointer approach** is key: always match the largest possible valid pairs before moving down.  
- Sorting ensures that once a match fails, you can safely move one pointer without missing future opportunities.  
- This is a standard **greedy matching problem** pattern.  


</details>



<details>
<summary>Ferris Wheel</summary>

---

### Idea
- You are given:  
  - `n` = number of children.  
  - `x` = maximum allowed weight per gondola.  
- Each child has a weight `listOfWeights[i]`.  
- Each gondola can carry **at most two children**, and their combined weight cannot exceed `x`.  
- The task: **minimize the number of gondolas needed** to carry all children.  


### Algo Steps
1. **Input**  
   - Read integers `n` and `x`.  
   - Read list `listOfWeights` of size `n`.  

2. **Sort the Weights**  
   - Sort `listOfWeights` in ascending order.  
   - Sorting allows pairing the **lightest and heaviest** children efficiently.  

3. **Two-Pointer Pairing**  
   - Initialize two pointers:  
     - `left = 0` lightest child.  
     - `right = n-1` heaviest child.  
   - Initialize `counter = 0` to count gondolas.  
   - While `left <= right`:  
     - If `listOfWeights[left] + listOfWeights[right] ≤ x`, pair them in one gondola (`left++`).  
     - Always place `right` in a gondola (`right--`).  
     - Increment `counter` for each gondola used.  

4. **Result**  
   - After the loop, `counter` holds the **minimum number of gondolas** needed.  


### Complexity
- **Sorting**: `O(n log n)`  
- **Two-pointer traversal**: `O(n)`  
- **Total**: `O(n log n)`  

- **Space Complexity**: `O(n)` for storing the weights.  


### Tricks
- The **two-pointer approach** is key: pair the **lightest remaining child with the heaviest** to minimize the number of gondolas.  
- Sorting ensures that once a child is paired, you can safely move pointers without missing future opportunities.  
- This is a standard **greedy pairing problem** pattern.  

---

</details>




<details>
<summary>Concert Tickets</summary>

---

### Idea
- You are given:  
  - `n` = number of available tickets.  
  - `m` = number of customers.  
- Each ticket has a price `ticket_prices[i]`.  
- Each customer has a maximum price `t` they are willing to pay.  
- Each customer can buy **at most one ticket**, and each ticket can be sold **at most once**.  
- The task: **for each customer, assign the most expensive ticket ≤ their budget** or `-1` if no such ticket exists.  


### Algo Steps
1. **Input**  
   - Read integers `n` and `m`.  
   - Read `n` ticket prices and store them in a `multiset` (allows duplicates and fast removals).  
   - Read `m` customer budgets.  

2. **Process Each Customer**  
   - For each customer with budget `t`:  
     - Use `lower_bound(t+1)` on the `multiset` to find the first ticket **greater than `t`**.  
     - If the iterator points to the beginning, no ticket ≤ `t` exists → output `-1`.  
     - Otherwise, move the iterator one step back to get the **largest ticket ≤ t**.  
     - Output the ticket price and remove it from the `multiset` (sold).  


### Complexity
- **Insert `n` tickets into multiset**: `O(n log n)`  
- **Process each of `m` customers**: each `lower_bound` + erase = `O(log n)`  
- **Total**: `O((n+m) log n)`  

- **Space Complexity**: `O(n)` for storing ticket prices.  


### Tricks
- Using a `multiset` allows:  
  - Fast search for the largest ticket ≤ budget.  
  - Automatic handling of duplicate ticket prices.  
- The `lower_bound(t+1)` trick ensures you get the **largest ticket ≤ t** efficiently.  
- Erasing the ticket from the `multiset` prevents it from being sold twice.  

---

</details>



<details>
<summary>Restaurant Customers</summary>

---

### Idea
- You are given:  
  - `n` = number of customer groups.  
- Each group has:  
  - `a` = arrival time.  
  - `b` = departure time.  
- The task: **find the maximum number of customers present in the restaurant at any moment**.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - For each customer group, read arrival `a` and departure `b`.  

2. **Create Events**  
   - Represent each arrival as `(time, +1)` and each departure as `(time, -1)`.  
   - Store all events in a single list `customers`.  

3. **Sort Events**  
   - Sort the events by time:  
     - If two events have the same time, **arrivals (+1) come before departures (-1)**.  
   - Sorting ensures that overlapping intervals are counted correctly.  

4. **Sweep Through Events**  
   - Initialize `cur = 0` (current number of customers) and `mx = 0` (maximum).  
   - Iterate through the events:  
     - Add the event type (`+1` for arrival, `-1` for departure) to `cur`.  
     - Update `mx = max(mx, cur)`.  

5. **Result**  
   - After processing all events, `mx` holds the **maximum number of customers simultaneously in the restaurant**.  


### Complexity
- **Creating events**: `O(n)`  
- **Sorting events**: `O(n log n)`  
- **Sweeping through events**: `O(n)`  
- **Total**: `O(n log n)`  

- **Space Complexity**: `O(n)` for storing events.  


### Tricks
- Use a **sweep line / event-based approach**: arrivals increase count, departures decrease count.  
- Sorting events carefully ensures correct handling when arrivals and departures happen at the same time.  
- Representing events as `(time, type)` pairs simplifies both sorting and iteration.  

---

</details>




<details>
<summary>Movie Festival</summary>

---

### Idea
- You are given:  
  - `n` = number of movies.  
- Each movie has:  
  - `start` = start time.  
  - `end` = end time.  
- Each movie takes exactly the interval `[start, end)`.  
- The task: **attend the maximum number of non-overlapping movies**.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - For each movie, read `start` and `end` times.  

2. **Store Movies**  
   - Use a `struct Movie` with `start` and `end`.  
   - Store all movies in a `vector<Movie>` called `movies`.  

3. **Sort Movies by End Time**  
   - Sort `movies` in ascending order of `end` time.  
   - If two movies end at the same time, sort by `start` time.  
   - Sorting ensures the greedy approach works correctly (always pick the movie that ends earliest).  

4. **Greedy Selection**  
   - Initialize `prev = 0` (end time of the last attended movie) and `counter = 0`.  
   - Iterate through the sorted movies:  
     - If `movie.start >= prev`, you can attend this movie.  
       - Increment `counter`.  
       - Set `prev = movie.end`.  
     - Otherwise, skip the movie.  

5. **Result**  
   - After iterating through all movies, `counter` holds the **maximum number of non-overlapping movies** you can attend.  


### Complexity
- **Sorting**: `O(n log n)`  
- **Greedy traversal**: `O(n)`  
- **Total**: `O(n log n)`  

- **Space Complexity**: `O(n)` for storing the movies.  


### Tricks
- Always **sort by end time** first — this is the core of the greedy approach.  
- Using a struct with `start` and `end` makes the code more readable, but using `pair<end,start>` works as well.  
- Once a movie is selected, update `prev` to its **end time**, not start.  
- This is a classic **interval scheduling problem** pattern in competitive programming.  

---

</details>



<details>
<summary>Sum of Two Values</summary>

---

### Idea
- You are given:  
  - `n` = number of elements in the array.  
  - `x` = target sum.  
- You need to find **two distinct elements** in the array whose sum is exactly `x`.  
- If such a pair exists, output their **1-based indices**. Otherwise, output `"IMPOSSIBLE"`.  


### Algo Steps
1. **Input**  
   - Read integers `n` and `x`.  
   - Read array of `n` elements.  

2. **Use a Map to Track Seen Values**  
   - Create a map `seen` that stores `value -> index`.  
   - Iterate through the array:  
     - For each element `a[i]`, check if `x - a[i]` exists in `seen`.  
       - If it does, you have found a valid pair: output the indices.  
     - Otherwise, add `a[i]` to `seen` with its index.  

3. **Output Result**  
   - If no pair is found after iterating through the array, print `"IMPOSSIBLE"`.  


### Complexity
- **Time Complexity**: `O(n)`  
  - Each lookup and insertion in `map` is amortized `O(log n)`.  
- **Space Complexity**: `O(n)` for storing the map of seen elements.  


### Tricks
- Using a **hash map** (or `std::map`) allows checking in `O(log n)` whether a complement exists.  
- Store **indices** in the map to output the solution directly.  
- This is a classic **two-sum problem** pattern in competitive programming.  

---

</details>




<details>
<summary>Maximum Subarray Sum</summary>

---

### Idea
- You are given:  
  - `n` = number of elements in the array.  
  - An array of integers of length `n`.  
- The task: **find the maximum sum of any contiguous subarray**.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - Read array of `n` integers.  

2. **Kadane’s Algorithm**  
   - Initialize two variables:  
     - `cur` = current subarray sum, initially `0`.  
     - `mx` = maximum subarray sum, initially `-∞`.  
   - Iterate through the array:  
     - Add the current element to `cur`.  
     - Update `mx = max(mx, cur)`.  
     - If `cur < 0`, reset `cur = 0` (start a new subarray).  

3. **Output Result**  
   - After iterating, `mx` contains the **maximum subarray sum**.  


### Complexity
- **Time Complexity**: `O(n)` — single pass through the array.  
- **Space Complexity**: `O(1)` — only a few variables are used.  


### Tricks
- Kadane’s algorithm works by keeping track of the **current running sum** and **resetting it when it becomes negative**.  
- This is a standard **greedy + dynamic programming** pattern for maximum subarray problems.  
- Handles arrays with negative numbers correctly by initializing `mx` to `-∞`.  

---

</details>




<details>
<summary>Stick Lengths</summary>

---

### Idea
- You are given:  
  - `n` = number of sticks.  
  - An array of stick lengths `sticks[i]`.  
- The task: **make all sticks the same length** with the **minimum total cost**, where changing a stick’s length costs the absolute difference.  

- Key observation: the **median** of the stick lengths minimizes the sum of absolute differences.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - Read array `sticks` of length `n`.  

2. **Sort the Stick Lengths**  
   - Sort `sticks` in ascending order.  
   - The median is at index `n / 2`.  

3. **Compute Minimum Cost**  
   - Initialize `mn = 0`.  
   - For each stick length `stick`:  
     - Add `abs(stick - median)` to `mn`.  

4. **Output Result**  
   - Print `mn`, the minimum total adjustment cost.  


### Complexity
- **Sorting**: `O(n log n)`  
- **Sum calculation**: `O(n)`  
- **Total**: `O(n log n)`  

- **Space Complexity**: `O(n)` for storing stick lengths.  


### Tricks
- Choosing the **median** as the target minimizes the sum of absolute differences (a standard property in statistics).  
- Sorting is necessary to find the median efficiently.  
- This is a **greedy / statistical observation** problem common in CSES and competitive programming.  

---

</details>



<details>
<summary>Missing Coin Sum</summary>

---

### Idea
- You are given:  
  - `n` = number of coins.  
  - An array `coins[i]` of positive integer coin values.  
- The task: **find the smallest positive integer that cannot be formed as a sum of any subset of coins**.  

- Key observation: if you process the coins in **ascending order** and maintain a running `prefix` sum of constructible values:  
  - If a coin is greater than `prefix`, then `prefix` cannot be formed.  
  - Otherwise, add the coin to `prefix` to extend the range of sums.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - Read array `coins` of length `n`.  

2. **Sort Coins**  
   - Sort `coins` in ascending order.  
   - This ensures that you always extend the range of constructible sums in order.  

3. **Find Missing Sum**  
   - Initialize `prefix = 1` (smallest positive sum to construct).  
   - Iterate through `coins`:  
     - If `coins[i] > prefix`, output `prefix` and terminate — it's the smallest missing sum.  
     - Otherwise, update `prefix += coins[i]`.  

4. **Output Result**  
   - After iterating all coins, print `prefix` (smallest unconstructible sum).  


### Complexity
- **Sorting**: `O(n log n)`  
- **Prefix computation**: `O(n)`  
- **Total**: `O(n log n)`  

- **Space Complexity**: `O(n)` for storing coins.  


### Tricks
- Sorting is key: ensures that you always try to build sums from smallest to largest.  
- The **prefix sum approach** is greedy: it always keeps track of the largest sum that can be formed with coins processed so far.  
- This is a classic **constructive greedy problem** in competitive programming.  


---

</details>


<details>
<summary>Collecting Numbers</summary>

---

### Idea
- You are given:  
  - `n` = number of cards, numbered `1` to `n`.  
  - A sequence of `n` integers representing the order in which cards appear.  
- The task: **determine the minimum number of rounds required to collect all cards in increasing order**.  
  - In one round, you can take a contiguous subsequence of cards in **strictly increasing order**.  


### Algo Steps
1. **Input**  
   - Read integer `n`.  
   - Read array of length `n` representing card order.  

2. **Track Seen Cards**  
   - Use a boolean array `seen` of size `n+1`.  
   - Iterate through the cards:  
     - If the previous card (`x-1`) has **not been seen yet**, increment `counter` (new round required).  
     - Mark the current card `x` as seen.  

3. **Output Result**  
   - Print `counter`, the **minimum number of rounds** needed.  


### Complexity
- **Time Complexity**: `O(n)` — single pass through the array.  
- **Space Complexity**: `O(n)` — for `seen` array.  


### Tricks
- The key observation: a **new round** is needed whenever the previous number has not been collected yet.  
- Using a **boolean array** allows constant-time checks for previous numbers.  
- This is a classic **greedy approach** for sequence-based collection problems.  


---

</details>



<details>
<summary>Collecting Numbers II</summary>

---

### Idea
- You are given:
  - `n` numbers arranged in an array `elements[1..n]` (1-based indexing).  
  - `m` swap operations `(a, b)` that swap two positions in the array.  
- Define a **round** as collecting numbers in increasing order starting from 1.  
- The task: **after each swap, determine the minimum number of rounds needed to collect all numbers**.


### Observations
- A round is defined by **contiguous increasing sequences**.  
- Only neighbors `x-1` and `x+1` matter for counting new rounds.  
- You can track **positions of each number** using a `pos[number]` array.  
- Initially, the number of rounds is `1` plus the count of numbers whose **position is less than the previous number**.


### Algorithm Steps

1. **Input & Initialization**
   - Read integers `n` and `m`.
   - Read array `elements[1..n]`.  
   - Initialize `pos[number]` as the current position of each number.  
   - Initialize `counter = 1`.  
   - Count initial rounds:
     ```cpp
     rep(i, 2, n) 
         if (pos[i] < pos[i - 1]) 
             ++counter;
     ```

2. **Update Function**
   - For a swap `(a, b)`:
     - Check neighbors of `elements[a]` (`elements[a]-1` and `elements[a]+1`) and update `counter` if the relative order changes.  
     - Repeat for `elements[b]`.  
     - Update `pos[elements[a]]` and `pos[elements[b]]`.  
     - Swap the elements in the array.

3. **Process Queries**
   - For each swap `(a, b)`:
     - Call `update(a, b)`.
     - Output the current `counter` (minimum rounds after the swap).


### Complexity
- **Initialization**: `O(n)` to populate `pos` and count initial rounds.  
- **Each swap**: `O(1)` since only neighbors are checked.  
- **Total**: `O(n + m)`  
- **Space Complexity**: `O(n)` for `elements` and `pos` arrays.


### Tricks
- Use **1-based indexing** for simplicity when checking neighbors.  
- Only **neighbors matter**; no need to check the entire array after each swap.  
- Maintaining the `pos` array allows **constant-time updates** of rounds.


---

</details>



<details>
<summary>Playlist</summary>

---

### Idea
- You are given:
  - A playlist of `n` songs, each represented by an integer.  
- The task: **find the length of the longest contiguous subsequence with all distinct songs**.  

This is equivalent to finding the **longest subarray with unique elements**.


### Observations
- A brute-force approach (checking all subarrays) would be `O(n²)` and too slow.  
- Use the **two pointers / sliding window technique** with a set:
  - Pointer `i` → right boundary of the window (current song being added).  
  - Pointer `j` → left boundary of the window (used to remove duplicates).  
- Maintain a `set` of seen songs inside the current window.  
- When a duplicate is found:
  - Move `j` forward and erase songs until the duplicate is removed.  
- Track the current window size (`counter`) and update the maximum length (`mx`).  


### Algorithm Steps

1. **Input & Initialization**
   - Read integer `n` (number of songs).  
   - Read array `songs[0..n-1]`.  
   - Initialize an empty set `seen`.  
   - Initialize pointers `j = 0`, `counter = 0`, `mx = 0`.  

2. **Sliding Window**
   - For each index `i` from `0..n-1`:  
     - While `songs[i]` is already in `seen`:  
       - Remove `songs[j]` from the set.  
       - Increment `j` and decrement `counter`.  
     - Add `songs[i]` to `seen`.  
     - Increment `counter`.  
     - Update `mx = max(mx, counter)`.  

3. **Output**
   - Print `mx` (the maximum window size with all distinct songs).  


### Complexity
- **Time Complexity:**  
  - Each song is added once and removed once → `O(n log n)` (because of `set` operations).  
  - If `unordered_set` is used, average complexity improves to `O(n)`.  
- **Space Complexity:**  
  - `O(n)` for storing the set of songs.  


### Tricks
- The **two pointers** technique is crucial to avoid `O(n²)` checking.  
- Using a set allows **fast duplicate detection and removal**.  
- Alternative: `unordered_set` can optimize constant factors for faster runtime.  

---

</details>


<details>
<summary>Cubes</summary>

---

### Idea
- You are given:
  - An integer `n` (number of cubes).
  - A sequence of cube sizes `k₁, k₂, …, kₙ`.  
- The task: **build the tallest possible tower by stacking cubes** such that:
  - Each new cube must be placed on top of a cube **strictly larger** than it.  

This reduces to simulating the tower construction with greedy logic.


### Observations
- The problem is equivalent to maintaining the **top cube of each tower**:
  - If there exists a tower whose top cube is **greater than `k`**, replace that top with `k`.
  - Otherwise, start a new tower with `k`.  
- This is essentially the **patience sorting** technique (also used in LIS problems).
- A `multiset` maintains current tower tops in sorted order:
  - `lower_bound(k+1)` finds the smallest tower top strictly greater than `k`.
  - If such a tower exists → replace its top with `k` (erase old top, insert `k`).
  - If not → insert `k` as a new tower.


### Algorithm Steps

1. **Input & Initialization**
   - Read integer `n`.  
   - Initialize an empty multiset `cubes`.  

2. **Processing Cubes**
   - For each cube size `k`:  
     - Use `it = cubes.lower_bound(k+1)` to find the smallest top strictly greater than `k`.  
     - If `it != cubes.end()`:
       - Remove that tower top (`cubes.erase(it)`).
     - Insert `k` into the multiset.  

3. **Output**
   - The number of towers is equal to the size of the multiset:  
     ```cpp
     cout << cubes.size() << endl;
     ```


### Complexity
- **Time Complexity:**  
  - Each cube requires one `lower_bound` and at most one `erase` and `insert`.  
  - Each operation is `O(log n)`.  
  - Total complexity: `O(n log n)`.  

- **Space Complexity:**  
  - `O(n)` in the worst case (all cubes form separate towers).  


### Tricks
- Using `lower_bound(k+1)` instead of `lower_bound(k)` ensures **strictly larger** matching.  
- `multiset` allows duplicate tower tops, which is important when multiple towers can have the same size.  
- This is the same idea behind the **LIS patience sorting algorithm**, but here we directly need the number of piles (towers), not their length.  

---

</details>


<details>
<summary>Traffic Lights</summary>

---

### Idea
- You are given:
  - A street of length `x`.
  - `n` traffic light placements at positions `p₁, p₂, …, pₙ`.  
- The task: **after each light is added, output the length of the longest segment without traffic lights**.  

This simulates splitting the street into intervals as new lights are placed.


### Observations
- Initially, the street is a single segment `[0, x]` of length `x`.  
- Each time a new light is placed at position `p`:
  - It **splits an existing segment** `[down, up]` into two segments: `[down, p]` and `[p, up]`.  
- To efficiently track:
  - A `set` of positions of lights (including `0` and `x`).
  - A `multiset` of segment lengths.
- When inserting a new light:
  1. Find the neighbors `down = prev(p)` and `up = next(p)` from the `set`.  
  2. Remove the old segment `(up - down)` from the `multiset`.  
  3. Insert the two new segments `(p - down)` and `(up - p)` into the `multiset`.  
- The maximum segment length is always the last element of the `multiset`.


### Algorithm Steps

1. **Input & Initialization**
   - Read integers `x` (street length) and `n` (number of lights).  
   - Initialize a `set streets` with `{0, x}` (endpoints).  
   - Initialize a `multiset lights` with `{x}` (the full street length).  

2. **Process Each Light**
   - For each new light position `p`:  
     - Insert `p` into `streets`.  
     - Find its neighbors:  
       ```cpp
       auto it = streets.find(p);
       auto up = *next(it);
       auto down = *prev(it);
       ```
     - Remove old segment: `lights.erase(lights.find(up - down))`.  
     - Add new segments:  
       ```cpp
       lights.insert(up - p);
       lights.insert(p - down);
       ```
     - Print the maximum segment: `*lights.rbegin()`.  

3. **Output**
   - After each light insertion, output the maximum segment length, separated by spaces.  


### Complexity
- **Time Complexity:**  
  - Each light insertion requires:
    - One `set` insertion (`O(log n)`).
    - Neighbor lookup via `prev`/`next` (`O(1)`).
    - Up to two `multiset` insertions and one erase (`O(log n)` each).  
  - Total: `O(n log n)`.  

- **Space Complexity:**  
  - `O(n)` for storing light positions and segment lengths.  


### Tricks
- Using `set` ensures lights are always stored in sorted order for neighbor lookup.  
- `multiset` handles multiple segments of the same length and allows easy removal of just one occurrence.  
- `*lights.rbegin()` is a neat way to always get the current maximum segment length in constant time.  

---

</details>



<details>
<summary>Distinct Values Subarrays</summary>

---

### Idea
- You are given:
  - An array of `n` integers.  
- The task: **count the total number of subarrays that contain only distinct elements**.  

This is equivalent to summing the lengths of all windows that contain unique elements.


### Observations
- A brute-force approach (checking all subarrays) would be `O(n²)`, too slow for `n = 2e5`.  
- Instead, use a **two pointers / sliding window** approach with a hash map (`unordered_map`).  
- Maintain:
  - `left` → left boundary of the current window.
  - `right` → right boundary as we iterate through the array.
  - `seen[x]` → the most recent index where `x` was found.  
- When a duplicate appears:
  - Move `left` to `max(left, seen[x] + 1)` to ensure uniqueness.  
- For each position `right`, the number of distinct subarrays ending at `right` is `(right - left + 1)`.  
- Accumulate this count into `sum`.



### Algorithm Steps

1. **Input & Initialization**
   - Read integer `n` (array length).  
   - Initialize:
     - `unordered_map<ll, ll> seen` → last index of each element.  
     - `left = 0`, `sum = 0`.  

2. **Sliding Window**
   - For each index `right` from `0..n-1`:  
     - Read element `x`.  
     - If `x` has been seen before and its last index is inside the window:  
       ```cpp
       if (seen.count(x)) 
           left = max(left, seen[x] + 1);
       ```
     - Update last occurrence: `seen[x] = right`.  
     - Count distinct subarrays ending at `right`:  
       ```cpp
       sum += right - left + 1;
       ```

3. **Output**
   - Print `sum`.  


### Complexity
- **Time Complexity:**  
  - Each element is processed once as `right`, and `left` only moves forward.  
  - Hash map lookups/updates are `O(1)` average.  
  - Total: `O(n)`.  

- **Space Complexity:**  
  - `O(n)` for storing last seen positions in the hash map.  


### Tricks
- The trick is realizing that **each index contributes to multiple subarrays**.  
  - By counting `(right - left + 1)`, you efficiently account for all distinct subarrays ending at `right`.  
- Using `unordered_map` ensures fast lookups for last occurrences.  
- The sliding window ensures we don’t double-count duplicates.  

---

</details>
