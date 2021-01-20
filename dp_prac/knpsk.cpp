// #include<iostream>     //Recursive solution....
// using namespace std;

// int rec(int *set, int i, int j)
// {
//     if(i < 0  ||  j < 0)
//         return INT8_MAX;
//     else if(i == 0)
//         return j;
//     else 
//         return min(rec(set, i-1, j), rec(set, i-1, j-set[i]));
// }

// int main()
// {
//     // int set[4] = {0, 1, 8, 4};
//     // int sz = 4;
//     int w; int n;
//     // cout << "Enter the maximum weight of knapsack: ";
//     cin >> w >> n;
//     // cout << "Max weight that can be filled is : ";
//     int sz = n+1;
//     int set[sz]; set[0] = 0;
//     for(int i=1; i<sz; i++)
//         cin >> set[i];
//     int g = rec(set, sz-1, w);
//     if(w > g)
//         cout << w - g << "\n";
//     else  cout << w << "\n";
//     // cout  << g << "\n";
// }


#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    // int set[4] = {0, 1, 4, 8};
    // int sz = 4;
    int w; int n;
    // cout << "Enter the maximum weight of knapsack: ";
    cin >> w; cin >> n; int sz = n + 1;
    int set[sz];  set[0] = 0;
    for(int i=1; i<sz; i++)
        cin >> set[i];
    // cout << "Max weight that can be filled is : ";
    if(sz > 2)
  {
    sort(set, set+sz);
    // int dp[sz][w+1];

    int **dp = new int*[sz];

for (int i = 0; i <sz ; i++) {

   dp[i] = new int[w+1];

}

    for(int i=0; i<sz; i++)
        for(int j=0; j<=w; j++)
            dp[i][j] = -1;         
    for(int i=0; i<sz; i++)
        dp[i][0] = 0;
    for(int j=0; j<=w; j++)
        dp[0][j] = 0;

    for(int j=0; j<=w; j++)
        if(j < set[1])
            dp[1][j] = 0;
        else dp[1][j] = set[1];
        
    for(int i=2; i<sz; i++)
        {
            for(int j=1; j<=w; j++)
                if(j < set[i])
                    dp[i][j] = dp[i-1][j];
                else if(j == set[i])
                    dp[i][j] = j;
                else 
                {
                        if(dp[i-1][j] + set[i] <= j)
                        {if(j >= max(dp[i-1][j], dp[i-1][j - set[i]]))
                            dp[i][j] = max(dp[i-1][j], dp[i-1][j - set[i]]) + set[i];
                        else dp[i][j] = dp[i][j-1];
                        }
                        else {dp[i][j] = dp[i-1][j - set[i]] + set[i];
                               dp[i][j] = max(dp[i][j], dp[i-1][j]); }
                }
                //    { dp[i][j] = max(dp[i-1][j], dp[i-1][j]+set[i]);
                //     if(dp[i][j] + set[i] < w)
                //         dp[i][j] += set[i];
                //    }
        }   

    //     for (int i = 0; i <= n; i++) { 
    //         for (int j = 0; j <= w; j++) { 
    //         if (i == 0 || j == 0) 
    //             dp[i][j] = 0; 
    //         else if (set[i - 1] <= j) 
    //             dp[i][j] = max( 
    //                 set[i-1] + dp[i - 1][j - set[i - 1]], 
    //                 dp[i - 1][j]); 
    //         else
    //             dp[i][j] = dp[i - 1][j]; 
    //     } 
    // } 

// int maxx = INT8_MIN;
//     for(int i=1; i<sz; i++)
//         {
//              for(int j=1; j<=w; j++)
//                 // maxx = max( dp[i][w], maxx);
//                 cout  << dp[i][j] << " ";
//             cout << "\n";
//         }
       cout << dp[sz-1][w] << "\n";
  }
  else 
  {
      cout << set[1] << "\n";
  }

}