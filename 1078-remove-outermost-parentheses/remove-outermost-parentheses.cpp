class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        set<int> str;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (count == 0) str.insert(i);  // outermost opening
                count++;
            } else if (s[i] == ')') {
                count--;
                if (count == 0) str.insert(i);  // outermost closing
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (str.find(i) == str.end()) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};