#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter distance between the cities : "; 
    int d; cin >> d;  
    cout << "Enter max diatance car can travel when tank full : ";
    int mx_dst; cin >> mx_dst;
    cout << "Enter no. of fuel stops : ";
    int stp; cin >> stp;
    vector<int> vec(stp+2 ,0);
    vec[0] = 0;
    vec[stp+1] = d;
    int curr_dist = mx_dst;
    cout << "Enter distances at which fuel stops are present : ";
    for(int i=1; i<stp+1; i++)
      cin >> vec[i];
    int count=0;
      for(int i=1; i<stp+1; i++)
      if(mx_dst - vec[i] < 0)
      {cout << "Car cannot reach the destination point." << "\n";  return 0;}
      else 
      {
          if(mx_dst - vec[i+1] <= 0)
          {
              count++;
              mx_dst = vec[i] + curr_dist;
          }
    }

     cout << "No. fo times to we need to refill the tank is : " << count << "\n"; 
      
}