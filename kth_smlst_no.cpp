#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int a = *x;
    *x = *y;
    *y = a; 
}

int prtion(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i=low-1;
    for(int j=low; j<high; j++)
    if(arr[j] <= pivot)
    {
        i++;
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

int q_sort(int *arr, int low, int high, int k)
{
     if(low < high)
     {
         int q = prtion(arr, low, high);
         if((q+1) == k)
         return q;
         else if(k < q+1) q_sort(arr, low, q-1, k);
         else q_sort(arr, q+1, high, k);
     }
}

int main()
{
    cout << "Enter size of the array: ";
    int sz; cin >> sz;
    cout << "Enter array: ";
    int arr[sz];
    for(int i=0; i<sz; i++)
    cin >> arr[i];

     cout << "To find the kth smallest number, enter k : ";
     int k; cin >> k;
     if(k > sz || k < 0)
     cout << "Invaid input." << "\n";
     else {
    int g = q_sort(arr, 0, sz-1, k);
    cout << "The kth smallest number in the array is : " << arr[g] << endl;}

    return 0;
}