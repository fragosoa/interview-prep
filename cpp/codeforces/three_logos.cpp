#include <bits/stdc++.h>
using namespace std;

class Rectangle{
public:
    int x,y;
    vector<vector<char>> grid;
    bool isError = false;
    Rectangle(int ix,int iy,char c = '.') {
        x = ix;
        y = iy;
        grid.assign(y,vector<char>(x,c));
        if(c == 'E') isError = true;
    }

    void setGrid(vector<vector<char>> grid1){
        grid = grid1;
    }

    void printXY(){
        cout << x << " , " << y << endl;
    }

    void printGrid(){
        for(int i = 0;i<y;i++){
            for(int j=0;j<x;j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    void rotate(){
        int nx = y;
        int ny = x;

        vector<vector<char>> ngrid;
        ngrid.assign(ny,vector<char>(nx,'.'));

        for(int i=0;i<ny;i++){
            for(int j=0;j<nx;j++){
                ngrid[i][j] = grid[y-1-j][i];
            }
        }

        x = nx;
        y = ny;
        grid = ngrid;
    }
};

Rectangle generateRectangleH(Rectangle A, Rectangle B){
    // A left of B, requires A.y == B.y
    int x = A.x + B.x;
    int y = A.y;

    vector<vector<char>> grid;
    grid.assign(y, vector<char>(x, '.'));

    for(int i = 0; i < A.y; i++)
        for(int j = 0; j < A.x; j++)
            grid[i][j] = A.grid[i][j];

    for(int i = 0; i < B.y; i++)
        for(int j = 0; j < B.x; j++)
            grid[i][A.x + j] = B.grid[i][j];

    Rectangle c = Rectangle(x, y);
    c.setGrid(grid);
    return c;
}

Rectangle generateRectangle(Rectangle A, Rectangle B){
    int x = A.x;
    int y = A.y + B.y;
    
    vector<vector<char>> grid;
    grid.assign(y,vector<char>(x,'.'));
    int i = 0;
    int j = 0;
    for(i=0;i<A.y;i++){
        for(j=0;j<A.x;j++){
            grid[i][j] = A.grid[i][j];
        }
    }
    j = 0;


    for(int k=0;k<B.y;k++){
        j = 0;
        for(int l=0;l<B.x;l++){
            grid[i][j] = B.grid[k][l]; 
            j++;
        }
        i++;
    }
    Rectangle c = Rectangle(x,y);
    c.setGrid(grid);
    
    return c;

}

vector<Rectangle> check(Rectangle A, Rectangle B){
    vector<Rectangle> results;
    for(int ra = 0; ra < 2; ra++){
        for(int rb = 0; rb < 2; rb++){
            Rectangle ta = A, tb = B;
            if(ra) ta.rotate();
            if(rb) tb.rotate();
            if(ta.x == tb.x) results.push_back(generateRectangle(ta, tb));
            if(ta.y == tb.y) results.push_back(generateRectangleH(ta, tb));
        }
    }
    return results;
}


/*
5 1 2 5 5 2
*/
int main(){
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    Rectangle a = Rectangle(ax,ay,'A');
    Rectangle b = Rectangle(bx,by,'B');
    Rectangle c = Rectangle(cx,cy,'C');

    vector<Rectangle> rectangles = {a,b,c};

    int totalArea = ax*ay + bx*by + cx*cy;
    int n = (int)round(sqrt(totalArea));

    vector<tuple<int,int,int>> pairs = {{0,1,2},{0,2,1},{1,2,0}};
    for(auto [c1,c2,rem] : pairs){
        for(auto& C : check(rectangles[c1], rectangles[c2])){
            for(auto& D : check(C, rectangles[rem])){
                if(D.x == D.y && D.x == n){
                    cout << D.x << endl;
                    D.printGrid();
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0; 
}