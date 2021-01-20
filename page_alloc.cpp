#include<bits/stdc++.h>
using namespace std;
#define inp(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define ll long long
const long int modu = 1000000007;
const long long int  bound = 1e15;
// int gcd(int a, int b)
// {(a == 0) ? return b : return gcd(b%a, a);}

ll students(ll *arr, ll n, ll mid)
{
    ll no_stud = 1;
    ll cur_sum = arr[0];
    for(ll i=1; i<n; i++)
        if(cur_sum + arr[i] <= mid)
            cur_sum += arr[i];
        else
            {
                no_stud++;
                cur_sum = arr[i];
            } 

    return no_stud;
}           

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    inp(arr, n);
    if(n < m)
        cout << -1 << "\n";
    else
    {    ll sum = 0; ll mx = -bound;
        for(ll i=0; i<n; i++)
        {
            sum += arr[i];
            mx = max(mx, arr[i]);
        }    
        ll low = mx;
        ll high = sum;
        ll result = bound;
        while(low <= high)
        {
            ll mid = low + (high - low)/2;
            ll no_stud = students(arr, n, mid);
            
            if(no_stud <= m)
            {
                high = mid-1;
                result = min(result, mid);
            }    
            else 
                low = mid+1;
        }
        cout << result << "\n";
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