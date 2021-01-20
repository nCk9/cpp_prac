#include<iostream>   //to find max sum of non adjacent elements in a 2Xn matrix.
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<2; j++)
            cin >> arr[j][i];
    
    int dp[2][n];
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    int maxx = 0;
    for(int j=1; j<n; j++)
           for(int i=0; i<2; i++)
            {
                if(i == 0)
                    dp[i][j] = max(dp[i+1][j-1]+arr[i][j], dp[i][j-1]);
                else 
                    dp[i][j] = max(dp[i-1][j-1]+arr[i][j], dp[i][j-1]);
                maxx = max(maxx, dp[i][j]);
            }
    
    for(int i=0; i<2; i++)
      {
            for(int j=0; j<n; j++)
                cout << dp[i][j] << " ";
            cout << '\n';            
      }    
      
      cout << "Max. sum is : " << maxx << "\n";
}