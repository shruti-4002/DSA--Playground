class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int j=1;
        int i=0;
        while(i<n-1 && j<n){
            if(arr[i]==0 && arr[j]!=0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }else if(arr[i]==0 && arr[j]==0){
                j++;
            }else{
                i++;
                j++;
            }
        }
    }
};