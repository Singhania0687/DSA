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

    // adding element at the end
    void addAtEnd(Node* &head,int val){
        if(head==NULL)
        {
            head=new Node(val);
            return ;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new Node(val);
        return ;
    }

    // delete at the beginning
    void deleteAtStart(Node* &head){
        if(head==NULL)
          return ;
          Node* t=head;
          head=head->next;
          delete t;
          return ;
    }
    // delete at the end
    void deleteAtEnd(Node* &head){
        if(head==NULL)
          return ;
          if(!head->next)
          {
            delete head;
            head=NULL;
            return ;
          }
          Node* temp=head;
          while(temp->next && temp->next->next)
            temp=temp->next;
            Node *t=temp->next;
            temp->next=NULL;
            delete t;
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
    // mid element of the list
    Node* midElement(Node* head){
        if(head==NULL)
        return NULL;
        Node* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    // detect if there is a cycle
    bool hasAcycle(Node* head){
        if(head==NULL)
          return false;
          Node* slow=head,*fast=head;
          while(fast && fast->next)
           {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
              return true;
           }
           return false;
    }
    // count total no. of nodes,sum,avg and can do various mathematical calculation
    vector<float> mathematicalCalculations(Node* head){
        //  displaying in format of count ,sum ,avg
        if(head==NULL)
           return {};
           float sum,avg,cnt=0.0;
           Node* temp=head;
           while(temp){
            ++cnt;
            sum+=temp->data;
            temp=temp->next;
           }
           avg=sum/cnt;
           return {cnt,sum,avg};
    }
};

void main(){


}