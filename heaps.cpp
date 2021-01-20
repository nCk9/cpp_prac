#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(int *arr, int i, int sz)
{
    int left = 2*i;
    int right = 2*i+1;
    int smallest = INT8_MAX;

    if(left < sz  && arr[left] < arr[i])
        smallest = left;
    else
        smallest = i;

    if(right < sz  &&  arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, smallest, sz);
    }    

}

void max_heapify(int *arr, int i, int sz)
{
    int  left = 2*i;
    int  right = 2*i+1;
    int  largest = 0;

    if(left < sz && arr[left] > arr[i])
        largest = left;
    else
        largest = i;
 
    if(right < sz  && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, sz);
    }
}

void heap_sort(int *arr,  int sz)
{
    int heap_sz = sz;
    for(int i=sz; i>1; i--)
    {
        swap(arr[1], arr[i]);
        heap_sz--;
        max_heapify(arr, 1, heap_sz);
    }
}

int main()
{
    int sz;  
    cout << "Enter the size of the array : ";
    cin >> sz;
    int arr[sz+1];
    arr[0]= INT8_MIN;
    cout << "Enter the elements of the array : ";
    for(int i=1; i<sz+1; i++)
        cin >> arr[i];
    cout << "Min heap structure is : ";
    for(int i=(sz+1)/2; i>=1; i--)
        min_heapify(arr, i, sz+1);

    for(int i=1; i<sz+1; i++)
        cout << arr[i] << " ";
    cout << "\n";    

    for(int i=(sz+1)/2; i>=1; i--)
        max_heapify(arr, i, sz+1);

    cout << "Max heap structure is : ";
    for(int i=1; i<sz+1; i++)
        cout << arr[i] << " ";
    cout << "\n";

    heap_sort(arr, sz);        //to be called after array is converted to max_heap structure.
    cout <<"Sorted array is: ";
    for(int i=1; i<sz+1; i++)
        cout << arr[i] << " ";
    cout << "\n";

}