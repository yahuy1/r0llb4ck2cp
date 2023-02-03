#include<bits/stdc++.h>

using namespace std;

vector<string> seperate(string s, char c) {
    string s3;
    
    for (int i = s.length(); i > 0; i--) {
        if (s[i] == c) {
            s3 = s.substr(i + 1, -1);
            break;
        }
    }
    return {s, s3};
}

int main(int argc, char** argv) { 
    string line;
    vector<string> lines;
    vector<vector<string>> final;
    vector<string> a, b;
    float values[10000];
    freopen("dust_outlier.csv", "w", stdout);
    ifstream in;
    in.open(argv[1]);

    while (getline(in, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        final.push_back(seperate(lines[i], ','));
    }
    for (int i = 1; i < lines.size(); i++) {
        if (final[i][1] != "") {
            values[i] = stof(final[i][1]);
            if ((values[i] < 5) || (values[i] > 550.5)) {
                a.push_back(final[i][0]);
            } else {
                b.push_back(final[i][0]);
            }
        }
    }
    cout << "number of outliers: " << a.size() << endl;
    cout << "id, time, values" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }

    in.close();
    return 0;
}