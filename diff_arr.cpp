#include<iostream>
using namespace std;

int main()
{
    int sz;        //performing range updates using difference arrays.
    cin >> sz;
    int arr[sz];
    for(int i=0; i<sz; i++)
        cin >> arr[i];

    int diff[sz+1];
    diff[0] = arr[0];
    for(int i=1; i<sz+1; i++)
        diff[i] = arr[i] - arr[i-1];

    int q;
    cin >> q;
    while(q--)
    {        // range updates in O(1) time!!
        int l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r+1] -= x; 
    }
    arr[0] = diff[0];
    for(int i=0; i<sz; i++)
        {
            if(i != 0)
                arr[i] = diff[i] + arr[i-1];
        
            cout << arr[i] << " ";
        }
}