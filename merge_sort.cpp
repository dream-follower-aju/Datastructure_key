/*
-----------(Merge sort)----------
Key point := based on divide nand conqure algorithm

*/
#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    //(temp arrays a and b)
    int a[n1]; // stored l to mid elemnts
    int b[n2]; //stored mid to r elements

    for (int i = 0; i < n1; i++)
    {
        
        a[i] = arr[l+i];
        cout << a[i]<<" ";
    }
    
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+1+i];
        cout << b[i]<<" ";
    }
    cout << endl;

    int i = 0;
    int j = 0;
    int k = l; //pointer to traverse array to store the merge array ;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    /*
    int n;
    cout << "ENTER THE SIZE OF ARRAY :=\n";
    cin >> n;
    int arr[n];
    cout << "ENTER THE n ELEMENS OF ARRAY :=\n";
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    */
    int arr[] = {5, 4, 3, 2, 1,6};
    mergesort(arr, 0, 5);
    for (int i = 0; i <6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}