#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input_day3.txt");
    string line;
    int ans = 0;
    while(getline(file,line)){
        int n = line.size();
        int firstMax = line[0]-'0';
        int secondMax = INT_MIN;
        int idx = 0;
        for(int i=1;i<n;i++){
            if(i==n-1 && (line[i]-'0')>firstMax) continue;
            if((line[i]-'0')>firstMax){
                firstMax = line[i]-'0';
                idx = i;
            }
        }

        for(int i=idx+1;i<n;i++){
            secondMax = max(secondMax, line[i]-'0');
        }

        ans += firstMax*10+secondMax;
        
    }
    cout<<ans<<endl;
}