#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    Node*Next;
    Node*Prev;
};
void InsertAtBeginning(Node*&head ,int Value)
{
    /*
        1-Create a new node with the desired value.
        2-set the next pointer of the new node to the Current head of the list.
        3-set the previous pointer of the Current head to the new node.
        4-set the new node as the new head of the list.
    */
    Node*newNode=new Node();
    newNode->Next=head;
    newNode->Value=Value;
    newNode->Prev=NULL;

    if (head!=NULL) {
        head->Prev=newNode;
    }
    head=newNode;
    
}
void PrintNodeDetails(Node* head)
{
    if (head->Prev!=NULL)
        cout<<head->Prev->Value;
    else
        cout<<"NULL";
    
    cout<<" <--> "<<head->Value<<" <--> ";
    if (head->Next!=NULL)
        cout<<head->Next->Value<<"\n";
    else
        cout<<"NULL";
}
//Print the Linked List 
void PrintLinkedDetails(Node*head)
{
    cout<<"\n\n";
    while (head!=NULL)
    {
        PrintNodeDetails(head);
        head=head->Next;
    }
    
}
//Print the Linked List
void PrintList(Node*head)
{
    cout<<"NULL <--> ";
    while (head!=NULL)
    {
        cout<<head->Value<<" <--> ";
        head=head->Next;
    }
    cout<<"NULL";
    
}
void InsertAfter(Node*&Current,int Value)
{
    Node*NewNode=new Node();

    NewNode->Prev=Current;
    NewNode->Next=Current->Next;
    NewNode->Value=Value;

    if (Current->Next==NULL)
    {
        Current->Next->Prev=NewNode;
    }
    Current->Next=NewNode;
}
void InsertAtEnd(Node*head,int Value)
{
    Node* NewNode=new Node();
    NewNode->Value=Value;
    NewNode->Next=NULL;
    if (head==NULL) {
        NewNode->Prev=NULL;
        head=NewNode;
    }
    else {
        Node*Current=head;
        while (Current->Next!=NULL) {
            Current=Current->Next;
        }
        Current->Next=NewNode;
        Current->Prev=Current;
    }
}
void DeleteNode(Node*& head,Node*& NodeToDelete)
{
    if (head==NULL||NodeToDelete==NULL) {
        return;
    }
    if (head==NodeToDelete) {
        head=NodeToDelete->Next;
    }
    if (NodeToDelete->Next!=NULL) {
        NodeToDelete->Next->Prev=NodeToDelete->Prev;
    }
    if (NodeToDelete->Prev!=NULL) {
        NodeToDelete->Prev->Next=NodeToDelete->Next;
    }
    delete NodeToDelete;

}
Node *Find(Node*head,int Value)
{
    while (head!=NULL)
    {
        if(head->Value==Value)
        return head;

        head=head->Next;
    }

    return NULL;
    
}
void DeleteLastNode(Node*head)
{
    if (head==NULL)
    {
        return;
    }
    if (head->Next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    Node* Current=head;
    while (Current->Next->Next!=NULL)
    {
        Current=Current->Next;
    }
    Node*temp=Current->Next;
    Current->Next=NULL;
    delete temp;
    
}
void DeleteFirstNode(Node*&head)
{
    if (head==NULL)
    {
        return;
    }
    Node*temp=new Node();
    head=head->Next;
    if (head!=NULL)
    {
        head->Prev=NULL;
    }
    delete temp;
    
    
}
int main()
{

    Node*head=NULL;

    InsertAtBeginning(head,10);
    InsertAtBeginning(head,20);
    InsertAtBeginning(head,40);
    InsertAtBeginning(head,50);

    //PrintLinkedDetails(head);
    DeleteFirstNode(head);
    DeleteLastNode(head);
    
    PrintList(head);

    
  

}