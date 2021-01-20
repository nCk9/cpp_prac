#include<iostream>
#include<unordered_map>
using namespace std;

typedef class node{
    public:
    int data;
    node *left;
    node *right;
}tree;

unordered_map<int, bool> vis;
tree *root = NULL;

void inorder(tree *node)
{
    if(node != NULL)
    {
        inorder(node -> left);
        cout << node -> data << "\n";
        inorder(node -> right);
    }
}

int dfs(tree *temp)
{

    if(temp == NULL)
       return 0;
        
    else
    {
        cout << temp -> data << " ";
        if(!vis[temp -> data])
        {
            dfs(temp -> left);
            dfs(temp -> right);
            vis[temp -> data] = true;
        }
    }
    
}

int bfs(tree *temp)
{

}

void insert(tree *newnd, tree* temp_root)
{
    if(temp_root -> data > newnd -> data)
        {
            if(temp_root -> left == NULL)
                temp_root -> left = newnd;
            else insert(newnd, temp_root -> left);
        }
    else
    {
        if(temp_root -> right == NULL)
            temp_root -> right = newnd;
        else insert(newnd, temp_root -> right);
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
            // case 4 : bfs(root);
            //     break;
            case 5 : exit();
        }
    }
}