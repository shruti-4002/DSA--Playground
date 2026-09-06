class Solution {
public:

bool sameRow(const unordered_set<char>&targetset,string s){

for(char c:s){
    if(targetset.find(tolower(c))==targetset.end()){
        return false;
    }
}

return true;

}

    vector<string> findWords(vector<string>& words) {
    unordered_set<char> s1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> s2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> s3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    vector<string>ans;

    for(string s : words){
        const unordered_set<char>* targetset = nullptr;

        if(s1.find(tolower(s[0]))!=s1.end()){
            targetset=&s1;
        }else if(s2.find(tolower(s[0])) != s2.end()){
            targetset=&s2;
        }else{
            targetset=&s3;
        }

        bool valid=sameRow(*targetset,s);
        if(valid){
            ans.push_back(s);
        }


    }

return ans;


    }
};