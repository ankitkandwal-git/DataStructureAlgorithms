# Graph Problems & Algorithms

## Overview
This directory contains comprehensive solutions to **Graph** problems and algorithms. Graphs are fundamental data structures used to represent networks, relationships, and connections. This collection covers essential traversal techniques, cycle detection, connected components, and advanced algorithmic problems.

---

## 🎯 What is a Graph?

A **Graph** is a data structure consisting of:
- **Vertices (Nodes)**: Points in the graph
- **Edges**: Connections between vertices
- **Directed**: Edges have direction (A → B)
- **Undirected**: Edges have no direction (A --- B)
- **Weighted**: Edges have associated costs/weights

### Key Properties:
- **Connected**: Path exists between any two vertices
- **Cyclic**: Contains at least one cycle
- **Acyclic**: No cycles (trees are acyclic graphs)

---

## 🗂️ Folder Structure

| Topic | Description |
|-------|-------------|
| **BFS** | Breadth-First Search - explore graph level by level |
| **BiparitteGraphs** | Check if graph can be 2-colored (bipartite property) |
| **CycleDetectionUsingBFS** | Detect cycles in undirected/directed graphs using BFS |
| **DistinctIslands** | Count islands with distinct shapes or unique patterns |
| **FloodFill** | Fill connected regions with same color (like paint bucket tool) |
| **NearestZeroes** | Find distance to nearest zero/target from all cells |
| **NumberOfEnclaves** | Count enclosed regions surrounded by boundaries |
| **NumberOfIslands** | Count connected components/island groups in grid |
| **NumberOfProvinces** | Count connected components in friendship graph |
| **OWithXBoundary** | Find 'O' regions completely surrounded by 'X' |
| **RepresentationOfGraphs** | Adjacency list, adjacency matrix, edge list implementations |
| **RottingOrange** | Multi-source BFS - time for rot to spread to all oranges |
| **SafeNode** | Find nodes from which all paths lead to terminal nodes |
| **TopologicalSort** | Order nodes linearly respecting directed edges (DAG) |

---

## 📊 Graph Representation Methods

### **1. Adjacency List**
Most memory-efficient for sparse graphs
```python
graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1]
}
```
- Space: O(V + E)
- Time: O(V + E) for traversal

### **2. Adjacency Matrix**
Best for dense graphs and checking edge existence
```python
graph = [
    [0, 1, 1, 0],
    [1, 0, 0, 1],
    [1, 0, 0, 0],
    [0, 1, 0, 0]
]
```
- Space: O(V²)
- Time: O(1) to check edge

### **3. Edge List**
Simple representation with weighted edges
```python
edges = [
    (0, 1, 5),  # from, to, weight
    (1, 3, 2),
    (2, 0, 3)
]
```
- Space: O(E)
- Time: O(E) for traversal

---

## 🔍 Core Traversal Techniques

### **Breadth-First Search (BFS)**
- Level-by-level exploration using queue
- Used for: shortest paths, connected components, bipartite detection
- Time: O(V + E) | Space: O(V)

```python
from collections import deque

def bfs(graph, start):
    queue = deque([start])
    visited = {start}
    
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
```

### **Depth-First Search (DFS)**
- Deep exploration using stack/recursion
- Used for: topological sort, cycle detection, connected components
- Time: O(V + E) | Space: O(V)

```python
def dfs(graph, node, visited):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
```

---

## 📋 Problem Categories

### **Category 1: Connected Components & Islands**
| Problem | Approach | Time | Space |
|---------|----------|------|-------|
| NumberOfIslands | BFS/DFS | O(m×n) | O(m×n) |
| NumberOfProvinces | Union-Find/DFS | O(V²) | O(V) |
| NumberOfEnclaves | BFS/DFS from boundary | O(m×n) | O(m×n) |
| DistinctIslands | BFS/DFS with shape tracking | O(m×n) | O(m×n) |
| OWithXBoundary | Reverse BFS from boundary | O(m×n) | O(m×n) |

### **Category 2: Cycle & Path Detection**
| Problem | Approach | Time | Space |
|---------|----------|------|-------|
| CycleDetectionUsingBFS | BFS with parent tracking | O(V + E) | O(V) |
| BiparitteGraphs | 2-coloring with BFS | O(V + E) | O(V) |
| TopologicalSort | DFS or Kahn's Algorithm | O(V + E) | O(V) |
| SafeNode | Reverse DFS/Topological | O(V + E) | O(V) |

### **Category 3: Multi-Source & Fill Problems**
| Problem | Approach | Time | Space |
|---------|----------|------|-------|
| FloodFill | DFS/BFS from source | O(m×n) | O(m×n) |
| RottingOrange | Multi-source BFS | O(m×n) | O(m×n) |
| NearestZeroes | Multi-source BFS | O(m×n) | O(m×n) |

### **Category 4: Graph Construction**
| Problem | Approach | Time | Space |
|---------|----------|------|-------|
| RepresentationOfGraphs | Building from input | O(V + E) | O(V + E) |
| BFS | Traversal implementation | O(V + E) | O(V) |

