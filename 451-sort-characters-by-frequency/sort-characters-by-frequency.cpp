class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return "";

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Convert map to vector of pairs
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Sort by frequency descending
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        // Build the result string
        string result;
        for (const auto& p : freqVec) {
            result.append(p.second, p.first); // repeat character p.second times
        }

        return result;
    }
};
