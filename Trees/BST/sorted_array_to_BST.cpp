// converting a sorted array to a BST
# include<iostream>
# include<vector>
using namespace std;
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