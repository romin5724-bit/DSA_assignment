# Information on prog_4.c

## Data structures 
- `struct DNode`, with `int data` and pointers `prev` and `next`.

## Functions
- `newNode(int)` - to create a new node. 
- `insert_after(DNode *node, int val)` - to insert a new node with value `val` right after `node`. 
- `delete_node(DNode **head, DNode *node)` - to delete the `node` from the list and update the head (if applicable). 
- `print_forward(DNode *head)` - to output a printable representation of the list starting at head.

## main()
- shows creating a small doubly linked list, inserting a new node after another node, and deleting a node.

## Sample output 
```
The original list is: 10 20 30 
Insert 25 after 20:
10 20 25 30 
Delete node with 20:
10 25 30 
```