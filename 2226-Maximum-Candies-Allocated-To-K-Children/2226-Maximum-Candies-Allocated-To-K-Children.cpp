#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible_distribution(vector<int>& candies, long long &k, int &m) {
    long long totalChildrenServed = 0;

    // Calculate how many children can receive 'm' candies
    for (int i = 0; i < candies.size(); i++) {
        totalChildrenServed += candies[i] / m;
    }

    // If we can serve at least 'k' children, return true
    return totalChildrenServed >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();
    long long totalCandies = 0;

    // Calculate total number of candies available
    for (int i = 0; i < n; i++) {
        totalCandies += candies[i];
    }

    int s = 1;
    long long e = totalCandies / k; // Maximum possible candies per child
    int m = s + (e - s) / 2;
    int maxPossibleCandies = 0;

    // Binary search to find the maximum number of candies per child
    while (s <= e) {
        if (possible_distribution(candies, k, m)) {
            maxPossibleCandies = m;  // Update the answer
            s = m + 1; // Try for a higher value
        } else {
            e = m - 1; // Try for a lower value
        }
        m = s + (e - s) / 2;
    }

    return maxPossibleCandies;
}


int main() {
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    int result = maximumCandies(candies, k);
    cout << "Maximum number of candies each child can get: " << result << endl;

    return 0;
}