#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* Next;

    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};
void inserAtTail(Node* &head, int val);
void display(Node* head);
void removingDuplicates(Node* &head);




int main()
{
    Node* head=NULL;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        inserAtTail(head, val);
    }
    removingDuplicates(head);
    display(head);



    return 0;
}

void inserAtTail(Node* &head, int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node *temp=head;

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;
}
void display(Node* head)
{
    if(head==NULL)
    {
        cout<< "Your Linked List is empty"<<endl;
        return;
    }
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<< temp->value;
        if(temp->Next!=NULL)
        {
            cout<< "->";
        }
        temp=temp->Next;
    }
}

void removingDuplicates(Node* &head)
{
    Node* temp=head;
    Node* temp2=head->Next;

    while(temp2!=NULL)
    {
        if(temp->value!=temp2->value)
        {
            temp->Next=temp2;
            temp=temp->Next;
        }
        temp2=temp2->Next;
    }
    temp->Next=temp2;
}

