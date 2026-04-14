# Dynamic Programming Problems & Algorithms

## Overview
This directory contains comprehensive solutions to **Dynamic Programming (DP)** problems. Dynamic Programming is a powerful optimization technique that solves complex problems by breaking them into overlapping subproblems and storing their solutions to avoid redundant computations. It's essential for competitive programming and interview preparation.

---

## 🎯 What is Dynamic Programming?

**Dynamic Programming** combines two key ideas:
1. **Optimal Substructure**: A problem can be solved using solutions to smaller subproblems
2. **Overlapping Subproblems**: The same subproblems appear multiple times in the computation

By solving each subproblem once and caching the result, we achieve significant performance improvements.

---

## 🗂️ Folder Structure

| Topic | Description |
|-------|-------------|
| **ClimbStairs** | Find number of ways to climb n stairs with step sizes (typically 1 or 2) |
| **FibonnaciSeries** | Classic Fibonacci sequence problem with DP optimization |
| **FrogJump** | Frog jumping on a lily pad with constraints and costs |
| **FrogJump2** | Advanced frog jumping problem with different jump patterns |
| **FrogJump3** | Extended frog jumping challenge with additional constraints |
| **HouseRobber** | Maximize theft from houses without robbing adjacent ones |
| **MaximumPathSum** | Find maximum sum path in grid or matrix |
| **MinimumPathSum** | Find minimum cost path from top-left to bottom-right |
| **SamuraiAndFriend** | Game theory or optimization problem with multiple agents |
| **SubsetSum** | Determine if subset of array sums to target value |
| **Triangle** | Find minimum sum path from top to bottom in triangle |
| **UniquePath1** | Count unique paths in grid (only right and down moves) |
| **UniquePath2** | Count unique paths with obstacles in grid |

---

## 📊 Core DP Concepts

### **1. Memoization (Top-Down Approach)**
- Use recursion with caching
- Solve from larger problem → base cases
- Easier to understand and implement initially
- Can have stack overflow issues with deep recursion

```python
memo = {}

def solve(n):
    if n in memo:
        return memo[n]
    
    if n <= 1:
        return n
    
    memo[n] = solve(n-1) + solve(n-2)
    return memo[n]
```

### **2. Tabulation (Bottom-Up Approach)**
- Use iteration with DP table
- Solve from base cases → larger problem
- More space/time predictable
- Generally preferred for production code

```python
def solve(n):
    dp = [0] * (n + 1)
    dp[0], dp[1] = 0, 1
    
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]
```

### **3. Space Optimization**
- Reduce tabulation space by keeping only necessary previous states

```python
def solve(n):
    prev, curr = 0, 1
    
    for i in range(2, n + 1):
        next_val = prev + curr
        prev, curr = curr, next_val
    
    return curr
```

---

## 📋 Problem Categories

### **Category 1: Simple Sequences**
- **FibonnaciSeries**: Foundational DP problem
- **ClimbStairs**: Counting combinations with constraints

| Problem | Time | Space | Optimal |
|---------|------|-------|---------|
| Fibonacci | O(n) | O(n) | O(1) |
| ClimbStairs | O(n) | O(n) | O(1) |

### **Category 2: Grid/Path Problems**
- **MinimumPathSum**: 2D DP from top-left to bottom-right
- **MaximumPathSum**: Find best path with maximum gain
- **UniquePath1**: Count ways with no obstacles
- **UniquePath2**: Count ways avoiding obstacles
- **Triangle**: Minimize cost from top to bottom

| Problem | Time | Space | Optimal |
|---------|------|-------|---------|
| MinPath | O(m×n) | O(m×n) | O(n) |
| UniquePath | O(m×n) | O(m×n) | O(n) |

### **Category 3: 1D Array DP**
- **HouseRobber**: Maximize profit without adjacent elements
- **SubsetSum**: Check feasibility of target sum

| Problem | Time | Space |
|---------|------|-------|
| HouseRobber | O(n) | O(n) |
| SubsetSum | O(n×sum) | O(n×sum) |

### **Category 4: Jump/Movement Problems**
- **FrogJump**: Calculate minimum/maximum with jumping mechanics
- **FrogJump2**: Variant with different rules
- **FrogJump3**: Extended complexity

