#include<bits/stdc++.h>
#include<ctime>

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

int main() { 
    string line;
    vector<string> lines;
    freopen("dust_statistics.csv", "w", stdout);

    ifstream in;
    in.open("../task_2.2/dust_aqi.csv");

    while (getline(in, line)) {
        lines.push_back(line);
    }

    map <string, int> state_id;
    state_id["Good"] = 1;
    state_id["Moderate"] = 2;
    state_id["Slightly unhealthy"] = 3;
    state_id["Unhealthy"] = 4;
    state_id["Very unhealthy"] = 5;
    state_id["Hazardous"] = 6;
    state_id["Extremely hazardous"] = 7;

    string state[8] = {"", "Good", "Moderate", "Slightly unhealthy", "Unhealthy", "Very unhealthy", "Hazardous", "Extremely hazardous"};

    int count[10003][8];
    int max_id = 0;

    for (int i = 1; i < lines.size(); i++) {
        vector <string> x = separate(lines[i], ',');
        int id = stoi(x[0]);
        max_id = max(max_id, id);  
        count[id][state_id[x[6]]]++;
    }

    for (int id = 1; id <= max_id; id++) {
        for (int i = 1; i <= 7; i++) {
            cout << id << ", " << state[i] << ", " << count[id][i] << endl;
        }
    }

    in.close();
    return 0;
}