//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 09/08/25.
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


/**
 Leetcode 155: Min Stack
 */

class MinStack {
public:
    
    stack<pair<int,int>> mystack;
    MinStack() {
    }
    
    void push(int val) {
        if(mystack.empty()){
            mystack.push({val,val});
            return;
        }

        int mini = mystack.top().second;
        if(val < mystack.top().second) mini = val;
        
        mystack.push({val,mini});

    }
    
    void pop() {
        mystack.pop();
    }
    
    int top() {
        return mystack.top().first;
    }
    
    int getMin() {
        return mystack.top().second;
    }
};
int main(int argc, const char * argv[]) {
    cout << "heelo" << endl;
    return 0;
}

