class Solution {
public:
    int search(vector<int>& arr, int target) {
           int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (arr[mid]==target){
                return mid;
            }

            if(arr[low]<=arr[mid]){ //sorted
                if(arr[low]<=target && arr[mid]>target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{   //unsorted

            if(target<=arr[high] && target>arr[mid]){
                low=mid+1;
            }else{

                high=mid-1;
            }



            }


            
        }

        return -1;

    }
};