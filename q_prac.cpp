#include<bits/stdc++.h>
using namespace std;
#define inp(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define ll long long
const long int modu = 1000000009;
const long long int  bound = 2e18;
ll gcd(ll a, ll b)
{return (a == 0) ? b : gcd(b%a, a);}
// ll bin_exp(ll x, ll n)
//     {
//         if(x == 0)
//             return 0;
//         if(n == 0)
//             return 1;
//         else{
//             if(n%2 == 0)    
//                 return bin_exp((x*x, n/2);
//             else
//                 return (x*bin_exp(x*x, (n-1)/2));
//         }
//     }

// ll to_int(string str)  //bianry string to decimal
// {
//     ll val=0;
//     for(ll i=str.size()-1, j=0; i>=0; i--, j++)
//         val += str[i] == '1' ? pow(2, j)*1 : pow(2, j)*0;

//     return val;
// }

void solve()
{
    ll n;
    cin >> n;
    ll X=2*n;
    ll sum=0;
    for(ll i=1; i<=n; i++)
        sum += gcd(X, i);

    cout << sum << " " << X << "\n";
}           

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >>t;
    while(t--)
        solve();
}