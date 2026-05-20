class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
       if(nums.size()==1){
        return 1;
       }
       if(nums.size()==2){
        return 2;
       }
    
       int i=2;
        for(int j=i;j<nums.size();j++){
            if(nums[i-2]==nums[j]){
                continue;
            }

                nums[i]=nums[j];
                i++;
                
            
        }
        
       return i;
    }
};