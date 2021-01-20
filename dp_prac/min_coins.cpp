#include<iostream>
using namespace std;    //Recursive solution...exponential time 

int rec(int *arr, int i, int j)
{
    if(i < 0 || j < 0)
        return 1000001;
    else if(j == 0)
        return 0;
    else 
    {
        int t1 = rec(arr, i, j-arr[i]) + 1;
        int t2 = rec(arr, i-1, j);
        return min(t1, t2);
    }
}

int main()
{
    int sz = 3;
    int arr[] = {2, 7, 3};
    
    int amt;
    cin >> amt;
    
    cout << "Min no. of coins req. is : " << rec(arr, sz-1, amt);
    
}