---

## 🎓 Learning Roadmap

### **Phase 1: Foundations**
1. **RepresentationOfGraphs** - Understand different graph representations
2. **BFS** - Master breadth-first search
3. Basic DFS (through other problems)

### **Phase 2: Simple Traversals**
4. **NumberOfIslands** - Count connected components
5. **FloodFill** - Region filling using traversal
6. **NumberOfProvinces** - Connected components in graph

### **Phase 3: Cycle & Path Problems**
7. **CycleDetectionUsingBFS** - Detect cycles
8. **BiparitteGraphs** - Check graph bipartiteness
9. **TopologicalSort** - Linear ordering of DAG

### **Phase 4: Advanced Multi-Source & Complex**
10. **RottingOrange** - Multi-source BFS
11. **NearestZeroes** - Distance calculations
12. **SafeNode** - Path analysis and filtering
13. **NumberOfEnclaves** & **OWithXBoundary** - Boundary-aware traversal
14. **DistinctIslands** - Advanced island detection

---

## 💡 Key Graph Algorithms

### **Algorithm 1: Union-Find (Disjoint Set Union)**
For connected components with path compression
```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != py:
            self.parent[px] = py
```

### **Algorithm 2: Topological Sort (Kahn's)**
```python
def topological_sort(graph, indegree):
    queue = [node for node in range(len(indegree)) if indegree[node] == 0]
    result = []
    
    while queue:
        node = queue.pop(0)
        result.append(node)
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    
    return result
```

### **Algorithm 3: Multi-Source BFS**
```python
def multi_source_bfs(grid, sources):
    queue = deque(sources)
    visited = set(sources)
    distance = {src: 0 for src in sources}
    
    while queue:
        node = queue.popleft()
        for neighbor in get_neighbors(node):
            if neighbor not in visited:
                visited.add(neighbor)
                distance[neighbor] = distance[node] + 1
                queue.append(neighbor)
    
    return distance
```

---

## ⚙️ Time & Space Complexity Reference

| Algorithm | Time | Space | When to Use |
|-----------|------|-------|-------------|
| BFS | O(V + E) | O(V) | Shortest path, level-order |
| DFS | O(V + E) | O(V) | Topological sort, cycle detect |
| Union-Find | O(α(n)) | O(V) | Connected components |
| Topological Sort | O(V + E) | O(V) | DAG ordering |
| Multi-source BFS | O(V + E) | O(V) | Distance from multiple sources |

---

## 🚀 Tips for Graph Problems

### **Step 1: Understand the Graph Structure**
- Directed or undirected?
- Weighted or unweighted?
- Sparse or dense?

### **Step 2: Choose Representation**
- Adjacency list for sparse graphs
- Adjacency matrix for dense graphs
- Edge list for special cases

### **Step 3: Select Algorithm**
- Connected components → BFS/DFS/Union-Find
- Shortest path (unweighted) → BFS
- Topological order → DFS or Kahn's
- Cycle detection → DFS or Union-Find

### **Step 4: Implement & Test**
- Handle edge cases (isolated nodes, cycles, etc.)
- Test on small examples
- Verify time/space complexity

### **Step 5: Optimize**
- Consider space optimization
- Move to iterative if stack overflows
- Use Union-Find for connectivity problems

---

## 🔗 Related Concepts

| Concept | Used In |
|---------|---------|
| **Trees** | Special acyclic graphs |
| **Shortest Paths** | Dijkstra, BFS (unweighted) |
| **Minimum Spanning Tree** | Kruskal's, Prim's |
| **Network Flow** | Max flow algorithms |
| **Dynamic Programming** | Optimal paths in DAG |

---

## 📚 Prerequisites

- Understanding of **nodes, edges, vertices, and connections**
- Comfortable with **queues and stacks**
- Knowledge of **recursion** for DFS
- Familiar with **adjacency lists and matrices**
- Basic understanding of **time/space complexity**

---

## 🎯 Problem Difficulty Guide

| Level | Topics |
|-------|--------|
| **⭐ Easy** | BFS, FloodFill, NumberOfIslands, CycleDetectionUsingBFS |
| **⭐⭐ Medium** | BiparitteGraphs, TopologicalSort, RottingOrange, NearestZeroes, NumberOfProvinces |
| **⭐⭐⭐ Hard** | SafeNode, NumberOfEnclaves, DistinctIslands, OWithXBoundary |

---

## ✅ Quick Checklist

- [ ] Understand graph structure (directed/undirected, weighted/unweighted)
- [ ] Choose appropriate representation
- [ ] Decide between BFS vs DFS
- [ ] Handle visited nodes correctly
- [ ] Test with disconnected components
- [ ] Verify edge cases (empty graph, single node, cycles)
- [ ] Analyze time and space complexity

---

**Last Updated:** 2026  
**Status:** 14 comprehensive problems covering essential graph algorithms
