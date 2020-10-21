#include<bits/stdc++.h>
#define UNDEFINE_PIXEL 'O'

using namespace std;

bool DEBUG = 0;

char* mTable;
int mTable_n, mTable_m;

void Command_I(int, int);
void Command_C();
void Command_L(int, int, char);
void Command_V(int, int, int, char);
void Command_H(int, int, int, char);
void Command_K(int, int, int, int, char);
void Command_F(int, int, char);
void Command_S(string);
void Command_X();

void Command_I(int m, int n){ // create new table M*N
	/*
	if(DEBUG){
		cout<<"create new table M*N | ";
		cout<<"{m}="<<m;
		cout<<";{n}="<<n;
		cout<<'\n';
	}
	*/
	mTable_m = m; mTable_n = n;
	mTable = (char*)malloc(sizeof(char)*n*m);
	Command_C();
}

void Command_S(string fName){ //write now table to the file and print that.
	/*
	if(DEBUG){
		cout<<"write now table to the file and print that. | ";
		cout<<"{fName}="<<fName;
		cout<<'\n';
	}
	*/
	cout<<fName<<'\n';
	for(int i=0;i<mTable_n;++i){
		for(int j=0;j<mTable_m;++j)
			cout<<mTable[i*mTable_m+j];
		cout<<'\n';
	}
}

void Command_C(){
	/*
	if(DEBUG){
		cout<<"clear the table to {"<<UNDEFINE_PIXEL<<"}";
		cout<<'\n';
	}
	*/
	for(int i=0;i<mTable_n;++i){
		for(int j=0;j<mTable_m;++j){
			mTable[i*mTable_m+j]=UNDEFINE_PIXEL;
		}
	}
}

void Command_L(int x, int y, char C){
	/*
	if(DEBUG){
		cout<<"draw C in (x, y) | ";
		cout<<"{mTable_m}="<<mTable_m;
		cout<<";{mTable_n}="<<mTable_n;
		cout<<";{x}="<<x;
		cout<<";{y}="<<y;
		cout<<";{C}="<<C;
		cout<<";{y*mTable_m+x}="<<y*mTable_m+x;
		cout<<'\n';
	}
	*/
	mTable[(y-1)*mTable_m+(x-1)] = C;
}

void Command_V(int x, int y1, int y2, char C){
	if(y1 > y2){
		int c = y1;
		y1 = y2;
		y2 = c;
	}
	for(int i=y1;i<=y2;++i)mTable[(i-1)*mTable_m+(x-1)] = C;
}

void Command_H(int x1, int x2, int y, char C){
	if(x1 > x2){
		int c = x1;
		x1 = x2;
		x2 = c;
	}
	for(int i=x1;i<=x2;++i)mTable[(y-1)*mTable_m+(i-1)] = C;
}

void Command_K(int x1, int y1, int x2, int y2, char C){
	if(DEBUG){
		cout<<"Draw a rectangle pixel | ";
		cout<<"{x1}="<<x1;
		cout<<";{y1}="<<y1;
		cout<<";{x2}="<<x2;
		cout<<";{y2}="<<y2;
		cout<<";{}="<<C;
		cout<<'\n';
	}
	if(x1 > x2){
		int c = x1;
		x1 = x2;
		x2 = c;
	}
	if(y1 > y2){
		int c = y1;
		y1 = y2;
		y2 = c;
	}
	for(int i=y1;i<=y2;++i){
		for(int j=x1;j<=x2;++j){
			mTable[(i-1)*mTable_m+(j-1)] = C;
		}
	}
}

void Command_F(int x, int y, char C){
	char thePixel = mTable[(y-1)*mTable_m+(x-1)];
	Command_L(x, y, C);
	for(int i=0;i<mTable_n;++i){
		for(int j=0;j<mTable_m;++j){
			if(mTable[i*mTable_m+j] == thePixel)mTable[i*mTable_m+j] = C;
		}
	}
}


int main(){
	int m, n, x, y, x1, x2, y1, y2;
	char C;
	char INType;
	string fName;
	ios_base::sync_with_stdio(false);
	while(cin>>INType){
		if(DEBUG)cout<<"test: {INType}="<<INType<<";";
		switch(INType){
			case 'I':
				cin>>m>>n;
				Command_I(m, n);
				break;
			case 'C':
				Command_C();
				break;
			case 'L':
				cin>>x>>y>>C;
				Command_L(x, y, C);
				break;
			case 'V':
				cin>>x>>y1>>y2>>C;
				Command_V(x, y1, y2, C);
				break;
			case 'H':
				cin>>x1>>x2>>y>>C;
				Command_H(x1, x2, y, C);
				break;
			case 'K':
				cin>>x1>>y1>>x2>>y2>>C;
				Command_K(x1, y1, x2, y2, C);
				break;
			case 'F':
				cin>>x>>y>>C;
				Command_F(x, y, C);
				break;
			case 'S':
				cin>>fName;
				Command_S(fName);
				break;
			case 'X':
				return 0;
				break;

			default:
				break;
		}
		if(DEBUG)cout<<"\n new in ";
	}
}
