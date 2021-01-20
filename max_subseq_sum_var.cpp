// to find max subsequence sum of an array of integers provided elements should'nt be consecutive...
#include<iostream>  //O(n) dp solution(tabulation)
#include<vector>
using namespace std;

int main()
{
    int sz;
    cin >> sz;
    int arr[sz];
    for(int i=0; i<sz; i++)
        cin >> arr[i];

    vector<int> dp(sz, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2; i<sz; i++)
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);

    cout << dp[sz-1];
    
    
}

// Recurrence : Rec(i) = max(Rec(i-1), Rec(i-2) + arr[i]).



// #include <bits/stdc++.h>  //memoization solution(O(n), dp)..
// using namespace std;
// #define int long long
 
// vector<int> v;
// int res[100005];
 
// int msa(int n)
// {
// 	if(n==0) return v[0];
// 	if(n==1) return max(v[0],v[1]);
// 	else if(res[n]==0)
// 	 res[n] = max(msa(n-1),v[n]+msa(n-2));
// 	return res[n];
// }
 
// main()
// {
// 	int n,i,x;
// 	cin >> n;
// 	for(i=0;i<n;i++)
// 	{
// 		cin >> x; 
// 		v.push_back(x);
// 	} 
// 	cout << msa(n-1) << endl;
// 	return 0;
// }