class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int total = mainTank;
        int result = 0;
        while(total>=5 && additionalTank > 0){
            int move = min(additionalTank, total/5);
            result += 10 * move * 5;
            total -= 4 * move;
            additionalTank -= move;
        }
        result += total*10;
        return result;
    }
};