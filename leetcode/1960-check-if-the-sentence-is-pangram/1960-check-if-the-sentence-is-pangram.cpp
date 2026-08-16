class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mp;

        for (int i = 0; i < 26; i++) {
        mp['a' + i] = 0; 
    }
        for(char c:sentence){
            mp[c]++;
        }

     for(int  i=0;i<26;i++){
        if(mp['a'+i]==0){
            return false;
        }
     }
     return true;
    }
};