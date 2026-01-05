#include <iostream>
# include<priority_queue>
# include <unordered_map>
using namespace std;

class Solution {
public:
    priority_queue<long> maxHeap;
    priority_queue<long, vector<long>, greater<long>> minHeap;
    unordered_map<long, int> delayed;

    void pruneMax() {
        while (!maxHeap.empty() && delayed[maxHeap.top()] > 0) {
            delayed[maxHeap.top()]--;
            maxHeap.pop();
        }
    }

    void pruneMin() {
        while (!minHeap.empty() && delayed[minHeap.top()] > 0) {
            delayed[minHeap.top()]--;
            minHeap.pop();
        }
    }

    void balance() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            pruneMax();
        } 
        else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            pruneMin();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Insert
            if (maxHeap.empty() || nums[i] <= maxHeap.top())
                maxHeap.push(nums[i]);
            else
                minHeap.push(nums[i]);

            balance();

            // Remove element leaving window
            if (i >= k) {
                long out = nums[i - k];
                delayed[out]++;

                if (out <= maxHeap.top())
                    pruneMax();
                else
                    pruneMin();

                balance();
            }

            // Get median
            if (i >= k - 1) {
                if (k % 2 == 1)
                    ans.push_back(maxHeap.top());
                else
                    ans.push_back(((double)maxHeap.top() + minHeap.top()) / 2.0);
            }
        }
        return ans;
    }
};
