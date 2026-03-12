class Solution {
public:
    bool solve(vector<int>& nums, int maxOperations, int penalty) {
        long long ops = 0;
        for(int x : nums) {
            ops += (x - 1) / penalty;
        }
        return ops <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(solve(nums, maxOperations, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;

    }
};