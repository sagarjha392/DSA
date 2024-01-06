#include <stdio.h>

int linearSearch(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int x)
{
    // binary search is only used for searching in sorted arrays
    int mid, high = size, low = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void BubbleSort(int *arr, int size)
{
    /* Worst Case time complexity is O(n^2)*/
    // int isSorted = 0;
    printf("\nSorting............\n");
    for (int i = 0; i < size - 1; i++)
    { // loop for passes
        printf("Pass: %d\n", i);
        // isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        { // loop for comparison and swapping
            if (arr[j] > arr[j + 1])
            {
                // swap if jth element is greater than j+1th element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // isSorted=0;
            }
        }

        // if(isSorted){
        //     return ;
        // }
    }
}

void insertionSort(int *arr, int size)
/*
1. Best Case time complexity is O(n)
2 Worst Case time complexity is O(n^2)

*/
{
    int key, j;

    // Loop for passes
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *A, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        int temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

void merge(int *A, int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {11, 32, 23, 44, 25, 16, 17, 98}; // unsorted array for linear search
    // int arr[] = {11, 16, 17, 23, 25, 32, 44, 98}; // sort array for binary  search
    
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    MergeSort(arr, 0, size-1);
    printf("\n");
    printArray(arr, size);


    // quickSort(arr, 0, size - 1);
    // printf("\n");
    // printArray(arr, size);
    // selectionSort(arr, size);
    // printf("\n");
    // printArray(arr, size);
    // insertionSort(arr, size);
    // printf("\n");
    // printArray(arr, size);
    // BubbleSort(arr, size);
    // printf("\n");
    // printArray(arr, size);
    // BubbleSort(arr, size);
    // printf("\n");
    // printArray(arr, size);

    // int element = 32;
    // int index = binarySearch(arr, size, element);
    // if (index == -1)
    // {
    //     printf("Element not found");
    // }
    // else
    // {
    //     printf("%d found at index %d", element, index);
    // }

    return 0;
}