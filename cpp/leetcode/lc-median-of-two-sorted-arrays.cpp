//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 23/08/25.
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
 Leetcode 4: Median of two sorted arrays
 */

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size()) swap(A,B);

        int total = A.size()+B.size();
        int half = (total)/2;

        int left = 0;
        int right = A.size();

        while(left<=right){
            int i = (left+right)/2;
            int j = half-i;

            int Aleft = (i > 0) ? A[i - 1] : INT_MIN;
            int Aright = (i < A.size()) ? A[i] : INT_MAX;
            int Bleft = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < B.size()) ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright){
                if(total%2){
                    return (double)min(Aright,Bright);
                }
                else{
                    return (double)(max(Aleft,Bleft) + min(Aright,Bright))/2-0;
                }
                
            }
            else if(Aleft > Bright){
                right = i-1;
            }
            else left = i+1;
        }
        return -1;
    }
int main(int argc, const char * argv[]) {
    vector<int> in = {1,3};
    vector<int> in2 = {2};
    cout << findMedianSortedArrays(in,in2) << endl;
    return 0;
}

