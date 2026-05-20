class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int m=i;
        
        while(m<=j){
            if(nums[m]==2){
                swap(nums[m],nums[j]);
                j--;
            }else if(nums[m]==0){
                swap(nums[m],nums[i]);
                i++;
                m++;
            }else{
                m++;
            }
        }
    }
};