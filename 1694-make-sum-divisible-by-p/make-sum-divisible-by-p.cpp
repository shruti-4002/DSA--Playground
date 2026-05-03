class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long long sum=0;
        for(int x:nums){
            sum+=x;
        }

        if(sum%p==0){
            return 0;
        }
      
        int need=sum%p;
        unordered_map<long long,long long>mp;
            long long curr=0;
            long long len=LLONG_MAX;
              mp[0]=-1;
        for(int i=0;i<nums.size();i++){
                curr+=nums[i];
                int rem=((curr%p-need +p)%p);

                if(mp.find(rem)!=mp.end()){
                    len=min(len,i-mp[rem]);
                }

                mp[(curr%p+p)%p]=i;

                


        }

        if(len>=nums.size()|| len==LLONG_MAX)return -1;
        return len;





    }
};