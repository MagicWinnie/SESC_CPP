#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

int rand_in_range(int min, int max)
{
    return min + (rand() * (int)(max - min) / RAND_MAX);
}

vector<string> split(string s, char deli = ' ')
{
    vector<string> out;
    string buffer;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] != deli)
            buffer += s[i]; 
        else
        {
            out.push_back(buffer);
            buffer = "";
        }
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "rus");
    fstream f("input_text.txt");
    
    srand((unsigned)time(NULL));

    vector<vector<string>> db_keys;
    vector<string> db_values;

    string s1, s2, s3;
    f >> s1 >> s2;

    while (f >> s3)
    {
        vector<string> temp = { s1, s2 };
        db_keys.push_back(temp);
        db_values.push_back(s3);
        s1 = s2;
        s2 = s3;
    }

    int rand_start = rand_in_range(0, db_keys.size());
    vector<string> to_find = { db_keys[rand_start][0], db_keys[rand_start][1] };

    cout << to_find[0] << " " << to_find[1] << " ";
    
    for (int i = 0; i < 100; i++)
    {
        vector<string> matches;
        for (int i = 0; i < db_keys.size(); i++)
            if (db_keys[i][0] == to_find[0] && db_keys[i][1] == to_find[1]) matches.push_back(db_values[i]);

        if (matches.size() == 0) 
        { 
            break;
            cout << "STOPPING" << endl;
        }

        string temp = matches[rand_in_range(0, matches.size())];
        cout << temp << " ";
        to_find = { to_find[1], temp };
    }
    f.close();
}