void gauss() 
{
    int now = 0, to;
    int t;
    for (int i = 0; i < 16; i++, now++)
    {
        t = a[now][i];
        for (int j = 0; j < 16 + 1; j++) a[now][j] /= t;
        for (int j = 0; j < n; j++) 
        if (j != now) 
        {
            t = a[j][i];
            for (int k = 0; k < 16 + 1; k++) a[j][k] -= t * a[now][k];
        }
    }
}