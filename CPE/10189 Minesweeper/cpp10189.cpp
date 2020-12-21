#include<iostream>

using namespace std;

int n,m;
int **ans;

void newAns(int, int);
void isStar(int x, int y);
void addPoint(int x,int y);

void newAns(int n, int m){
    ans = new int*[n];
    for(int i=0;i<n;++i){
        ans[i] = new int[m];
        for(int j=0;j<m;++j){
            ans[i][j] = 0;
        }
    }
}

void isStar(int x, int y){
    addPoint(x+1, y-1);
    addPoint(x+1, y);
    addPoint(x+1, y+1);
    addPoint(x  , y+1);
    addPoint(x-1, y+1);
    addPoint(x-1, y);
    addPoint(x-1, y-1);
    addPoint(x  , y-1);
}

void addPoint(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m)return ;
    ++ans[x][y];
}

int main(){
    /*
    n=4,m=4;
    string map[4];
    map[0] = "*...";
    map[1] = "....";
    map[2] = ".*..";
    map[3] = "....";
    */
    /*
    n=3,m=5;
    string map[3];
    map[0] = "**...";
    map[1] = ".....";
    map[2] = ".*...";
    */

    while(cin>>n>>m){
        if(n==0 && m==0)break;
        newAns(n, m);

        string map[n];
        for(int i=0;i<n;++i){
            cin>>map[i];
            for(int j=0;j<m;++j){
                if(map[i][j] == '*'){
                    isStar(i, j);
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<(map[i][j]=='*' ? '*' : (char)(ans[i][j]+48));
            }
            cout<<'\n';
        }
    }
    delete [] ans;
    return 0;
}
