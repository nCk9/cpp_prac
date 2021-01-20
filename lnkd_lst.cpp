#include<iostream>
using namespace std;

typedef class node{
    public : 
    int data;
    node *next;
} faang;

faang *head1 = NULL;
faang *head2 = NULL;

void Insert()
{
    faang *nwnd1 = NULL;
    nwnd1 = new(faang);
    cout << "Enter element : ";
    cin >> nwnd1 -> data;
    nwnd1 -> next = NULL;

    faang *nwnd2 = NULL;
    nwnd2 = new(faang);
    nwnd2 -> data = nwnd1 -> data;
    nwnd2 -> next = NULL;
    if(head2 == NULL)
        head2 = nwnd2;
     else 
     {
        nwnd2 -> next = head2;
        head2 = nwnd2;
     }

    if(head1 == NULL)
        head1 = nwnd1;    
    else 
    {
        faang *temp = head1; 
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = nwnd1;
    }
    
}

void Delete()
{
    faang *prev = NULL;
    faang *temp = head1;
    while(temp -> next != NULL)
       {
           prev = temp;
           temp = temp -> next;
       }
    prev -> next = NULL;
    delete temp;
    
}

void Display()
{

    faang *temp = head1;
    while(temp -> next != NULL)
       {
           cout << temp -> data << " -> ";
           temp = temp -> next;
       } 
       cout << temp -> data  << " -> NULL"<< "\n"; 

    faang *temp2 = head2;
    while(temp2 -> next != NULL)
       {
           cout << temp2 -> data << " -> ";
           temp2 = temp2 -> next;
       } 
       cout << temp2 -> data  << " -> NULL"<< "\n"; 

    
}

int main()
{
    cout << "Linked list implementation." << "\n";
    int k;

    while(k != 4)
    {
        cout << "Press 1 to insert element at the end in the linked list." << "\n";
        cout << "Press 2 to delete element from the end in the linked list." << "\n";
        cout << "Press 3 to display elements in the linked list." << "\n";
        cout << "Press 4 to exit." << "\n";
        cin >> k;
        switch(k)
        {
            case 1: Insert();
            break;
            case 2: Delete();
            break;
            case 3: Display();
            break;
            case 4: break;
        }
    }
}