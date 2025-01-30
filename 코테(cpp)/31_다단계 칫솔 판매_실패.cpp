#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    string name;
    int profit;
    int sell;
    int incentive;
    Node* parent;
    vector<Node*> children;

public:
    Node(string name) : name(name), parent(nullptr) {}
};

class Tree
{
public:
    Node* root;
    unordered_map<string, int> profit_map;

public:
    Tree()
    {
        root = new Node("");
    }

    //노드에 자식을 추가
    void addChild(Node* node, string name)
    {
        Node* new_node = new Node(name);
        new_node->parent = node;
        node->children.push_back(new_node);
    }

    //특정값(이름)을 가진 노드를 찾아서 반환
    Node* searchNode(Node* node, string name)
    {
        if (node->name == name)
            return node;

        vector<Node*>& child_list = node->children;

        if (child_list.size() == 0) {
            return nullptr;
        }

        Node* tmp;
        Node* result;
        for (int i = 0; i < child_list.size(); ++i) {
            tmp = searchNode(child_list[i], name);
            if (tmp != nullptr)
                result = tmp;
        }

        return result;
    }

    //노드에 판매 대금을 저장
    void setSell(Node* node, int sell)
    {
        node->sell = sell;
    }

    int updateNodeProfit(Node* node)
    {
        vector<Node*>& child_list = node->children;

        if (child_list.size() == 0) {
            node->incentive = node->sell / 10;
            node->profit = node->sell - node->incentive;
            this->profit_map.insert(make_pair(node->name, node->profit));
            return node->incentive;
        }

        int incentive_sum = 0;

        for (int i = 0; i < child_list.size(); ++i) {
            incentive_sum += updateNodeProfit(child_list[i]);
        }

        int total = node->sell + incentive_sum;
        node->incentive = (total) / 10;
        node->profit = total - node->incentive;
        this->profit_map.insert(make_pair(node->name, node->profit));
        return node->incentive;
    }


};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    Tree tr;


    //트리를 완성
    for (int i = 0; i < enroll.size(); ++i) {
        string enroll_name = enroll[i];
        string parent_name = referral[i];

        if (parent_name == "-") {
            tr.addChild(tr.root, enroll_name);
        }
        else {
            Node* p_node = tr.searchNode(tr.root, parent_name);
            tr.addChild(p_node, enroll_name);
        }
    }

    //트리에 판매 대금 저장
    for (int i = 0; i < seller.size(); ++i) {
        string seller_name = seller[i];
        int sell = amount[i] * 100;

        Node* found = tr.searchNode(tr.root, seller_name);
        found->sell += sell;
    }

    tr.updateNodeProfit(tr.root);

    for (int i = 0; i < enroll.size(); ++i) {
        string name = enroll[i];
        answer.push_back(tr.profit_map[name]);
    }

    return answer;
}