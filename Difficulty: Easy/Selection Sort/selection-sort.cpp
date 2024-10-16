//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i,int n)
    {
      int min_index = i; // Assume the first unsorted element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j; // Update min_index if a smaller element is found
            }
        }
        return min_index;   
    }
     
    void selectionSort(int arr[], int n)
    {
       for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part
        int min_index = select(arr, i, n);
        
        // Swap the found minimum element with the first element of the unsorted part
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends