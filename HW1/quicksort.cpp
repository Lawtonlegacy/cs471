// quicksort.cpp for HW1
// Robert Lawton
// 30 Aug 2021
// For CS F471 Fall 2021
// Glenn Chappell

#include <iostream>

// Utility function
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort array using Lomuto partition Scheme
// Preconditions:
// Must be an array of integers, lo = starting index, hi = last element of array

int partition(int A[], int lo, int hi){
    int pivot = A[hi];
    int i = lo - 1;
    for(int j = lo; j <= hi; j++){
        if (A[j] <= pivot){
            i = i + 1;
            swap(&A[i], &A[j]);
        }
    }
    return i;
}

void quicksort(int A[], int lo, int hi){
    if(lo >= 0 && hi >= 0){
        if(lo < hi){
            int p = partition(A, lo, hi);
            quicksort(A, lo, p - 1);
            quicksort(A, p + 1, hi);
        }
    }
}

void printArray(int A[], int size){
    for(int i = 0; i < size; i++){
        std::cout<< A[i] << " ";
    }
    std::cout<< std::endl;
}

int main(){
    int test1[] = {0, 22, -8, -9, 1, 1, 1, 5, 5};
    int test2[] = {-15, 3, 63, 0 , -4, 6, 0, 2, -15, 78, 2, 7};
    int test3[] = {-21, 66, 230, 789231, 230, -73412, 72};
    int n  = sizeof(test1)/sizeof(test1[0]);
    quicksort(test1, 0, n-1);
    std::cout << "Sorted Array: \n";
    printArray(test1,n);
    n = sizeof(test2)/sizeof(test2[0]);
    quicksort(test2, 0, n-1);
    std::cout << "Sorted Array: \n";
    printArray(test2,n);
    n = sizeof(test3)/sizeof(test3[0]);
    quicksort(test3, 0, n-1);
    std::cout << "Sorted Array: \n";
    printArray(test3,n);
    return 0;
}