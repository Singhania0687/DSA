/*
 Building a LinkedList Class in order to facilitate addition of elemets at front ,back ,middle and at any place.
    Also facilitating deletion of elements from front , back , middle and any place.
    Also facilitating searching of elements in the linked list.
    Also facilitating displaying the elements of the linked list.
    Functionality to reverse the array ,finding the mid element using slow and fast pointer


*/
# include<iostream>
using namespace std;
class Node{
    public:

    // class variable
    int data;
    Node* next;

    // default constructor
    Node(){
        data=0;
        next=NULL;
    }

    // parameterized constructor
    Node(int val){
        data=val;
        next=NULL;
    }
    
    // adding elements at the beginning
    void addAtStart(Node* &head,int val){
        if(head==NULL)
        {
            head=new Node(val);
            return ;
        }
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        return;
    }

    // displaying the Nodes 
    void display(Node* head){
        Node* temp=head;
        while(temp){
            if(temp->next)
            cout<<temp->data<<" -> ";
            else
            cout<<temp->data;
            temp=temp->next;

        }
        cout<<endl;
    }
};