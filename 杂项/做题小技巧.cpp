//找环小技巧
void DFS(int x, int fa)
{
    vis[x] = 1, pre[x] = fa;
    for (int y : E[x])
    {
        if (y == fa)
            continue;
        if (!vis[y])
            DFS(y, x);
        else if (vis[y] == 1)
        {
            A.push_back(road_map[{x, y}]);
            int t1 = x, t2 = pre[t1];
            do
            {
                //cout << "cur edge" << t1 << " " << t2 << endl;
                A.push_back(road_map[{t1, t2}]);
                t1 = t2, t2 = pre[t1];
            } while (t1 != y);
        }
    }
    vis[x] = 2;
}