class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int res = INT_MIN;
        for(int j = i + 1;j<prices.size();j++){
            int curr = prices[i];
            int future = prices[j];
            cout<<curr<<" "<<future<<endl;
            if(curr>future){
                i = j;
            }else{
                res = max(res,(future - curr));
            }
        }
        return res==INT_MIN?0:res;
    }
};