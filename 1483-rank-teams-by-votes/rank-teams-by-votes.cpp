class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1) {
            return votes[0];
        }
        int size = votes[0].size();
        sort(votes.begin(), votes.end());
        map<char, vector<int>> freq;
        for (auto p : votes) {
            for (int i = 0; i < p.length(); i++) {
                freq[p[i]].resize(size, 0);
                freq[p[i]][i]++;
            }
        }
        string st = "";
        vector<pair<vector<int>, char>> vec;
        for(auto& p : freq){
            vec.push_back({p.second, p.first});
        }

        sort(vec.begin(), vec.end(), [](const pair<vector<int>, char>& a, const pair<vector<int>, char>& b){
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        for(auto p : vec){
            st += p.second;
        }
        return st;
    }
};
