class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.size()==0){
                leftSmall[i]=0;
            }else{
                leftSmall[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.size()==0){
                rightSmall[i]=n-1;
            }else{
                rightSmall[i]=s.top()-1;
            }
            s.push(i);
        }

        int area=-1;
        for(int i=0; i<n; i++){
            int width=rightSmall[i]-leftSmall[i]+1;
            int newArea=width*heights[i];
            area=max(area,newArea);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> > mat(n,vector<int>(m));
        for(int j=0; j<m; j++){
            mat[0][j]=matrix[0][j]-'0';
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0'){
                    mat[i][j]=0;
                }else{
                    mat[i][j]=mat[i-1][j]+1;
                }
            }
        }

        for(int i=0; i<n; i++){
            area=max(area,largestRectangleArea(mat[i]));
        }


        return area;
    }
};