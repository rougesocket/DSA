class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int,vector<int> , greater<int> > mi;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    	//adding elements if the top of min heap is less
        if(mi.size()>0 && mi.top()<num){
            mi.push(num);
        }else{
        	//push it to max half
            mx.push(num);
        }
        
        //if difference is two we need to balance it so that we have correct median at the top
        if(mi.size()-mx.size()==2){
            mx.push(mi.top());
            mi.pop();
        }else if(mx.size()-mi.size()==2){
            mi.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
    	//if sizes are equal then we have even elements so median is the average of the two
        if(mx.size()==mi.size())return (mi.top()+mx.top())/2.0;
        //else we have odd elements so the heap which has larger elements will always contain the median
        return (mx.size()>mi.size())? mx.top(): mi.top();
    }
};
