#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's possible to transform the array to zero array
bool zero_array_posbl(vector<int> &nums, vector<vector<int>>& queries, int k) {
    int n = nums.size();
    vector<int> t(n, 0);
    int m = queries.size();

    // Apply the first k queries
    for (int i = 0; i <= k; i++) {
        t[queries[i][0]] += queries[i][2];
        if (queries[i][1] < n - 1) {
            t[queries[i][1] + 1] -= queries[i][2];
        }
    }

    // Calculate the prefix sum
    for (int i = 1; i < n; i++) {
        t[i] += t[i - 1];
    }

    // Check if the transformed array can be zeroed
    for (int i = 0; i < n; i++) {
        if (nums[i] > t[i]) {
            return false;
        }
    }
    return true;
}

// Function to check if all elements in the array are zero
bool allZeros(const vector<int>& arr) {
    return all_of(arr.begin(), arr.end(), [](int x) { return x == 0; });
}

// Function to find the minimum number of operations to make the array zero
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    if (allZeros(nums)) {
        return 0;
    }

    int m = queries.size();
    int n = nums.size();
    int s = 0;
    int e = m - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    // Binary search to find the minimum number of operations
    while (s <= e) {
        if (zero_array_posbl(nums, queries, mid)) {
            ans = mid + 1;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    vector<vector<int>> queries = {
        {0, 2, 1},
        {1, 3, 2},
        {2, 4, 1}
    };

    int result = minZeroArray(nums, queries);
    cout << "Minimum number of operations to make the array zero: " << result << endl;

    return 0;
}