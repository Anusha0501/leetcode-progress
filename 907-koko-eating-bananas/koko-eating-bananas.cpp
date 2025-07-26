class Solution {
public:
    long long calculatetotalhours(const vector<int>& piles, long long hourly) {
        long long totalh = 0;
        for (int pile : piles) {
            totalh += (pile + hourly - 1) / hourly;  // safer ceil-like logic
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int answer = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalh = calculatetotalhours(piles, mid);

            if (totalh <= h) {
                answer = mid;
                high = mid - 1;  // try smaller speed
            } else {
                low = mid + 1;   // need faster eating
            }
        }

        return answer;
    }
};
