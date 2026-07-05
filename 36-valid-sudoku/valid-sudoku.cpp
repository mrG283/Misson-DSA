class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>row(9);
        vector<unordered_set<char>>column(9);
        vector<unordered_set<char>>boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char num=board[i][j];
                int box=(i/3)*3+(j/3);
                if(num=='.'){
                    continue;
                }
                if(row[i].find(num)!=row[i].end()){
                    return false;
                }
                if(column[j].find(num)!=column[j].end()){
                    return false;
                }
                if(boxes[box].find(num)!=boxes[box].end()){
                    return false;
                }
                row[i].insert(num);
                column[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
        
    }
};