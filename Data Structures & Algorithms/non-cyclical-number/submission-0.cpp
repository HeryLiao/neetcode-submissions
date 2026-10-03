class Solution {
private:
    int getNext(int n){
        int totalSum = 0;
        while (n > 0){
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)){
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
