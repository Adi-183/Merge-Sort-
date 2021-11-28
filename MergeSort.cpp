#include <iostream>
using namespace std;
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void mergethis(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
                            
{
    int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

void mergesortloops(int arr[],int n){
    int curr_size;  // For current size of subarrays to be merged
                    // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
                   // to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = min(left_start + curr_size - 1, n-1);
 
           int right_end = min(left_start + 2*curr_size - 1, n-1);
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           mergethis(arr, left_start, mid, right_end);
       }
   }

}
void mergesortrecursion(int a[],int si, int ei){
    /*Base Case*/
    if(si>=ei){
     return;   
    }
    int mid=(si+ei)/2;
    mergesortrecursion(a,si,mid);
    mergesortrecursion(a,mid+1,ei);
    int arr1[mid-si+1];
    int arr2[ei-mid];    
    for(int i=0;i<mid-si+1;i++){
        arr1[i]=a[i+si];
    }
    for(int i=0;i<ei-mid;i++){
        arr2[i]=a[i+mid+1];
    }
    mergeArrays(arr1,arr2,mid-si+1,ei-mid,a+si);
    return;
}
void selectionsort(int a[], int n){
    int min=0;
    int temp;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=a[i];
            a[i]=a[min];    /*Swap a[i] and a[min]*/
            a[min]=temp;
        }

    }
    
}
int main()
{
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int a[n],b[n],c[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    int d;
    cout<<"Press 1 to sort with selection sort"<<endl;
    cout<<"Press 2 to sort with merge sort using recursion"<<endl;
    cout<<"Press 3 to sort with merge sort using loops(iterative implementation)"<<endl;
    cin>>d;
    
    switch (d)
    {
    case 1:
        selectionsort(a,n);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        break;
    case 2:
        mergesortrecursion(b,0,n-1);
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        break;
    case 3:
        mergesortloops(c,n);
        for(int i=0;i<n;i++){
            cout<<c[i]<<" ";
        }
        break;
    
    default:
        cout<<"Wrong Choice!";
        break;
    }
}