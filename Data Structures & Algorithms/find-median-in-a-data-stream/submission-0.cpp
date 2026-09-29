class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.size() == right.size()) {
            if(left.empty() || num <= left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }
        } else if(left.size() > right.size()) {
            if(num >= left.top()) {
                right.push(num);
            } else { // need to transfer max left element from left to right
                int maxLeft = left.top();
                left.pop();
                right.push(maxLeft);
                left.push(num);
            }
        } else { // right.size() > left.size()
            if(num <= right.top()) {
                left.push(num);
            } else { // need to transfer min right element from right to left
                int minRight = right.top();
                right.pop();
                left.push(minRight);
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()) { // Middle element exists
            if(left.size() > right.size()) {
                return static_cast<double>(left.top()); //if n odd: median from larger half
            } else {
                return static_cast<double>(right.top()); //if n odd: median from larger half
            }
        } else { // average between two middles
            return static_cast<double>(left.top() + right.top()) / 2.0;
        }
    }

private:
    priority_queue<int> left{}; // smaller numbers, highest first
    priority_queue<int, vector<int>, greater<>> right{}; // higher numbers, lowest first
};

/*
Key insight: Use TWO heaps


[1] -> 1.0
[1,2] -> 1.5
[1,2,3] -> 


Invariants:
1) Arrays need to be balanced (max 1 size diff)
1,  234 => wrong 

2) How do we know what number to add where
No elements => whereever

if balanced: newElement
If imbalanced (more on the left):
    newElmement < left.top() => insert newElement in left, pop left.top, add left.top() to righz 

*/
