#include <iostream>
#include <stack>

using namespace std;

int graph[100][100] = {0};
bool visited[100] = {false};

void dfs(int sNode, int n){
    stack<int> stk;
    stk.push(sNode);
    visited[sNode] = true;
    while(!stk.empty()){
        int cNode = stk.top();
        stk.pop();
        cout << cNode << " ";
        for(int neighbour = 0; neighbour < n; neighbour++){
            if(graph[cNode][neighbour] && !visited[neighbour]){
                stk.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main() {
    int n, sNode;
    cout << "Enter number of nodes: ";
    cin >> n;


    cout << "Enter the matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting node: ";
    cin >> sNode;

    dfs(sNode, n);

    return 0;
}
