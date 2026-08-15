class Solution {
public:
           int first(vector<int>&arr,int target){
            int ans=-1;
            int start=0;
            int end=arr.size()-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(arr[mid]==target){
                    ans=mid;
                    end=mid-1;
                }else if(arr[mid]<target){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            
            return ans;
        }
        
        
          int sec(vector<int>&arr,int target){
            int ans=-1;
            int start=0;
            int end=arr.size()-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(arr[mid]==target){
                    ans=mid;
                    start=mid+1;
                }else if(arr[mid]<target){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            
            return ans;
        }
  
    vector<int> searchRange(vector<int>& arr, int target) {
                vector<int>ans;
        int f1=first(arr,target);
        int f2=sec(arr,target);
        ans.push_back(f1);
        ans.push_back(f2);
        return ans;
       

    }
};