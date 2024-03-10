class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(int i=0; i<apple.size(); i++){
            sum+=apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cap=0;
        int count=0;
        for(int i=0; i<capacity.size(); i++){
            if(cap>=sum){
                return count;
            }
            cap+=capacity[i];
            count++;
        }
        return count;
    }
};