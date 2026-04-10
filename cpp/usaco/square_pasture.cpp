#include <bits/stdc++.h>
using namespace std;


struct Rect{
    int x1,x2,y1,y2;
    void read(){ cin>>x1>>y1>>x2>>y2;}
    Rect(int a=0,int b=0,int c=0,int d=0){
        x1 = a;
        y1 = b;
        x2= c;
        y2= d;
    } 
};
int main(){
    Rect a,b;
    
    a.read();
    b.read();

    Rect c(min(a.x1,b.x1),min(a.y1,b.y1),max(a.x2,b.x2),max(a.y2,b.y2));
    int l = max((c.x2-c.x1),(c.y2-c.y1));
    l *= l;
    cout << l << endl;
    return 0; 
}