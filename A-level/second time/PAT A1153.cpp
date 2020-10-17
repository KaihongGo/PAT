#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

struct Student
{
    string id;
    int score;
};
struct Node
{
    int site, nt;
};

map<char, vector<Student>> level;
map<int, vector<Student>> site;
map<string, vector<Node>> date;

bool cmp1(Student a, Student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}
bool cmp2(Node a, Node b)
{
    if (a.nt != b.nt)
        return a.nt < b.nt;
    else
        return a.site > b.site;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Student> stu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].score;
        int siteId = stoi(stu[i].id.substr(1, 3));
        string getDate = stu[i].id.substr(4, 6);
        level[stu[i].id[0]].push_back(stu[i]); // type 1
        site[siteId].push_back(stu[i]);        //type 2
    }
    int type;
    string term;
    for (int i = 0; i < m; i++)
    {
        cin >> type >> term;
        printf("Case %d: %d %s\n", i + 1, type, term.c_str());
        if (type == 1)
        {
            sort(level[term[0]].begin(), level[term[0]].end(), cmp1);
            for (auto student : level[term[0]])
                cout << student.id << " " << student.score << endl;
        }
        else if (type == 2)
        {
            int Nt = site[stoi(term)].size();
            int Ns = 0;
            for (auto e : site[stoi(term)])
                Ns += e.score;
            cout << Nt << " " << Ns << endl;
        }
        else if (type == 3)
        {
        }
    }
    // switch 语句无法定义变量？
}