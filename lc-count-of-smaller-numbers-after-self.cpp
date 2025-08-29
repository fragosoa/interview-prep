//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 27/08/25.
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
 Leetcode 315: Count of smaller numbers after self
 */
int N = 200005;
int offset = 10000;
vector<int> st;

void build(){
    st.resize(2*N,0);
}

// [l,r)
int query(int l,int r){
    int sum = 0;
    for(l+=N,r+=N;l<r;l>>=1,r>>=1){
        if(l & 1) sum+= st[l++];
        if(r & 1) sum+= st[--r];
    }
    
    return sum;
}
void update(int x){
    for(st[x+=N]++; x>1; x>>=1){
        st[x>>1] = st[x] + st[x^1];
    }
}
vector<int> countSmaller(vector<int>& nums) {
    
    int n = nums.size();
    build();
    vector<int> res(n,0);
    for(int i=n-1;i>=0;i--){
        int val = nums[i]+offset;
        res[i] = query(0,val);
        update(val);
    }
    
    return res;
    
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {5,2,6,1};
    vector<int> ans =countSmaller(nums);
    for(int x:ans){
        cout << x << " ";
    }
    return 0;
}

