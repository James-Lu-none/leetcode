# learned algorithms

## chapters

1. Time Complexity
2. Division and Conquer & Recurrences
3. Greedy Algorithms
4. prune and search
5. Dynamic Programming
6. Graph Algorithms
7. NP-Complete Theory
8. Backtracking

## data structures

1. vector
2. queue
3. priority queue
4. stack
5. hash table
6. linked list
7. double linked list
8. skip list
9. trie
10. heap (min-heap, max-heap)
11. Binary Indexed Tree (BIT) / Fenwick Tree

## sorting algorithms

| Algorithm | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|-----------|-----------------------------|-------------------------|------------------|
| quick sort | O(n log n) | O(n^2) | O(log n) |
| merge sort | O(n log n) | O(n log n) | O(n) |
| time sort | O(n log n) | O(n log n) | O(1) |
| heap sort | O(n log n) | O(n log n) | O(1) |
| bubble sort | O(n^2) | O(n^2) | O(1) |
| insertion sort | O(n^2) | O(n^2) | O(1) |
| selection sort | O(n^2) | O(n^2) | O(1) |
| tree sort | O(n log n) | O(n^2) | O(n) |
| shell sort | O(n log n) | O(n^2) | O(1) |
| bucket sort | O(n + k) | O(n^2) | O(n + k) |
| Radix sort | O(d * n) | O(d * n) | O(n + k) |
| counting sort | O(n + k) | O(n + k) | O(k) |
| cube sort | O(n^(3/2)) | O(n^(3/2)) | O(1) |
| merge sort | O(n log n) | O(n log n) | O(n) |

# partitioning algorithms

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Dutch National Flag Problem (3-way partitioning) | O(n) | O(1) |


## searching algorithms

1. binary search on answer (when the answer is a number and has a monotonic property ())
2. depth-first search (DFS)
3. breadth-first search (BFS)
4. fast and slow pointers (Floyd's Tortoise and Hare algorithm)

## methods

1. Inversion Pair 
    - with merge sort: O(n log n)
        step1: divide the array into two halves
        step2: count the number of reverse pairs in the left half and right half recursively
        step3: count the number of reverse pairs across the two halves (i.e., left[i] > right[j]) with two pointers
        step4: merge the two halves together
2. subarray iteration: O(n^2) with left right bounds -> O(n) with prefix sum

## choice of data structure for range query problems

- Sum of range using Nested Loop :
A simple solution is to run a loop from l to r and calculate the sum of elements in the given range. To update a value, simply do arr[i] = x. The first operation takes O(n) time and the second operation takes O(1) time. 

- Sum of range using Prefix Sum :
Another solution is to create another array and store the sum from start to i ,at the ith index in this array. The sum of a given range can now be calculated in O(1) time, but update operation takes O(n) time now. This works well if the number of query operations is large and very few updates.

- Sum of range using Segment Tree :
The most efficient way is to use a segment tree, we can use a Segment Tree to do both operations in O(log(N)) time.

## solve patterns

1. Prefix Sum
    - 303. Range Sum Query - Immutable
    - 525. Contiguous Array
    - 560. Subarray Sum Equals K

2. Two Pointers
    - 167. Two Sum II - Input Array is Sorted
    - 15. 3 Sum
    - 11. Container with most water

3. Sliding Window
    - 643. Maximum Average Subarray I
    - 3. Longest Substring without Repeating Characters
    - 76. Minimum Window Substring

4. Fast and Slow Pointers
    - 141. Linked List Cycle
    - 202. Happy Number
    - 287. Find the Duplicate Number

5. Linked List in-place reversal
    - 206. Reverse Linked List
    - 92. Reverse Linked List II
    - 24. Swap Nodes in Pairs

6. Monotonic Stack
    - 496. Next Greater Element I
    - 739. Daily Temperatures
    - 84. Largest Rectangle in Histogram

7. Top K. Elements OR min/max Heap
    - 215. Kth Largest element in an array
    - 347. Top K Frequent Elements
    - 373. Find K Pairs with Smallest Sums

8. Overlapping Intervals
    - 56. Merge Intervals
    - 57. Insert Interval
    - 435. Non-overlapping intervals

9. Modified Binary Search
    - 33. Search in Rotated Sorted Array
    - 153. Find Minimum in Rotated Sorted Array
    - 240. Search a 2D Matrix II

10. Binary Tree Traversal
    - 257. Binary Tree Paths
    - 230. Kth Smallest Element in a BST
    - 124. Binary Tree Maximum Path Sum
    - 107. Binary Tree Level Order Traversal II

11. Depth First Search
    - 133. Clone Graph
    - 113. Path Sum II
    - 210. Course Schedule II

12. Breadth First Search
    - 102. Binary Tree Level Order Traversal
    - 994. Rotting Oranges
    - 127. Word Ladder

13. Matrix Traversal
    - 733. Flood Fill
    - 200. Number of Islands
    - 130. Surrounded Regions

14. Backtracking
    - 46. Permutations
    - 78. Subsets
    - 51. N-Queens

15. Dynamic Programming
    - 70. Climbing Stairs
    - 322. Coin Change
    - 300. Longest Increasing Subsequence
    - 416. Partition Equal Subset Sum
    - 312. Burst Balloons
    - 1143. Longest Common Subsequence