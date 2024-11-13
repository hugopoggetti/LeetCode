class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_f = 0;
        int bill_t = 0;
        int bill_tw = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                bill_f++;
            if (bills[i] == 10) {
                if (bill_f < 1) {
                    return false;
                }
                bill_f--;
                bill_t++;
            }
            if (bills[i] == 20) {
                if (bill_f < 1 && bill_t < 1)
                    return false;
                bill_tw++;
                bill_f--;
                bill_t--;
            }
        }
        return  true;
    }
};
