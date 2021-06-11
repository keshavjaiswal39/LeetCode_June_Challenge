class MyCalendar {
public:
	map<int,int> bookings;
    MyCalendar() 
    {
        
        
    }
    
    bool book(int start, int end) 
	{
		// if the map is empty, then we can directly insert start and end
		if(bookings.empty())
		{
			bookings.insert(pair<int,int> (start,end));
			return true;
		}
		
		// if the start time is inside the map then we go inside this condition
		if(bookings.find(start) == bookings.end())
		{
			// next and prev are iterator not the value
			// next = upperbound of start
			auto next = bookings.upper_bound(start);
			// prev = next and then
			auto prev = next;
			// decrement it
			prev--;
			
			
			// if the next is the end, it means we will compare start with next's second
			if(next == bookings.end())
			{
				// rbegin gives me the last element
				auto last = bookings.rbegin();
				// if start is less then *last.second then return false
				if(start < (*last).second)
					return false;
			}
			
			// if the next is the start, it means we will compare end with next's first
			else if(next == bookings.begin())
			{
				// if the end is greater than *next.first means return false
				if(end> (*next).first)
					return false;
			}
			
			// if i have to insert in between , means check for *next.first and *prev.second
			else if(start < (*prev).second || (end > (*next).first))
				return false;
			
			// All case passed so insert in the map
			bookings.insert(pair<int,int> (start,end));
				return true;
		}
		
		// else we return false
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
