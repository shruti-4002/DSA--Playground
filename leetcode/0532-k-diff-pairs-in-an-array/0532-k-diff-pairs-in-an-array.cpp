class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int start=0;
        int end=1;
        int ans=0;
        sort(nums.begin(), nums.end());
        while(start<nums.size()&&end<nums.size()){

                if(start==end){
                    end++;
                    continue;
                    
                }

            if(nums[end]-nums[start]==k){
                ans++;
                int ifdup=nums[start];
                while(start<nums.size() && nums[start]==ifdup){
                    start++;
                }


            }else if(nums[end]-nums[start]<k){
                end++;
            }else{
                start++;
            }
        }

        return ans;
    }
};