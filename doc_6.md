# Documentation for prog_6.c

## Data structures
- Arrays are used to model  heaps. If the array is zero indexed:
  - Left child = 2*i + 1 
  - Right child = 2*i + 2

## Functions
- `heapify_max` / `heapify_min` - Heaps leverage percolate-down to restore heap property.
- `build_max_heap` / `build_min_heap` - call heapify from the last internal node and percolate down.

## main()
-  demonstrates building max-heap and min-heap from an example array. 

## Sample output
```
Original array: 7 3 5 1 9 2 8 
Max-heap array: 9 7 8 1 3 2 5 
Min-heap array: 1 3 2 7 9 5 8 
```