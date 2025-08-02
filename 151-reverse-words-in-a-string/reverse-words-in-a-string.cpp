class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string str = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                str += s[i];
            } else {
                if (str != "") {
                    words.push_back(str);
                    str = "";
                }
            }
        }

        if (str != "")
            words.push_back(str);
        string ans = "";
        reverse(words.begin(), words.end());
        for (int i = 0; i < words.size() - 1; i++) {
            ans += words[i]+ " ";
        }
        ans += words[words.size() - 1];
        return ans;
    }
};