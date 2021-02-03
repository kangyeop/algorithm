#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
  public:
    int x;
    int y;
    int index;
    Node *left;
    Node *right;

    Node() {}

    Node(int a, int b, int idx) {
        x = a;
        y = b;
        index = idx;
        left = nullptr;
        right = nullptr;
    }

    bool operator<(Node a) {
        if (y == a.y) {
            return this->x < a.x;
        } else {
            return this->y > a.y;
        }
    }
};

void addNode(Node *parent, Node *child) {
    if (child->x < parent->x) {
        if (parent->left == NULL)
            parent->left = child;
        else
            addNode(parent->left, child);
    } else {
        if (parent->right == NULL)
            parent->right = child;
        else
            addNode(parent->right, child);
    }
}

void preorder(vector<int> &answer, Node *node) {
    if (node == NULL)
        return;
    answer.push_back(node->index);
    preorder(answer, node->left);
    preorder(answer, node->right);
}

void postorder(vector<int> &answer, Node *node) {
    if (node == NULL)
        return;
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> arr;
    for (int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        arr.push_back(Node({ x, y, i + 1 }));
    }

    sort(arr.begin(), arr.end());

    Node *root;

    root = &arr[0];

    for (int i = 1; i < arr.size(); i++) {
        addNode(root, &arr[i]);
    }

    vector<vector<int>> answer(2, vector<int>(0, 0));
    preorder(answer[0], root);
    postorder(answer[1], root);
    return answer;
}