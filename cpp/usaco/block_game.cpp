#include <bits/stdc++.h>
using namespace std;


vector<int> process(string s1,string s2){
    vector<int> a(26);
    vector<int> b(26);
    vector<int> c(26);

    for(char c:s1){
        a[c - 'a']++;
    }
    for(char c:s2){
        b[c - 'a']++;
    }

    for(int i=0;i<a.size();i++){
        c[i] = max(a[i],b[i]);
    }
    return c;
}
void combine(vector<int> &a, vector<int> &letters){
    for(int i=0;i<letters.size();i++){
        letters[i] += a[i];
    }
}
int main(){
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);

    int n;
    cin>>n;
    vector<int> letters(26);
    for(int i=0;i<n;i++){
        string w1,w2;
        cin>>w1>>w2;
        vector<int> res = process(w1,w2);
        combine(res,letters);
    }
    for(int i=0;i<26;i++){
        cout << letters[i] << endl;
    }
    return 0; 
}