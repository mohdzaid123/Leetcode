class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        // Create a boolean array to mark numbers as prime or not.
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count the number of prime numbers (marked as true in the array).
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};
