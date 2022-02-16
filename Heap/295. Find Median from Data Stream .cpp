class MedianFinder {
public:
    
    priority_queue<int> first; // maxHeap
    priority_queue<int, vector<int>, greater<int>> second; // minHeap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if( first.empty() || first.top() > num )
            first.push(num);
        else
            second.push(num);
        
        int firstSize = first.size();
        int secondSize = second.size();
        
        // firstHalf has more 
        if(firstSize - secondSize > 1)
        {
            second.push(first.top());
            first.pop();
        }
        // secondhalf has more
        else if(secondSize - firstSize > 1)
        {
            first.push(second.top());
            second.pop();
        }
        
    }
    
    double findMedian() 
    {
        // both have equal size , average of both
        if(first.size() == second.size())
        {
            return first.empty() ? 0 : ( first.top() + second.top()) / 2.0;
        }
        //otherwise top element of having more values
        else
        {
            return first.size() > second.size() ? first.top() : second.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
