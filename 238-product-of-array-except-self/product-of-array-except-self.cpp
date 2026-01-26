class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // Answer array where result will be stored
        vector<int> ans(n, 1);

        /*
        STEP 1: Prefix product
        ans[i] will store the product of all elements to the LEFT of i
        */
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        /*
        STEP 2: Suffix product
        suffix stores the product of elements to the RIGHT of i
        */
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix = suffix * nums[i + 1];
            ans[i] = ans[i] * suffix;
        }

        // Final answer contains product except self for each index
        return ans;
    }
};
