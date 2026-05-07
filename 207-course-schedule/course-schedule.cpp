class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjacency list
        vector<vector<int>> adj(numCourses);

        // indegree[i] = how many prerequisites course i needs
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {

            int a = p[0];
            int b = p[1];

            // b --> a
            adj[b].push_back(a);

            // a has one more incoming edge
            indegree[a]++;
        }

        queue<int> q;

        // Push all courses having 0 prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            completed++;

            // visit neighbors
            for (int neighbor : adj[node]) {

                indegree[neighbor]--;

                // if no prerequisite left
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // if all courses completed -> possible
        return completed == numCourses;
    }
};