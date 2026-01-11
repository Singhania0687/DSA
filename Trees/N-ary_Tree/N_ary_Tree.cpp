// Constructing n-ary_tree
# include<iostream>
# include<vector>
using namespace std;
class N_ary_Tree{
    public:
    int data;
    vector<N_ary_Tree *>children;
    N_ary_Tree(int val){
        data=val;
    }
    N_ary_Tree(int val,vector<N_ary_Tree *>children)
    {
        data=val;
        this->children=children;
    }
};
N_ary_Tree* clone(N_ary_Tree* root){
    if(root==NULL)
    return NULL;
    N_ary_Tree* n=new N_ary_Tree(root->data);
    for(auto it:n->children)
    {
        n->children.push_back(clone(it));
    }
    return n;
}
void Postorder(N_ary_Tree* root,vector<int>&v){
    if(root==NULL)
    return;
    for(auto it:root->children){
        Postorder(it,v);
        v.push_back(it->data);
    }

}
void PreOrder(N_ary_Tree* root,vector<int>&v){
    if(root==NULL)
    return ;
    for(auto it:root->children){
        v.push_back(it->data);
        PreOrder(it,v);
    }
}


int main(){
   
    vector<N_ary_Tree *> v={new N_ary_Tree(20),new N_ary_Tree(30),new N_ary_Tree(40),new N_ary_Tree(50),new N_ary_Tree(60)};
     N_ary_Tree* root=new N_ary_Tree(10,v);
         vector<N_ary_Tree *> v1={new N_ary_Tree(70),new N_ary_Tree(80),new N_ary_Tree(90),new N_ary_Tree(100),new N_ary_Tree(160)};
        root->children[3]->children=v1;
        
}