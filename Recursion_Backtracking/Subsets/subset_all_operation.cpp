# include<iostream>
# include<vector>
# include<unordered_set>
using namespace std;

/* I am implementing a single function that can handle unique subset generation
     of size k*/
void generateSubset(vector<int>&nums,vector<vector<int>>&ans,int idx,vector<int>&temp,int k){
    // base case

        // in order to get subset of size k 
        if(temp.size()==k)
         {
            ans.push_back(temp);
            return ;
        }
    // creating an internal unordered set in order to keep a track of unique elemet at the given level
    unordered_set<int>st;
     for(int i=idx;i<nums.size();++i){
         
        if(st.find(nums[i])==st.end()){
            // include
            temp.push_back(nums[i]);
            generateSubset(nums,ans,i+1,temp,k);
            // exclude
            temp.pop_back();
            st.insert(nums[i]);
        }
     }
    } 

    // for generating unique permutation of numbers 
  void generatePermutation(vector<int>&nums,vector<vector<int>>&ans,int idx){ 
    // base case
    if(idx==nums.size())
    {
        ans.push_back(nums);
        return ;
    }
    unordered_set<int>st;
    for(int i=idx;i<nums.size();++i)
    {
        if(st.find(nums[i])==st.end())
        {
            swap(nums[i],nums[idx]);
            generatePermutation(nums,ans,idx+1);
            swap(nums[i],nums[idx]);
            st.insert(nums[i]);
        }
    }
  }

int main()
{
    vector<int>nums={1,3,1,4,2};
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>temp;
    // generateSubset(nums,ans,0,temp,2);
    generatePermutation(nums,ans,0);
    for(auto it:ans){
        for(auto i:it)
        cout<<i<<" , ";
        cout<<endl;
    }

}