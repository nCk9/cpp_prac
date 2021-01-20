#include<bits/stdc++.h>
using namespace std;
int ct=0;
void gene_sbsts(vector<vector<int>>& res, vector<int> subsets, int idx, int *arr, int sz)
{
    res.push_back(subsets);
    for(int i=idx; i<sz; i++)
    {
        subsets.push_back(arr[i]);
        gene_sbsts(res, subsets, i+1, arr, sz);
        ct++;
        subsets.pop_back();
    }
}


int main()//generating all subsets of a set
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n ;i++)
        cin >> arr[i];
        
    vector<vector<int>> res;
    vector<int> subsets;
    
    gene_sbsts(res, subsets, 0, arr, n);
    
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    
    cout << ct + 1 << "\n";
}