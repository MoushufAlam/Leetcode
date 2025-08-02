class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int count = 1;
        unordered_map<int, int> mpp;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            mpp[i]++;
        }
        int curr = intervals[n-1][1];
        int prevIndex = -1;
        for (int i = n - 1; i >= 0; i--) {
            if(intervals[i][1]<=curr){
                if(prevIndex !=-1){
                    mpp[i] += mpp[prevIndex];
                }
                count = max(count,mpp[i]);
                curr = intervals[i][0];
                prevIndex = i;
            }
        }
        return n - count;
    }
};