#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class Node
{
public:
    int x, y, id;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node(int x, int y, int id)
        : x(x), y(y), id(id)
    {
    }
};

class BST
{
public:
    Node* root = nullptr;

public:

    void insert(int x, int y, int id) {
        root = insertNode(this->root, new Node(x, y, id));
    }

    Node* insertNode(Node* curNode, Node* newNode) {
        if (curNode == nullptr) {
            //cout << newNode->x << ", " << newNode->y << " id : " << newNode->id << endl;
            return newNode;
        }

        if (curNode->x > newNode->x)
            curNode->left = insertNode(curNode->left, newNode);
        if (curNode->x < newNode->x)
            curNode->right = insertNode(curNode->right, newNode);

        return curNode;
    }

    void traversal(vector<vector<int>>& answer) {
        vector<int> arr;

        preOrder(this->root, arr);
        answer.push_back(arr);
        arr.clear();

        postOrder(this->root, arr);
        answer.push_back(arr);
        arr.clear();
    }

    void preOrder(Node* curNode, vector<int>& arr) {

        arr.push_back(curNode->id);

        if (curNode->left != nullptr)
            preOrder(curNode->left, arr);
        if (curNode->right != nullptr)
            preOrder(curNode->right, arr);
    }

    void postOrder(Node* curNode, vector<int>& arr) {

        if (curNode->left != nullptr)
            postOrder(curNode->left, arr);
        if (curNode->right != nullptr)
            postOrder(curNode->right, arr);

        arr.push_back(curNode->id);
    }
};

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    BST tree;

    vector<tuple<int, int, int>> nodes;
    for (int i = 0; i < nodeinfo.size(); ++i) {
        nodes.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });
    }

    sort(nodes.begin(), nodes.end(), compare);

    for (auto& [x, y, id] : nodes) {
        cout << x << ", " << y << ", " << id << endl;
        tree.insert(x, y, id);
    }

    tree.traversal(answer);
    return answer;
}