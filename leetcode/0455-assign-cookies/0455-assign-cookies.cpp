class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child=g.size();
        int cookie=s.size();
        

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<child && j<cookie){
            if(g[i]<=s[j]){
            i++;
            j++;
            count++;
        }else if(g[i]>s[j]){
            j++;
        }else{
        i++;
        }
        }
        return count;
    }
};