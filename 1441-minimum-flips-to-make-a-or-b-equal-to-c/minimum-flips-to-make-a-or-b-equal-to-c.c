int count_ones (int x) {
    int result = 0;
    while (x>0) {
        x = x & (x-1);
        result++;
    }
    return result;
}

int minFlips(int a, int b, int c){
    int result = 0;
    int f0 = (a | b) ^ c;
    int f1 = (a & b & (~c));
    result += count_ones(f0);
    result += count_ones(f1);
    return result;
}