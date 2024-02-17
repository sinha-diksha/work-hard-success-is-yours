class MedianFinder {
   priority_queue<int> left_max_heap;
   priority_queue<int, vector<int>, greater<int> > right_min_heap;
   int size;

public:
    MedianFinder() {
       size=0;
    }
    
    void addNum(int num) {
        size++;
        if(left_max_heap.size()==0 || num<left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }
        int a=left_max_heap.size();
        int b=right_min_heap.size();

        if(a-b>1){
            
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(a<b){
            cout<<right_min_heap.top()<<endl;
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(size%2==0){
            return (left_max_heap.top()+right_min_heap.top())/(double)2;
        }
        double a=left_max_heap.top();
        return a;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */