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


int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxprofit = 0;

        for(int x:prices){
            if(x<mini){
                mini = x;
            }

            maxprofit = max(maxprofit,x-mini);
        }

        return maxprofit;
    }

/**
 Leetcode 121: Best time to buy and sell stock
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {7,1,5,3,6,4};
    int res = maxProfit(in);
    cout << res << endl;
    return 0;
}

