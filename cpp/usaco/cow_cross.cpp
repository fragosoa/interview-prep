#include <bits/stdc++.h>
using namespace std;


unordered_map<char,pair<int,int>> intervals;

bool check(char a,char b){
    pair<int,int> A = intervals[a];
    pair<int,int> B = intervals[b];
    return A.first < B.first && B.first < A.second && A.second < B.second;
    
}
int main(){
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);

    string paths;
    cin>>paths;
    
    


    for(int i=0;i<paths.length();i++){
        char cow = paths[i];
        // cow not there
        if(intervals.find(cow) == intervals.end()){
            intervals[cow] = make_pair(i,-1);
        }
        else{
            intervals[cow].second = i;
        }
    }

    /*for(auto kv:intervals){
        cout << kv.first << ": " << kv.second.first << " , " << kv.second.second << endl;
    }*/
    int count = 0;
    for(char cow = 'A';cow<='Z';cow++){
        for(char other = 'A';other<='Z';other++){
            if(cow == other)continue;
            if(check(cow,other)) count++;
        }
    }
    cout << count << endl;
    return 0; 
}