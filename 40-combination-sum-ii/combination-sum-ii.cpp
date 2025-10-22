class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current, int start, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // if current number > target, no need to continue
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], current, i + 1, ans);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort first
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(candidates, target, current, 0, ans);
        return ans;
    }
};
