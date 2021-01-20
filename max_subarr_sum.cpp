// #include<iostream>  //O(n^3) solution...
// using namespace std;

// int main()
// {
//     int sz;cin >> sz;
//     int arr[sz];
//     for(int i=0; i<sz; i++)
//     cin >> arr[i];
//     int sas=1; int max_sum=0;
//     while(sas < sz)
//     {
//         for(int i=0; i<sz ;i++)
//         {
//             int sum=0, ct=0;
//             while(ct < sas)
//             {   if(i+ct < sz)
//                     sum += arr[i+ct];
//                 ct++; 
//             }

//             if(max_sum < sum)
//             max_sum = sum;
//         }
//         sas++;
//     }

//     cout << max_sum << "\n";
// }

// #include <bits/stdc++.h> 
// using namespace std; 
  
// bool isPerfectSquare(long double x) 
// {   
//   long double sr = sqrt(x); 
  
//   // If square root is an integer 
//   return ((sr - floor(sr)) == 0); 
// } 
  

// #include<iostream>   //iterative solution ...stll O(n^2)
// using namespace std;

// int main()
// {
//     int sz;cin >> sz;
//     int arr[sz];
//     for(int i=0; i<sz; i++)
//         cin >> arr[i];
//     int max_sum=0;
//     for(int i=0; i<sz; i++)
//      {
//          int sum = 0;
//          for(int j=i; j>=0; j--)
//           {
//              sum += arr[j];
//             max_sum = max(max_sum, sum);
//           }   
//      }
//      cout << "Max. subarray sum is : " << max_sum << "\n";
// }

// #include<iostream>  //recursive solution...still O(n^2)
// using namespace std;
// int max_sum;

// int rec(int *arr, int sz)
// {
//     if(sz == 1)
//         return max(max_sum, arr[sz-1]);
//     else 
//     {
//         return max(rec(arr, sz-1) + arr[sz-1], arr[sz-1]);
//     }

// }

// int main()
// {
//     int sz;
//     cin >> sz;
//     int arr[sz];
//     max_sum=0;
//     for(int i=0; i<sz; i++)
//         cin >> arr[i];
//     for(int i=1; i<=sz; i++)
//         cout << rec(arr, i) << " ";
// }

#include<iostream>   //divide & conquer solution...O(nlogn)
using namespace std;

int cross_sum_subarr(int *arr, int low, int mid, int high)
{
  int left_cross_sum = -88;
  int sum=0; 
  int i=mid;
  while(sum >= left_cross_sum  &&  i>=0)
  {
    sum += arr[i--];
    left_cross_sum = max(sum, left_cross_sum);
  }
  int right_cross_sum=-88; sum=0; i=mid+1;
  while(sum >= right_cross_sum  &&  i<=high)
  {
    sum += arr[i++];
    right_cross_sum = max(right_cross_sum, sum);
  }

  return (right_cross_sum + left_cross_sum);
}

int max_sum(int arr[], int low, int high)
{
  if(high == low)
    return arr[low];
  else
  {
    int mid = (low+high)/2;
    int left_sum = max_sum(arr, low, mid);
    int right_sum = max_sum(arr, mid+1, high);

    int cross_sum = cross_sum_subarr(arr, low, mid, high);

    if(right_sum > left_sum  && right_sum > cross_sum)
      return right_sum;
    else if(left_sum > right_sum  && left_sum > cross_sum)
      return left_sum;
    else return cross_sum;
  }

}

int main()
{
  int sz;
  cin >> sz;
  int arr[sz];
  for(int i=0; i<sz; i++)
    cin >> arr[i];

  cout << max_sum(arr, 0, sz-1) << "\n"; 
  
}



// #include<iostream>  //iterative dp solution...O(n)
// #include<vector>
// using namespace std;

// int main()
// {
//     int sz;
//     cin >> sz;
//     int maxx = 0;
//     int arr[sz];
//     for(int i=0; i<sz; i++)
//         cin >> arr[i];
//     vector<int> dp(sz);
//     dp[0] = max(dp[0], arr[0]);
//     for(int i=1; i<sz; i++)
//       {
//         dp[i] = max(dp[i-1] + arr[i], arr[i]);
//         maxx = max(maxx, dp[i]);
//       }  

//     cout << maxx << "\n"; 
// }