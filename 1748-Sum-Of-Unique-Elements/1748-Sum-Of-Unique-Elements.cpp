#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 2};
    cout << "Sum of unique elements: " << sumOfUnique(nums) << endl;
    return 0;
}
int sumOfUnique(vector<int>& nums) {
    unordered_map<int,int> hash;
    for(int i =0;i<nums.size();i++){
        if(hash[nums[i]]==2){
            continue;
        }
        hash[nums[i]]++;
    }
    int sum =0;
    for(int i =0;i<nums.size();i++){
        if(hash[nums[i]]==1){
            sum+=nums[i];
        }
    }
    return sum;
}