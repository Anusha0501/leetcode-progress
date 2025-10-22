class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current, int start, vector<vector<int>>& ans) {
        if (target == 0) { 
            ans.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], current, i, ans); // reuse allowed
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(candidates, target, current, 0, ans);
        return ans;
    }
};
