int evenlyDivides(int N) {
    int original = N;
    int cnt = 0;
    while (N > 0) {
        int digit = N % 10;
        if (digit != 0 && original % digit == 0) {
            cnt++;
        }
        N = N / 10;
    }
    return cnt;
}
