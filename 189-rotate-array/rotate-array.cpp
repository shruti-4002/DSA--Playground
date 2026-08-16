class Solution {
public:

    void rev(vector<int>&arr,int start,int end){
        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;

        }
    }
    void rotate(vector<int>& arr, int k) {
        
        k= k%arr.size();
        rev(arr,0,arr.size()-1);
        rev(arr,0,k-1);
        rev(arr,k,arr.size()-1);
        

    }
};