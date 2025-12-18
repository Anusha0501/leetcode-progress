class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());   // Step 1: sort to handle duplicates
        backtrack(0, nums, subset, result);
        
        return result;
    }
    
private:
    void backtrack(int start, vector<int>& nums, vector<int>& subset,
                   vector<vector<int>>& result) {
        result.push_back(subset);   // add current subset
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) 
                continue;
            
            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, result);
            subset.pop_back();      // backtrack
        }
    }
};
