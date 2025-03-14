#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;  // Stores indices of elements in window
    vector<int> res; // Stores max elements

    for(int i = 0; i < n; i++) {
        // Remove out-of-bound indices
        while(!dq.empty() && dq.front() <= i - k) 
            dq.pop_front();

        // Remove smaller elements from back
        while(!dq.empty() && nums[i] >= nums[dq.back()]) 
            dq.pop_back();

        dq.push_back(i); // Push current index

        // Store max value after first window is filled
        if(i >= k - 1) 
            res.push_back(nums[dq.front()]);
    }
    return res;
}


int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}