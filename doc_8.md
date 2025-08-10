# prog_8.c documentation

## Data structures
- Uses integer arrays to hold data. A couple of global counters, one to count comparisons called, comps and one to count swaps called swaps.
  
## Functions 
- `bubble_sort`, `selection_sort`, `insertion_sort` - All track comparisons and swaps.
- `merge_sort` - Only counts comparisons in the merge part (swaps don't have any meaning in a merge).

## main()
- Creates `N` random integers in [1,1000], copies the array, prompts the user to choose a sorting algorithm, runs it, prints the original and sorted array and counts.

## Sample execution
```
Enter N (number of random integers): 5
Original array:
23 987 12 450 321 
Choose sorting algorithm:
1. Bubble
2. Selection
3. Insertion
4. Merge
Enter choice: 1
Sorted array:
12 23 321 450 987 
Comparisons: 10
Swaps: 4
```