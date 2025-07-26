class Solution {
public:
    int finddays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int required_days = finddays(weights, mid);
            if (required_days <= days) {
                ans = mid;          // ✅ store valid answer
                high = mid - 1;     // try smaller capacity
            } else {
                low = mid + 1;      // need more capacity
            }
        }

        return ans;
    }
};
