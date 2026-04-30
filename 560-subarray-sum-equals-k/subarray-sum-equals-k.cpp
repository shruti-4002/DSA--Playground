class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
         for(int i=0;i<nums.size();i++){
      int Sum=0;
      for(int j=i;j<nums.size();j++){
       
       
             Sum+=nums[j];

             if(Sum==k){
            count++;
             }
         
        
             }
      
    }
    return count;
    }
};