#include <bits/stdc++.h>
using namespace std;
const long long int inf = -1e15;
const long long int INF = 1e15;
long long int solve2(long long int n) {
    if((n&(n+1LL)) == 0)
        return (2*n) + 1LL;
    else if(n%2 == 0)
        return n+1;
    else 
        return n+2;
}
 
long long int solve1(long long int n) {
    return ((n | (n+1LL)));
}
 
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    srand(time(0));
    while (1) 
    {
        
        long long int n = rand()%100 + 1;
    
        long long int ans1 = solve1(n);
        long long int ans2 = solve2(n);
        if(ans1 == ans2)
        {    cout << n << "\n";
            cout << "OK, Correct" << "\n"; } 
        else{
                cout << "WRONG" << "\n";
                cout << n << "\n";
                cout << ans1 << " " << ans2 << "\n";
                break;
        } 
    }
}