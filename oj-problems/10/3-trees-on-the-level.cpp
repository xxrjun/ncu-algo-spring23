#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// definition of tree node
struct Node
{
    int value;
    Node *left, *right;
    Node() : value(-1), left(NULL), right(NULL) {}
};

bool insert(Node *root, int value, string path)
{
    for (char c : path)
    {
        if (c == 'L')
        {
            if (root->left == NULL)
                root->left = new Node();
            root = root->left;
        }
        else
        {
            if (root->right == NULL)
                root->right = new Node();
            root = root->right;
        }
    }
    if (root->value != -1)
        return false; // Node already has a value
    root->value = value;
    return true;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != root)
            cout << " ";
        cout << node->value;

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
    cout << endl;
}

bool check(Node *now)
{
    if (now->value == -1)
        return false;

    bool noEmptyNode = true;
    if (now->left != NULL)
        noEmptyNode = check(now->left) && noEmptyNode;
    if (now->right != NULL)
        noEmptyNode = check(now->right) && noEmptyNode;

    return noEmptyNode;
}

int main()
{
    int n;
    cin >> n;

    string s;
    while (n--)
    {
        cin >> s;
        Node *root = new Node();
        bool isComplete = true;
        do
        {
            // get value and path
            int value = stoi(s.substr(1));
            string path = s.substr(s.find(',') + 1, s.size() - s.find(',') - 2);
            isComplete = insert(root, value, path) && isComplete;
        } while (cin >> s, s != "()");

        // check if the tree has empty nodes
        isComplete = check(root) && isComplete;

        // check if the tree is complete
        if (!isComplete)
        {
            cout << "not complete" << endl;
            continue;
        }
        else
            levelOrderTraversal(root);
    }
    return 0;
}
