# Binary Tree Problems & Algorithms

## Overview
This directory contains solutions and implementations of various **Binary Tree** problems and algorithms. Binary Trees are fundamental data structures used extensively in computer science for organizing hierarchical data, enabling efficient searching, and solving complex problems through tree traversal techniques.

---

## 🗂️ Folder Structure

```text
BinaryTree/
├── AddBinaryRootToLeaf/
├── BalancedBinaryTree/
├── BinaryPathSum/
├── BinaryTreePaths/
├── BinaryTreeTraverse/
├── BottomViewOfBinaryTree/
├── BoundaryTraversalTree/
├── CheckSubTreeIsBinaryTree/
├── ChildrenSumProperty/
├── CountFamilyMember/
├── DiameterOfBinaryTree/
├── HeightOfTree/
├── IdenticalBinaryTree/
├── LeafSequence/
├── LeftViewOfBinaryTree/
├── LevelOrderTraversal/
├── LowestCommonAnchestor/
├── MaximumPathOfBinaryTree/
├── MaximumWidthOfBinaryTree/
├── MaxPathSum/
├── MinHeightOfTree/
├── PathSum2/
├── PathSum3/
├── PostOrder/
├── PreOrder/
├── PreOrderAndInOrderTraversal/
├── ProductOfRightLeaves/
├── RightViewOfBinaryTree/
├── SymmetricBinaryTree/
├── TopViewOfBinaryTree/
└── VerticalOrderTraversal/
```

### 📝 Questions Covered by Folder

- **AddBinaryRootToLeaf**: Sum of binary numbers from root to leaf, converting paths to binary values.
- **BalancedBinaryTree**: Check if a binary tree is balanced (height difference between subtrees ≤ 1).
- **BinaryPathSum**: Problems related to calculating and verifying path sums in binary trees.
- **BinaryTreePaths**: Generate all root-to-leaf paths in a binary tree and related path operations.
- **BinaryTreeTraverse**: General traversal techniques and utilities for navigating binary trees.
- **BottomViewOfBinaryTree**: Print nodes visible from the bottom view of the binary tree (last node at each horizontal distance).
- **BoundaryTraversalTree**: Traverse only the boundary nodes of a binary tree (left, bottom, right edges).
- **CheckSubTreeIsBinaryTree**: Verify if one tree is a subtree of another binary tree.
- **ChildrenSumProperty**: Check or construct binary trees where parent value equals sum of children values.
- **CountFamilyMember**: Count nodes based on family relationships (parent-child, ancestors, etc.).
- **DiameterOfBinaryTree**: Find the longest path between any two nodes in a binary tree.
- **HeightOfTree**: Calculate the maximum depth/height of a binary tree.
- **IdenticalBinaryTree**: Check if two binary trees are structurally identical with same values.
- **LeafSequence**: Problems involving leaf node sequences and patterns.
- **LeftViewOfBinaryTree**: Print nodes visible from the left side of the binary tree.
- **LevelOrderTraversal**: Breadth-first traversal, printing nodes level by level.
- **LowestCommonAnchestor**: Find the lowest common ancestor of two nodes in a binary tree.
- **MaximumPathOfBinaryTree**: Find the maximum sum path between any two nodes in a tree.
- **MaximumWidthOfBinaryTree**: Find the maximum width (number of nodes) at any level of the binary tree.
- **MaxPathSum**: Find the maximum sum path between any two nodes in a tree (alternate implementation).
- **MinHeightOfTree**: Calculate the minimum height from root to any leaf node.
- **PathSum2**: Find all root-to-leaf paths that sum to a target value.
- **PathSum3**: Find number of paths (not necessarily root-to-leaf) with target sum.
- **PostOrder**: Post-order traversal: left → right → node (bottom-up approach).
- **PreOrder**: Pre-order traversal: node → left → right (top-down approach).
- **PreOrderAndInOrderTraversal**: Reconstruct binary tree from pre-order and in-order traversals.
- **ProductOfRightLeaves**: Calculate product of all right leaf nodes.
- **RightViewOfBinaryTree**: Print nodes visible from the right side of the binary tree.
- **SymmetricBinaryTree**: Check if a binary tree is symmetric (mirror image of itself).
- **TopViewOfBinaryTree**: Print nodes visible from the top view of the binary tree.
- **VerticalOrderTraversal**: Traverse and print nodes in vertical order (left to right columns).

---

## 📊 Key Concepts Covered

### **Traversal Techniques**
- **In-Order**: Left → Node → Right (useful for BST to get sorted sequence)
- **Pre-Order**: Node → Left → Right (useful for tree copying)
- **Post-Order**: Left → Right → Node (useful for deletion)
- **Level-Order**: BFS approach, process nodes level by level

### **Path & Sum Problems**
- Root-to-leaf path calculations
- Path sum validation and enumeration
- Maximum/minimum path sums
- Paths in any configuration (not just root-to-leaf)

### **Tree Properties**
- Height and depth calculations
- Balanced tree verification
- Diameter computation
- Tree comparison and mirroring

### **Boundary & Special Cases**
- Boundary node traversal
- Leaf node operations
- Ancestor-descendant relationships

---

## 🎯 Problem Difficulty Levels

| Level | Topics |
|-------|--------|
| **Beginner** | PreOrder, PostOrder, HeightOfTree, LevelOrderTraversal |
| **Intermediate** | BinaryTreeTraverse, MaxPathSum, PathSum2, DiameterOfBinaryTree |
| **Advanced** | BoundaryTraversalTree, PreOrderAndInOrderTraversal, MaxPathSum |

---

## 💡 Common Approaches

### 1. **Recursive DFS**
Most binary tree problems use recursive depth-first search patterns:
```
function solve(node):
    if node is null:
        return base_case
    
    left_result = solve(node.left)
    right_result = solve(node.right)
    
    return combine(left_result, right_result, node)
```

### 2. **Iterative Traversal**
Using stacks for DFS or queues for BFS when recursion isn't ideal.

### 3. **Level-Order BFS**
Queue-based approach for problems requiring level-by-level processing.

---

## 🚀 Getting Started

1. Start with **basic traversals**: PreOrder, PostOrder, LevelOrderTraversal
2. Progress to **simple calculations**: HeightOfTree, DiameterOfBinaryTree
3. Advance to **path problems**: PathSum2, PathSum3, MaxPathSum
4. Tackle **complex scenarios**: BoundaryTraversalTree, tree reconstruction

---

## 📝 Time & Space Complexity Quick Reference

| Problem Type | Time | Space |
|--------------|------|-------|
| Basic Traversal | O(n) | O(h) |
| Height/Path calculations | O(n) | O(h) |
| All Paths enumeration | O(n × h) | O(h) |
| Reconstruction | O(n) | O(h) |

*Where n = number of nodes, h = height of tree*

---

## 🔗 Related Concepts

- **Binary Search Trees (BST)**: Special case where left < parent < right
- **AVL Trees / Red-Black Trees**: Self-balancing BSTs
- **Heaps**: Complete binary trees with heap property
- **Segment Trees / Fenwick Trees**: Advanced tree structures for range queries

---

## 📚 Prerequisites

- Understanding of basic tree terminology (node, edge, root, leaf, subtree)
- Recursion and backtracking concepts
- Basic data structures (arrays, lists, queues, stacks)
- Time and space complexity analysis

---

**Last Updated:** 2026  
**Status:** Complete with comprehensive problem coverage
