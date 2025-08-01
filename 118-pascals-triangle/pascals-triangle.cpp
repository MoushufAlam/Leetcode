class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vec.push_back({1});
        vector<int> copy_vec;
        for (int i = 0; i < numRows - 1; i++) {
            vector<int> temp;
            temp.push_back(1);
            int index = 0;
            while (temp.size() < (i+1)) {
                temp.push_back(copy_vec[index]+copy_vec[index+1]);
                index++;
            }
            temp.push_back(1);
            vec.push_back(temp);
            copy_vec = temp;
        }
        return vec;
    }
};