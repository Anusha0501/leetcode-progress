class Solution {
public:
    vector<string> result;
    string num;
    int target;

    void dfs(int index, string expr, long value, long last) {
        // If we've used all digits
        if (index == num.length()) {
            if (value == target)
                result.push_back(expr);
            return;
        }

        for (int i = index; i < num.length(); i++) {
            // Avoid leading zeros
            if (i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long curr = stol(part);

            if (index == 0) {
                // First number (no operator)
                dfs(i + 1, part, curr, curr);
            } else {
                dfs(i + 1, expr + "+" + part, value + curr, curr);
                dfs(i + 1, expr + "-" + part, value - curr, -curr);
                dfs(i + 1,
                    expr + "*" + part,
                    value - last + last * curr,
                    last * curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        dfs(0, "", 0, 0);
        return result;
    }
};
