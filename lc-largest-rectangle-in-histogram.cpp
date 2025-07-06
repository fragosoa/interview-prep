//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 03/07/25.
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


int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
    
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) right[i] = n-1;
            else right[i] = s.top()-1;
            s.push(i);
        }
        stack<int> s2;

        for(int i=0;i<n;i++){
            while(!s2.empty() && heights[s2.top()] >= heights[i]) s2.pop();
            if(s2.empty()) left[i] = 0;
            else left[i] = s2.top()+1;
            s2.push(i);
        }
        right[n-1] = n-1;
        left[0] = 0;

        int maxi = 0;
        for(int i=0;i<n;i++){
            int area = heights[i]*(right[i]-left[i]+1);
            maxi = max(maxi,area);
        }

        return maxi;
}

/**
 Leetcode 84. Largest Rectangle in Histogram
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {2,1,5,6,2,3};
    int res = largestRectangleArea(in);
    cout << res << endl;
    return 0;
}

