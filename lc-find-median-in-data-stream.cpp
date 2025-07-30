//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 29/07/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;


class MedianFinder {
public:
    struct maxCompare{
        bool operator()(const int &a,const int &b){
            return a<b;
        }
    };

    struct minCompare{
        bool operator()(const int &a,const int &b){
            return a>b;
        }
    };

    // left
    priority_queue<int, vector<int>, maxCompare> maxHeap;

    //right
    priority_queue<int, vector<int>, minCompare> minHeap;
    MedianFinder() {
        
    }

    void balance(){
        int leftSize = maxHeap.size();
        int rightSize = minHeap.size();

        // left is greater than right
        if(leftSize-rightSize > 1){
            int tp = maxHeap.top();maxHeap.pop();
            minHeap.push(tp);
            return;
        }
        if(rightSize-leftSize > 1){
            int tp = minHeap.top();minHeap.pop();
            maxHeap.push(tp);
            return;
        }
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        int leftTop = maxHeap.top();
        if(num>leftTop) minHeap.push(num);
        else maxHeap.push(num);

        balance();

    }
    
    double findMedian() {
        int leftSize = maxHeap.size();
        int rightSize = minHeap.size();

        if(leftSize == rightSize){
            return (double)(maxHeap.top()+minHeap.top())/2;
        }
        if(leftSize > rightSize) return maxHeap.top();
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 Leetcode 295: Find median in data stream
 */

int main(int argc, const char * argv[]) {
    cout << "hee" << endl;
    return 0;
}

