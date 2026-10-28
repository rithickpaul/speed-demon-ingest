
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

struct EndpointStats {
    long long requests = 0;
    long long errors = 0;
};

int main() {
    ifstream file("logs.txt");

    if (!file.is_open()) {
        cerr << "Error: Cannot open logs.txt" << endl;
        return 1;
    }

    unordered_map<string, EndpointStats> stats;
    string line;

    while (getline(file, line)) {
        string timestamp;
        string endpoint;
        string statusText;
        string latencyText;

        stringstream ss(line);

        if (!getline(ss, timestamp, ',') ||
            !getline(ss, endpoint, ',') ||
            !getline(ss, statusText, ',') ||
            !getline(ss, latencyText, ',')) {
            continue;
        }

        try {
            int status = stoi(statusText);
            int latency = stoi(latencyText);

            if (endpoint.empty() ||
                status < 100 || status > 599 ||
                latency < 0) {
                continue;
            }

            EndpointStats &s = stats[endpoint];

            s.requests++;

            if (status >= 500 && status <= 599) {
                s.errors++;
            }

        } catch (...) {
            continue;
        }
    }

    file.close();

    cout << "Endpoint,Requests,Errors,ErrorRate(%)\n";

    for (const auto &item : stats) {
        const string &endpoint = item.first;
        const EndpointStats &s = item.second;

        double errorRate =
            100.0 * s.errors / s.requests;

        cout << endpoint << ","
             << s.requests << ","
             << s.errors << ","
             << errorRate << "%\n";
    }

    return 0;
}
