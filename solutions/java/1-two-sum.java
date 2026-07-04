class Solution {
    // solution 1: brute force
    public int[] twoSum1(int[] nums, int target)
    {
        int n = nums.length;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target) return new int[] {i, j};
            }
        }

        return new int[] {};
    }
}