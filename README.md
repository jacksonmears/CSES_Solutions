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

<br>


- Start from `n`.  
- If `n` is even then divide by 2.  
- If odd then multiply by 3 and add 1.  
- Continue until `n = 1`.  
- O(log n) time.  

<br>

</details>

<details>
<summary>Missing Number</summary>

<br>

- We know the sum of numbers from 1 to n is `n*(n+1)/2` total.  
- Read the n-1 given numbers, compute their sum.  
- Subtract from the total to find the missing number.  
- Time complexity: O(n). Space: O(1).

<br>

</details>


<details>
<summary>Repetitions</summary>
<br>

- We iterate through the string, tracking the length of the current run of identical characters.  
- Update the maximum run length whenever it increases and reset counter back to one when it's a different character.
- Time complexity: O(n). Space: O(1).
<br>
</details>


<details>

<summary>Increasing Array</summary>
<br>

- Iterate through the array tracking the value of the previous element. 
- If the current element is smaller than the previous then we need to increase the total count by the difference.
- Time complexity: 0(n)
<br>
</details>


<details>

<summary>Permutations</summary>
<br>

- impossible solutions for `n = 2` or `n = 3` because any arrangement will have two consecutive numbers differing by 1.
- For all other `n` we can simply print all even then all odd values.
- Time complexity: O(n)
<br>
</details>



---

## Sorting and Searching

<details>
<summary>Distinct Numbers</summary>
<br>
- Sort the array and count the number of distinct elements by comparing each to the previous.
- The most straight forward way to accomplish this is by transforming the input array into a set and printing the size.
- Time complexity: O(n log n). Space: O(1) extra.
<br>
</details>

<details>
<summary>Apartments</summary>
<br>
We sort both desired sizes and available apartments.  
Use two pointers to match each applicant with the closest acceptable apartment within `k` size difference.  
- Time complexity: O(n log n).  
<br>
</details>


---
