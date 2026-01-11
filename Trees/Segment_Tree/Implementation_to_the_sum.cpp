// Implementing Segment Tree
# include<iostream>
# include<vector>
using namespace std;
class SegmentTree{
    public:
    vector<int>sgmt;
    SegmentTree(int n){
        sgmt.resize(4*n,0);
    }
    // building sgmt tree for finding the sum of the range
    void build(vector<int>&arr,int l,int r,int idx){
        if(r==l)
        {
            sgmt[idx]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(arr,l,mid,2*idx+1);
        build(arr,mid+1,r,2*idx+2);
        sgmt[idx]=sgmt[2*idx+1]+sgmt[2*idx+2];
    }
    
    // updating the value of the given index
    void update(int l,int r,int &pos,int idx,int &val){
        if(l==r)
        {
            sgmt[idx]=val;
            return ;
        }
        int mid=l+(r-l)/2;
        if(pos<=mid)
        update(l,mid,pos,2*idx+1,val);
        else
        update(mid+1,r,pos,2*idx+2,val);
        sgmt[idx]=sgmt[2*idx+1]+sgmt[2*idx+2];
    }
    // querying the sum in the given range
    int sumQuery(int l,int r, int lpos,int rpos)
    {
        
    }

};
int main(){

}