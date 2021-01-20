#include<iostream>             //coin change variation
using namespace std;
                                      
int rec(int *arr, int i, int j)
{
    if(j == 0)
        return 1;
    else if(i<0 || j<0)
        return 0;
    else if(arr[i] > j)
        return rec(arr, i-1, j);
    else 
        return (rec(arr, i-1, j-arr[i]) + rec(arr, i-1, j));
}


int main()
{
    int sz;
    cin >> sz;
    int arr[sz];
    
    for(int i=0; i<sz; i++) 
        cin >> arr[i];
    int amt;
    cin >> amt;
    
    cout << rec(arr, sz-1, amt);
}