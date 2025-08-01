class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ans=INT_MIN;

        while(start<end){
            int h1 = height[start];
            int h2 = height[end];
            int temp = (h1>h2)?(h2 * (end-start)):(h1*(end-start));
            if(h1>h2){
                end--;
            }else{
                start++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};