class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // With 2 pigs, poison killing in 15 minutes, and having 60 minutes
        // we can find the poison in up to 25 buckets in the following way.
        // Arrange the buckets in a 5×5 square:
        //  1  2  3  4  5
        //  6  7  8  9 10
        // 11 12 13 14 15
        // 16 17 18 19 20
        // 21 22 23 24 25
        // now use one pig to find the row (drink 1, 2, 3, 4, 5, wait 15 minutes, drink 6, 7, 8, 9, 10, wait 15 minutes...)
        // and use the second pig to find the column
        // If the row pig dies in the nth test, the poison is in the nth row, same for column pig
        // if neither died, the poison bucket is at fifth column/row (this is why we can cover five rows/columns with four tests)
        // so with 3 pigs with 60 mins, we can solve for another dim, up to 5x5x5=125 bucket
        // so with k=floor(minToTest/minToDie) tests, we can determine up to k^n buckets with n pigs

        int k = minutesToTest/minutesToDie;
        int n = 0;
        while (pow(k+1, n)<buckets) {
            n++;
        }
        return n;
    }
};