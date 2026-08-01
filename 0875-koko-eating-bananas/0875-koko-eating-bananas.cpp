class Solution {
public:
    int findmax(vector<int>& v) {
        int maxi = INT_MIN;
        for (int x : v)
            maxi = max(maxi, x);
        return maxi;
    }

    long long calculatehours(vector<int>& v, int hourly) {
        long long totalH = 0;

        for (int x : v) {
            totalH += ((long long)x + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculatehours(piles, mid);

            if (totalH <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};