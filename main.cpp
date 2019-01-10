#include <vector>
#include <map>
#include <iostream>
#include "Graphs.h"

using namespace std;

int main() {
//    vector<vector<int>> matr;
//    matr.emplace_back(vector<int> {0, 1, 0, 0, 1});
//    matr.emplace_back(vector<int> {1, 0, 1, 1, 1});
//    matr.emplace_back(vector<int> {0, 1, 0, 1, 0});
//    matr.emplace_back(vector<int> {0, 1, 1, 0, 1});
//    matr.emplace_back(vector<int> {1, 1, 0, 1, 0});

    map<int, vector<int >> data;
    data.emplace(0, vector<int> {2, 3});
    data.emplace(1, vector<int> {2, 3});
    data.emplace(2, vector<int> {0, 1, 4, 5});
    data.emplace(3, vector<int> {0, 1, 4});
    data.emplace(4, vector<int> {2, 3, 6, 7});
    data.emplace(5, vector<int> {2, 6});
    data.emplace(6, vector<int> {4, 5});
    data.emplace(7, vector<int> {4});

    vector<vector<int>> w;
    w.emplace_back(vector<int> {0, inf, 3, 6, inf, inf, inf, inf});
    w.emplace_back(vector<int> {inf, 0, 4, 2, inf, inf, inf, inf});
    w.emplace_back(vector<int> {3, 4, 0, inf, 8, 2, inf, inf});
    w.emplace_back(vector<int> {6, 2, inf, 0, 6, inf, inf, inf});
    w.emplace_back(vector<int> {inf, inf, 8, 6, 0, inf, 2, 2});
    w.emplace_back(vector<int> {inf, inf, 2, inf, inf, 0, 5, inf});
    w.emplace_back(vector<int> {inf, inf, inf, inf, 2, 5, 0, inf});
    w.emplace_back(vector<int> {inf, inf, inf, inf, 2, inf, inf, 0});


//    vector<Vertex> arr;
//
//    arr = BFS(data, 1);
//    PrintPath(arr, arr[1], arr[7]);
//
//    cout << '\n';
//    for (auto& item: arr) {
//        cout << item.d << endl;
//    }
//
    Dijkstra(data, w, 0, 7);

}
