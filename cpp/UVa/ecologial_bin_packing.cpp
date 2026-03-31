#include <bits/stdc++.h>
using namespace std;

vector<int> bins = {0,1,2};
vector<vector<int>> numbers(3,vector<int>(3));

int getmoves(vector<int> conf){
    int src1 = 0;
    int src2 = 1;
    int dest = 2;

    int moves = numbers[conf[src1]][conf[dest]] + numbers[conf[src2]][conf[dest]];

    src1 = 0;
    src2 = 2;
    dest = 1;

    moves += numbers[conf[src1]][conf[dest]] + numbers[conf[src2]][conf[dest]];

    src1 = 1;
    src2 = 2;
    dest = 0;

    moves += numbers[conf[src1]][conf[dest]] + numbers[conf[src2]][conf[dest]];

    return moves;
}
int minmovs = 10000000;
int main(){
    
    cin>>numbers[0][0];
    cin>>numbers[0][1];
    cin>>numbers[0][2];

    cin>>numbers[1][0];
    cin>>numbers[1][1];
    cin>>numbers[1][2];

    cin>>numbers[2][0];
    cin>>numbers[2][1];
    cin>>numbers[2][2];
    
    map<int,char>  nams;
    nams[0] = 'B';
    nams[1] = 'G';
    nams[2] = 'C';


    do{
        int movs = getmoves(bins);
        minmovs = min(minmovs,movs);
    }while(next_permutation(bins.begin(),bins.end()));
    cout << minmovs << endl;

    return 0; 
}