class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v(n);
        for(int j=0; j<n; j++){
            int maxi=INT_MIN;
            for(int i=0; i<m; i++){
                maxi=max(matrix[i][j], maxi);
            }
            v[j]=maxi;
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=v[j];
                }
            }
        }

        return matrix;
        
    }
};