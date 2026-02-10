#include <stdio.h>
#define SIZE 100
//  MIN HEAP PART
// function to adjust min heap
void makeMinHeap(int arr[], int n, int i) {
    int smallest = i;          // assume current index is smallest
    int left = 2 * i + 1;      // left child
    int right = 2 * i + 2;     // right child

    // check left child
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    // check right child
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    // if smallest is not parent, swap
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        // check again for affected subtree
        makeMinHeap(arr, n, smallest);
    }
}

// function to build min heap from unsorted array
void buildMyMinHeap(int arr[], int n) {
    // start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        makeMinHeap(arr, n, i);
    }
}

//MAX HEAP PART
// function to adjust max heap
void makeMaxHeap(int arr[], int n, int i) {
    int largest = i;           // assume current index is largest
    int left = 2 * i + 1;      // left child
    int right = 2 * i + 2;     // right child
    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // if largest is not parent, swap
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // check again for affected subtree
        makeMaxHeap(arr, n, largest);
    }
}

// function to build max heap from unsorted array
void buildMyMaxHeap(int arr[], int n) {
    // start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        makeMaxHeap(arr, n, i);
    }
}

// function to print array
void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// MAIN FUNCTION 

int main() {
    int data[SIZE], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    // Make a copy for max heap so original data is not lost
    int copyArr[SIZE];
    for (int i = 0; i < n; i++) {
        copyArr[i] = data[i];
    }
    // Build Min Heap
    buildMyMinHeap(data, n);
    printf("\nMin Heap:\n");
    showArray(data, n);
    // Build Max Heap
    buildMyMaxHeap(copyArr, n);
    printf("\nMax Heap:\n");
    showArray(copyArr, n);

    return 0;
}