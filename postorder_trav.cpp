// Post-order traversal of a tree(iterative method using two stacks)..
#include <bits/stdc++.h> 
using namespace std;


struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
 
struct Node *newNode(int item) 
{ 
    struct Node *temp =  new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
struct Node* insert(struct Node* Node_1, int key) 
{ 
    if (Node_1 == NULL) return newNode(key); 
  
      if (key < Node_1 -> key) 
        Node_1 -> left  = insert(Node_1 -> left, key); 
    else if (key > Node_1 -> key) 
        Node_1 -> right = insert(Node_1 -> right, key);    
  
    return Node_1; 
}   
void postOrderIterative(Node* root) 
{ 
    if (root == NULL)                              // solving for the exapmle below: 
        return; 
                                                   //           40
    stack<Node *> s1, s2;                          //         /    \
                                                   //       20      50   
    s1.push(root);                                 //      /  \    /  \
                                                   //    12    32 46   55
   Node* Node_1;
    while (!s1.empty()) 
    {  
        Node_1 = s1.top(); 
        s1.pop(); 
        s2.push(Node_1); 

        if (Node_1 -> left) 
            s1.push(Node_1 -> left); 
        if (Node_1 -> right) 
            s1.push(Node_1 -> right); 
    } 
  
    while (!s2.empty()) { 
        Node_1 = s2.top(); 
        s2.pop(); 
        cout << Node_1 -> key << " "; 
    } 
} 

int main() 
{ 
    cout << "Enter number of Nodes in the tree : ";
    int nds; cin >> nds;
    struct Node *root = NULL;
    cout << "Enter the nodes : ";
    for(int i=1; i<=nds; i++)
      {
          int val; cin >> val;
        if( i == 1)
            root = insert(root, val);
        else insert(root, val);
      }     
   cout << "Post-order traversal is as follows : ";
   postOrderIterative(root);  
   
    return 0; 
} 