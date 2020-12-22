#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define DEBUG 1

using namespace std;

struct myClass {
    bool operator() (int a, int b) {return a>b;}
} mySortOpera;

int maxNum(vector <int> arr);
vector<int> DEC2Vc(int num);
int Vc2DEC(vector <int> arr);
void showVector(vector <int>arr);

int maxNum(vector <int> arr){
    sort(arr.begin(), arr.end(), mySortOpera);
    showVector(arr);
    return Vc2DEC(arr);
}

vector<int> DEC2Vc(int num){
    int length = ceil(log10(num));


    if(DEBUG){
        cout<<"function - DEC2Vc\n";
        cout<<"\tlength= "<<length<<'\n';
    }
    /*
    int *arr = new int[length];

    for(int i=length-1;i>=0;--i){
        *(arr+i) = num%10;
        num/=10;
    }
    */

    vector<int> arr(length, 0);
    for(int i=length-1;i>=0;--i){
        arr.at(i)=(num%10);
        num/=10;
    }
    return arr;
}

int Vc2DEC(vector <int> arr){
    int num = 0;
    for(int i=0;i<arr.size();++i){
        num*=10;
        num+=arr.at(i);
        cout<<'\t'<<num<<'\n';
    }
    return num;
}

void showVector(vector <int>arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr.at(i);
    }
    cout<<';';
    return;
}

int main(){
    int num = 123456789;
    vector <int> numArr;
    numArr = DEC2Vc(num);
    int maxnum = maxNum(numArr);
    showVector(numArr);
    cout<<'\n';
    cout<<"maxnum= "<<maxnum<<'\n';
    return 0;
}
