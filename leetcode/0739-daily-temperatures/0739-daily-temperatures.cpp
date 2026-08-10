class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        vector<int>ans(temp.size());
        

        for(int i=temp.size()-1;i>=0 ;i--){
            

           
            while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
    
            };

            ans[i]=st.empty()?0:st.top()-i;
          
     
        
          st.push(i);

        }

        return ans;
    }
};