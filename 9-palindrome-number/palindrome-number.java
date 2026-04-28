class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;  // handle negative numbers

        if (x == Palindrome(x)) {
            return true;
        } else {
            return false;
        }
    }

    private int Palindrome(int x) {
        int reverse = 0;

        while (x != 0) {
            int p = x % 10;              // last digit
            reverse = reverse * 10 + p;  // build reverse
            x = x / 10;                  // reduce number
        }

        return reverse;
    }
}