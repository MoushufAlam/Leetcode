class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end) {
            char st = tolower(s[start]);
            char en = tolower(s[end]);
            cout<<st<<" "<<en<<endl;
            if (!isalnum(st)) {
                start++;
                continue;
            }
            if (!isalnum(en)) {
                end--;
                continue;
            }
            if (st != en) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};