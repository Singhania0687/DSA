# include<iostream>
# include<deque>
using namespace std;

// Maximum sliding window
vector<int>MaxSlidingWindow(vector<int>&arr,vector<int>&v,int &k){
    deque<int>dq;
    vector<int>ans;
    int n=arr.size(),i,j=0;
    for(i=0;i<n;++i){
        // removing the smaller element to get the montonicity
        while(!dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();
            dq.push_back(i);
            // removing the element when window size is reached 
            if(i-j+1>=k)
           {
            ans.push_back(arr[dq.front()]);
            if(dq.front()==j)
            dq.pop_front();
            ++j;
        }
    }
    return ans;
}


// First Negative integer in every window of size k
vector<int>FirstNegative(vector<int>&arr,vector<int>&v,int &k){
    queue<int>dq;
    vector<int>ans;
    int n=arr.size(),i,j=0;
    for(i=0;i<n;++i){
            if(arr[i]<0)
            dq.push(i);
            // removing the element when window size is reached 
            if(i-j+1>=k)
           {
            if(!dq.empty())
            {ans.push_back(arr[dq.front()]);
                if(dq.front()==j)
                dq.pop();

            }
            else
            ans.push_back(0);
            ++j;
        }
    }
    return ans;
}

int main(){

}