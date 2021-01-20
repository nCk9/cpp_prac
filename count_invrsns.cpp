// #include<iostream>
// using namespace std;
// int ct=0;
// int merge(int *arr, int mid, int low, int high)
// {
//     int n1 = mid-low+1;
//     int n2 = high-mid;
//     int aux_1[n1], aux_2[n2];
//     for(int i=0; i<n1; i++)
//         aux_1[i] = arr[i+low];
        
//     for(int i=0; i<n2; i++)
//         aux_2[i] = arr[i+1+mid];
    
//     int i=0, j=0; int k=low; int g=low;
//     while(i < n1  && j < n2)
//     {
//         if(aux_1[i] <= aux_2[j])
//            {
//                 arr[k++] = aux_1[i++];
//                 g++;
//            }
//         else
//            { 
//                ct += mid-g+1 ;
//                arr[k++] = aux_2[j++]; 
//            } 
//     }
    
//     while(i < n1)
//         arr[k++] = aux_1[i++];
        
//     while(j < n2)
//         arr[k++] = aux_2[j++];
// }

// int merge_sort(int *arr, int low, int high)
// {
//     if(low < high)
//     {
//         int mid = (low+high)/2;
        
//         merge_sort(arr, low, mid);
//         merge_sort(arr, mid+1, high);
//         merge(arr, mid, low, high);
//     }
// }


// int main()
// {
//     int sz;
//     cin >> sz;
//     int arr[sz];
//     for(int i=0; i<sz; i++)
//         cin >> arr[i];
        
//     merge_sort(arr, 0, sz-1);
//     for(int i=0; i<sz; i++)
//         cout << arr[i] << " ";
//     cout << "\nNumber of inversions is : " << ct << "\n";
// }


#include<iostream>
using namespace std;
int ct=0; int sct=0;


int merge(int *arr, int mid, int low, int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    int aux_1[n1], aux_2[n2];
    for(int i=0; i<n1; i++)
        aux_1[i] = arr[i+low];
        
    for(int i=0; i<n2; i++)
        aux_2[i] = arr[i+1+mid];
    
    int i=0, j=0; int k=low; int g = low; 
    while(i < n1  && j < n2)
    {
        
        
        if(aux_1[i] <= aux_2[j])
           { 
                arr[k++] = aux_1[i++]; 
                g++;
           }
        else
           {
               ct += mid-g+1 ;  // for simple inversions i.e. a[i]  > a[j] where i<j....
               arr[k++] = aux_2[j++]; 
           }
    }
    
    int l = low; int p=0, q=0;   //for strong inversions i.e. a[i] > 2*a[j] where i<j...
    while(p < n2  && q < n1)
        if(aux_1[q] > 2*aux_2[p])
            {sct += mid - l + 1;
             p++;}
        else {l++; q++;}
    
    while(i < n1)
        arr[k++] = aux_1[i++];
        
    while(j < n2)
        arr[k++] = aux_2[j++];
    
}

int merge_sort(int *arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, mid, low, high);
    }
}


int main()
{
    int sz;
    cin >> sz;
    int arr[sz];
    for(int i=0; i<sz; i++)
        cin >> arr[i];
        
    merge_sort(arr, 0, sz-1);
    for(int i=0; i<sz; i++)
        cout << arr[i] << " ";
    cout << "\nNumber of inversions is: " << ct << "\n";
    cout << "Number of strong inversions is: " << sct << "\n";
}
