class Solution {
public:
int getsq(int m){
    int ans=0;
    while(m>0){
    int c=m%10;
    m=m/10;
    ans=ans+c*c;

    }

    return ans;
}
    bool isHappy(int n) {
        
        unordered_set<int>st;
        if(n==1)return true;
        while(n!=1){
            n=getsq(n);
            if(n==1){
                return true;
            }

            if(st.find(n)!=st.end()){
                return false;
            }

            st.insert(n);

        }
        return false;
    }
};