# 🐀 Rat in a Maze — C++ Solution

This repository contains a **C++ implementation** of the classic **Rat in a Maze** problem, frequently asked in coding interviews and featured on **GeeksforGeeks**.

---

## 🧩 Problem Description

A rat is placed at the top-left cell `(0, 0)` of a square maze represented as a binary matrix.

- `1` represents an open cell (path).
- `0` represents a blocked cell.
  
The rat must reach the destination cell `(n-1, n-1)` using **four possible moves**:
- `U` → Up  
- `D` → Down  
- `L` → Left  
- `R` → Right  

The goal is to find **all possible paths** from the source to the destination, moving only through `1`s, without revisiting any cell.

---

## 💡 Approach

This problem is solved using **recursion and backtracking**:
1. Start from `(0, 0)` and explore all valid directions (`D, L, R, U`).
2. Mark each visited cell temporarily to avoid cycles.
3. When reaching the destination, record the current path.
4. Backtrack to explore alternative routes.
5. Return all valid paths in **lexicographical order**.

---

## 🧠 Example

### Input
```cpp
maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};
