#include<iostream>
#include<bits/stdc++.h>
using namespace std;  //dfs and bfs iterative implementation

class Graph
{
    int V;
    list<int> *adj;
    public : 
    Graph(int V);
    void add_edge(int v, int w);
    void DFS(int s);
    void BFS(int s);
};

Graph :: Graph(int V)
{
    this -> V = V;
    adj = new list<int>[V];
}

void Graph :: add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: DFS(int s)
{
    vector<bool> vis(V, false);
    stack<int> stack;
    stack.push(s);

    while(!stack.empty())
    {
        s = stack.top();
        stack.pop();

        if(!vis[s])
        {
            cout << s << " ";
            vis[s] = true;
        }

        for(auto i = adj[s].begin(); i!=adj[s].end(); i++)
        if(!vis[*i])
            stack.push(*i);
    }
}

void Graph :: BFS(int s)
{
    vector<bool> vis(V, false);
    queue<int> queue;
    queue.push(s);

    while(!queue.empty())
    {
        s = queue.front();
        queue.pop();
        cout << s << " ";
        // if(!vis[s])
        // {
        //     cout << s << " ";
            vis[s] = true;
        // }

        for(auto i = adj[s].begin(); i!=adj[s].end(); i++)
        if(!vis[*i])
           {
               queue.push(*i);
               vis[*i] = true;
           } 
    }
}

int main()
{
    int sz;
    cout << "Enter the number of nodes in the graph :";
    cin >> sz; 
    Graph g(sz);
    for(int i=0; i<sz; i++)
        {
            int a, b;
            cin >> a >> b;
            g.add_edge(a, b);
            g.add_edge(b, a);
        }
        cout << "Enter the source node : ";
        int req; 
        cin >> req;
        cout << "DFS is as follows : ";
        g.DFS(req);
        cout << "\nBFS is as follows : ";
        g.BFS(req);
        return 0;
}