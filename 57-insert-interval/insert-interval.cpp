class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        bool flag = false;
        for (int i = 0; i < intervals.size(); i++) {
            int u = intervals[i][0];
            int v = intervals[i][1];
            if (flag) {
                if (end < u)
                    ans.push_back(intervals[i]);
                continue;
            }
            if (end < u) {
                ans.push_back(newInterval);
                flag = true;
                ans.push_back(intervals[i]);
                continue;
            }
            if (start > v && !flag) {
                ans.push_back(intervals[i]);
            } else {
                if (start < u) {
                    intervals[i][0] = start;
                }
                int temp = i;
                for (int j = i + 1; j < intervals.size(); j++) {
                    int fir = intervals[j][0];
                    int sec = intervals[j][1];
                    if (end >= fir) {
                        if (end > sec) {
                            continue;
                        } else {
                            end = sec;
                            temp = j;
                            break;
                        }
                    }
                }
                flag = true;
                intervals[i][1] = max(intervals[i][1], end);
                ans.push_back(intervals[i]);
                i = temp;
            }
        }
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
        }
        if (start > ans[ans.size() - 1][1]) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};