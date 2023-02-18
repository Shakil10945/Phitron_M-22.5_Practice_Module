#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char letter;
    Node *Next;

    Node(char ch)
    {
        letter=ch;
        Next=NULL;
    }
};

void insertAtTail(Node* &head,char ch);
void display(Node* head);
void checkPalindrome(Node* &head);
Node* reverseLinkedList(Node* &head);
bool exactcheck(Node* &temp,Node* temp2);

void checkPalindrome(Node* &head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->Next!=NULL)
    {
        fast=fast->Next->Next;
        slow=slow->Next;
    }

    Node* temp=head;
    Node* temp2;
    temp2=reverseLinkedList(slow);

    bool exact;
    exact=exactcheck(temp,temp2);

    if(exact==true)
    {
        cout<< "Yes"<<endl;
    }
    else
    {
        cout<< "No"<<endl;
    }

    Node* now=reverseLinkedList(temp2);




}







int main()
{
    Node *head=NULL;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>ch;
        insertAtTail(head,ch);
    }

    checkPalindrome(head);



    display(head);



    return 0;
}




void insertAtTail(Node* &head,char ch)
{
    Node *newNode=new Node(ch);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;
}


void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<< temp->letter;
        temp=temp->Next;
    }
}

Node* reverseLinkedList(Node* &head)
{
    Node* prev=NULL;
    Node* current=head;
    Node* next=current->Next;

    while(true)
    {
        current->Next=prev;
        prev=current;
        current=next;
        if(current==NULL)
        {
            break;
        }
        next=next->Next;
    }
    return prev;
}


bool exactcheck(Node* &temp,Node* temp2)
{
    while(temp->Next!=NULL)
    {
        if(temp->letter!=temp2->letter)
        {
            return false;
        }
        temp=temp->Next;
        temp2=temp2->Next;
    }
    return true;
}
