#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> *adj, int s, int level[], bool vis[])
{
    queue<int> qu;
    qu.push(s);
    vis[s] = true;
    level[s] = 0;
    
    while(!qu.empty())
    {
        s = qu.front();
        qu.pop();
        
        for(auto x : adj[s])
            if(!vis[x])
            {
                qu.push(x);
                vis[x] = true;
                level[x] = level[s] + 1;
            }
    }
    
}


int main()
{
    int nodes;
    cin >> nodes;
    vector<int> adj[nodes];
    int level[nodes]; bool vis[nodes];
    int src = 0;
    for(int i=0; i<nodes; i++)
    {
        int a;
        cin >> a;
        if(a == -1)
            src = i;
        else
        {
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
        level[i] = 0;
        vis[i] = false;
    }
    
    bfs(adj, src, level, vis);
    // cout << "\n";
    int max_height = 0;
    for(int i=0; i<nodes; i++)
        // cout << i << " " << level[i] << "\n";
        max_height = max(max_height, level[i]);
    // cout << "Height of the tree is : " << max_height + 1 << "\n";
    cout << max_height+1 << "\n";
}