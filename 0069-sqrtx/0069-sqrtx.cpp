class Solution {
public:
    int mySqrt(int n) {
        if (n == 0) return 0;

        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= n / mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};