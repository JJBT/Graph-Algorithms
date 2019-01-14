#include <vector>
#include <map>
#include <iostream>
#include "Graphs.h"
#include "Spanning.h"

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


    map<int, vector<int >> data1;
    data1.emplace(0, vector<int> {1, 7});
    data1.emplace(1, vector<int> {0, 2, 7});
    data1.emplace(2, vector<int> {1, 3, 5, 8});
    data1.emplace(3, vector<int> {2, 4, 5});
    data1.emplace(4, vector<int> {3, 5});
    data1.emplace(5, vector<int> {2, 3, 4, 6});
    data1.emplace(6, vector<int> {5, 7, 8});
    data1.emplace(7, vector<int> {0, 1, 6, 8});
    data1.emplace(8, vector<int> {2, 6, 7});

    vector<vector<int>> w1;
    w1.emplace_back(vector<int> {0, 4, inf, inf, inf, inf, inf, 8, inf});
    w1.emplace_back(vector<int> {4, 0, 8, inf, inf, inf, inf, 11, inf});
    w1.emplace_back(vector<int> {inf, 8, 0, 7, inf, 4, inf, inf, 2});
    w1.emplace_back(vector<int> {inf, inf, 7, 0, 9, 14, inf, inf, inf});
    w1.emplace_back(vector<int> {inf, inf, inf, 9, 0, 10, inf, inf, inf});
    w1.emplace_back(vector<int> {inf, inf, 4, 14, 10, 0, 2, inf, inf});
    w1.emplace_back(vector<int> {inf, inf, inf, inf, inf, 2, 0, 1, 6});
    w1.emplace_back(vector<int> {8, 11, inf, inf, inf, inf, 1, 0, 7});
    w1.emplace_back(vector<int> {inf, inf, 2, inf, inf, inf, 6, 7, 0});


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
//    Dijkstra(data, w, 0, 7);

    MST_Prim(data1, w1, 0);
}
