//  Code to generate all possible comobinations of a string.

#include <iostream>
#include<string> 
using namespace std; 

void swap_ch(char *x, char *y)   //function to swap two characters.
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
  
void all_permutations(string str, int low, int high)  //generator function.
{    
    if (low == high)  
        cout<< str << " ";  
    else
        for (int i = low; i <= high; i++)  
        {    
            swap_ch(&str[low], &str[i]);  
    
            all_permutations(str, low+1, high);  

            swap_ch(&str[low], &str[i]);  
        }  
      
}  
  
int main()  
{  
    string init_str = "123";  
    all_permutations(init_str, 0, init_str.size()-1);  
      

    // string init_str;                                   // if user friendly program is required...
    // cin >> init_str;
    // all_permutations(init_str, 0, init_str.size()-1);
    return 0;
}