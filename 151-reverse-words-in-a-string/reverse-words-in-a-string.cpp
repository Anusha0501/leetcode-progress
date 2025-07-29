class Solution {
public:
    string reverseWords(string s) {
        // Remove leading/trailing/multiple spaces
        int n = s.size();
        string result, word;
        for (int i = 0; i < n;) {
            while (i < n && s[i] == ' ') i++;  // skip spaces
            if (i >= n) break;
            word = "";
            while (i < n && s[i] != ' ') word += s[i++];
            if (!result.empty()) result = word + " " + result;
            else result = word;
        }
        return result;
    }
};
