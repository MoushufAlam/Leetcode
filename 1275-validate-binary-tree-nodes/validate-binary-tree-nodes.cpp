class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        map<int, vector<int>> graph;
        vector<int> indegree(10001, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                graph[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                graph[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        int temp = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                temp = i;
                break;
            }
        }
        queue<int> q;
        vector<bool> visited(10001, false);
        bool flag = false;
        if (temp != -1) {
            q.push(temp);
            visited[temp] = true;
        } else {
            q.push(0);
            visited[0] = true;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout<<u<<endl;
            if (visited[u] && u != temp) {
                return false;
            }
            visited[u] = true;
            if(graph[u].size()<=2)
            {
                for (auto v : graph[u]) {
                    q.push(v);
                }
            }else return false;
        }
        for(int i = 0 ;i<n;i++){
            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }
};