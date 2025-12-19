class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }

private:
    void backtrack(int start, string& s,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        // If we reached the end of the string, store one partition
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        // Try all substrings starting at 'start'
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, result);
                path.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
