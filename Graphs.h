#include <vector>
#include <queue>


using namespace std;

struct ver {
    int n;
    struct ver *pi;
    int d;
    int color; // 0 - white, 1 - gray, 2 - black

} typedef Vertex ;


const int inf = 100000000;


vector<struct ver> BFS(map<int, vector<int >> data, int s) {
    /*
     * data - adjacency list
     * s - source vertex
     */

    vector<Vertex> arr;

    for (size_t i = 0; i < data.size(); ++i) {
        Vertex str;
        str.n = i;
        str.d = inf;
        str.pi = nullptr;
        str.color = 0;

        arr.push_back(str);
    }

    Vertex *source = &arr[s];
    source->n = s;
    source->color = 1;
    source->d = 0;
    source->pi = nullptr;


    queue<Vertex*> Q;
    Q.push(source);

    while (!Q.empty()) {
        Vertex *u = Q.front();
        Q.pop();

        for (auto& item: data[u->n]) {
            Vertex *v = &arr[item];
            if (v->color == 0) {
                v->color = 1;
                v->d = u->d + 1;
                v->pi = &arr[u->n];

                Q.push(v);
            }
        }

        u->color = 2;
    }

    return arr;

}


int ComponentsNum(map <int, vector<int>> data) {
//    Return number of connectivity components

    int comps = 0;

    vector<Vertex> arr;

    for (size_t i = 0; i < data.size(); ++i) {
        Vertex str;
        str.n = i;
        str.d = inf;
        str.pi = nullptr;
        str.color = 0;

        arr.push_back(str);
    }



    vector<int > visited(arr.size(), 0);

    for (auto& it: data) {
        int s = it.first;

        if (!visited[s]) {

            Vertex *source = &arr[s];
            source->n = s;
            source->color = 1;
            source->d = 0;
            source->pi = nullptr;

            visited[s] = 1;

            queue<Vertex*> Q;
            Q.push(source);

            while (!Q.empty()) {
                Vertex *u = Q.front();
                Q.pop();

                visited[u->n] = 1;

                for (auto& item: data[u->n]) {
                    Vertex *v = &arr[item];
                    if (v->color == 0) {
                        v->color = 1;
                        v->d = u->d + 1;
                        v->pi = &arr[u->n];

                        Q.push(v);
                    }
                }

                u->color = 2;
            }

            ++comps;

        }
    }

//
//    for (auto& item1: arr) {
//        cout << item1.d << endl;
//    }
//    cout << '\n';

    return comps;
}


void PrintPath(vector<struct ver> arr, Vertex s, Vertex v) {
//    Print path from s to v
    /*
     * arr - array from BFS(s)
     */

    if(v.n == s.n) {
        cout << s.n << endl;
    } else if (v.pi == nullptr) {
        cout << "There is no path from s to v" << endl;
    } else {
        PrintPath(arr, s, *v.pi);
        cout << v.n << endl;
    }
}


vector<struct ver> InitializeSingleSource(map<int, vector<int>> data, int s) {
    /*
     * data - adjacency list
     * s - source vertex
     */

    vector<Vertex> arr;

    for (size_t i = 0; i < data.size(); ++i) {
        Vertex str;
        str.n = i;
        str.d = inf;
        str.pi = nullptr;

        arr.push_back(str);
    }

    Vertex *source = &arr[s];
    source->n = s;
    source->d = 0;

    return arr;

}

bool Relax(struct ver *u, struct ver *v, vector<vector<int>> w) {
    /*
     * u - initial vertex
     * v - end vertex
     * w - matrix of weights
     */

    if (v->d > u->d + w[u->n][v->n]) {
        v->d = u->d + w[u->n][v->n];
        v->pi = u;
        return true;
    }
    return false;
}


void Dijkstra(map<int, vector<int>> data, vector<vector<int >> w, int s, int f) {
    /*
     * data - adjacency list
     * w - matrix of weights
     * s - initial vertex
     * f - end vertex
     */

    vector<Vertex > arr = InitializeSingleSource(data, s);
    vector<Vertex* > path;

    auto cmp = [](Vertex* left, Vertex* right){ return left->d > right->d;};
    priority_queue<Vertex*, vector<Vertex*>, decltype(cmp)> Q(cmp);

    for (size_t i = 0; i < arr.size(); ++i) {
        Q.push(&arr[i]);
    }

    while (!Q.empty()) {
        Vertex *u = Q.top();
        Q.pop();

        for (auto& item: data[u->n]) {
            Vertex *v = &arr[item];
            if(Relax(u, v, w) && v->n == f) {
//                path to f

                path.clear();
                Vertex* p = v;
                while (p != nullptr) {
                    path.push_back(p);
                    p = p->pi;
                }
            }
        }

    }

    cout << "Distances" << endl;
    for (auto& item1: arr) {
        cout << item1.d << endl;
    }
    cout << '\n';

    cout << "Path from s to f" << endl;
    for (auto& item2: path) {
        cout << item2->n << endl;
    }
}
