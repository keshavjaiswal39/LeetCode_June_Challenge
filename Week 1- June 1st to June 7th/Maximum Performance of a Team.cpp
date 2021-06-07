class Solution {
public:
    
//    [&](const pair<int,int> a,const pair<int,int> b)
//	{
//             if(a.first == b.first)
//        {
//            return a.second>b.second;
//        }
//        
//        return a.first>b.first;
//    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        // lets make a vector of pair of speend and efficiency
        vector<pair<int,int> > map;
        
        for(int i=0;i<n;i++)
        {
            map.push_back({efficiency[i], speed[i]});
        }
        
        // we will sort the map vector on the basis of efficiency in decreasing order
        sort(map.begin(),map.end(),[](const pair<int,int> &a,const pair<int,int> &b)
        {
            if(a.first == b.first)
            {
                return a.second > b.second;
            }

            return a.first > b.first;
        });
        
        long result = 0;
        long total_speed = 0;
        
        // lets create a min heap so that we can get the min speed always on the top
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(auto it:map)
        {
            total_speed += it.second;
            
            if(minHeap.size() >= k)
            {
                total_speed -= minHeap.top();
                minHeap.pop();
                minHeap.push(it.second);
            }
            else
            {
                minHeap.push(it.second);
            }
            
            result = max(result, it.first * total_speed);
        }
        
        return result % 1000000007;        
    }
};
