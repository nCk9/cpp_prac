#include<iostream>   //dynamic programming approach to longest common subsequence problem
#include<string>
using namespace std;
int dp[100][100];


int rec(string str1, string str2, int sz1, int sz2)
{
    if(sz1 <= 0 || sz2 <= 0)
        return 0;
    else
    {
        if(dp[sz1-1][sz2-1] == -1)
        {
            if(str1[sz1-1] == str2[sz2-1])          
                    dp[sz1-1][sz2-1] = 1+rec(str1, str2, sz1-1, sz2-1);
            else 
            {

                int temp1 = rec(str1, str2, sz1-1, sz2);
                int temp2 = rec(str1, str2, sz1, sz2-1);
                dp[sz1-1][sz2-1] = max(temp1, temp2);
            }
        }
        return dp[sz1-1][sz2-1];
    }
}

int main()
{
    string str1, str2;
    cout << "Enter the string to be compared :\n";
    cin >> str1 >> str2;
    for(int i=0; i<str1.size(); i++)
        for(int j=0; j<str2.size(); j++)
            dp[i][j] = -1 ;   
    int len = rec(str1, str2, str1.size(), str2.size());
    cout <<"Length of longest common sbusequence is: " << len << "\n";

    // for(int i=0; i<str1.size(); i++)
    // {
    //     for(int j=0; j<str2.size(); j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }    

    string ans;
    int i = str1.size()-1; int j = str2.size()-1;
    while(i >= 0  && j >= 0)
        if(str1[i] == str2[j])
        {
            ans += str1[i];
            i--; j--;
        }   
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else 
                j--;
        }
    cout << "Subsequence is: ";
    for(int k=len-1; k>=0; k--)
        cout << ans[k];
    cout << "\n";
}