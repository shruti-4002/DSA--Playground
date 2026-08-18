class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        
        int j=-1;
       for(int i=0;i<arr.size();i++){
        if(arr[i]!=val){
            j++;
            arr[j]=arr[i];
        }

       }

        return j+1;
    }
};