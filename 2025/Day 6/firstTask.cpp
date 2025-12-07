#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string>lines;
    string s;
    ifstream file("input_day6.txt");
    while(getline(file,s)) lines.push_back(s);

    int rows = lines.size();
    int cols = 0;

    for(auto &r : lines) cols = max(cols,(int)r.size());

    for(auto &r : lines) r.resize(cols,' ');

    vector<bool> isSep(cols,false);
    for(int c=0;c<cols;c++){
        bool sep = true;
        for(int r = 0;r<rows;r++){
            if(lines[r][c]!=' '){
                sep = false;
                break;
            }
        }
        isSep[c] = sep;
    }

    vector<pair<int,int>>problems;
    int c = 0;
    while(c<cols){
        if(isSep[c]){
            c++;
            continue;
        }
        int start = c;
        while(c<cols && !isSep[c]) c++;
        problems.push_back(make_pair(start,c));
    }

    long long total = 0;

    for(auto &p : problems){
        int L = p.first;
        int R = p.second;

        vector<long long>nums;

        for(int r=0;r<rows-1;r++){
            string seg = lines[r].substr(L,R-L);

            string digits = "";
            for(char ch : seg){
                if(isdigit(ch)) digits.push_back(ch);
            }

            if(!digits.empty()){
                nums.push_back(stoll(digits));
            }
        }

        string opSeg = lines[rows-1].substr(L,R-L);
        char op = 0;

        if(opSeg.find('+')!=string::npos) op ='+';
        else if (opSeg.find('*') != string::npos) op = '*';

        long long value;
        if (op == '+') {
            value = 0;
            for (auto x : nums) value += x;
        } else {
            value = 1;
            for (auto x : nums) value *= x;
        }

        total += value;
    }

    cout<<total<<endl;
}