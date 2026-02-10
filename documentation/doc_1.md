
# Program 1: Balanced Bracket Checker

## Overview
This program checks if brackets are balanced in mathematical expressions. It ensures that every opening bracket has a corresponding closing bracket and that they are closed in the correct order.

### Supported Bracket Types
- **Round brackets:** `( )`
- **Square brackets:** `[ ]`
- **Curly brackets:** `{ }`

---

## Data Structure: Stack
The program uses a **Stack** data structure to manage brackets. It follows the **LIFO** (Last-In, First-Out) principle, meaning the last bracket added is the first one checked.

### C Structure
```c
struct Stack {
    int top;         // index of the top element (-1 when empty)
    char items[MAX]; // array to store stack elements
};
```

### What it does
- Stores opening brackets as they are found in the expression
- **Capacity:** Can hold up to 100 brackets
- **Mechanism:** When an opening bracket is found, it is "pushed" onto the stack. When a closing bracket is found, the top element is "popped" to see if it matches.

---

## Functions in the Program

### Basic Stack Functions
- **initStack():** Sets up a new empty stack by resetting the top index.
- **isEmpty():** Checks if the stack has nothing in it.
- **push():** Puts a bracket on top of the stack.
- **pop():** Takes the top bracket off the stack.

### Helper Functions
- **isOpeningBracket():** Checks if we found an opening bracket like `(`, `[`, or `{`.
- **isClosingBracket():** Checks if we found a closing bracket like `)`, `]`, or `}`.
- **isMatchingPair():** Checks if the opening and closing brackets match (e.g., `(` with `)`).

### Algorithm Core
- **areParenthesesBalanced():**
  - Goes through the expression one character at a time.
  - Puts opening brackets on the stack.
  - When it finds closing brackets, checks if they match with the top of the stack.
  - Returns true if everything matches correctly at the end.

---

## How the Algorithm Works

1. **Start** with an empty stack.
2. **Go through** each character in the math expression:
   - If it's an opening bracket `(` `[` `{`: Put it on the stack.
   - If it's a closing bracket `)` `]` `}`:
     - Check if the stack is empty (this means there is an extra closing bracket).
     - Take the top bracket from the stack and see if it matches.
     - If they don't match, the expression is wrong.
3. **At the end:** If the stack is empty, all brackets are balanced.

---

## Test Cases

The main() function tests the program using three different scenarios to ensure accuracy.

| Expression | Expected Result | Reason |
|---|---|---|
| `a + (b - c) * (d` | Not Balanced | Missing a closing parenthesis. |
| `m + [a - b * (c + d * {m)]` | Not Balanced | Mismatched brackets ({ closed by ]). |
| `a + (b - c)` | Balanced | All brackets match correctly. |

### Sample Output
```
Expression 1: a + (b - c) * (d
Result: not balanced

Expression 2: m + [a - b * (c + d * {m)]
Result: not balanced

Expression 3: a + (b - c)
Result: balanced
```

---

## Performance Analysis

- **Time Complexity:** $O(n)$ — The program goes through the expression exactly once.
- **Space Complexity:** $O(n)$ — Uses memory proportional to the number of opening brackets in the worst case.

---

## Key Features

- Works with all three bracket types: `( )`, `[ ]`, `{ }`.
- Checks if brackets are in the right order.
- Ignores letters, numbers, and math symbols.
- Easily identifies common syntax errors.
