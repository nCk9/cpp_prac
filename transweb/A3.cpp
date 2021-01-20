#include "collect.h"
#include "Knapsack.h"
#include <unordered_map>
using namespace std;


int main(int argc, char *argv[])
{
    if(argc != 3)    //check if number of arguments is 3(here).
        cout << "Error" << "\n";
    else 
    {
        string str;
        int seed = stoi(argv[argc-1]); // seed to generate values
        int size = stoi(argv[argc-2]); // total knapsack size 
        Knapsack myBag(size);  // instance of knapsack
        unordered_map<char, int> ump;   //to store count of each object in knapsack 
        if(size <= 0  ||  seed <= 0)   //check if size and seed is positive
            cout << "Invalid size or seed.\n";
        else
        {
            int add_size=0; // this size keeps track of added items.
            int curr_size = 0; //  this size is mainly used for the purpose of terminating the while loop
            while(curr_size <= size) 
            {
                char ch = generate(seed);
                if(ch > 71  || ch < 65)   //check if generated character is between A and G.
                    {
                        cout << "Inavlid object trying to insert in knapsack.\n";
                        break;
                    } 
                else 
                {
                    switch(ch)
                    {
                        case 'A': 
                        {A obj;
                        curr_size += myBag.addObj<A>(obj);  
                        if(curr_size <= size)      // if curr_size > size, then the loop will get terminated.
                            {
                                ump['A']++;
                                str += myBag.getSack();  //Adding characters corresponding to the objects added in the knapsack
                                add_size = curr_size;    //Exact occupied size of the knapsack.
                            }
                        break;}
                        
                        case 'B':
                        {B obj;
                        curr_size += myBag.addObj<B>(obj);
                        if(curr_size <= size)
                            {
                                ump['B']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}

                        case 'C':
                        {C obj;
                        curr_size += myBag.addObj<C>(obj);
                        if(curr_size <= size)
                            {
                                ump['C']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}

                        case 'D':
                        {D obj;
                        curr_size += myBag.addObj<D>(obj);
                        if(curr_size <= size)
                            {
                                ump['D']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}

                        case 'E':
                        {E obj;
                        curr_size += myBag.addObj<E>(obj);
                        if(curr_size <= size)
                            {
                                ump['E']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}

                        case 'F':
                        {F obj;
                        curr_size += myBag.addObj<F>(obj);
                        if(curr_size <= size)
                            {
                                ump['F']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}

                        case 'G':
                        {G obj;
                        curr_size += myBag.addObj<G>(obj);
                        if(curr_size <= size)
                            {
                                ump['G']++;
                                str += myBag.getSack();
                                add_size = curr_size;
                            }
                        break;}
                    }
                }
            }
            cout << "Knapsack size : " << size << "\n";
            cout << "Added object size: "<< add_size << "\n";
        } 
        cout << str << "\n";    //printing out the stream of characters inside the knapsack.
        for(char i='A'; i<='G'; i++)
            if(ump[i] != 0)
            {
                switch(i)
                {
                    case 'A':
                    {
                         cout << "A: " << sizeof(A) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'B':
                    {
                         cout << "B: " << sizeof(B) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'C':
                    {
                         cout << "C: " << sizeof(C) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'D':
                    {
                         cout << "D: " << sizeof(D) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'E':
                    {
                         cout << "E: " << sizeof(E) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'F':
                    {
                         cout << "F: " << sizeof(F) << ", " << ump[i] << "\n";
                         break;
                    }

                    case 'G':
                    {
                         cout << "G: " << sizeof(G) << ", " << ump[i] << "\n";
                         break;
                    }
                }
            }
        
    }
    
}