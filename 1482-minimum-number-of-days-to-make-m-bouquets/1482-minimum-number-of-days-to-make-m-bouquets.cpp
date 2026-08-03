class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                cnt++;
            }
            else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        // For the last continuous group
        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Not enough flowers
        if (1LL * m * k > bloomDay.size())
            return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int low = mini;
        int high = maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};