class Solution {
public:
    
    int dp[101][101];
    
    bool check(string s1, string s2, string s3, int n, int m, int len)
    {
        // base case
        
        // if no character left in string s3, it means return true.
        if(len==0)
        {
            return 1;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        int a,b;
        // keep the pointer a and b at index 0 of both string s1 and s2.
        a=b=0;
        
        // we will check for two cases
        
        // if the first character of string s1 matches with the first character of string s3, it means the next character can be either of s1 or s2, but here we will call recursive function to check for ramaining character of s1 and check if they on interleaving with s1 forms the remaining pattern as s3 or not
        if(n-1>=0 and s1[n-1]==s3[len-1])
            a = check(s1,s2,s3,n-1,m,len-1);
        
        // if the first character of string s2 matches with the first character of string s3, it means the next character can be either of s1 or s2, but here we will call recursive function to check for ramaining character of s2 and check if they on interleaving with s1 forms the remaining pattern as s3 or not
        
        if(m-1>=0 and s2[m-1]==s3[len-1])
            b = check(s1,s2,s3,n,m-1,len-1);
        
        // now we will return the value of a or b (a || b) to the 2d dp array
        
        return dp[n][m] = a or b;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.size();
        int m = s2.size();
        int len = s3.size();
        
        // If the len of s3 is not equal to len of string s1 and s2, it means they are intervleaving string
        if(n+m!=len)
        {
            return 0;
        }
    
        dp[n][m];
        // make the element of 2d dp array as -1 initially
        memset(dp,-1,sizeof(dp));
        
        return check(s1,s2,s3,n,m,len);
        
    }
};
