#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;
        
        // Sort the array to handle duplicates and use two pointer technique
        sort(begin(nums), end(nums));
        
        for (int i = 0; i + 2 < nums.size(); ++i) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            // Use two pointers technique for the remaining array
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                const int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    // Skip duplicates for l
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    // Skip duplicates for r
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        
        return ans;
    }
};

// Test function to demonstrate usage
int main() {
    Solution solution;
    
    // Test case 1: [-1,0,1,2,-1,-4]
    vector<int> nums1 = {-1,0,1,2,-1,-4};
    cout << "\nTest Case 1: Input = [-1,0,1,2,-1,-4]" << endl;
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test case 2: [0,1,1]
    vector<int> nums2 = {0,1,1};
    cout << "\nTest Case 2: Input = [0,1,1]" << endl;
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j];
            if (j < result2[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test case 3: [0,0,0]
    vector<int> nums3 = {0,0,0};
    cout << "\nTest Case 3: Input = [0,0,0]" << endl;
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result3[i].size(); j++) {
            cout << result3[i][j];
            if (j < result3[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}
