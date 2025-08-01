class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        set<int> st;
        unordered_map<int, vector<int>> graph;
        for (auto p : pairs) {
            outdegree[p[0]]++;
            indegree[p[1]]++;
            st.insert(p[0]);
            st.insert(p[1]);
            graph[p[0]].push_back(p[1]);
        }
        int u = pairs[0][0];
        for (auto p : st) {
            if (outdegree[p] - indegree[p] == 1) {
                u = p;
                break;
            }
        }
        stack<int> s;
        vector<int> eulerPath;
        vector<vector<int>> ans;
        s.push(u);
        while(!s.empty()){
            int curr = s.top();
            if(!graph[curr].empty()){
                int ngbr = graph[curr].back();
                graph[curr].pop_back();
                s.push(ngbr);
            }else{
                eulerPath.push_back(curr);
                s.pop();
            }
        }
        reverse(eulerPath.begin(),eulerPath.end());
        for(int i=0;i<eulerPath.size()-1;i++){
            ans.push_back({eulerPath[i],eulerPath[i+1]});
        }
        return ans;
    }
};