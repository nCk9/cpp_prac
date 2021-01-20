#include<iostream>
using namespace std;

int peak_find(int arr[], int low, int high)
{
    if(low == high)  //only one element
        return low;
    else 
    {
        int mid = (low+high)/2;
        
        if((arr[mid-1] < arr[mid] || mid == 0)  &&  arr[mid+1] < arr[mid])
            return mid;
        else if(arr[mid-1] < arr[mid]  &&  arr[mid] < arr[mid+1])
            return peak_find(arr, mid+1, high);
        else return peak_find(arr, low, mid-1);
    }

}

int main()
{
    int sz;
    cin >> sz;
    int arr[sz];
    for(int i=0; i<sz; i++)
        cin >> arr[i];
    int idx = peak_find(arr, 0, sz-1);

    cout << "Peak element in the array is: " << arr[idx] << "\n";
}