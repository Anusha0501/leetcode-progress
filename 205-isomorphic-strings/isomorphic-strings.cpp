class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }

private:
    vector<int> encode(const string& str) {
        unordered_map<char, int> mp;
        vector<int> res;
        int index = 0;

        for (char ch : str) {
            if (!mp.count(ch)) {
                mp[ch] = index++;
            }
            res.push_back(mp[ch]);
        }

        return res;
    }
};
