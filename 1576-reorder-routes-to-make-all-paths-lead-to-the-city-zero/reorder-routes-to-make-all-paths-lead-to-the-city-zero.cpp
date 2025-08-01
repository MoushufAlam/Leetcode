class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        set<pair<int, int>> st;
        for (auto p : connections) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
            visited[p[0]] = false;
            visited[p[1]] = false;
            st.insert({p[0], p[1]});
        }
        int ans = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    if (st.find({u, v}) != st.end()) {
                        ans++;
                    }
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};