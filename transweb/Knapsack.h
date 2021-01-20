#include<iostream>
#include<string.h>
#include "collect.h"

class Knapsack
{
    private:
     int cu_size=0;
     char sack; 
     int s; 
    public:
   
    Knapsack(int size)
    { s = size;  };
    
    template <class T>    //template to intake different objects
    int addObj(T obj) 
   { 
        int size_of_obj = sizeof(obj);
        if (cu_size <= s)
        {   
            cu_size += size_of_obj;
            sack = obj.getName();    // using getName() method to get the corresponding character to the object
        }
            return size_of_obj;
    }
    char getSack()
    {
        return sack;   //returns character corresponding to the object inserted in the knapsack.
    } 
};
