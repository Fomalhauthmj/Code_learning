#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
void Disp(queue<char> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string sa, sb;
    cin >> sa >> sb;
    queue<char> qa;
    int lena = sa.length();
    for (int i = 0; i < lena; i++)
        qa.push(sa[i]);
    //初始化队列A
    queue<char> qb;
    int lenb = sb.length();
    for (int i = 0; i < lenb; i++)
        qb.push(sb[i]);
    //初始化队列B
    bool start = true;
    vector<char> v;
    int cnt = 0;
    while (!qa.empty() && !qb.empty())
    {
        cnt++;
        if (cnt > 1000)
            break;
        if (start) //A开始
        {
            vector<char>::iterator pos = find(v.begin(), v.end(), qa.front());
            if (pos != v.end())
            {
                char ch = qa.front();
                qa.pop();
                qa.push(ch);
                while (v.end() != pos)
                {
                    qa.push(v[v.size() - 1]);
                    v.pop_back();
                }
                start = true;
            }
            else
            {
                v.push_back(qa.front());
                qa.pop();
                start = false;
            }
        }
        else //B开始
        {
            vector<char>::iterator pos = find(v.begin(), v.end(), qb.front());
            if (pos != v.end())
            {
                char ch = qb.front();
                qb.pop();
                qb.push(ch);
                while (v.end() != pos)
                {
                    qb.push(v[v.size() - 1]);
                    v.pop_back();
                }
                start = false;
            }
            else
            {
                v.push_back(qb.front());
                qb.pop();
                start = true;
            }
        }
        /*
        cout << "Cur a:";
        Disp(qa);
        cout << "Cur b:";
        Disp(qb);
        cout << "Cur:";
        for (auto ele : v)
        {
            cout << ele;
        }
        cout << endl;
        */
    }
    //system("pause");
    if (qa.empty())
    {
        Disp(qb);
    }
    else if (qb.empty())
    {
        Disp(qa);
    }
    else
    {
        cout << -1 << endl;
    }
    //cout << cnt << endl;
    //system("pause");
    return 0;
}