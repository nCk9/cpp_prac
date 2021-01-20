#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int, int>> adj[nodes];
    unordered_map<int, int> trav_set;
    for(int i=0; i<edges; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
        trav_set[a] = INT_MAX;
        trav_set[b] = INT_MAX;
    }
    vector<bool> vis(nodes, false);
    cout << "Enter the source vertex for dijkstra's algorithm: ";
    int src; cin >> src;
    vector<pair<int, int>> ans;
    trav_set[src] = 0;    //trav_set contains key as node no. and value as its distance from 0(source)
    int dst_curr_src = 0;
    while(!trav_set.empty())
    {
        int nd=0, dst=INT_MAX;
        for(auto x: trav_set)
            {
                dst = min(dst, x.second);
                if(dst == x.second)
                    nd = x.first;
            }
        dst_curr_src += trav_set[nd];
        trav_set.erase(nd);
        vis[nd] = true;
        
        ans.push_back(make_pair(nd, dst));
        
        for(auto x: adj[nd])
            if(!vis[x.first])
                trav_set[x.first] = min(trav_set[x.first], x.second+dst_curr_src);
    }
    cout << "Shortest distances of the nodes from given source is(node, distance): \n";
    for(auto x : ans)
        cout << x.first << " " << x.second << "\n";
}
