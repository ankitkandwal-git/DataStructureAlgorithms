# Binary Search Tree (BST)

A Binary Search Tree is a binary tree data structure where each node has at most two children, with the property that the value of nodes in the left subtree is less than the parent node's value, and values in the right subtree are greater than the parent node's value.

## Directory Structure

```
BinarySearchTree/
│
├── DeletionBST/
│   ├── main.cpp
│   ├── Main.java
│   └── output/
│
├── InsertBST/
│   ├── main.cpp
│   ├── Main.java
│   └── output/
│
├── KthSmallestNumber/
│   ├── main.cpp
│   └── output/
│
├── LowestCommonAnchestor/
│   ├── main.cpp
│   ├── Main.java
│   └── output/
│
├── MergeTwoBST/
│   └── main.cpp
│
├── PredecessorBinarySearchTree/
│   ├── main.cpp
│   └── output/
│
├── SearchBST/
│   ├── main.cpp
│   ├── Main.java
│   └── output/
│
├── SuccessorBinarySearchTree/
│   └── main.cpp
│
├── ValidateBinarySearchTree/
│   └── main.cpp
│
└── readme.md
```

---

## Folder Descriptions

### 1. **DeletionBST/**
Implement deletion operations in a Binary Search Tree. Covers removing nodes while maintaining BST properties.
- **main.cpp**: C++ implementation
- **Main.java**: Java implementation
- **output/**: Test outputs

### 2. **InsertBST/**
Implement insertion operations to add new nodes into a Binary Search Tree while maintaining the BST property.
- **main.cpp**: C++ implementation
- **Main.java**: Java implementation
- **output/**: Test outputs

### 3. **KthSmallestNumber/**
Find the Kth smallest element in a Binary Search Tree using in-order traversal or other efficient techniques.
- **main.cpp**: C++ implementation
- **output/**: Test outputs

### 4. **LowestCommonAnchestor/**
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
- **main.cpp**: C++ implementation
- **Main.java**: Java implementation
- **output/**: Test outputs

### 5. **MergeTwoBST/**
Merge two Binary Search Trees into a single BST while maintaining the BST property.
- **main.cpp**: C++ implementation

### 6. **PredecessorBinarySearchTree/**
Find the predecessor of a given node in a Binary Search Tree (the node with the largest value smaller than the given node).
- **main.cpp**: C++ implementation
- **output/**: Test outputs

### 7. **SearchBST/**
Implement search operations to find a specific value in a Binary Search Tree.
- **main.cpp**: C++ implementation
- **Main.java**: Java implementation
- **output/**: Test outputs

### 8. **SuccessorBinarySearchTree/**
Find the successor of a given node in a Binary Search Tree (the node with the smallest value larger than the given node).
- **main.cpp**: C++ implementation

### 9. **ValidateBinarySearchTree/**
Validate whether a given binary tree is a valid Binary Search Tree by verifying the BST properties.
- **main.cpp**: C++ implementation

---

## Key Concepts

- **Time Complexity**: Average O(log n), Worst case O(n)
- **Space Complexity**: O(h) where h is height
- **Operations**: Insert, Delete, Search, Traversal, Predecessor, Successor
