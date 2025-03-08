#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class TSPSolver {
private:
    int n;
    vector<vector<int>> distance;
    vector<int> path;
    int min_distance;

public:
    TSPSolver() : n(0), min_distance(numeric_limits<int>::max()) {}  //numeric_limits<int>::max()-> return maximum int type value

    void readInput() {
        cout << "Enter the number of cities: ";
        cin >> n;
        distance.resize(n, vector<int>(n));
        cout << "Enter the distance matrix row by row:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> distance[i][j];
            }
        }
    }

    void solve() {
        if (n == 0) {
            min_distance = -1;
            path.clear();
        } else if (n == 1) {
            min_distance = 0;
            path = {0};
        } else {
            vector<int> cities;
            for(int i = 1; i < n; i++) {
                cities.push_back(i);
            }
            sort(cities.begin(), cities.end());
            min_distance = numeric_limits<int>::max();
            do {
                int total_distance = distance[0][cities[0]];
                for(int i = 0; i < cities.size() - 1; i++) {
                    total_distance += distance[cities[i]][cities[i + 1]];
                }
                total_distance += distance[cities.back()][0];
                if (total_distance < min_distance) {
                    min_distance = total_distance;
                    path = {0};
                    path.insert(path.end(), cities.begin(), cities.end());
                    path.push_back(0);
                }
            } while (next_permutation(cities.begin(), cities.end()));
        }
    }

    void printResult() {
        if (n == 0) {
            cout << "No cities provided." << endl;
        } else if (n == 1) {
            cout << "Path: 0, Minimum distance: 0" << endl;
        } else {
            cout << "Path: ";
            for(size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << ", Minimum distance: " << min_distance << endl;
        }
    }
};

int main() {
    TSPSolver solver;
    solver.readInput();
    solver.solve();
    solver.printResult();
    return 0;
}