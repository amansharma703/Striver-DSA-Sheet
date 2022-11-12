// PROBLEM LINK
// https://leetcode.com/problems/min-stack/

/*
    Solution : BruteForce
    Time complexity : O(N)
    Space Complexity : O(N)
*/


class MinStack {
    vector<int> v;
    int minVal = INT_MAX;
public:
    MinStack() {
        
    }
    
    void findMin(){
        int minv = INT_MAX;
        for(auto x : v){
            minv = min(x, minv);
        }
        minVal = minv;
    }

    void push(int val) {
        v.push_back(val);
        minVal = min(val, minVal);
    }
    
    void pop() {
        int back = v.back();
        v.pop_back();
        if(back == minVal){
            findMin();
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */