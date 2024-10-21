//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pi - 1);  // Left side of pivot
        quickSort(arr, pi + 1, high); // Right side of pivot
    }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];  // Pivot element
        int i = (low - 1);      // Index of the smaller element
    
        for (int j = low; j < high; j++) {
            // If the current element is smaller or equal to the pivot
            if (arr[j] <= pivot) {
                i++;  // Increment index of the smaller element
                swap(arr[i], arr[j]);  // Swap arr[i] and arr[j]
            }
        }
    
        // Swap the pivot element with the element at index (i + 1)
        swap(arr[i + 1], arr[high]);
        
        return (i + 1);
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends