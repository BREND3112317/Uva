#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

int n=7;
char BASE_KEY[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int convert2DEC(string str, int base){
    int ans = 0;
    for(int i=0;i<str.length();++i){
        if(str[i]>=48 && str[i]<48+10)ans = ans*base + (str[i]-48);
        else if(str[i]>=65 && str[i]<65+26)ans = ans*base + (str[i]-55);
        if(DEBUG)cout<<"{ans}="<<ans<<'\n';
    }
    return ans;
}

string DEC2BASE(int num, int base){
    string ans = "";
    for(int i=0;i<n;++i){
        ans = BASE_KEY[num%base] + ans;
        num/=base;
    }
    return ans;
}

int main(){
    string str;
    int base_1, base_2;
    while(cin>>str>>base_1>>base_2){
        int num = convert2DEC(str, base_1);
        string ans = DEC2BASE(num, base_2);
        if(DEBUG)cout<<str<<" = "<<num<<" = ";
        cout<<ans<<'\n';
    }
}

/*
1111000 2 10
1111000 2 16
2102101 3 10
2102101 3 15
12312 4 2
1A 15 2
ABCD 16 15
03 13 10
*/
