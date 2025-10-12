class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Function to compute (base^exp) % mod efficiently
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) 
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // number of even indices
        long long oddCount = n / 2;        // number of odd indices
        
        long long evenPow = modPow(5, evenCount, MOD); // 5 choices for even indices
        long long oddPow = modPow(4, oddCount, MOD);   // 4 choices for odd indices
        
        return (evenPow * oddPow) % MOD;
    }
};
