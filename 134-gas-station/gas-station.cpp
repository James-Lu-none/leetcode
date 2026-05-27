class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalTank = 0;
        int tempTank = 0;
        int startFrom = 0;
        
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            totalTank += diff;
            tempTank += diff;
            if(tempTank < 0){
                tempTank = 0;
                startFrom = i + 1;
                printf("start again from %d", startFrom);
            }
        }
        // we still have to check if total is positive
        return (totalTank < 0) ? -1 : startFrom;
    }
};