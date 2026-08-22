class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel;
        unordered_map<char,int>con;

        for(char c:s){
            c=tolower(c);
           if(c=='a'|| c=='e' || c=='i'||c=='o'|| c=='u'){
            vowel[c]++;
           }else{

            con[c]++;
           }
        }
int maxc=0;
int maxv=0;
        for(auto v:vowel){
            if(v.second>maxv){
                maxv=v.second;            }
        }

         for(auto c:con){
            if(c.second>maxc){
                maxc=c.second;            }
        }


        return maxc+maxv;

    }
};