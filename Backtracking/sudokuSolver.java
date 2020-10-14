import java.util.Arrays;

public class Sudoku {
    public static void main(String[] args) {
    int[][] board ={ {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    sudoku(board, 0,0);
    }
    public static void sudoku(int[][] board, int row, int col){
        if (row == 9){
            //print board
            for (int i = 0; i < 9; i++) {
                System.out.println(Arrays.toString(board[i]));
            }
            return;
        }
        //completed the row
        if (col == 9){
            sudoku(board, row+1,0);
            return;
        }
        //if current ite is blank
        if(board[row][col]==0){
            //process
            for (int i = 1; i <= 9; i++) {
                if(isSafe(board, row, col, i)){
                    board[row][col] = i;
                    sudoku(board, row, col+1);
                    board[row][col] = 0;
                }
            }
        } else {
            sudoku(board, row, col+1);
        }
    }

    public  static boolean isSafe(int[][] board, int row, int col, int val){
        //check row
        for (int c = 0; c <9 ; c++) {
            if(board[row][c] == val){
                return false;
            }
        }
        //check column
        for (int r = 0; r<9; r++){
            if (board[r][col] == val){
                return false;
            }
        }

        //check current box
        int rowChunk = row/3;
        int colChunk = col/3;

        for (int a = rowChunk*3; a <(rowChunk+1)*3 ; a++) {
            for (int b = colChunk*3; b < (colChunk+1)*3 ; b++) {
                if(board[a][b] == val){
                    return false;
                }
            }
        }
        return true;
    }
}