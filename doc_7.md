# Q7: Shortest Path Finder (Dijkstra Algorithm)

## 1. Overview
The program determines the shortest path between a starting point and all other points in a weighted graph. The program uses Dijkstra's algorithm to find paths through its adjacency matrix system. The program uses arrays to store distances and visited nodes which makes it easy to understand and track.

## 2. Data Structures Used
**Adjacency Matrix and Arrays**

- `int graph[NODES][NODES];` // The graph stores edge weights which connect different nodes. A value of 0 indicates no direct connection.
- `int dist[NODES];` // The system stores shortest distance information which starts from the source and extends to all nodes.
- `int visited[NODES];` // The system stores permanent processing status for all nodes in the network.

**Description:**
- `graph[NODES][NODES]` The system represents the complete graph structure which contains all edge weights.
- `dist[NODES]` The system stores current shortest distance information which indicates the distance from the starting node to all other nodes.
- `visited[NODES]` The system marks completed nodes which belong to the shortest path set. The algorithm uses distance information to find the closest unexplored node and then it processes its neighboring nodes.

## 3. Purpose
- The program finds the shortest path distances which start from a given source node to all other nodes in a weighted graph.
- The system handles isolated nodes properly which results in their distance showing as `INT_MAX`.
- The program shows Dijkstra's algorithm through its basic elements by using simple arrays and loop structures for demonstration.

## 4. Functions Implemented

### a. `findNearestNode(int dist[], int visited[])`
- The system detects the unexplored node which has the lowest estimated distance to all other nodes.
- The system checks all nodes to find the node which has the lowest distance value and returns that node's index to the user.
- The main algorithm loop uses this function to choose which node will be processed next.

### b. `shortestPathCalculator(int graph[NODES][NODES], int start)`
- The program provides all essential Dijkstra's algorithm functions through this central program module.
- The system starts all distance measurements at `INT_MAX` while establishing the starting node distance at 0.
- The system uses distance information to identify which nodes should be visited next. After visiting a node, the system checks all its neighboring nodes to find any shorter paths to them.
- The program displays the shortest computed distance from the source to all nodes in the system.

## 5. Main Method Organization
- The system establishes the weighted graph through an adjacency matrix which contains predefined connections between nodes.
- The program selects a specific source node which will determine the path evaluation process.
- The system uses `shortestPathCalculator()` to execute the path calculation process and present the results.
- The program ensures proper handling of isolated nodes by maintaining their distance information at `INT_MAX`.

## 6. Sample Output
Shortest path calculations begin from node 0.

Node Shortest Distance from Source 0
0 0
1 10
2 50
3 30
4 60
5 2147483647

**Notes:**
- The distance to node 5 stays at INT_MAX (2147483647) because the node exists in isolation from all others.
- The other nodes show their shortest distance from the source node which is node 0.