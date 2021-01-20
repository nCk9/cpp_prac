// #include<iostream>  //to check if it can reach destination(n, m), staring from (0,0)...recursive approach
// using namespace std;

// bool rec(int i, int j, int n, int m, int **arr)
// {
//     if(i == n-1  && j == m-1)
//         return true;
//     else if(arr[i][j] == 0) return false;
//     else 
//     {
//         if(i+1 >= n)
//             return rec(i, j+1, n, m, arr);
//         else if(j+1 >= m)
//             return rec(i+1, j, n, m, arr);
//         else 
//         {  
//             (rec(i+1, j, n, m, arr) || rec(i, j+1, n, m, arr));
//         }
//     }
// }


// int main()   // 0 for obstracle and 1 for empty space
// {
//     int n, m;
//     cin >> n >> m;
//     // int arr[n][m];
//     int **arr;
//     arr = new int *[n];
//     for(int i = 0; i <n; i++)
//         arr[i] = new int[m];
        
        
//     for(int i=0; i<n; i++)
//         for(int j=0; j<m; j++)
//             cin >> arr[i][j];
    
//     bool t = rec(0, 0, n, m, arr);
    
//     t == 1 ? cout << "True" : cout << "False";
// }


#include<iostream>  // dynamic programming approach...
using namespace std;

int main()   // 0 for obstracle and 1 for empty space
{
    int n, m;
    cin >> n >> m;
    bool arr[n][m];
    // int **arr;
    // arr = new int *[n];
    // for(int i = 0; i <n; i++)
    //     arr[i] = new int[m];
        
        
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    
    int dp[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dp[i][j] = 0;

    for(int i=n-1; i>=0; i--)
        if(arr[i][m-1] != 0)
            dp[i][m-1] = arr[i][m-1];
        else break;


    for(int j=m-1; j>=0; j--)
        if(arr[n-1][j] != 0)
            dp[n-1][j] = arr[n-1][j];
        else break;


    for(int i=n-2; i>=0; i--)
        for(int j=m-2;j>=0; j--)
            {
                if(arr[i][j] != 0)
                    dp[i][j] = (dp[i+1][j] + dp[i][j+1]);
                // else dp[i][j] = 0;
            } 
    cout << "\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << dp[i][j] << " ";
        cout << '\n';
    }    

    // dp[0][0] == 1 ? cout << "We can reach to the destination form (0,0).\n" : cout << "We can't reach destination form (0, 0).\n";
    

}