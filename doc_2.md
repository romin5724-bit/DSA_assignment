# Documentation for prog_2.c

## Data Structures

- Contains arrays utilized as stacks for operators and for evaluation.

- Output for the postfix string is allocated dynamically.

## Functions

- `prec(char)` - gives the value of the precedence.

- `isOp(char)` - checks for an operator.

- `infix_to_postfix(const char*)` - uses shunting-yard algorithm to output a postfix string of space separated tokens.

- `eval_postfix(const char*)` - processes the postfix expression and provides the computed value.

## main()

- Shows conversion and evaluation using the example expression

`3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3`.

## Sample Output

```
Infix: 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3

Postfix: 3 4 2 * 1 5 - 2 3 ^ ^ / + 

Evaluated value: 3

```

