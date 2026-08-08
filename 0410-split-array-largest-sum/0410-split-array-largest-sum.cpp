class Solution {
public:

    int split(vector<int>& arr, int limit) {

        int squid = 1;          // Number of subarrays
        long long squidk = 0;   // Current subarray sum

        for (int i = 0; i < arr.size(); i++) {

            if (squidk + arr[i] <= limit) {
                squidk += arr[i];
            }
            else {
                squid++;
                squidk = arr[i];
            }
        }

        return squid;
    }

    int splitArray(vector<int>& arr, int k) {

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int squid = split(arr, mid);

            if (squid > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};