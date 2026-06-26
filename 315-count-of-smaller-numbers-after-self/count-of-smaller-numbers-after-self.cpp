class Solution {
public:
    int count=0;


void sort(vector<int>&nums,int left,int mid,int right,vector<pair<int,int>>&pp,vector<int>&temp){

    int i=left;
    int j=mid+1;
    vector<pair<int,int>>ans;

    while(i<=mid && j<=right){
        if(pp[j].first<pp[i].first){
            temp[pp[i].second]+=right-j+1;
            ans.push_back(pp[i]);
            i++;
        }else{
            ans.push_back(pp[j]);
            j++;
        }
    }

    while(i<=mid){
        ans.push_back(pp[i]);
        i++;
    }

     while(j<=right){
        ans.push_back(pp[j]);
        j++;
    }


    for(int l=0,k=left;k<=right;k++){
        pp[k]=ans[l];
        l++;
    }

}



    void ms(vector<int>&nums,int left,int right,vector<pair<int,int>>&pp,vector<int>&temp){
        int mid=left+(right-left)/2;

        if(left>=right){
            return;
        }

        ms(nums,left,mid,pp,temp);
        ms(nums,mid+1,right,pp,temp);
        sort(nums,left,mid,right,pp,temp);

    }



    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>pp;
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            pp.push_back({nums[i],i});
        }
        ms(nums,0,nums.size()-1,pp,temp);
        
        return temp;

    }
};