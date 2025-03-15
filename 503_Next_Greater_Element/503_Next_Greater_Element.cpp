#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums);

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);
    
    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st; // Stack to store elements for comparison
    int n = nums.size(); // Size of the input array
    int max = INT_MAX; // A sentinel value to represent an empty stack condition
    st.push(max); // Initialize stack with sentinel value
    vector<int> ans(n); // Result vector to store next greater elements
    
    // Loop through the array twice to handle circular nature
    for (int i = 2*n - 1; i >= 0; i--) {
        int j = i % n; // Get the correct index in the original array
        int curr = nums[j]; // Current element being processed
        
        // Pop elements from stack while they are smaller or equal to the current element
        while (curr >= st.top()) {
            st.pop();
        }
        
        // If the top of the stack is the sentinel value, assign -1 (no greater element)
        if (st.top() == max) {
            if (i < n) ans[j] = -1;
        } else {
            // Otherwise, the top of the stack is the next greater element
            if (i < n) ans[j] = st.top();
        }
        
        // Push the current element onto the stack for future comparisons
        st.push(curr);
    }
    return ans; // Return the result vector
}
