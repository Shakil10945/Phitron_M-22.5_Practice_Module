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
void cutTheLLL(Node* &head);

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
void cutTheLLL(Node* &head)
{
    Node* x=head;
    int grandtotal=0;
    Node* temp=head;


    while(temp!=NULL)
    {
        int sum=0;
        Node* temp2=temp;
        while(temp2!=NULL)
        {
            sum+=temp2->value;
            if(temp2->Next==NULL && sum!=0)
            {
                if(grandtotal==0)
                {
                    head=temp;
                    x=temp;
                }
                else
                {
                    x->Next=temp;
                    x=x->Next;
                }
                grandtotal++;
            }
            if(sum==0)
            {
                temp=temp2;
                break;
            }
            temp2=temp2->Next;

        }
        temp=temp->Next;
    }
    x->Next=NULL;
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
    cutTheLLL(head);


    display(head);







    return 0;
}
