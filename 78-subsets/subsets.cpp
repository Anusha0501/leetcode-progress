class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int index, vector<int>& nums, vector<int>& current) {
        // store current subset
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);          // choose
            backtrack(i + 1, nums, current);     // explore
            current.pop_back();                  // unchoose
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(0, nums, current);
        return result;
    }
};
