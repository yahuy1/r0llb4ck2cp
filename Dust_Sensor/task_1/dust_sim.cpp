#include<bits/stdc++.h>
#include<ctime>

using namespace std;

string twoNumber(int s) {
    if (s < 10) return "0" + to_string(s);
    else return to_string(s);
}

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main(int argc, char** argv) { 

    freopen("dust_sensor.csv", "w", stdout);
    srand ((time(0)));
    string hour, minute, second;
    string n_time;
    float r;

    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);

    int sensors = 1;
    int sampling = 30; 
    int interval = 24;

    for (int i = 1; i < argc; i++) {
        if (i == argc) {
            cerr << "Invalid Arguments" << "\n";
            return 0;
        }

        string si = argv[i];
        if (si != "-n" && si != "-st" && si != "-si") {
            cerr << "Invalid Arguments" << "\n";
            return 0;
        }

        string si1 = argv[i + 1];
        if (si == "-n") {
            if (!isNumber(si1)) {
                cerr << "Invalid Arguments" << "\n";
                return 0;
            }
            sensors = stoi(si1);
            i++;
        } else if (si == "-st") {
            if (!isNumber(si1)) {
                cerr << "Invalid Arguments" << "\n";
                return 0;
            }
            sampling = stoi(si1);
            i++;
        } else if (si == "-si") {
            if (!isNumber(si1)) {
                cerr << "Invalid Arguments" << "\n";
                return 0;
            }
            interval = stoi(si1);
            i++;
        }
    }

    string date = to_string(t.tm_year+1900) + ":" + to_string(t.tm_mon+1) + ":" + to_string(t.tm_mday);

    cout << "id, time, values" << endl;
    int n = 3600/sampling;
    int n_hour = 0, n_minute = 0, n_second = 0, s_second = 0;
    while (n_hour <= interval) {
        if (n_hour == interval && (n_minute != 0 || n_second != 0)) break;
        n_time = twoNumber(n_hour) + ":" + twoNumber(n_minute) + ":" + twoNumber(n_second); 

        for (int i = 1; i <= sensors; i++) {
            r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            cout << i << " ," << date << " ," << n_time << " ," << setprecision(1) << fixed << r * 600 << endl;
        }

        s_second += sampling;
        n_hour = s_second / 3600;
        int temp = s_second % 3600;
        n_minute = temp / 60;
        n_second = temp % 60;
    }
        
    return 0;
}