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

int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxarea = 0;
        while(left<right){
            int area = min(height[left],height[right])*(right-left);
            maxarea = max(maxarea,area);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxarea;
    }
/**
 Leetcode 11: Container with most water
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {1,8,6,2,5,4,8,3,7};
    int ans=maxArea(in);
    cout << ans << endl;
    
    return 0;
}

