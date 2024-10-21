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
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;  // Size of the left subarray
        int n2 = r - m;      // Size of the right subarray
    
        // Create temporary arrays to hold the two subarrays
        int left[n1], right[n2];
    
        // Copy data into the temporary arrays
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            right[i] = arr[m + 1 + i];
    
        // Merge the two subarrays back into arr[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
    
        // Copy any remaining elements of the left subarray
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
    
        // Copy any remaining elements of the right subarray
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends