# Qn 8: Sorting Algorithms Performance Analyzer

## Overview

This program demonstrates and compares four fundamental sorting algorithms:

- Bubble Sort  
- Selection Sort  
- Insertion Sort  
- Merge Sort  

Instead of only sorting numbers, the program also measures how each algorithm behaves internally by counting:

- Total number of comparisons  
- Total number of swaps or movements  

The goal of this program is not just to sort an array, but to help understand the efficiency differences between simple O(n²) algorithms and the more optimized O(n log n) Merge Sort.

---

## 1. Explanation of Data Structures

### a. Integer Array

The main data structure used in this program is a one-dimensional integer array:

```cpp
int numbers[size];
```

This array stores randomly generated values between 1 and 1000. It is passed to the selected sorting function for processing.

Since sorting algorithms work directly on arrays, no additional complex data structures (like linked lists or trees) are required.

---

### b. Global Performance Counters

```cpp
long long totalComp;
long long totalMoves;
```

Two global variables are used to track performance:

- `totalComp` counts how many comparisons are made.  
- `totalMoves` counts how many swaps or shifts occur.  

They are declared as `long long` to safely store large values when the array size increases. Using global variables ensures that all sorting functions can update the same counters.

---

## 2. Description of Functions & Their Purpose

### a. initStats()

This function resets the performance counters to zero before starting a new sorting process.  

**Purpose:** Ensures accurate measurement for each algorithm.

---

### b. displayList(int data[], int size)

Prints all elements of the array in a clean format.  

**Purpose:** Helps visualize the original and sorted array.

---

### c. bubbleArrange(int data[], int size)

Implements the Bubble Sort algorithm.  

**How it works:**

- Finds the minimum element in the unsorted portion.  
- Swaps it with the current position.  
- Repeats until fully sorted.  

**Time Complexity:** O(n²)

---

### d. insertArrange(int data[], int size)

Implements the Insertion Sort algorithm.  

**How it works:**

- Takes one element at a time.  
- Inserts it into its correct position within the already sorted portion.  

**Time Complexity:** O(n²)

Efficient when the array is already nearly sorted.

---

### e. insertArrange(int data[], int size)

Implements the Insertion Sort algorithm.  

**How it works:**

- Takes one element at a time.  
- Inserts it into its correct position within the already sorted portion.  

**Time Complexity:** O(n²)

Efficient when the array is already nearly sorted.

---

### f. combine(int data[], int left, int mid, int right)

This function is part of Merge Sort.  

**How it works:**

- Merges two already sorted subarrays.  
- Ensures the final combined array remains sorted.  
- Counts comparisons and moves during merging.

---

### g. mergeArrange(int data[], int start, int end)

Implements the Merge Sort algorithm using recursion.  

**How it works:**

- Divides the array into two halves.  
- Recursively sorts each half.  
- Calls combine() to merge them.  

**Time Complexity:** O(n log n)

More efficient for large datasets.

---

## 3. Organization of the main() Method

The main() method follows a clear and logical structure:

- The user is asked to enter the number of elements.  
- An array of that size is created.  
- Random numbers are generated using rand().  
- The original array is displayed.  
- The user selects a sorting algorithm.  
- Performance counters are reset.  
- The chosen sorting function is executed.  
- The sorted array is displayed.  
- The total comparisons and moves are printed.

---

## 4. Sample Output of a Complete Run

```
Enter number of items: 6

Initial Array:
345 12 789 56 234 98

Choose Sorting Method:
1. Bubble
2. Selection
3. Insertion
4. Merge
Enter option: 4

Sorted Array:
12 56 98 234 345 789

Total Comparisons: 8
Total Swaps/Moves: 12
```

