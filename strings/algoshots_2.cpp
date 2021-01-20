#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string str1[n], str2[m];
    for(int i=0; i<n ;i++)
        cin >> str1[i];
    for(int i=0; i<m; i++)
        cin >> str2[i];

    int t;
    cin >> t;
    while(t--)
    {
        long int k;
        cin >> k;
        k--;
        string ans;
        ans = str1[k%n] + str2[k%m];
        cout << ans << "\n";
    }    
}