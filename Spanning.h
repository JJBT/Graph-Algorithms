#include <vector>
#include <queue>

using namespace std;


struct vert {
    int n;
    struct vert *pi;
    int key;

} typedef Vert ;


bool cmp(struct vert* left, struct vert* right);
bool IsInQueue(priority_queue<Vert*, vector<Vert*>, bool(*)(struct vert*, struct vert*)> Q, Vert* v);


void MST_Prim(map<int, vector<int>> data, vector<vector<int>> w, int r) {

    vector<Vert> arr;

    for (size_t i = 0; i < data.size(); ++i) {
        Vert str;
        str.n = i;
        str.key = inf;
        str.pi = nullptr;

        arr.push_back(str);
    }

    Vert *root = &arr[r];
    root->key = 0;

//    auto cmp = [](Vert* left, Vert* right){ return left->key > right->key;};
    priority_queue<Vert*, vector<Vert*>,  bool(*)(struct vert*, struct vert*)> Q(cmp);

    for (size_t i = 0; i < arr.size(); ++i) {
        Q.push(&arr[i]);
    }

    while (!Q.empty()) {
        Vert* u = Q.top();
        Q.pop();

        for (auto item: data[u->n]) {
            Vert *v = &arr[item];

            if (IsInQueue(Q, v) && w[u->n][v->n] < v->key) {
                v->pi = u;
                v->key = w[u->n][v->n];
            }
        }
    }

    for (auto& item1: arr){
        if (item1.n != r) {
            cout << "(" << item1.pi->n << ", " << item1.n <<   ")" << " = " << item1.key << endl;
        }
    }
}

bool cmp(struct vert* left, struct vert* right){
    if (left->key != right->key) {
        return left->key > right->key;
    } else {
        return left->n > right->n;
    }
}


bool IsInQueue(priority_queue<Vert*, vector<Vert*>, bool (*)(struct vert*, struct vert*)> Q, Vert* v) {
    while (!Q.empty()) {
        Vert* temp = Q.top();
        Q.pop();
        if (temp->n == v->n) {
            return true;
        }
    }
    return false;
}
