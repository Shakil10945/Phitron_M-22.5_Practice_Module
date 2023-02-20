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

Node* insertAtTail(Node* &head,Node* &tail,int val);
void display(Node* head);
void reverseKthTermAntiClockwise(Node* &head,int k);

Node* insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return tail;
    }
    tail->Next=newNode;
    return tail->Next;
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
        cout<<temp->value;
        if(temp->Next!=NULL)
        {
            cout<< "->";
        }
        temp=temp->Next;
    }
    cout<<endl;
}

void reverseKthTermAntiClockwise(Node* &head,int k)
{
    int count=1;
    Node* temp=head;
    while(count!=k)
    {
        temp=temp->Next;
        count++;
    }

    Node* kthTerm=temp;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=head;
    head=kthTerm->Next;
    kthTerm->Next=NULL;

    Node *cur=head;
    Node* prev=NULL;
    Node* next=head->Next;

    while(true)
    {
        cur->Next=prev;
        prev=cur;
        cur=next;
        if(cur==NULL)   break;
        next=next->Next;
    }
    head=prev;
}


int main()
{
    Node* head=NULL;
    Node* tail;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        tail=insertAtTail(head,tail,val);
    }
    int k;
    cin>>k;
    reverseKthTermAntiClockwise(head,k);


    display(head);







    return 0;
}
