class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=0;
        int suf=0;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;

            pre=nums[i]*pre;
            suf=nums[n-i-1]*suf;
            ans=max(pre,max(suf,ans));
        }

        return ans;
    }
};