//we use Dp to solve this problem
// we use the same approach as the longest common subsequence
// we use he Take and Not Take approach

class Solution {
public:
int solve(int ind, int prev_ind, vector<int>nums, vector<vector<int>>&dp){
        if(ind == nums.size()){
            return  0;
        }
        
        if(dp[ind][prev_ind+1] != -1)
        return dp[ind][prev_ind+1];

        int Pick  = 0;
            if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            Pick = 1+solve(ind+1, ind, nums,dp);
        }
        int notPick = 0+solve(ind+1,prev_ind, nums,dp);

        return dp[ind][prev_ind+1] = max(Pick,notPick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};