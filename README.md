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

- Start from `n`.  
- If `n` is even then divide by 2.  
- If odd then multiply by 3 and add 1.  
- Continue until `n = 1`.  
- O(log n) time.  

</details>

<details>
<summary>Missing Number</summary>

We know the sum of numbers from 1 to n is `n*(n+1)/2` total.  
- Read the n-1 given numbers, compute their sum.  
- Subtract from the total to find the missing number.  
- Time complexity: O(n). Space: O(1).

</details>


<details>
<summary>Repetitions</summary>

- We iterate through the string, tracking the length of the current run of identical characters.  
- Update the maximum run length whenever it increases and reset counter back to one when it's a different character.
- Time complexity: O(n). Space: O(1).

</details>

---

## Sorting and Searching

<details>
<summary>Distinct Numbers</summary>

- Sort the array and count the number of distinct elements by comparing each to the previous.
- The most straight forward way to accomplish this is by transforming the input array into a set and printing the size.
- Time complexity: O(n log n). Space: O(1) extra.

</details>

<details>
<summary>Apartments</summary>

We sort both desired sizes and available apartments.  
Use two pointers to match each applicant with the closest acceptable apartment within `k` size difference.  
- Time complexity: O(n log n).  

</details>


---
