#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input2.txt");
    int ans = 0;
    int val = 50;
    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;
        char dir = line[0];
        int rotation = stoi(line.substr(1));
        ans += rotation / 100;
        rotation %= 100;
        int temp = val;

        if (dir == 'L')
        {

            val = (val - rotation + 100) % 100;
            if (temp != 0)
            {
                if (val == 0)
                    ans++;
                else if (val > temp)
                    ans++;
            }
        }
        else
        {
            val = (val + rotation + 100) % 100;
            if (temp != 0)
            {
                if (val == 0)
                    ans++;
                else if (val < temp)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}