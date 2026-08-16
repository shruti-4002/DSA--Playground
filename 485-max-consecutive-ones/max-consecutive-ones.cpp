class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int  maxnum=0;
       int  currnum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currnum++;
                maxnum=max(currnum,maxnum);
            }else{
                
                currnum=0;
            }
        }

        return maxnum;
    }
};