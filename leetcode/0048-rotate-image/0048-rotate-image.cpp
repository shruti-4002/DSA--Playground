class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        //transpose start from diagonal
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    
        for(int i=0;i<m;i++){
            int start=0;
            int end=n-1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }

    

    }
};