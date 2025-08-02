class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int cost = 0;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            q;
        q.push({0, 0, 0});
        visited[0][0] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [cost, x, y] = q.top();
            q.pop();

            if (x == n - 1 && y == m - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    !visited[newX][newY]) {
                    
                    int nextTime = max(cost,moveTime[newX][newY]);
                    visited[newX][newY] = true;
                    q.push({nextTime+1, newX, newY});
                }
            }
        }
        return cost;
    }
};