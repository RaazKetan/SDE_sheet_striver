#include <bits/stdc++.h>
int solve(int i, int j, int m,int n,string s, string t,
vector<vector<int>>&dp){
	if(i>=m || j>=n)
	return 0;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int Pick = 0;
	if(s[i] == t[j]){
		Pick = 1+solve(i+1,j+1,m,n,s,t,dp);
	}
	int notPick = max(solve(i+1,j,m,n,s,t,dp),
	solve(i,j+1,m,n,s,t,dp));
	return  dp[i][j] =max(Pick,notPick);
}
int lcs(string s, string t)
{
	//Write your code here
	int m = s.size();
	int n = t.size();
	vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	return solve(0,0,m,n,s,t,dp);
}