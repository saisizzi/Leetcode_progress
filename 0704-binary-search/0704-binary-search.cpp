class Solution {
public:

    int solve(vector<int>& nums, int target, int low, int high) {

        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        else if (target > nums[mid])
            return solve(nums, target, mid + 1, high);

        else
            return solve(nums, target, low, mid - 1);
    }

    int search(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size() - 1);
    }
};