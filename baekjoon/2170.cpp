#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    long long x;
    long long y;
};

bool compare(Node a, Node b) { return a.x < b.x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<Node> arr;

    for (int i = 0; i < n; i++) {
        Node temp;
        cin >> temp.x >> temp.y;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compare);

    long long sum = 0;
    int fin = -1000000001;

    for (int i = 0; i < n; i++) {
        long long x = arr[i].x;
        long long y = arr[i].y;
        if (x > fin) {
            sum += abs(y - x);
            fin = y;
        } else if (y > fin) {
            sum += abs(y - fin);
            fin = y;
        }
    }

    cout << sum << "\n";

    return 0;
}