#include<bits/stdc++.h>
using namespace std;

long long int my_sol(long long int *arr, int sz)
{
    // long long int sum[sz];
    //     sum[0] = arr[0];
    //     sum[1] = max(arr[0] + arr[1], -arr[0]-arr[1]);
    //     for(int i=2; i<sz; i++)
    //             sum[i] = max(sum[i-1]+arr[i], sum[i-2]-arr[i-1]-arr[i]);
    //     // for(int i=0; i<sz; i++)
    //     //         cout << sum[i] << " ";
    //     return sum[sz-1];

    if(sz == 2)
                return max(arr[0] + arr[1], -arr[0]-arr[1]);
        else
        {
                long long int sum=0, prev_sum=0;
                int i=0; prev_sum = 0;
                while(i < sz-1)
                {
                        sum = prev_sum + max(arr[i], -arr[i]);
                                if(prev_sum + arr[i] < sum)
                                        arr[i+1] = -arr[i+1];
                        prev_sum = sum;
                        i++;
                }
                sum += arr[sz-1];        
                return sum;
        }
}

long long int their_sol(long long int *arr, int sz)
{
    int cnt=0;
    long long int mi=INT_MAX;
    long long int sum=0;
    for(int i=0;i<sz;i++)
    {
        if(arr[i]<0)
          cnt++;
        mi=min(mi,abs(arr[i]));
        sum+=abs(arr[i]);
    }
 
    if(cnt%2==0)
      return sum;
    else
       return (sum-2*mi);
}

int main()
{
    srand(time(0));
    while(1)
    {  
        int sz;
        sz = rand()%20+1;
        long long arr[sz];
        
        for(int i=0; i<sz; i++)
            arr[i] = rand()%100 - 50;
        cout << sz << "\n";
            for(int i=0; i<sz; i++)
                cout << arr[i] << " ";
        
        long long int res1 = my_sol(arr, sz);
        long long int res2 = their_sol(arr, sz);

        if(res1 == res2)
            cout << "Correct" << "  ";
        else 
        {
            cout << "Wrong" << "\n" << "Input : \n";

            cout << sz << "\n";
            for(int i=0; i<sz; i++)
                cout << arr[i] << " ";
            cout << "\n";
            cout << "My soln: " << res1 << ",   " << "Correct sol: " << res2 << "\n";
            break;
        }
    }
}