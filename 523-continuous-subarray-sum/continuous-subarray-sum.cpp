class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int Sj=0;
        int length=0;
        mp[0]=-1;

        for(int i=0;i<nums.size();i++){

            Sj+=nums[i];

            int rem=Sj%k;
            

//agarsame rem exits akrta hai toh conform hai ki mutiple of K HAI UNKE BITCH KA  SUBARRAY KA SUM 
//BUS SUM MUTIPLE HAIN YA NAHI NO NEED TOC HECK JUST CHECK GAP
            if(mp.find(rem)!=mp.end()){
            
            length=i-mp[rem];
            if(length>=2)
            return true;
    

            }else{
                      mp[rem]=i;   

            }

          
        }

        return false;
    }
};