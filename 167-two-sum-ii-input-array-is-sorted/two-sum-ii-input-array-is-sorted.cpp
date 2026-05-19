class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement]+1, i+1};
            }
            
            // If not found, add the current number and its index to the map
            mp[nums[i]] = i;
        }
        return {};
    }
};