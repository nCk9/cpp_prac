#include<bits/stdc++.h>
using namespace std;

typedef class node{
    public:
    int data;
    node *left;
    node *right;
}tree;

tree *root = NULL;

void inorder(tree *node)
{
    if(node != NULL)
    {
        inorder(node -> left);
        cout << node -> data << " ";
        inorder(node -> right);
    }
}

int dfs(tree *temp)
{

    if(temp == NULL)
       return 0;
        
    else
    {
        // cout << temp -> data << " ";   
        // if(!vis[temp -> data])   //recursive
        // {
        //     dfs(temp -> left);
        //     dfs(temp -> right);
        //     vis[temp -> data] = true;
        // }
        unordered_map<int, bool> vis;
        stack<tree*> stk;
        stk.push(temp);

        while(!stk.empty())    //iterative
        {
            tree* x = stk.top();
            stk.pop();
            if(!vis[x->data])
                cout << x -> data << " ", vis[x->data] = true;
            if(x -> left != NULL)
                stk.push(x -> left);
            if(x -> right != NULL)
                stk.push(x -> right);
        }
    }
    
}

int bfs(tree *temp)
{
    if(temp != NULL)
    {   
        unordered_map<int, bool> vis;
        queue<tree*> qu;
        qu.push(temp);
        while(!qu.empty())
        {
            tree* x = qu.front();
            qu.pop();
            if(!vis[x -> data])
                cout << x -> data << " ", vis[x -> data] = true;

            if(x -> left != NULL)
                qu.push(x -> left);

            if(x -> right != NULL)
                qu.push(x -> right);
        }
    }
}

void insert(tree *newnd, tree* temp_root)
{
    if(temp_root -> data > newnd -> data)
        {
            if(temp_root -> left == NULL)
                temp_root -> left = newnd;
            else 
                insert(newnd, temp_root -> left);
        }
    else
    {
        if(temp_root -> right == NULL)
            temp_root -> right = newnd;
        else 
            insert(newnd, temp_root -> right);
    }
    
}

void util_insert()
{
    int ele;
    cout << "Enter the element to insert in the tree: ";
    cin >> ele;
    tree *newnd = new(tree);
    newnd -> data = ele;
    newnd -> left = newnd -> right = NULL;

    if(root == NULL)
        root = newnd;
    else
        insert(newnd, root);

}

int main()
{
    cout << "Binary Serch Tree traversals." << "\n";
    int k=0;
    while(k != 5)
    {
        cout << "Press 1 for insertion." << "\n";
        cout << "Press 2 for inorder travesal." << "\n";
        cout << "Press 3 for dfs travesal." << "\n";
        cout << "Press 4 to bfs traversal." << "\n";
        cout << "Press 5 to exit." << "\n";
        cin >> k;
        switch(k)
        {
            case 1 : util_insert();
                break;
            case 2: inorder(root);
                break;
            case 3 : dfs(root);
                break;
            case 4 : bfs(root);
                break;
            case 5 : exit(0);
        }
    }
}
