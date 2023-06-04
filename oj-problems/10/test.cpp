#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#define MAX 10001
using namespace std;
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    node() { value = -1, left = NULL, right = NULL; } // 預設tree node的值
} binaryNode;
binaryNode *root;
deque<binaryNode *> qu; // 為了tree on the level
bool cflag = true, dflag = true;
void check(binaryNode *now)
{ // 檢查樹是否有空節點，該有節點而未有節點
    if (now->value == -1)
        cflag = false; // cflag為false表示有空節點
    if (now->left != NULL)
        check(now->left);
    if (now->right != NULL)
        check(now->right);
}
void levelOrder(binaryNode *now)
{ // tree on the level
    qu.push_back(now);
    cout << qu.front()->value; // 為了output時數字間的空白，先output第一個數字
    if (qu.front()->left != NULL)
        qu.push_back(qu.front()->left);
    if (qu.front()->right != NULL)
        qu.push_back(qu.front()->right);
    qu.pop_front();
    while (!qu.empty())
    {
        cout << " " << qu.front()->value;
        if (qu.front()->left != NULL)
            qu.push_back(qu.front()->left);
        if (qu.front()->right != NULL)
            qu.push_back(qu.front()->right);
        qu.pop_front();
    }
    cout << endl;
}
void buildTree(binaryNode *now, string pos, int spos, int num)
{ // 建立tree，now為現在所在節點
    if (pos == "")
    { // pos為節點所在位置字串，spos為目前在pos字串的哪一個字元，num為插入的值
        if (now->value != -1)
            dflag = false; // dflag為false表示節點重複
        else
        {
            now->value = num;
        }
    }
    if (pos.length() > spos)
    {
        if (pos[spos] == 'L')
        { // 往左邊
            if (now->left == NULL)
            { // 未有節點則建立
                binaryNode *bNode = new binaryNode;
                if (pos.length() == (spos + 1))
                    bNode->value = num; // 判斷是否已到插入位置，若是則插入值
                now->left = bNode;      // 插入新增節點到now的左邊
            }
            else
            {
                if (pos.length() == (spos + 1))
                { // 判斷是否已到插入位置
                    if (now->left->value != -1)
                        dflag = false; // 該節點已經有了  dflag為false表示節點重複
                    else
                        now->left->value = num; // 更新結點值
                }
            }
            buildTree(now->left, pos, spos + 1, num); // 遞迴，看pos的第spos+1個字元是L還是R，決定左邊還右邊
        }
        else if (pos[spos] == 'R')
        { // 往右邊
            if (now->right == NULL)
            { // 未有節點則建立
                binaryNode *bNode = new binaryNode;
                if (pos.length() == (spos + 1))
                    bNode->value = num; // 判斷是否已到插入位置，若是則插入值
                now->right = bNode;     // 插入新增節點到now的右邊
            }
            else
            {
                if (pos.length() == (spos + 1))
                { // 判斷是否已到插入位置
                    if (now->right->value != -1)
                        dflag = false; // 該節點已經有了  dflag為false表示節點重複
                    else
                        now->right->value = num; // 更新結點值
                }
            }
            buildTree(now->right, pos, spos + 1, num); // 遞迴，看pos的第spos+1個字元是L還是R，決定左邊還右邊
        }
    }
}
int main()
{
    int n;
    cin >> n;
    string s;
    string pa;
    int num, i, result, cresult;
    while (n--)
    {
        cin >> s;
        binaryNode *root = new binaryNode;
        do
        {
            if (s.length() == 2)
                break; // 表示該組測資輸入結束
            num = 0;
            for (i = 1; i < s.length() - 1; i++)
            { // 讀取節點數值到num
                if (s[i] == ',')
                    break;
                num = num * 10 + s[i] - '0';
            }
            // cout <<num<<endl;
            pa = s.substr(i + 1, s.length() - i - 2); // 取出節點位置字串到pa
            // cout << pa<<endl;
            buildTree(root, pa, 0, num); // 每個節點，就呼叫一次buildTree
        } while (cin >> s);
        check(root); // 樹建好了，檢查是否有空節點
        if (dflag == false)
            cout << "not complete" << endl; // node是否有重複
        else if (cflag == false)
            cout << "not complete" << endl; // tree是否有空節點
        else
            levelOrder(root);       // level走訪
        cflag = true, dflag = true; // 為下一組測資準備
    }
    return 0;
}