# Documentation for prog_3.c

## Data structures

- `struct Node` consisting of `int data` and `Node *next` representing a singly linked list.

## Functions

- `newNode(int)` - creates and returns a new node.

- `push(Node**, int)` - adds a new node at the head of the list.

- `reverse_print(Node*)` - uses recursion to traverse to the end of the list and print nodes during backtracking.

## main()

- Construct a sample list `1 -> 2 -> 3 -> 4`, prints it head to tail, and calls reverse_print to print tail to head.

## Sample output

```

Forward order (head to tail): 1 2 3 4 

Reverse traversal output: 4 3 2 1 

```

