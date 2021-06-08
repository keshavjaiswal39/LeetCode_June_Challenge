class Solution {
public:
    // int dp[1005];
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
    
        int first = cost[0];
        int second = cost[1];
        
        for(int i=2;i<n;i++)
        {
            int temp = second;
            second = min(cost[i] + first, cost[i] + second);
            first = temp; 
        }
        
        return min(first,second);
    }
};
