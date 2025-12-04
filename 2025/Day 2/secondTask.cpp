#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
using i64 = long long;
;

string to_string_i128(i128 x)
{
    if (x == 0)
        return "0";

    bool neg = false;
    if (x < 0)
    {
        neg = true;
        x = -x;
    }

    string s;
    while (x > 0)
    {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }

    if (neg)
        s.push_back('-');

    reverse(s.begin(), s.end());
    return s;
}
i64 ceil_div(i64 a, i64 b)
{
    return (a + b - 1) / b;
}

bool isRepeated(i64 x)
{
    string s = to_string(x);
    int n = (int)s.size();

    for(int len = 1;len*2<=n;len++){
        if(n%len!=0)continue;
        int t = n/len;
        if(t<2)continue;
        string block = s.substr(0,len);
        bool ok = true;
        for(int i=len;i<n;i+=len){
            if(s.substr(i,len)!=block){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input1_day2.txt");

    if (!file)
    {
        cout << "Error";
        return 1;
    }

    vector<pair<i64, i64>> ranges;
    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;
        for (char &c : line)
        {
            if (c == ',')
                c = ' ';
        }

        stringstream ss(line);
        string token;

        while (ss >> token)
        {
            auto dash = token.find('-');
            if (dash == string::npos)
                continue;

            i64 L = stoll(token.substr(0, dash));
            i64 R = stoll(token.substr(dash + 1));
            ranges.push_back({L, R});
        }
    }

    i64 pow10[20];
    pow10[0] = 1;

    for (int i = 1; i <= 18; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }

    unordered_set<i64>invalidIds;
    invalidIds.reserve(1000000);

    for (auto [L, R] : ranges)
    {
        if(L>R) swap(L,R);
        if(R<=0) continue;

        for(int k=1;k<=18;k++){
            for(int t=2;k*t<=18;t++){
                i128 M = 0;
                for(int i=0;i<t;i++){
                    int exp = k*i;
                    if(exp>18){
                        M=0;
                        break;
                    }
                    M += (i128)pow10[exp];
                }
                if(M==0) continue;

                i64 m = (i64)M;
                i64 x_min = pow10[k-1];
                i64 x_max = pow10[k]-1;

                i64 x_low = ceil_div(max<i64>(L,1),m);
                i64 x_high = R/m;

                i64 x1 = max(x_low,x_min);
                i64 x2 = min(x_high,x_max);
                if(x1>x2) continue;

                for(i64 x=x1;x<=x2;x++){
                    i128 N = (i128)x*(i128)m;
                    if(N<L || N>R) continue;
                    i64 n = (i64)N;
                    if(isRepeated(n)){
                        invalidIds.insert(n);
                    }
                }
            }
        }
    }
    i128 total_sum = 0;
    for(i64 v : invalidIds){
        total_sum += (i128)v;
    }
    cout << to_string_i128(total_sum) << "\n";
    return 0;
}