class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for(i=0; i<heights.size()-1; i++){
       
            if(heights[i+1]<=heights[i]){

                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(diff<=bricks){
                bricks-=diff;
                pq.push(diff);
            }else if(ladders>0){
                if(!pq.empty()){
                    int a=pq.top();
                    if(diff<a){
                        pq.pop();
                        bricks+=a;
                        bricks-=diff;
                        ladders--;
                        pq.push(diff);
                    }else{
                        ladders--;
                    }
                }else{
                    ladders--;
                }
            }else{
                break;
            }
        }

        return i;
    }
};