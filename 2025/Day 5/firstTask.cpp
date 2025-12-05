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

    i64 ans = 0;

    while(getline(file,line)){

        if(line.empty()) continue;
        i128 id = to_i128(line);

        int lo = 0 , hi = merged.size()-1;
        bool fresh = false;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(merged[mid].first <=id){
                if(merged[mid].second>=id){
                    fresh = true;
                    break;
                }
                lo = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }

        if(fresh) ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}