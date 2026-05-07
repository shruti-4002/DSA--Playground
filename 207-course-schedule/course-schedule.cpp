class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);//adjaceny list
        vector<int>ans;
        vector<int>indegree(numCourses,0);//incoming edges
        queue<int>q;


        for(auto& p : prerequisites){
            int a=p[0];
            int b=p[1];
            //[]-->[]; children
            adj[b].push_back(a);
            indegree[a]++;
            
        }

        //check whose indegree is 0 remebr in topo sort we add 
        //elements with indegree 0 only to queue;
        //keep reducing the indgree until it becomes 0;


        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){

            auto curr = q.front();
            ans.push_back(curr);
            q.pop();

            for(auto x: adj[curr]){

                indegree[x]--;

                if(indegree[x]==0){
                    q.push(x);
                }


            }
            





        }

        if(ans.size()!=numCourses){
            return false;
        }

        return true;










    }
};