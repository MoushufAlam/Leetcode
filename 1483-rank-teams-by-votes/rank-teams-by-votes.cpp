class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1) return votes[0];

        int n = votes[0].size();
        map<char, vector<int>> freq;

        for (auto& vote : votes) {
            for (int i = 0; i < n; ++i) {
                freq[vote[i]].push_back(n - i);
            }
        }
        
        for (auto& [ch, vec] : freq) {
            sort(vec.rbegin(), vec.rend());
        }

        vector<pair<vector<int>, char>> rank;
        for (auto& [ch, vec] : freq) {
            rank.push_back({vec, ch});
        }

        sort(rank.begin(), rank.end(), [](auto& a, auto& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        string res = "";
        for (auto& [_, ch] : rank) {
            res += ch;
        }

        return res;
    }
};
