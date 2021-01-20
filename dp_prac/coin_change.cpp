// #include<iostream>
// using namespace std;

// int rec(int *arr, int i, int amt)   // oviously it won't give correct answer for the min required coins problem. Base case is different. 
// {
//     if(i < 0  ||  amt < 0)
//         return 0;
//     else if(amt == 0)
//          return 1;
//     else 
//           return (rec(arr, i, amt - arr[i]) + rec(arr, i-1, amt));
// }

// int main()       //to find no. of ways to make coin change...recursive method.
// {
//     int arr[3] = {2, 3, 5};
//     cout << "Enter amount to be made: ";
//     int amt; cin >> amt;
//     int k = rec(arr, 2, amt);
//     cout <<  k << "\n";
// }




#include<iostream>
using namespace std;
int main()
{
    int coins[4] = {2, 6, 3, 5};  int sz=4; // dynamic programming solution...failes some cases though(idk why)
    cout << "Enter amount to be made : ";
    int amt; cin >> amt;
    int dp[sz][amt+1] = {-1};
    for(int i=0; i<sz; i++)   // base case1
        dp[i][0] = 1;
    for(int j=1; j<=amt; j++)  // base case2
        dp[0][j] = 0;

    for(int i=1; i<sz; i++)
        for(int j=2; j<=amt; j++)
            {
                dp[i][j] += dp[i-1][j];
                if(j >= coins[i])
                    dp[i][j] += dp[i][j-coins[i]];
            } 

    for(int i=0; i<sz; i++)
        {
            for(int j=0; j<=amt; j++)
             cout << dp[i][j] << " ";
            cout << "\n";
        }
}



// #include<iostream>   //memoized solution perfectly working fine!(no. of ways to reach an amount).
// using namespace std;
// long int dp[100][10001];

// long int rec(int *arr, int i, int amt)
// {
//     if(i < 0  ||  amt < 0)
//         return 0;
//     else if(amt == 0)
//         return 1;
//     else
//     {
//         if(dp[i][amt] == -1)
//         {
//             long int temp2 = rec(arr, i, amt - arr[i]);
//             long int temp1 = rec(arr, i-1, amt);
//             dp[i][amt] = (temp1 + temp2);
//         }
//         return dp[i][amt];
//     }
// }


// int main()//no. of ways to reach x
// {

//     int amt, sz;
//     cin >> amt >> sz;
//     int arr[sz];
//     for(int i=0; i<sz; i++)
//         cin >> arr[i];
        
//     for(int i=0; i<sz; i++)
//         for(int j=0; j<amt+1; j++)
//             dp[i][j] = -1;
//     cout << rec(arr, sz-1, amt);
// }
