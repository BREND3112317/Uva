#include<iostream>
#include<queue>
using namespace std;

class point{
public:
    point(int x, int y);
    int x,y;
};

point::point(int x,int y){
    this->x = x;
    this->y = y;
}


int main(){
    int n=4,m=4;
    queue<point*> stars;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            //cout<<map[i][j]<<" ";
            stars.push(new point(i,j));
        }
        //cout<<";\n";
    }

    point *p;
    while(stars.empty() == false){
        p = stars.front();
        cout<<p->x<<", "<<p->y<<'\n';
        stars.pop();
    }
}
