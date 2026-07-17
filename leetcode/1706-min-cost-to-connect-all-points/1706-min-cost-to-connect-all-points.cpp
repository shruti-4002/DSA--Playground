class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& houses) {
                int n = houses.size(); 
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        
        pq.push({0, 0});
        
        int totalCost = 0;
        int housesConnected = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int dist = curr.first;
            int u = curr.second;
            
            // Agar ye house pehle se hi kisi saste raste se connect ho chuka hai, toh skip karo
            if (visited[u]) continue;
            
            // House ko include karo aur cost add karo
            visited[u] = true;
            totalCost += dist;
            housesConnected++;
            
            // Agar saare houses connect ho gaye, toh aage loop chalane ki zaroorat nahi
            if (housesConnected == n) break;
            
            // Current house 'u' se baki saare unvisited houses ka distance nikal kar push karo
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    // Manhattan Distance Formula: |x1 - x2| + |y1 - y2|
                    int d = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    pq.push({d, v});
                }
            }
        }
        
        return totalCost;
    }
};