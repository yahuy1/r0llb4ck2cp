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
    float average[10003], sum[10003], count[10003];
    float Max[10003];
    string Max_date[10003], Max_time[10003];
    float Min[10003];
    string Min_date[10003], Min_time[10003];
    string state[10003];
    freopen("dust_summary.csv", "w", stdout);

    ifstream in;
    in.open("../task_2.1/dust_finals.csv");

    while (getline(in, line)) {
        lines.push_back(line);
    }

    int max_id = 0;
    string duration;
    for (int i = 1; i < lines.size(); i++) {
        vector <string> x = separate(lines[i], ',');
        int id = stoi(x[0]);
        max_id = max(max_id, id);   
    }

    for (int i = 1; i <= max_id; i++) {
        Max[i] = -1e9;
        Min[i] = 1e9;
    }

    for (int i = 1; i < lines.size(); i++) {
        vector <string> x = separate(lines[i], ',');
        int id = stoi(x[0]);
        count[id]++;
        float value = stof(x[3]);
        sum[id] += value;
        if (Max[id] < value) {
            Max[id] = value;
            Max_date[id] = x[1];
            Max_time[id] = x[2];
        }
        if (Min[id] > value) {
            Min[id] = value;
            Min_date[id] = x[1];
            Min_time[id] = x[2];
        }
        duration = x[2];
    }

    for (int i = 1; i <= max_id; i++) average[i] = sum[i] / count[i];

    cout << "id, parameters, time, values\n";
    for (int i = 1; i <= max_id; i++) {
        cout << i << ", max, " << Max_date[i] << ", " << Max_time[i] << ", " << Max[i] << endl;
        cout << i << ", min, " << Min_date[i] << ", " << Min_time[i] << ", " << Min[i] << endl;
        cout << i << ", mean, " << duration << ", " << sum[i] / count[i] << endl;
    }

    in.close();
    return 0;
}