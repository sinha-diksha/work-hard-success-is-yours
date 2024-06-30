class Solution {
public:
    vector<int> r={1,-1,0,0};
    vector<int> c={0,0,1,-1};
    bool find(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if(idx==word.length()){
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='$'){
            return false;
        }

        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(int k=0; k<4; k++){
            int new_i=i+r[k];
            int new_c=j+c[k];
            if(find(board, word, new_i, new_c, idx+1)){
                return true;
            }
        }
        board[i][j]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
		
                if(board[i][j] == word[0] && find(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};