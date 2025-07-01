//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 30/06/25.
//

#include <iostream>
using namespace std;

int dp[1000][1000];
void printm(int n, int m){
    
}
bool isValidSubsequence(vector<int> A, vector<int> B) {
  // Write your code here.
  int rows = A.size();
  int cols = B.size();
  
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(A[i] == B[j]){
        dp[i][j] = 1+(i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0);
      }
      else{
        dp[i][j] = max((i-1>=0 ? dp[i-1][j] : 0),(j-1>=0 ? dp[i][j-1] : 0));
      }
    }
    
  }
 return dp[rows-1][cols-1] == cols;
}

int main(int argc, const char * argv[]) {
    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence = {5, 1, 22, 25, 6, -1, 8, 10};
    cout <<isValidSubsequence(array,sequence) << endl;
    return 0;
}

