/* The functions which
builds the segment tree */

void build(int segT[], int arr[], int i, int l, int r)
{
    if (l == r)
    {
        segT[i] = arr[l];
        return;
    }

    int m = l + (r - l) / 2;
    build(segT, arr, 2 * i + 1, l, m);
    build(segT, arr, 2 * i + 2, m + 1, r);

    segT[i] = min(segT[2 * i + 1], segT[2 * i + 2]);
}

int *constructST(int arr[], int n)
{
    int *segT = new int[4 * n];
    build(segT, arr, 0, 0, n - 1);
    return segT;
}

int query(int segT[], int n, int a, int b, int l, int r, int i)
{
    if (l > r || b < l || a > r)
    {
        return INT_MAX;
    }
    if (l >= a && r <= b)
    {
        return segT[i];
    }

    int m = l + (r - l) / 2;
    return min(query(segT, n, a, b, l, m, 2 * i + 1), query(segT, n, a, b, m + 1, r, 2 * i + 2));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    return query(st, n, a, b, 0, n - 1, 0);
}