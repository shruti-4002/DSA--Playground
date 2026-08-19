class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>ans;
      
        long long need=num/3;
        if(num%3!=0){
            return {};
        }
        long long first=need-1;
        long long sec=first+1;
        long long third=first+2;

        ans.push_back(first);
        ans.push_back(sec);
        ans.push_back(third);

        return ans;




    }
};