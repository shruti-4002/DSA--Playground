class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Size define karna zaroori hai
     
        vector<int> ans(n,1);

        // Prefix: i se pehle wale elements ka product
        int pre=1;
        for(int i = 1; i < n; i++) {
          pre=pre*nums[i-1];
          ans[i]=pre;
        }

      int suf=1;
        for(int i = n - 2; i >= 0; i--) {
          suf=suf*nums[i+1];
          ans[i]*=suf;
        }

       

        return ans;
    }
};