class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.size(); i++) {
            char cs = s[i];
            char ct = t[i];

            // Check if there's already a mapping from s to t
            if (map_s_to_t.count(cs)) {
                if (map_s_to_t[cs] != ct) return false; // inconsistent mapping
            } else {
                map_s_to_t[cs] = ct;
            }

            // Check reverse mapping from t to s to ensure one-to-one
            if (map_t_to_s.count(ct)) {
                if (map_t_to_s[ct] != cs) return false;
            } else {
                map_t_to_s[ct] = cs;
            }
        }

        return true;
    }
};
