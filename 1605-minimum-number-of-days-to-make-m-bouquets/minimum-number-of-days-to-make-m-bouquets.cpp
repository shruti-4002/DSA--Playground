class Solution {
public:

    bool possibleMake(vector<int>&arr,int ReqBoq,int OneBoq,int Days){
        int countOfFlower=0;
        int countOfBoq=0;
        for(int d:arr){

            if(d<=Days){
                countOfFlower++;
                if(countOfFlower==OneBoq){
                    countOfBoq++;
                    countOfFlower=0;
                }
            }else{
                countOfFlower=0;
            }
        }

        return (countOfBoq>=ReqBoq)?true:false;

    }

    int minDays(vector<int>& arr, int m, int k) {
        int low=*min_element(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        int ans=0;
       long long np=(long long)m*k;
       if(np>arr.size()){
        return -1;
       }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possibleMake(arr,m,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};