| Problem | Time | Space |
|---------|------|-------|
| FrogJump | O(n) | O(n) |

---

## 🎓 Learning Roadmap

### **Phase 1: Foundations (Start Here!)**
1. **FibonnaciSeries** - Understand memoization basics
2. **ClimbStairs** - Apply DP to counting problems
3. **HouseRobber** - 1D DP with state transition

### **Phase 2: 2D DP & Grid Problems**
4. **UniquePath1** - 2D grid path counting
5. **MinimumPathSum** - Optimize path sums
6. **UniquePath2** - Handle obstacles

### **Phase 3: Advanced Topics**
7. **SubsetSum** - Knapsack-style problem
8. **Triangle** - Different traversal patterns
9. **MaximumPathSum** - Complex state management

### **Phase 4: Complex Problems**
10. **FrogJump(1,2,3)** - Game-like scenarios
11. **SamuraiAndFriend** - Multi-agent optimization

---

## 💡 Key DP Patterns

### **Pattern 1: Linear Series (1D)**
```
dp[i] = f(dp[i-1], dp[i-2], ...)
```
*Used in:* Fibonacci, ClimbStairs, HouseRobber

### **Pattern 2: Grid Path (2D)**
```
dp[i][j] = f(dp[i-1][j], dp[i][j-1], grid[i][j])
```
*Used in:* MinPath, UniqueePath, MaxPath

### **Pattern 3: Subset/Knapsack**
```
dp[i][j] = can_achieve_using(first i items, capacity j)
```
*Used in:* SubsetSum

### **Pattern 4: Game Theory/Minimax**
```
dp[state] = best_outcome_from(state)
```
*Used in:* SamuraiAndFriend

---

## ⚙️ Time & Space Complexity Reference

| Approach | Time | Space | Use Case |
|----------|------|-------|----------|
| Naive Recursion | O(2^n) | O(n) | Never (TLE) |
| Memoization | O(states × transitions) | O(states) | Learning, debugging |
| Tabulation | O(states × transitions) | O(states) | Production |
| Space Optimized | O(states × transitions) | O(1) or O(n) | Final optimization |

---

## 🚀 Tips for Solving DP Problems

### **Step 1: Define State**
- Identify what `dp[i]` or `dp[i][j]` represents
- Example: "Minimum cost to reach position i"

### **Step 2: State Transitions**
- How does current state depend on previous states?
- Write the recursive relation

### **Step 3: Base Cases**
- When to stop recursion?
- What are the smallest inputs?

### **Step 4: Implementation**
- Choose memoization or tabulation
- Optimize space if possible

### **Step 5: Testing**
- Test with small inputs manually
- Handle edge cases
- Verify time/space efficiency

---

## 🔗 Related Concepts

| Concept | Related Problems |
|---------|-----------------|
| **Knapsack** | SubsetSum |
| **Fibonacci** | ClimbStairs |
| **Graph DP** | Paths in grids |
| **BFS/DFS** | Alternative to DP for some problems |
| **Greedy** | Sometimes competes with DP |

---

## 📚 Prerequisites

- Strong understanding of **recursion** and **backtracking**
- Comfortable with **arrays**, **matrices**, and **hashmaps**
- Knowledge of **time/space complexity** analysis
- Ability to **identify overlapping subproblems**

---

## 🎯 Problem Difficulty Guide

| Level | Topics |
|-------|--------|
| **⭐ Easy** | FibonnaciSeries, ClimbStairs, UniquePath1, HouseRobber |
| **⭐⭐ Medium** | MinimumPathSum, UniquePath2, Triangle, SubsetSum, MaximumPathSum |
| **⭐⭐⭐ Hard** | FrogJump variants, SamuraiAndFriend |

---

## ✅ Quick Checklist

- [ ] Understand what each subproblem represents
- [ ] Write the state transition formula
- [ ] Identify base cases
- [ ] Choose memoization or tabulation
- [ ] Verify correctness with small examples
- [ ] Analyze time/space complexity
- [ ] Optimize space if needed

---

**Last Updated:** 2026  
**Status:** 13 comprehensive problems covering essential DP patterns
