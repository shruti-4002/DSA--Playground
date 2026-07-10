class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>in(numCourses,0);
        unordered_map<int,vector<int>>mp;
        queue<int>q;

        for(auto& p :prerequisites ){
            int child=p[0];
           int parent= p[1];
           in[child]++;
           mp[parent].push_back(child);
        }

        for(int j=0;j<numCourses;j++){
            if(in[j]==0){
                q.push(j);
            }
        }


        int count=0;

        while(!q.empty()){
           int t= q.front();
           q.pop();
            count++;
           for(int c :mp[t]){
            in[c]--;
            if(in[c]==0){

                q.push(c);
            }
           }
        }


if(count==numCourses){
    return true;
}else{
    return false;
}



    }
};