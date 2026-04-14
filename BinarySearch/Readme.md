# Binary Search Problems & Algorithms

## Overview
This directory contains comprehensive solutions to **Binary Search** problems. Binary Search is one of the most efficient searching algorithms, used to find elements in sorted arrays with logarithmic time complexity. It's essential for competitive programming, interviews, and real-world applications.

---

## 🎯 What is Binary Search?

**Binary Search** is a divide-and-conquer algorithm that works on **sorted arrays** by repeatedly dividing the search space in half.

### Key Features:
- **Time Complexity**: O(log n) - extremely efficient
- **Space Complexity**: O(1) for iterative, O(log n) for recursive
- **Prerequisite**: Array must be sorted
- **Applicability**: Works on monotonic sequences, not just sorted arrays

### When to Use Binary Search:
- ✓ Sorted array and need to find an element
- ✓ Need to find boundary/insertion position
- ✓ Problems with monotonic properties
- ✓ When O(n) solution is too slow

---

## 🗂️ Folder Structure

| Topic | Description |
|-------|-------------|
| **BinarySearchElement** | Search for exact element in sorted array |
| **CeilTheFloor** | Find smallest element ≥ target (Ceil) and largest ≤ target (Floor) |
| **FirstAndLastOccurence** | Find first and last occurrence of target in array |
| **LowerBound** | Find first element NOT less than target (≥) |
| **PeekElement** | Find peak element where arr[i] > arr[i±1] |
| **SearchInsertion** | Find index where target should be inserted |
| **SearchRotatedArray1** | Search in rotated sorted array (no duplicates) |
| **UpperBound** | Find first element strictly greater than target (>) |

---

## 📊 Core Binary Search Concepts

### **1. Standard Binary Search**
Search for exact element in sorted array

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1  # Not found
```

**Time**: O(log n) | **Space**: O(1)

### **2. Binary Search for Boundary (Lower Bound)**
Find first element ≥ target

```python
def lower_bound(arr, target):
    left, right = 0, len(arr) - 1
    result = len(arr)  # Default: element not found
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] >= target:
            result = mid
            right = mid - 1  # Look for smaller index
        else:
            left = mid + 1
    
    return result
