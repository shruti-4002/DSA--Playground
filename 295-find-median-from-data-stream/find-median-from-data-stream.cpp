class MedianFinder {
public:
    vector<int>arr;
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
           //blindly push elemnts 
        maxheap.push(num);

        //now check the psuhed element is pushed correct
        if(!minheap.empty() && minheap.top()<maxheap.top()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }

           //now since we pushed arr either in max or min heap
        //2 cases either size of maxheap is greater or minheap is greater

        if(maxheap.size()>minheap.size()+1){
              minheap.push(maxheap.top());
            maxheap.pop();
        }else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(arr.size()==1){
            return arr[0];
        }
    
        //final size ke hisab se
        if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        }
        
        // Even count: Both tops ka average
        return (maxheap.top() + minheap.top()) / 2.0;


        
    




        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */