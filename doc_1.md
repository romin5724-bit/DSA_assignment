# Documentation for prog_1.c

## Data structures

- Stack operations are implemented using a simple `char stack[1024]` array along with an integer `top`.

- Character checks for opening and closing brackets are performed using `isOpening(char c)` and `isClosing(char c)`.

## Functions

- `isOpening(char c)` - checks if `c` is one of `(`, `[`, `{` and returns accordingly.

- `isClosing(char c)`` - checks if`c` is closing bracket and returns true if it is.

- `matches(char o, char c)` - validates the opening and closing pair.

- `balanced(const char *s)` - employs stack to validate if the provided string of parentheses are balanced and returns 1 (true) or 0 (false).

## main()

- Implements three test cases (provided in the assignment) and displays the balanced status of each.

## Sample output

```
Expression: a + (b - c) * (d

Balanced? No

Expression: m + [a - b * (c + d * {m)]

Balanced? No

Expression: a + (b - c)

Balanced? Yes
```

