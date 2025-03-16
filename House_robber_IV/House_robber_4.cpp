class Solution {
    public:
        bool istrue(vector<int>& nums, int k, int maxCap) {
            int count = 0;
            int i = 0;
            int n = nums.size();
    
            while (i < n) {
                if (nums[i] <= maxCap) {
                    count++;  // Select this house
                    i += 2;   // Skip adjacent
                } else {
                    i++;
                }
            }
    
            return count >= k;
        }
    
        vector<int> sorts(vector<int> nums) {
            sort(nums.begin(), nums.end());
            return nums;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            int mini = INT_MAX;
    
            // Sorting nums and working with values instead of indices
            vector<int> sortedNums = sorts(nums);
            int S = sortedNums[0];  // Minimum value in nums
            int e = sortedNums[n - 1];  // Maximum value in nums
    
            while (S <= e) {
                int m = S + (e - S) / 2;
    
                if (istrue(nums, k, m)) {
                    mini = min(mini, m);
                    e = m - 1;
                } else {
                    S = m + 1;
                }
            }
    
            return mini;
        }
    };
    