```

### **3. Binary Search for Boundary (Upper Bound)**
Find first element > target

```python
def upper_bound(arr, target):
    left, right = 0, len(arr) - 1
    result = len(arr)
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] > target:
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result
```

### **4. Binary Search in Rotated Array**
Handle rotation point in sorted array

```python
def search_rotated(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        
        # Determine which half is sorted
        if arr[left] <= arr[mid]:  # Left half sorted
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right half sorted
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1
```

---

## 📋 Problem Categories

### **Category 1: Basic Search**
| Problem | Goal | Time | Space |
|---------|------|------|-------|
| BinarySearchElement | Find exact element | O(log n) | O(1) |
| SearchInsertion | Find insertion position | O(log n) | O(1) |

### **Category 2: Boundary Problems**
| Problem | Goal | Time | Space |
|---------|------|------|-------|
| LowerBound | First element ≥ target | O(log n) | O(1) |
| UpperBound | First element > target | O(log n) | O(1) |
| CeilTheFloor | Smallest ≥ and largest ≤ target | O(log n) | O(1) |

### **Category 3: Occurrence Problems**
| Problem | Goal | Time | Space |
|---------|------|------|-------|
| FirstAndLastOccurence | First and last indices | O(log n) | O(1) |

### **Category 4: Complex Problems**
| Problem | Goal | Time | Space |
|---------|------|------|-------|
| SearchRotatedArray1 | Find in rotated sorted array | O(log n) | O(1) |
| PeekElement | Find peak without duplicates | O(log n) | O(1) |

---

## 🎓 Learning Roadmap

### **Phase 1: Foundations**
1. **BinarySearchElement** - Master the basic algorithm
2. **SearchInsertion** - Understand boundary concepts

### **Phase 2: Boundary & Advanced Search**
3. **LowerBound** - Find ≥ target
4. **UpperBound** - Find > target
5. **CeilTheFloor** - Practice both bounds

### **Phase 3: Multiple Occurrences**
6. **FirstAndLastOccurence** - Find first and last indices

### **Phase 4: Complex Scenarios**
7. **SearchRotatedArray1** - Handle rotated arrays
8. **PeekElement** - Find peaks in unsorted property

---

## 💡 Key Binary Search Patterns

### **Pattern 1: Exact Match**
```python
if arr[mid] == target:
    return mid
elif arr[mid] < target:
    left = mid + 1
else:
    right = mid - 1
```
*Used in:* BinarySearchElement

### **Pattern 2: Find Left Boundary**
```python
if arr[mid] >= target:
    result = mid
    right = mid - 1
else:
    left = mid + 1
```
*Used in:* LowerBound, FirstAndLastOccurence

### **Pattern 3: Find Right Boundary**
```python
if arr[mid] > target:
    right = mid - 1
else:
    left = mid + 1
```
*Used in:* UpperBound, FirstAndLastOccurence

### **Pattern 4: Monotonic Property Check**
```python
if condition(mid):
    right = mid  # Or mid - 1
else:
    left = mid + 1
```
*Used in:* SearchRotatedArray1, PeekElement

---

## ⚙️ Time & Space Complexity Reference

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Naive Linear Search | O(n) | O(1) | Simple | Too slow |
| Binary Search (Iterative) | O(log n) | O(1) | Efficient, no stack | Requires sorted array |
| Binary Search (Recursive) | O(log n) | O(log n) | Clean code | Stack space |

---

## 🚀 Tips for Binary Search Problems

### **Step 1: Verify Sortedness**
- Is the array sorted?
- Can you create a monotonic property?

### **Step 2: Define Search Space**
- What are we searching for?
- Exact match, left boundary, or right boundary?

### **Step 3: Handle Middle**
```python
mid = left + (right - left) // 2  # Avoid overflow
# NOT: mid = (left + right) // 2
```

### **Step 4: Update Pointers Correctly**
- **Exact match**: mid ± 1
- **Boundary**: Consider including mid in next iteration

### **Step 5: Test Edge Cases**
- Empty array
- Single element
- Target at boundaries
- Target not in array
- Duplicates (if applicable)

### **Step 6: Verify Correctness**
- Run on small examples
- Check loop termination
- Verify final indices

---

## 🔍 Common Pitfalls

| Pitfall | Solution |
|---------|----------|
| **Integer overflow** | Use `mid = left + (right - left) // 2` |
| **Off-by-one errors** | Carefully handle `left = mid` vs `mid + 1` |
| **Wrong boundary condition** | Use `left <= right` vs `left < right` correctly |
| **Not handling duplicates** | Handle duplicate cases separately if needed |
| **Incorrect target comparison** | Ensure comparison logic matches problem requirements |

---

## 📚 Prerequisite Knowledge

- Understanding of **array indexing**
- Comfortable with **loop conditions and updates**
- Knowledge of **problem constraints** (sorted, rotated, etc.)
- Ability to **identify monotonic properties**

---

## 🎯 Comparison with Other Search Techniques

| Technique | Time | Space | Use Case |
|-----------|------|-------|----------|
| Linear Search | O(n) | O(1) | Unsorted, small data |
| Binary Search | O(log n) | O(1) | Sorted data |
| Hash Table Lookup | O(1) avg | O(n) | Unordered, many queries |
| BST Search | O(log n) avg | O(n) | Dynamic insertion/deletion |

---

## 🔗 Related Concepts

| Concept | Connection |
|---------|-----------|
| **Sorted Arrays** | Direct application domain |
| **Binary Search Trees** | BST search uses similar logic |
| **Two Pointers** | Similar pointer movement technique |
| **Greedy Algorithms** | Binary search on answer |
| **Monotonic Functions** | Generalizes beyond sorted arrays |

---

## ✅ Problem Difficulty Guide

| Level | Topics |
|-------|--------|
| **⭐ Easy** | BinarySearchElement, SearchInsertion, LowerBound, UpperBound |
| **⭐⭐ Medium** | CeilTheFloor, FirstAndLastOccurence |
| **⭐⭐⭐ Hard** | SearchRotatedArray1, PeekElement |

---

## ✅ Quick Checklist

- [ ] Is the array sorted or have monotonic property?
- [ ] Am I looking for exact match or boundary?
- [ ] Correct mid calculation: `left + (right - left) // 2`
- [ ] Proper loop condition: `left <= right` or `left < right`?
- [ ] Correct pointer updates based on comparison
- [ ] Tested edge cases: empty, single, boundaries, duplicates
- [ ] Time complexity is O(log n)?

---

## 📖 Standard Template

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        mid_val = arr[mid]
        
        if mid_val == target:
            return mid  # Found
        elif mid_val < target:
            left = mid + 1       # Search right
        else:
            right = mid - 1      # Search left
    
    return -1  # Not found
```

---

**Last Updated:** 2026  
**Status:** 8 comprehensive binary search problems covering all major patterns
