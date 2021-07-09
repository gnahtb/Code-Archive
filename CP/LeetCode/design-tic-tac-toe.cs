public class TicTacToe {
    private int[,] _board;
    private int _boardSize { get; set; }
    
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        _boardSize = n;
        _board = new int[n, n];
    }
    
    private bool IsValidCell(int row, int col) {
        return 0 <= row && row < _boardSize && 0 <= col && col < _boardSize;
    }
    
    private int CountConsecutiveSameCells(int row, int col, int step_row, int step_col) {
        int sameCells = 0;
        while (IsValidCell(row + step_row, col + step_col) && 
               _board[row, col] == _board[row + step_row, col + step_col]) {
            ++sameCells;
            row += step_row;
            col += step_col;
        }
        return sameCells;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int Move(int row, int col, int player) {
        _board[row, col] = player;
        int horizontalLine = CountConsecutiveSameCells(row, col, 0, 1) + 
            CountConsecutiveSameCells(row, col, 0, -1);
        int verticalLine = CountConsecutiveSameCells(row, col, 1, 0) + 
            CountConsecutiveSameCells(row, col, -1, 0);
        int mainDiagonalLine = CountConsecutiveSameCells(row, col, -1, -1) + 
            CountConsecutiveSameCells(row, col, 1, 1);
        int antiDiagonalLine = CountConsecutiveSameCells(row, col, -1, 1) + 
            CountConsecutiveSameCells(row, col, 1, -1);
        if (horizontalLine == _boardSize - 1 ||
            verticalLine == _boardSize - 1 ||
            mainDiagonalLine == _boardSize - 1 ||
            antiDiagonalLine == _boardSize - 1)
            return player;
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.Move(row,col,player);
 */