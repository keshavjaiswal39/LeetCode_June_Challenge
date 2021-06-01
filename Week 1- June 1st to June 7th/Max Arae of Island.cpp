class Solution {
private:
    
    int n,m;
    
    int trav(int row,int col,vector<vector<int> > &grid)
    {
        // base case
        if(row<0 || col<0 || row>=m || col>=n || grid[row][col]==0)
        {
            return 0;
        }
        
        // mark it 0 , so that it is visited
        grid[row][col] = 0;
        
        // recursion
        return 1 + trav(row-1,col,grid) + trav(row+1,col,grid) + trav(row,col-1,grid) + trav(row,col+1,grid);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int> >&grid) 
    {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col])
                {
                    ans=max(ans,trav(row,col,grid));
                }
            }
        }
        return ans;
    }
};
