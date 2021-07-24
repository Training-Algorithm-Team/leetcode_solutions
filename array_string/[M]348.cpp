// https://leetcode.com/problems/design-tic-tac-toe/

/* Ta dem so phan tu cua moi player o moi hang, neu khi them vao ma so phan tu hang do cua player do == n thi ta return ket qua.

*/

class TicTacToe {
private:
    typedef array<int, 2> RowCol;
    vector<RowCol> rows, cols;
    RowCol forwardDiagonal, backwardDiagonal;
    int n;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : forwardDiagonal({0, 0}), backwardDiagonal({0, 0}){
        rows.resize(n, {0, 0});
        cols.resize(n, {0, 0});
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rows[row][player-1]++;
        cols[col][player-1]++;
        
        if (row == col) {
            forwardDiagonal[player-1]++;
        }
        if (row + col == n - 1) {
            backwardDiagonal[player-1]++;
        }
        
        if (rows[row][player-1] == n || cols[col][player-1] == n || forwardDiagonal[player-1] == n || backwardDiagonal[player-1] == n) {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
