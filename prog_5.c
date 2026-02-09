/* Undirected graph using adjacency matrix with BFS and DFS */

#include <stdio.h>
#define MAX_NODES 10

int connectionMatrix[MAX_NODES][MAX_NODES];   // adjacency matrix
int visitedList[MAX_NODES];                   // visited nodes
int totalVertices;

/*  BFS Traversal */
void performBFS(int initialNode)
{
    int queueArray[MAX_NODES];
    int frontPointer = 0, rearPointer = 0;

    // Clear visited array
    for(int i = 0; i < totalVertices; i++)
        visitedList[i] = 0;
    
    queueArray[rearPointer++] = initialNode;
    visitedList[initialNode] = 1;
    
    printf("BFS Traversal Order: ");
    
    while(frontPointer < rearPointer)
    {
        int currentNode = queueArray[frontPointer++];
        printf("%d ", currentNode);
        
        for(int neighbor = 0; neighbor < totalVertices; neighbor++)
        {
            // If edge exists and neighbor not visited
            if(connectionMatrix[currentNode][neighbor] == 1 && visitedList[neighbor] == 0)
            {
                queueArray[rearPointer++] = neighbor;
                visitedList[neighbor] = 1;
            }
        }
    }
    printf("\n");
}

/* DFS Traversal */
void performDFS(int currentVertex)
{
    printf("%d ", currentVertex);
    visitedList[currentVertex] = 1;
    
    for(int adjacent = 0; adjacent < totalVertices; adjacent++)
    {
        // If connected and not visited
        if(connectionMatrix[currentVertex][adjacent] == 1 && visitedList[adjacent] == 0)
        {
            performDFS(adjacent);   // recursive call
        }
    }
}

/* Main Function */
int main()
{
    int edgeCount;
    int vertex1, vertex2;
    int startingPoint;
    
    printf("Enter total vertices: ");
    scanf("%d", &totalVertices);
    
    // Initialize matrix to zero
    for(int row = 0; row < totalVertices; row++)
        for(int col = 0; col < totalVertices; col++)
            connectionMatrix[row][col] = 0;
    
    printf("Enter total edges: ");
    scanf("%d", &edgeCount);
    
    printf("Enter edges (u v):\n");
    for(int i = 0; i < edgeCount; i++)
    {
        scanf("%d %d", &vertex1, &vertex2);
        // Undirected graph - set both directions
        connectionMatrix[vertex1][vertex2] = 1;
        connectionMatrix[vertex2][vertex1] = 1;
    }
    
    printf("Enter starting node: ");
    scanf("%d", &startingPoint);
    
    performBFS(startingPoint);
    
    // Reset visited for DFS
    for(int i = 0; i < totalVertices; i++)
        visitedList[i] = 0;
    
    printf("DFS Traversal Order: ");
    performDFS(startingPoint);
    printf("\n");
    
    return 0;
}