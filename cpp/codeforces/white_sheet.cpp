#include <bits/stdc++.h>
using namespace std;


struct Rect{
    int x1,y1,x2,y2;
    void read(){
        cin>>x1>>y1>>x2>>y2;
    }
    long long area(){
        return (long long)(x2-x1)*(y2-y1);
    }
};

long long intersect(Rect A,Rect B){
    long long xoverlap = max(0LL,(long long)min(A.x2,B.x2) - max(A.x1,B.x1));
    long long yoverlap = max(0LL,(long long)min(A.y2,B.y2) - max(A.y1,B.y1));

    return xoverlap*yoverlap;
}

// Returns the overlapping rectangle of A and B (may be degenerate)
Rect intersectRect(Rect A, Rect B){
    return {max(A.x1,B.x1), max(A.y1,B.y1), min(A.x2,B.x2), min(A.y2,B.y2)};
}

int main(){
    Rect c,a,b;
    c.read();
    a.read();
    b.read();

    Rect ab = intersectRect(a,b);
    long long tripleIntersect = intersect(ab,c);
    long long remainArea = intersect(a,c) + intersect(b,c) - tripleIntersect;
    //cout << (c.area()-remainArea) << endl;
    if(c.area() > remainArea){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


    return 0; 
}