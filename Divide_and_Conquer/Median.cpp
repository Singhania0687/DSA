#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    
    // Always binary search on the smaller array
    if(n > m) return findMedianSortedArrays(B, A);

    int low = 0, high = n;
    int total = n + m;
    int half = (total + 1)/2;

    while(low <= high) {
        int cutA = (low + high)/2;
        int cutB = half - cutA-2;

        int l1 = (cutA == 0 ? INT_MIN : A[cutA-1]);
        int l2 = (cutB == 0 ? INT_MIN : B[cutB-1 ]);
        int r1 = (cutA == n ? INT_MAX : A[cutA]);
        int r2 = (cutB == m ? INT_MAX : B[cutB]);

        // Valid partition
        if(l1 <= r2 && l2 <= r1) {
            if(total % 2 == 1) 
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        // Move cutA left
        else if(l1 > r2) high = cutA - 1;
        // Move cutA right
        else low = cutA + 1;
    }
    return 0.0; // never reached
}

int main(){
    vector<int> A = {1, 3,5,9};
    vector<int> B = {2,6,7,89};
    cout << findMedianSortedArrays(A, B);
    return 0;
}
