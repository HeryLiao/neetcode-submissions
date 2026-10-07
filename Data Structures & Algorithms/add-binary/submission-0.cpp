class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry){
            int bitA = (i >= 0) ? (a[i] - '0') : 0;
            int bitB = (j >= 0) ? (b[j] - '0') : 0;
            int total = bitA + bitB + carry;
            res += to_string(total % 2);
            carry = total / 2;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};