# CSES Problem Set Solutions

This repository contains my solutions to the [CSES Problem Set](https://cses.fi/problemset/).  
The focus here is on explaining **how** and **why** each solution works.  

---

## Table of Contents
- [Introductory Problems](#introductory-problems)
- [Sorting and Searching](#sorting-and-searching)

---

## Introductory Problems

<details>
<summary>Weird Algorithm</summary>

<br><br>


- Start from `n`.  
- If `n` is even then divide by 2.  
- If odd then multiply by 3 and add 1.  
- Continue until `n = 1`.  
- O(log n) time.  

<br>

</details>

<details>
<summary>Missing Number</summary>

<br><br>

- We know the sum of numbers from 1 to n is `n*(n+1)/2` total.  
- Read the n-1 given numbers, compute their sum.  
- Subtract from the total to find the missing number.  
- Time complexity: O(n). Space: O(1).

<br>

</details>


<details>
<summary>Repetitions</summary>

<br><br>

- We iterate through the string, tracking the length of the current run of identical characters.  
- Update the maximum run length whenever it increases and reset counter back to one when it's a different character.
- Time complexity: O(n). Space: O(1).

<br>
</details>


<details>

<summary>Increasing Array</summary>

<br><br>

- Iterate through the array tracking the value of the previous element. 
- If the current element is smaller than the previous then we need to increase the total count by the difference.
- Time complexity: 0(n)

<br>
</details>


<details>

<summary>Permutations</summary>

<br><br>

- impossible solutions for `n = 2` or `n = 3` because any arrangement will have two consecutive numbers differing by 1.
- For all other `n` we can simply print all even then all odd values.
- Time complexity: O(n)

<br>
</details>

<details>

<summary>Number Spiral</summary>

<br><br>

- compare row and column
  - if column >= row:
    - if column is odd the sprials largest value is at the bottom of the column `column^2 - row + 1`
    - if column is even the spirals largest value is at the top of the column `(column - 1)^2 + row`
  - if row > column:
    - if row is even the spirals largest value is at the rightmost cell in the row `row^2 - column + 1`
    - if row is odd then largest is in leftmost cell in the row `(row - 1)^2 + column`
- Time complexity: O(1)

<br>

</details>

<details>

<summary>Two Knights</summary>

<br><br>

- difference between binomial coefficient (k squared chose 2) and points where the two knights could attack each other.
- total number of ways to place 2 knights on a KxK board is `(k^2 * (k^2 - 1)) / 2)` for k squared chose 2
- Now we need to subtract all instances where the two knights can attack each other that were included in the binomial coefficient
- Knights only attack in 2x3 or 3x2 (would be 1x2 and 2x1 in a matrix) rectangles and the number of such rectangles on a KxK board is `(k-1)(k-2)` and `(k-2)(k-1)` OR simply `2(k-1)(k-2)`
- within each rectangle the knights can attack each other in exactly 2 DISTINCT pairs in a 1x2 grid where knights attack each other (top left/bottom right, top right/bottom left)
- so the final number of squares to be removed is `4(k-1)(k-2)`
- entire formula is `(k^2 *(k^2 -1))/2 - 4*(k-1)*(k-2)`
- Time complexity: O(1)

<br>


</details>



---

## Sorting and Searching

<details>
<summary>Distinct Numbers</summary>

<br><br>

- Sort the array and count the number of distinct elements by comparing each to the previous.
- The most straight forward way to accomplish this is by transforming the input array into a set and printing the size.
- Time complexity: O(n log n). Space: O(1) extra.

<br>
</details>

<details>
<summary>Apartments</summary>

<br><br>

We sort both desired sizes and available apartments.  
Use two pointers to match each applicant with the closest acceptable apartment within `k` size difference.  
- Time complexity: O(n log n). 

<br>
</details>


---
