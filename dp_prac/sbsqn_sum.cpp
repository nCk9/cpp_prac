#include<iostream>        //Maximum subsequence sum with adjacent elements having atleast k difference in index
using namespace std;

int main()
{
    int sz;
    cin >> sz;
    int arr[sz+1];
    for(int i=0; i<sz+1; i++)   
        cin >> arr[i];
    int k;
    cin >> k;
    k += 1; r
    int dp[sz+1];
    dp[0] = max(0, arr[0]);
    int i=1;
    while(i<k)
    {
        dp[i] = max(dp[i-1], arr[i]);
        i++;
    }

    i = k;
    while(i<sz+1)
    {
        dp[i] = max(dp[i-1], dp[i-k] + arr[i]);
        i++;
    }
    for(int i=0; i<sz+1; i++)
        cout << dp[i] << " ";
}

/*
20
0 0 0 0 0 0 5 6 0 0 0 0 5 0 1 0 0 0 0 0 0
5
*/