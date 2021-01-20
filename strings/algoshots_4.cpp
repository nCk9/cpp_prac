#include<iostream>
#include<string>
using namespace std;

int main()  // O(1) solution.
{
    string str;
    cin >> str;

    int sz = str.size();
    int ct=0;
    for(int i=0; i<sz; i++)
        if(str[i] == 'a')
            ct++;
    if(ct > sz/2)
        cout << sz << "\n";
    else 
        cout << 2*ct - 1 << "\n";

}

// int main()   //O(n) worst case solution.
// {
//     string str;
//     cin >> str;

//     int sz = str.size();
//     int ct=0;
//     for(int i=0; i<sz; i++)
//         if(str[i] == 'a')
//             ct++;
//     int new_length = sz;
//     for(int i=0; i<sz; i++)
//     {
//         if(ct > new_length/2)
//             break;

//         if(str[i] != 'a')
//             new_length--;    
//     }       
//     cout << new_length <<"\n";          

// }