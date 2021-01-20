#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        if(n <= 11)
        {
            if(n < 11)
                cout << "NO\n";
            else 
                (str[0] == '8') ? cout << "YES\n" : cout << "NO\n";
        }    

        else
        {
            int new_length = n;
            for(int i=0; i<n; i++)
                if(str[i] == '8'  &&  new_length >= 11)
                {
                    cout <<"YES\n";
                    break;
                }    
                else if(str[i] != '8')
                    new_length--;
                else 
                {
                    cout << "NO\n";
                    break;
                }
            if(new_length <= 0)
                cout << "NO" << "\n";
        }
        
    }
}