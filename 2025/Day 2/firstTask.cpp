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
i64 ceil_div(i64 a , i64 b){
    return (a+b-1)/b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ifstream file("input1_day2.txt");

    if(!file){
        cout<<"Error";
        return 1;
    }

    vector<pair<i64,i64>>ranges;
    string line;

    while(getline(file,line)){
        if(line.empty()) continue;
        for(char &c : line){
            if(c==',') c = ' ';
        }

        stringstream ss(line);
        string token;

        while(ss >> token){
            auto dash = token.find('-');
            if(dash == string::npos) continue;

            i64 L = stoll(token.substr(0, dash));
            i64 R = stoll(token.substr(dash+1));
            ranges.push_back({L,R});
        }
    }

    i64 p10[20];
    p10[0] = 1;

    for(int i=1;i<=19;i++){
        p10[i] = p10[i-1] * 10;
    }

    i128 total_sum = 0;

    for(auto &rg: ranges){
        i64 L = rg.first;
        i64 R = rg.second;

        for(int k=1;k<=9;k++){
            i64 base = p10[k];
            i64 m = base + 1;

            i64 x_min = p10[k-1];
            i64 x_max = base - 1;

            i64 lo = ceil_div(L,m);
            i64 hi = R/m;

            i64 x1 = max(x_min,lo);
            i64 x2 = min(x_max,hi);

            if(x1>x2) continue;

            i128 cnt = (i128)(x2-x1+1);
            i128 sum_x = (i128)(x1+x2)*cnt/2;
            i128 sumN = sum_x * (i128)m;

            total_sum += sumN;
        }
    }
    cout << to_string_i128(total_sum) << "\n";
    return 0;
}