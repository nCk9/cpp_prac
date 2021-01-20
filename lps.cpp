// #include<iostream>  //longest plaindromic subsequence....recursive solution
// #include<string>
// using namespace std;

// int rec(int low, int high, string str)
// {
//     if(low > high)
//         return 0;
//     else 
//     {
//         if(low == high)
//                 return 1;
//         else if(str[low] == str[high])
//                 return 2 + rec(low+1, high-1, str);
//         else 
//                 return max(rec(low+1, high, str), rec(low, high-1, str));
//     }
// }

// int main()
// {
//         int t;
//         cin >> t;
//         while(t--)
//         {
//                 string str;
//                 cin >> str;
//                 int k = rec(0, str.size()-1, str);
//                 cout << k << "\n";
//         }
// }


#include<iostream>  //longest plaindromic subsequence...memoized approach(dp).
#include<string>
using namespace std;

int dp[10001][10001];

int rec(int low, int high, string str)
{
    
    if(low > high)
        return 0;
    else 
    {
        if(low == high)
                return 1;
                
        if(dp[low][high] == -1)
        {
            if(str[low] == str[high])
                dp[low][high] = 2 + rec(low+1, high-1, str);
            else 
                dp[low][high] = max(rec(low+1, high, str), rec(low, high-1, str));
        }
        return dp[low][high];
    }
}

int main()
{
        int t;
        cin >> t;
        while(t--)
        {
                string str;
                cin >> str;
                for(int i=0; i<str.size(); i++)
                    for(int j=0; j<str.size(); j++)
                        dp[i][j] = -1;
                int k = rec(0, str.size()-1, str);
                cout << k << "\n";
                
        }
}