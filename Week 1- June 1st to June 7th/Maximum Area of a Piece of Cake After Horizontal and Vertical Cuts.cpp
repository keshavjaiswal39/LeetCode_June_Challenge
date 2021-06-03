class Solution {
public:
    int getMaximumDifference(vector<int>& v, int len)
    {
        // we will find out the max diff in an array for both the verticalCuts and horizontalCuts
        
        // 1. Sort the array/vector
        sort(v.begin(),v.end());
        
        int max_diff=v[0];   
        
        // find out the diff between each element and compare it with max_diff, we need the max value in this               list
        for(int i=1;i<v.size();i++)
        {
            max_diff = max(max_diff,(v[i]-v[i-1]));
        }
        
        // if in case there is only one element, then may be for that single cut we can get a greater area, so we           will find out the maximum value between max_diff and (height/width)-v[n-1];
        
        // height in case of horizontal cut and width in case of vertical cut.(
        max_diff = max(max_diff, len-v[v.size()-1]);
        
        // Hence we got the max diff, so we will return it.        
        return max_diff;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        // lets find out the max difference for both the vector
        int maxdiff_horizontal = getMaximumDifference(horizontalCuts,h);
        int maxdiff_vertical = getMaximumDifference(verticalCuts,w);
        
        // return the product and find the modulus with 10^9+7
        return ((long) maxdiff_horizontal * maxdiff_vertical) % 1000000007; 
    }
};
