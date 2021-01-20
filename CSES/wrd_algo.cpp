#include<bits/stdc++.h>
using namespace std;
#define inp(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define ll long long
const long int modu = 1000000009;
const long long int  bound = 2e18;
// int gcd(int a, int b)
// {(a == 0) ? return b : return gcd(b%a, a);}

void solve()
{
    ll n;
    cin >> n;
    if(n == 1)
        cout << 1 << "\n";
    else if(n == 4)
        cout << "2 4 1 3\n";
    else if(n < 5)
        cout << "NO SOLUTION" << "\n";
    else
    {
        for(int i=0; i<n; i+=2)
            cout << i+1 << " ";
        for(int i=1; i<n; i+=2)
            cout << i+1 << " ";
        cout << "\n";
    }
}           

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >>t;
    // while(t--)
        solve();
}