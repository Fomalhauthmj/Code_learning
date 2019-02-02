void find(int left, int right, int &mx, int &mn)
{
    int mid = (left + right) >> 1;
    int max1, max2, min1, min2;
    find(left, mid, max1, max2);
    find(mid + 1, right, max2, min2);
    mx = max(max1, max2);
    mn = min(min1, min2);
}