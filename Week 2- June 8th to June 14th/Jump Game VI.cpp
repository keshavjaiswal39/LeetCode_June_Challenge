class Solution{
	public:
		int maxResult(vector<int> & nums, int k)
		{
			int n = nums.size();
			// this will store all the index
			deque<int> d;
			// push the first index
			d.push_back(0);
			
			for(int i=1;i<n;i++)
			{
				if(d.front()+k < i)
				{
					d.pop_front();
				}
				
				nums[i] += nums[d.front()];
				
				while(!d.empty() and nums[d.back()] < nums[i])
				{
					d.pop_back();
				} 
				
				d.push_back(i);
			}
			return nums[n-1];		
		}
};
