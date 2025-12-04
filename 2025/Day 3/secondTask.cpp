#include<bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
using i64 = long long;

string to_string_i128(i128 x){
    if(x==0) return "0";

    bool neg = false;
    if(x<0){
        neg = true;
        x = -x;
    }

    string s;
    while(x>0){
        s.push_back('0' + (int)(x%10));
        x/=10;
    }

    if(neg) s.push_back('-');

    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ifstream file("input_day3.txt");
    string line;
    i128 ans = 0;

    i64 p10[13];
    p10[0] = 1;

    for(int i=1;i<=12;i++){
        p10[i] = p10[i-1] * 10;
    }
    while(getline(file,line)){
        int n = line.size();
        vector<char>st;

        for(int i=0;i<n;i++){
            char d = line[i];

            while(!st.empty() && d > st.back() && (int)st.size()-1+(n-i)>=12){
                st.pop_back();
            }

            if((int)st.size()<12){
                st.push_back(d);
            }
        }

        for(int i = 0;i<12;i++){
            ans += (st[i]-'0') * p10[11-i];
        }

    }
    cout<<to_string_i128(ans)<<endl;
}