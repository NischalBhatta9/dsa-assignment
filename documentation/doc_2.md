# Program 2: Infix to Postfix Converter & Evaluator

## Overview
This program handles two critical tasks in mathematical computation: converting an **Infix** expression (standard notation like `2+3`) into a **Postfix** expression (Reverse Polish Notation like `2 3 +`) and then calculating the final result. 

By using Postfix notation, the program eliminates the need for parentheses and follows a strict linear order of operations, making it much easier for computers to process.

---

## Data Structure: The Stack
The program utilizes a **Stack** (Last-In, First-Out) as the engine for both conversion and calculation.

### Struct Definition
```c
struct Stack {
    int top;         // index of the top element
    int items[MAX];  // stores operators during conversion and numbers during evaluation
};
```

### What it does
- **Storage:** Holds characters (operators/brackets) or integers (operands).
- **Capacity:** Supports expressions up to 100 characters long.

---

## Function Breakdown

### Stack Management
- **initStack():** Resets the stack to an empty state.
- **push() / pop():** Adds or removes elements from the top.
- **peek():** Checks the top element without removing it—essential for comparing operator precedence.

### Core Logic
- **precedence():** Determines the priority of operators ($\times$, $/$ have higher priority than $+$, $-$).
- **applyOp():** Executes basic arithmetic ($+$, $-$, $\times$, $/$) on two numbers.
- **infixToPostfix():** Scans the input and reorders it based on the Shunting-yard logic.
- **evaluatePostfix():** Scans the postfix result and uses the stack to compute the final integer value.

---

## How the Algorithm Works

### The Conversion Process
The program reads the user's input character by character:

- **Operands (Numbers):** Sent directly to the output string.
- **Opening Brackets (:** Pushed onto the stack.
- **Closing Brackets ):** Elements are popped from the stack to the output until a matching ( is found.
- **Operators:** If the stack has an operator with higher or equal precedence, it is popped to the output before the current operator is pushed.

### The Evaluation Process
Once the expression is in Postfix format:

1. Scan the postfix string.
2. If a number is found, push it onto the stack.
3. If an operator is found, pop the top two numbers, apply the operation, and push the result back.
4. The last number remaining on the stack is the final answer.

---

## Usage & Examples

The program prompts the user for an infix expression and provides both the converted string and the final math result.

| Input (Infix) | Output (Postfix) | Result |
|---|---|---|
| `2+3*4` | `234*+` | 14 |
| `(2+3)*4` | `23+4*` | 20 |
| `8/2-1` | `82/1-` | 3 |

### Sample Terminal Interaction
```
Enter an infix expression (e.g., (2+3)*4): (5+5)*2

Postfix Version: 55+2*
Final Result: 20
```

---

## Complexity Analysis

- **Time Complexity:** $O(n)$ — The program passes through the input string once for conversion and once for evaluation.
- **Space Complexity:** $O(n)$ — The stack size scales linearly with the length of the mathematical expression.

---

## Key Features

- **User Input:** Accepts dynamic expressions via the console.
- **Smart Precedence:** Correctly handles BODMAS/PEMDAS rules.
- **Parentheses Support:** Allows for complex nested groupings.
- **Clean Logic:** Separates the "sorting" of the expression from the "calculating" of the result.