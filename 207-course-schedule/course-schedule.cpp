class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(auto & p : prerequisites){
           int child= p[0];
           int parent=p[1];
           mp[parent].push_back(child);
            indegree[child]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }

        }

        int count=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;
            for(auto x : mp[curr]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }

        if(count==numCourses)return true;

        return false;
    }
};