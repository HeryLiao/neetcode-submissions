class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0){
            x = 1 / x;
            N = -N;
        }
        return helper(x, N);
    }
private:
    double helper(double x, long long N){
        if (N == 0) return 1.0;
        if (N % 2 == 0) return helper (x * x, N / 2);
        else return x * helper(x * x, N / 2);
    }
};
