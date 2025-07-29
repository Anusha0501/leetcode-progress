class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading, trailing and multiple spaces
        stringstream ss(s);
        string word, result;

        while (ss >> word) {
            if (!result.empty()) result = word + " " + result;
            else result = word;
        }

        return result;
    }
};
