class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map <int, int> count;
            for (int card: hand){
                count[card]++;
            }
            for (auto& [card, num] : count){
                if (num > 0){
                    int need = num;
                    for (int i = 0; i < groupSize; i++){
                        int next_card = card + i;
                        if (count[next_card] < need){
                            return false;
                        }
                        count[next_card] -= need;
                    }
                }
            }
        return true;
    }
};
