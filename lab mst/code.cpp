class Solution {
public:
    string check;
    int n1,n2;
    bool solve(vector<vector<char>> &board, int r, int c, int in){
        if(r>= n1 || c >=n2 || r<0 || c <0) return false;
        if(in == check.size()) return true;
        if(board[r][c] != check[in]) return false;
        char j = board[r][c];
        board[r][c] = '%';
        if(solve(board,r,c+1,in+1)) return true;
        if(solve(board,r,c-1,in+1)) return true;
        if(solve(board,r+1,c,in+1)) return true;
        if(solve(board,r-1,c,in+1)) return true;
        board[r][c] = j;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char c = word[0];
        if(m == 1 && n== 1){
            if(c == board[0][0] && word.size() == 1) return true; 
            return false;
        }
        n1 = m;
        n2 = n;
        check = word;
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                if(solve(board,i,j,0)) return true;
            }
        }
        return false;
    }
};