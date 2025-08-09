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


/**
 Leetcode 260: Single number iii
 */

vector<int> singleNumber(vector<int>& nums) {
    int c = 0;
    for(int x:nums){
        c ^= x;
    }
    // a^b = c
    int diff = c & -c;
    int a = 0;
    int b = 0;
    for(int x:nums){
        if(x&diff){
            a ^= x;
        }
        else{
            b ^= x;
        }
    }
    return {a,b};
}

int main(int argc, const char * argv[]) {
    vector<int> in = {1,2,1,3,2,5};
    vector<int> res =singleNumber(in);
    cout << res[0] << " , " << res[1] << endl;
    
    return 0;
}

