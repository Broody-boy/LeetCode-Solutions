class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int time = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < tickets.size(); i++)
            q.push({tickets[i], i});

        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            front.first--; time++;                                      //decrement by 1 and increase time counter by 1
            if(front.first == 0 && front.second == k) return time;      // If the kth element is done with, return ans
            if(front.first != 0) q.push({front.first, front.second});   //If the current element is non zero, push it to end of queue
        }

        return INT_MAX; //dummy statement
    }
};