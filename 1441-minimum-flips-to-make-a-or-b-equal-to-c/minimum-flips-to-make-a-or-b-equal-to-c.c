// int count_ones (int x) {
//     int result = 0;
//     while (x>0) {
//         x = x & (x-1);
//         result++;
//     }
//     return result;
// }

int minFlips(int a, int b, int c){
    int result = 0;
    int f0 = (a | b) ^ c;
    int f1 = (a & b & (~c));
    while (f0>0) {
        f0 = f0 & (f0-1);
        result++;
    }
    while (f1>0) {
        f1 = f1 & (f1-1);
        result++;
    }
    return result;
}