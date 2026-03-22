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