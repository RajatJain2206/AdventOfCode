#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input_day4.txt");
    vector<vector<char> > paperRolls;
    string line;
    while (getline(file, line))
    {
        vector<char> temp;
        for (int i = 0; i < line.size(); i++)
        {
            temp.push_back(line[i]);
        }
        paperRolls.push_back(temp);
    }

    int drow[8] = {0, 1, 0, -1, 1, 1, -1, -1}; // R,D,L,U,DR,DD,DL,DU
    int dcol[8] = {1, 0, -1, 0, 1, -1, -1, 1};

    int accessible = 0;
    int rowBoundary = paperRolls.size();
    int colBoundary = paperRolls[0].size();
    for (int i = 0; i < rowBoundary; i++)
    {
        for (int j = 0; j < colBoundary; j++)
        {
            if (paperRolls[i][j] == '@')
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    int newRow = i + drow[k];
                    int newCol = j + dcol[k];

                    if (newRow >= 0 && newRow < rowBoundary && newCol >= 0 && newCol < colBoundary && paperRolls[newRow][newCol] == '@')
                    {
                        cnt++;
                    }
                }
                if (cnt < 4){
                    accessible++;
                }
                   
            }
        }
    }
    cout << accessible << endl;
}