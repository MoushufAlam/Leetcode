class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mpp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;

        for (auto& pair : mpp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};