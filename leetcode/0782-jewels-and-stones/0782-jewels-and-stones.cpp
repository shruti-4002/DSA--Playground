class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int>st;

        for(char c:jewels){
            st.insert(c);
        }
       int ans=0;

        for(char c:stones){
            if(st.find(c)!=st.end()){
                ans++;
            }

        }

        return ans;
    }
};