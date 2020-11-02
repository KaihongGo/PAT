//隐形的前序+中序 后序输出 PAT A1086
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 50;
struct node
{
    int data;
    node *lchild;
    node *rchild;
};

int pre[maxn], in[maxn];
int n; //节点个数

int num = 0;
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    num++;
    if (num != n)
        printf(" ");
}

node *preInCreate(int prel, int prer, int inl, int inr)
{
    if (prel > prer)
        return NULL;
    node *root = new node; //为这个结点地址分配空间
    root->data = pre[prel];
    int k = inl;
    while (in[k] != pre[prel])
    {
        k++;
    }
    int numleft = k - inl;
    root->lchild = preInCreate(prel + 1, prel + numleft, inl, k - 1);
    root->rchild = preInCreate(prel + numleft + 1, prer, k + 1, inr);//prel + numleft + 1
    return root;
}

int main()
{
    cin >> n;
    int preindex = 0, inindex = 0;
    stack<int> st;
    for (int i = 0; i < 2 * n; i++)
    {
        string s;
        cin >> s;
        if (s == "Push")
        {
            int num;
            cin >> num;
            st.push(num);
            pre[preindex++] = num;
        }
        else
        {
            in[inindex++] = st.top();
            st.pop();
        }
    }
    node *root = preInCreate(0, n - 1, 0, n - 1);
    postorder(root);
    return 0;
}