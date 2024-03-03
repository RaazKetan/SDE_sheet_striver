//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
int f(int ind, int wt[], int val[], int w,  vector<vector<int>>&dp){
        if(ind == 0)
        {
            if(wt[0]<=w)
            return val[0];
            
            return 0;
        }
        if(dp[ind][w] != -1)
        return dp[ind][w];
        
        
        int notPick = 0+ f(ind-1, wt,val,w,dp);
        int Pick = INT_MIN;
        if(wt[ind]<=w)
        Pick = val[ind]+f(ind-1,wt,val, w-wt[ind],dp);
        
        return dp[ind][w] = max(Pick,notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n, vector<int>(W+1,-1));
       return f(n-1, wt,val,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends