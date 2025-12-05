#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

i128 to_i128(const string &s){
    i128 ans = 0;
    for(char c : s){
        ans = ans*10 + (c-'0');
    }
    return ans;
}

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
    ifstream file("input_day5.txt");

    vector<pair<i128,i128>>ranges;
    string line;

    while(getline(file,line)){

        if(line.empty()) break;
        int dash = line.find('-');
        i128 left = to_i128(line.substr(0,dash));
        i128 right = to_i128(line.substr(dash+1));

        ranges.push_back({left, right});
    }

    sort(ranges.begin(), ranges.end());

    vector<pair<i128,i128>>merged;
    for(auto &p : ranges){
        if(merged.empty() || p.first > merged.back().second+1){
            merged.push_back(p);
        }
        else{
            merged.back().second = max(merged.back().second,p.second);
        }
    }

    i128 ans = 0;
    for(auto &p : merged){
        ans += (p.second - p.first + 1);
    }

    cout<<to_string_i128(ans)<<endl;
    
    return 0;
}