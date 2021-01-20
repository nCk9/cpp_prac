#include<iostream>
using namespace std;

int minn(int x, int y)
{
    if(x < y) 
        return y;
    else 
        return x;
}

int rec(int *stairs, int i)
{
    if(i == 1 || i == 2)
        return 0;
    else 
        return minn(rec(stairs, i-1)+stairs[i-1], 
                    rec(stairs, i-2)+stairs[i-2]);
}


int main()
{
    int sz, cost=0; cin >>sz;
    int stairs[sz+2];
    stairs[0] = 0; stairs[sz+1] = 0;
    for(int i=1; i<sz+1; i++)
        cin >> stairs[i];
    cout << "Minimum cost to reach the top is: " ;
    cout << rec(stairs, sz+1) << "\n";
}