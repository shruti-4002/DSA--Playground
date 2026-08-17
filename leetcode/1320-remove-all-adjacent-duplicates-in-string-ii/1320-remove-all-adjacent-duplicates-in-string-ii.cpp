class Solution {
public:
    string removeDuplicates(string s, int k) {
    stack<pair<char,int>>st;
    string ans="";
    for(char si : s){

        if(!st.empty() && st.top().first==si){
            st.top().second++;
        }else{
            st.push({si,1});
        }

        if(!st.empty() && st.top().second==k){
            st.pop();
        }


    }

    while(!st.empty()){
        ans.append(st.top().second,st.top().first);
        st.pop();

    }


    reverse(ans.begin(),ans.end());
    return ans;


    }
};