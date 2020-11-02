//PAT A1135.cpp 1135 Is It A Red-Black Tree (30 ·Ö)
//???
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	bool isblack;
	int data;
	int layer;
};

vector<Node> in, pre, layerorder;
bool cmp(Node a, Node b)
{
	return a.data < b.data;
}

void layerTraver(int inL, int inR, int  preL, int preR, int layer)
{
	if (inL > inR) return;
	int k = inL;
	while (in[k].data != pre[preL].data)
	{
		k++;
	}
	int  leftnum = k - preL;
	Node root = pre[preL];
	root.layer = layer;
	layerorder.push_back(root);
	layerTraver(inL + 1, k - 1, preL + 1, preL + leftnum, 2 * layer);
	layerTraver(k + 1, inR, preL + leftnum + 1, preR, 2 * layer + 1);
}

bool cmplayer(Node a, Node b)
{
	return a.layer < b.layer;
}

int main()
{
	int k; cin >> k;
	while (k--)
	{
		int n;
		cin >> n;
		pre.resize(n+1);
		for (int i = 0; i < n; i++)
		{
			int key; cin >> key;
			if (key < 0) pre[i].isblack = false;
			else pre[i].isblack = true;
			pre[i].data = abs(key);
		}
		in = pre;
		sort(in.begin(), in.end(), cmp);
		
		layerTraver(0, n - 1, 0, n - 1, 1);
		sort(layerorder.begin(), layerorder.end(), cmplayer);
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (layerorder[i].layer % 2 == 0 && layerorder[i].isblack == true)
				flag = false;
			else if (layerorder[i].layer % 2 != 0 && layerorder[i].isblack == false)
				flag = false;
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
}