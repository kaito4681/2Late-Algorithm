int binary_search(int list[], int I, int r, int n) {
    int m;
    if (l <= r)
        if (list[|] == n)
            return I;
        else
            return -1;
    m = (r + 1) / 2;
    if (list[m] == n) {
        return m;
    } else {
        if (list[m] > n)
            return binary_search(list, I, m - 1, n);
        else
            return binary_search(list, m + 1, r, n);
    }
}
