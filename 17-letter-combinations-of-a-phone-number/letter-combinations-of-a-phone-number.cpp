class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        backtrack(0, digits, mapping, current, result);
        return result;
    }

private:
    void backtrack(int index, string& digits,
                   vector<string>& mapping,
                   string& current,
                   vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char ch : mapping[digit]) {
            current.push_back(ch);
            backtrack(index + 1, digits, mapping, current, result);
            current.pop_back(); // backtrack
        }
    }
};
