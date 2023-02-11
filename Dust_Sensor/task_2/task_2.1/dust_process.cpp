#include<bits/stdc++.h>
using namespace std;

vector <string> separate(string s, char c) {
    vector <string> x;
    string cur = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != c) {
            cur += s[i];
        } else {
            int r = cur.size() - 1;
            while (r >= 0 && cur[r] == ' ') r--;
            int l = 0;
            while (l < cur.size() && cur[l] == ' ') l++;
            if (cur.substr(l, r - l + 1) != "") {
                x.push_back(cur.substr(l, r - l + 1));
            }
            cur = "";
        }
    }

    int r = cur.size() - 1;
    while (r >= 0 && cur[r] == ' ') r--;
    int l = 0;
    while (l < cur.size() && cur[l] == ' ') l++;
    if (cur.substr(l, r - l + 1) != "") {
        x.push_back(cur.substr(l, r - l + 1));
    }
    
    return x;
}

int main(int argc, char** argv) { 
    string line;
    vector <string> lines;
    vector < vector <string> > separated, finals, outliers;
    float values[10000];

    ifstream in;
    in.open("../../task_1/dust_sensor.csv");

    while (getline(in, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        separated.push_back(separate(lines[i], ','));
    }

    for (int i = 1; i < lines.size(); i++) {
        values[i] = stof(separated[i][3]);
        if ((values[i] < 5) || (values[i] > 550.5)) {
            outliers.push_back(separated[i]);
        } else {
            finals.push_back(separated[i]);
        }
    }

    ofstream out_outliers;
    out_outliers.open("dust_outliers.csv");

    out_outliers << "number of outliers: " << outliers.size() << endl;
    out_outliers << "id, time, values" << endl;
    for (int i = 0; i < outliers.size(); i++) {
        for (int j = 0; j < outliers[i].size(); j++) {
            out_outliers << outliers[i][j] << (j == outliers[i].size() - 1 ? "\n" : ", ");
        }
    }

    ofstream out_finals;
    out_finals.open("dust_finals.csv");

    out_finals << "id, time, values" << endl;
    for (int i = 0; i < finals.size(); i++) {
        for (int j = 0; j < finals[i].size(); j++) {
            out_finals << finals[i][j] << (j == finals[i].size() - 1 ? "\n" : ", ");
        }
    }

    out_outliers.close();
    out_finals.close();
    in.close();
    return 0;
}