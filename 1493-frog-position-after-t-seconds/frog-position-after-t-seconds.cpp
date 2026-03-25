class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
        }

        queue<pair<int, double>> q;
        vector<bool> visited(n + 1, false);

        q.push({1, 1.0});
        visited[1] = true;

        int time = 0;

        while (!q.empty() && time < t) {
            int size = q.size();

            while (size--) {
                auto [node, prob] = q.front();
                q.pop();

                int unvisited = 0;
                for (int nei : adj[node]) {
                    if (!visited[nei]) unvisited++;
                }

                if (unvisited == 0) {
                    q.push({node, prob});
                    continue;
                }

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push({nei, prob / unvisited});
                    }
                }
            }
            time++;
        }

        while (!q.empty()) {
            auto [node, prob] = q.front();
            q.pop();

            if (node == target) return prob;
        }

        return 0.0;
    }
};