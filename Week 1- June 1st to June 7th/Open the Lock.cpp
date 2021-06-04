class Solution {
public:
    int openLock(vector<string> &deadends, string target)
{
	queue<string> q;
	unordered_set<string> ends(deadends.begin(), deadends.end());
	int size, turns = 0, a, b;
	string curr, temp;
	
	// Initially our lock will have this pattern
	q.push("0000");
	
	while(!q.empty())
	{
		size = q.size();
		
		while(size)
		{
			size--;
			curr = q.front();
			q.pop();
			
			if(curr == target)
				return turns;
				
			if(ends.find(curr) != ends.end())
				continue;
			ends.insert(curr);
			
			for(int i=0;i<4;i++)
			{
				temp = curr;
				a = temp[i] - '0' + 1;
				b = temp[i] - '0' - 1;
				
				if(b<0)
					b += 10;
					a %= 10;
					b %= 10;
					
					temp[i] = a + '0';
					q.push(temp);
					
					temp[i] = b + '0';
					q.push(temp);				
			}
		}
		turns++;
	}
	return -1;	
}
};
