#include <vector>
#include <iostream>
#include <climits>
#include <string>
#include<sstream>
using namespace std;

int main() {
    int n;

    string line;
    getline(cin, line);

    vector<int>arr;
    stringstream ss(line);
    string temp;


    while (getline(ss, temp, ',')) {
        stringstream(temp) >> n;
        arr.push_back(n);
    }

    int max = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << max << endl;
    return 0;
}