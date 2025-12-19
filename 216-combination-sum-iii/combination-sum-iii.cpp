class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return result;
    }

private:
    void backtrack(int start, int k, int target) {
        // If we found k numbers and target is 0 → valid combination
        if (path.size() == k) {
            if (target == 0)
                result.push_back(path);
            return;
        }

        for (int num = start; num <= 9; num++) {
            if (num > target) break;  // pruning

            path.push_back(num);
            backtrack(num + 1, k, target - num);
            path.pop_back();          // backtrack
        }
    }
};
