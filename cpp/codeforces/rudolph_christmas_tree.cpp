#include<bits/stdc++.h>
using namespace std;

int n;
double b,h;
double trapecio(int dist){
    return (double)dist*(double)dist*(b/h)/2;
}
void solve(){
    cin>>n>>b>>h;
    vector<int> bases(n);

    for(int &p:bases) cin>>p;
    double total = 0;

    int curr = bases[0];
    for(int i=1;i<n;i++){
        //cout << "hge"<< endl;
        pair<int,int> A = make_pair(curr,curr+h);
        pair<int,int> B = make_pair(bases[i],bases[i]+h);
        
        double area = 0;
        int dist = min(A.second,B.second) - max(A.first,B.first);
        if(dist <= 0){
            area  = (b*h/2);
        }
        else{
            area = (double)((double)(b*h)/2) - trapecio(dist);
        }
        //cout << area << endl;
        total += area;
        curr = bases[i];
    }
    //cout << "---" << endl;
    total += (double)((double)(b*h)/2);
    cout << fixed << setprecision(9) << total << endl;
}
int main() {
    int q;
    cin>>q;
    while(q--){
        solve();
    }
}