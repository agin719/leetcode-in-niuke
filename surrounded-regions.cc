#ifndef LOGDB_SOL_H_
#define LOGDB_SOL_H_

class LogdbSol{
  public:
    void solve(vector<vector<char>> &board) {
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          if (board[i][j] == 'O') {
            if (i == 0 || i == board.size()-1 || j == 0 || j == board[i].size()-1) 
              continue;
            if ((board[i-1][j]=='X' || board[i-1][j]=='T') && (board[i][j-1]=='X' || board[i][j-1]=='T')) 
              board[i][j] = 'T';
          }
        }
      }

      for (int i = board.size()-1; i >= 0; i--) {
        for (int j = board[i].size()-1; j >= 0; j--) {
          if (board[i][j] == 'T') {
            if ((board[i+1][j]=='X' || board[i+1][j]=='U') && (board[i][j+1]=='X' || board[i][j+1]=='U'))
              board[i][j] = 'U';
            else 
              board[i][j] = 'O';
          }
        }
      }
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          if (board[i][j] == 'U') {
            if ((board[i-1][j]=='X' || board[i-1][j]=='U') && (board[i][j-1]=='X' || board[i][j-1]=='U')) 
              board[i][j] = 'X';
            else 
              board[i][j] = 'O';
          }
        }
      }


    }
};
XOXOXOOOXO  XOXOXOOOXO
XOOXXXOOOX  XOOXXXOOOX
OOOOOOOOXX  OOOOOOOOXX
OOOOOOXOOX  OOOOOOXOOX
OOXXOXXOOO  OOXXOXXOOO
XOOXXXOXXO  XOOXXXTXXO
XOXOOXXOXO  XOXTTXXTXO 
XXOXXOXOOX  XXTXXTXOTX
OOOOXOXOXO  OOOOXXXOXO
XXOXXXXOOO  XXOXXXXOOO
#endif

OXXXXXOO OXXXXXOO
OOOXXXXO OOOXXXXO
XXXXOOOO XXXXOOOO
XOXOOXXX XXOXXXXOOOXXX
OXOXXXOO OXUXXXOO
OXXOOXXO OXXUUXXO
OXOXXXOO OXUXXXOO
OXXXXOXX OXXXXOXX

