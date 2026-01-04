// To find the majority element in the given data structure
# include<iostream>
# include<vector>
using namespace std;

// Majority element 1
int majority1(vector<int>&nums){
    int ele,cnt=0;
    for(auto it:nums){
        if(cnt==0)
        {
            cnt=1;
            ele=it;
        }
        else if(it==ele){
            ++cnt;
        }
        else
        --cnt;
    }
    
        cnt=0;
        for(auto it:nums){
            if(it==ele)
            ++cnt;
        }
        if(cnt>nums.size()/2)
        return ele;
        return -1;

}
// Majority element 2 i.e the count of occurence of a no. is greater than n/3
vector<int> majority2(vector<int>&nums){
    vector<int>res;
    int ele1=0,ele2=1,cnt1=0,cnt2=0;
    for(auto it:nums){
        if(it==ele1)
        ++cnt1;
        else if(it==ele2)
        ++cnt2;
        else if(cnt1==0)
        {
            ele1=it;
            ++cnt1;
        }
        else if(cnt2==0)
        {
            ele2=it;
            ++cnt2;
        }
        else{
            --cnt1;
            --cnt2;
        }
    }
    
       cnt1=0,cnt2=0;
       for(auto it:nums){
        if(it==ele1)
        ++cnt1;
        else if(it==ele2)
        ++cnt2;
       }
       if(cnt1>nums.size()/3)
       res.push_back(ele1);
       if(cnt2>nums.size()/3)
       res.push_back(ele2);
        return res;

    }
   


int main(){

}