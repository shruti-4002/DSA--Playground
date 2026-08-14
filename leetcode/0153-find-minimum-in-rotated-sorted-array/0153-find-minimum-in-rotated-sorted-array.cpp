class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        

        while(start<end){
            int mid=((end-start)/2)+start;

        

            if(arr[mid]>arr[end]){
                start=mid+1;
        }else{
                end=mid;

        }
        };
        return arr[start];
    }
};