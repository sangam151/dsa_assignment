#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
long long totalComp = 0;     // total comparisons ganna
long long totalMoves = 0;    // total swaps/moves ganna
// counters reset garna
void initStats() 
{
    totalComp = 0;
    totalMoves = 0;
}
// array print garne function
void displayList(int data[], int size) 
{
    for (int x = 0; x < size; x++) 
        printf("%d ", data[x]);
    printf("\n");
}
// Bubble Sort (adjacent compare garera sort)
void bubbleArrange(int data[], int size) 
{
    for (int a = 0; a < size - 1; a++) 
    {
        for (int b = 0; b < size - a - 1; b++) 
        {
            totalComp++;
            if (data[b] > data[b + 1]) 
            {
                int tempVal = data[b];
                data[b] = data[b + 1];
                data[b + 1] = tempVal;
                totalMoves++;
            }
        }
    }
}

// Selection Sort (minimum khojera swap)
void selectArrange(int data[], int size) 
{
    for (int a = 0; a < size - 1; a++) 
    {
        int minIndex = a;
        for (int b = a + 1; b < size; b++) 
        {
            totalComp++;
            if (data[b] < data[minIndex])
                minIndex = b;
        }

        if (minIndex != a) 
        {
            int tempVal = data[a];
            data[a] = data[minIndex];
            data[minIndex] = tempVal;
            totalMoves++;
        }
    }
}

// Insertion Sort (proper position ma insert)
void insertArrange(int data[], int size) 
{
    for (int a = 1; a < size; a++) 
    {
        int current = data[a];
        int b = a - 1;
        while (b >= 0) 
        {
            totalComp++;
            if (data[b] > current) 
            {
                data[b + 1] = data[b];
                totalMoves++;
                b--;
            } 
            else 
                break;
        }
        data[b + 1] = current;
    }
}

// Merge function (2 sorted part combine)
void combine(int data[], int left, int mid, int right) 
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int leftPart[size1], rightPart[size2];
    // copy values
    for (int i = 0; i < size1; i++) 
        leftPart[i] = data[left + i];
    for (int j = 0; j < size2; j++) 
        rightPart[j] = data[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) 
    {
        totalComp++;
        if (leftPart[i] <= rightPart[j])
            data[k++] = leftPart[i++];
        else
            data[k++] = rightPart[j++];
        totalMoves++;
    }
    while (i < size1) 
    {
        data[k++] = leftPart[i++];
        totalMoves++;
    }
    while (j < size2) 
    {
        data[k++] = rightPart[j++];
        totalMoves++;
    }
}
// Merge Sort (divide and conquer approach)
void mergeArrange(int data[], int start, int end) 
{
    if (start < end) 
    {
        int middle = (start + end) / 2;
        mergeArrange(data, start, middle);
        mergeArrange(data, middle + 1, end);
        combine(data, start, middle, end);
    }
}
int main() 
{
    int size, option;
    printf("Enter number of items: ");
    scanf("%d", &size);
    int numbers[size];
    srand(time(NULL));
    // random values fill garne
    for (int i = 0; i < size; i++)
        numbers[i] = (rand() % 1000) + 1;
    printf("\nInitial Array:\n");
    displayList(numbers, size);
    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble\n");
    printf("2. Selection\n");
    printf("3. Insertion\n");
    printf("4. Merge\n");
    printf("Enter option: ");
    scanf("%d", &option);
    initStats();
    switch (option) 
    {
        case 1:
            bubbleArrange(numbers, size);
            break;
        case 2:
            selectArrange(numbers, size);
            break;
        case 3:
            insertArrange(numbers, size);
            break;
        case 4:
            mergeArrange(numbers, 0, size - 1);
            break;
        default:
            printf("Wrong choice!\n");
            return 0;
    }

    printf("\nSorted Array:\n");
    displayList(numbers, size);
    printf("\nTotal Comparisons: %lld\n", totalComp);
    printf("Total Swaps/Moves: %lld\n", totalMoves);
    return 0;
}