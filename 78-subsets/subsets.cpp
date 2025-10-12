class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to result
        result.push_back(current);
        
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);           // choose nums[i]
            backtrack(nums, i + 1, current, result); // move to next index
            current.pop_back();                   // backtrack
        }
    }
};
