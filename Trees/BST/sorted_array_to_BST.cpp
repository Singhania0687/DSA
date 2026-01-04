
# include<iostream>
# include<vector>
using namespace std;
class ListNode{
      public:
    int val;
    ListNode* next;
    ListNode(){
        val=0;
        next=NULL;
    }
    ListNode(int data){
        val=data;
        next=NULL;
    }

};
class Node{
    public:
    int val;
    Node* left,*right;
    Node(){
        val=0;
        right=left=NULL;
    }
    Node(int data){
        val=data;
        left=right=NULL;
    }
};
// sorted LinkedList to BST
Node* BSTLinkedList(ListNode* &head){
    if(head==NULL)
     return NULL;
     if(head->next==NULL)
     return new Node(head->val);
     ListNode* slow=head,*fast=head,*prev=NULL;
     while(fast->next && fast->next->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
     }
     Node* root=new Node(head->val);
     prev->next=NULL;
     root->left=BSTLinkedList(head);
     slow=slow->next;
     root->right=BSTLinkedList(slow);
     return root;
}



// sorted array to BST
Node* BST(vector<int>&nums,int left,int right){
    if(left>right)
    return NULL;
    int p=left+(right-left)/2;
    Node* root=new Node(nums[p]);
    root->left=BST(nums,left,p-1);
    root->right=BST(nums,p+1,right);
    return root;
}
int main(){

}