class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>ans;

        queue<int>q;

        for(auto &p: prerequisites){
            int child=p[0];
            int parent=p[1];

            adj[parent].push_back(child);

            indegree[child]++;

        }


        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto x: adj[curr]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }

        }

        return ans.size()==numCourses?ans:vector<int>{};



    }
};