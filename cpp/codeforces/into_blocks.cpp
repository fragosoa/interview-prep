#include <bits/stdc++.h>
using namespace std;



class Interval{
public:
    int start,end,key;
    Interval(int _start,int _end,int _key){
        start = _start;
        end = _end;
        key = _key;
    }
};
unordered_map<int,Interval> intervals;
unordered_map<int,int> numelems;


int main() {

	int n,q;
    cin>>n>>q;

    vector<int> nums(n);
    for(int &p:nums) cin>>p;

    for(int i=0;i<n;i++){
        int x = nums[i];
        if(intervals.find(x) == intervals.end()){
            Interval e = Interval(i,i,x);
            intervals.insert({x,e});
            numelems[x] = 1;
        } 
        else{
            intervals.at(x).end = i;
            numelems[x]++;
        }
    }

    vector<Interval> L;
    for(auto kv:intervals){
        L.push_back(kv.second);
    }

    sort(L.begin(),L.end(),[](Interval a,Interval b){
        return a.start < b.start;
    });

    Interval curr = L[0];
    int currdif = 0;
    int curr_total = numelems[curr.key];
    int curr_max = numelems[curr.key];
    for(int i=1;i<L.size();i++){
        if(curr.start <= L[i].start && L[i].start <= curr.end){
            curr_total += numelems[L[i].key];
            curr_max = max(curr_max, numelems[L[i].key]);
            curr.start = min(curr.start,L[i].start);
            curr.end = max(curr.end,L[i].end);
        }
        else{
            currdif += curr_total - curr_max;
            curr = L[i];
            curr_total = numelems[curr.key];
            curr_max = numelems[curr.key];
        }
    }
    currdif += curr_total - curr_max;

    cout << currdif << endl;






}