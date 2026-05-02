class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // Kyunki sum kabhi bhi n se upar nahi jayega, 
        // hum size n+1 ka array le sakte hain map ki jagah.
        vector<int> freq(n + 1, 0);
        
        int currSum = 0;
        int count = 0;
        
        // Base case: mp[0] = 1
        freq[0] = 1; 
        
        for (int x : nums) {
            currSum += x;
            
            // Target dhoondo: currSum - goal
            if (currSum >= goal) {
                count += freq[currSum - goal];
            }
            
            // Current sum ki frequency badhao
            freq[currSum]++;
        }
        
        return count;
    }
};