#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int value;
    int src;
    int dest;
};

int main() {
    int arr[5][5] = {
        {0, 2, 1, 0, 3},
        {2, 0, 4, 0, 0},
        {1, 4, 0, 5, 0},
        {0, 0, 5, 0, 6},
        {3, 0, 0, 6, 0},
    };

    vector<Edge> edges;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (arr[i][j] != 0 && arr[i][j] == arr[j][i]) {
                Edge value = {arr[i][j], i, j};
                edges.push_back(value);
            }
        }
    }

    for (int i = 0; i < edges.size() - 1; ++i) {
        for (int j = 0; j < edges.size() - i - 1; ++j) {
            if (edges[j].value > edges[j + 1].value) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    cout << "Connected nodes with the least edge value:" << endl;
    for (int i = 0; i < edges.size(); ++i) {
        cout << "Edge value: " << edges[i].value << ", Source node: " << edges[i].src << ", Destination node: " << edges[i].dest << endl;
    }
    return 0;
}
