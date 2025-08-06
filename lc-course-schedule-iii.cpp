//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 5/08/25.
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


int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int> &a, const vector<int> &b){ return a[1] < b[1];});

        int time = 0;
        priority_queue<int> pq;

        for(auto course:courses){
            int duration = course[0];
            int deadline = course[1];

            if(time+duration <= deadline){
                time+=duration;
                pq.push(duration);
            }
            else if(!pq.empty() && pq.top() > duration){
                time-=pq.top();
                pq.pop();
                pq.push(duration);
                time+=duration;
            }
        }

        return pq.size();

    }

/**
 Leetcode 630: Course Schedule iii
 */


int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{3,2},{4,3}};
    int res = scheduleCourse(in);
    cout << res << endl;
    return 0;
}

