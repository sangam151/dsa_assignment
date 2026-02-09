# Q5: Undirected Graph Traversal (BFS and DFS)

## 1. Overview
This program demonstrates an **undirected graph** using an adjacency matrix in C.  
It includes functions to:

- Perform Breadth First Search (BFS) traversal
- Perform Depth First Search (DFS) traversal

The graph is traversed starting from a user-defined vertex, and the order of traversal is displayed.

## 2. Data Structures Used
- `int adjMat[SIZE][SIZE];`  – adjacency matrix
- `int seen[SIZE];`           – visited array

**Details:**
- `adjMat` is a 2D array to store connections between vertices (1 = edge exists, 0 = no edge)  
- `seen` is a 1D array to track visited vertices during BFS and DFS to prevent revisiting  
- **Queue (array-based)** is used in BFS to process vertices in FIFO order  
- **Recursion stack** is used in DFS to explore depth-first  

## 3. Purpose
- To represent an undirected graph using an adjacency matrix  
- To traverse the graph using BFS and DFS  
- To demonstrate the use of a visited array to avoid infinite loops  
- To provide clear traversal output for any given starting vertex  

## 4. Functions Implemented

### a. `void doBFS(int startNode)`
- Traverses the graph using **Breadth First Search**  
- Uses a **queue** to visit vertices level by level  
- Marks visited nodes in the `seen` array  
- Prints **BFS traversal order**

### b. `void doDFS(int now)`
- Traverses the graph using **Depth First Search**  
- Uses **recursion** to explore nodes as deep as possible before backtracking  
- Marks visited nodes in the `seen` array  
- Prints **DFS traversal order**

## 5. Main Method Organization
1. Takes input for the number of vertices and edges  
2. Initializes the adjacency matrix with 0  
3. Accepts edge connections from the user and updates the matrix  
4. Takes the starting vertex as input  
5. Calls `doBFS()` to perform BFS traversal  
6. Resets the `seen` array  
7. Calls `doDFS()` to perform DFS traversal  

## 6. Sample Output

**Input**
Enter total vertices: 5
Enter total edges: 6
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4

**Output**
BFS Order: 0 1 2 3 4
DFS Order: 0 1 3 4 2