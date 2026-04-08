#include<bits/stdc++.h>
using namespace std;

int main() {
	int cows;
    string str;

    cin>>cows;
    cin>>str;
    int n = str.length();
    int flips = 0;
    for(int i=n-2;i>=0;i-=2){
        string curr = str.substr(i,2);
        if((curr == "GH" && flips %2 == 0) || (curr == "HG" && flips%2 == 1)) flips++;
    }

	cout << flips << endl;
}