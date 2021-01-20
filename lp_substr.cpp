#include<bits/stdc++.h>   //to find length of longest plaindromic substring 
using namespace std;

int rec(string str, int i, int j)
{
    if(i > j)
        return 0;
    else if(i == j)
        return 1;
    else 
    {
        if(str[i] == str[j])
            return rec(str, i+1, j-1) + 2;
        else return (max(rec(str, i, j-1), rec(str, i+1, j)));
    }
}

int main()
{
    string str;
    cin >> str;
    
    int ans = rec(str, 0, str.size()-1);
    
    cout << ans << "\n";
}