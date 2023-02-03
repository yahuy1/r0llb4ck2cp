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
    int hour_id[10003];
    string state[10003];
    int aqis[10003];
    freopen("dust_aqi.csv", "w", stdout);

    ifstream in;
    in.open("dust_final.csv");

    while (getline(in, line)) {
        lines.push_back(line);
    }

    for (int i = 1; i < lines.size(); i++) {
        vector <string> x = separate(lines[i], ',');
        vector <string> t = separate(x[2], ':');
        int hour = stoi(t[0]);
        hour_id[i] = hour;
        count[hour]++;
        float value = stof(x[3]);
        sum[hour] += value;
    }

    for (int i = 0; i <= 23; i++) average[i] = sum[i] / count[i];

    for (int i = 1; i < lines.size(); i++) {
        lines[i] += ", " + to_string(average[hour_id[i]]);
    }

    for (int i = 1; i < lines.size(); i++) {
        aqis[i] = round(0.85 * average[hour_id[i]]);
        if (aqis[i] >= 400) {
            state[i] = "Extremely hazardous";
        } else if (aqis[i] >= 300) {
            state[i] = "Hazardous";
        } else if (aqis[i] >= 200) {
            state[i] = "Very unhealthy";
        } else if (aqis[i] >= 150) {
            state[i] = "Unhealthy";
        } else if (aqis[i] >= 100) {
            state[i] = "Slightly unhealthy";
        } else if (aqis[i] >= 50) {
            state[i] = "Moderate";
        } else state[i] = "Good";
    }

    cout << "date, time, average, aqi, pollution\n";

    for (int i = 1; i < lines.size(); i++) {
        cout << lines[i] << ", " << state[i] << endl;
    }

    in.close();
    return 0;
}