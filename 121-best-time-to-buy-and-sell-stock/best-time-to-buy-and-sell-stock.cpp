class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        s.push(prices[n - 1]);
        int res = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (s.top() < prices[i]) {
                s.pop();
                s.push(prices[i]);
            } else {
                res = max(res, s.top() - prices[i]);
            }
        }
        return res;
    }
};