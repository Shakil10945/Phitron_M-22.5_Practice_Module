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
void insertAtHead(Node* &head, int val);
void inserAtTail(Node* &head, int val);
void display(Node* head);
void removingDuplicates(Node* &head);
void rotateClock(Node* &head, int x);






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
    int x;
    cin>>x;
    rotateClock(head,x);

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

void insertAtHead(Node* &head, int val)
{
    Node* newNode=new Node(val);
    newNode->Next=head;
    head=newNode;
}

void rotateClock(Node* &head, int x)
{
    Node* temp=head;
    int count=1;
    while(count!=x)
    {
        temp=temp->Next;
        count++;
    }

    while(temp->Next->Next!=NULL)
    {
        Node* temp2=temp->Next;
        while(temp2->Next->Next!=NULL)
        {
            temp2=temp2->Next;
        }
        insertAtHead(head,temp2->Next->value);
        Node* delNode=temp2->Next;
        temp2->Next=NULL;
        delete delNode;
    }
    insertAtHead(head,temp->Next->value);
    Node *delNode=temp->Next;
    temp->Next=NULL;
    delete delNode;

}
/*
void rotateClock(Node* &head, int x)
{
    Node* temp=head;
    int count=1;
    while(count!=x)
    {
        temp=temp->Next;
        count++;
    }

    while(temp->Next->Next!=NULL)
    {
        Node* temp2=temp->Next;
        while(temp2->Next->Next!=NULL)
        {
            temp2=temp2->Next;
        }
        insertAtHead(head,temp2->Next->value);
        Node* delNode=temp2->Next;
        temp2->Next=NULL;
        delete delNode;
    }
    insertAtHead(head,temp->Next->value);
    Node *delNode=temp->Next;
    temp->Next=NULL;
    delete delNode;
}
*/
