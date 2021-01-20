#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    unordered_map<string, int> ump;
    ump["Icosahedron"] = 20;
    ump["Tetrahedron"] = 4;
    ump["Cube"] = 6;
    ump["Octahedron"] = 8;
    ump["Dodecahedron"] = 12;
    int sum=0;
    while(t--)
    {
        string str;
        cin >> str;
        sum += ump[str];
    }

    cout << sum << "\n";
}