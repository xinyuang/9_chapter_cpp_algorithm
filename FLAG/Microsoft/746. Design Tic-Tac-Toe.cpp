#include<exception>

class GameEndException : public exception
{
	virtual const char* what() const noexcept
	{
		return "GameEndException";
	}
} gameEndException;

class AlreadyTakenException : public exception
{
	virtual const char* what() const noexcept
	{
		return "AlreadyTakenException";
	}
} takenException;

class TicTacToe {
private:
	char currentPlayer;
	char board[3][3];
	bool gameEnd;
	int step;
public:

	void initialize() {
		step = 0;
		currentPlayer = 'x';
		gameEnd = false;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = '-';
			}
		}
	}
	/** Initialize your data structure here. */
	TicTacToe() {
		initialize();
	}

	bool checkFull() {
		return step == 9;
	}

	bool checkEnd() {
		return gameEnd;
	}

	bool checkTaken(int r, int c) {
		return board[r][c] == 'x' || board[r][c] == 'o';
	}

	void checkWin(bool& res, int r, int c)
	{
		int count = 0;
		board[r][c] = currentPlayer;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] == currentPlayer) count++;
		}
		if (count == 3)
		{
			res = true;
			return;
		}
		count = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[2 - i][i] == currentPlayer) count++;
		}
		if (count == 3)
		{
			res = true;
			return;
		}
		count = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[r][i] == currentPlayer) count++;
		}
		if (count == 3)
		{
			res = true;
			return;
		}
		count = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][c] == currentPlayer) count++;
		}
		if (count == 3)
		{
			res = true;
			return;
		}
	}

	void changePlayer() {
		if (currentPlayer == 'x') currentPlayer = 'o';
		else currentPlayer = 'x';
	}

	bool move(int row, int col) {
		if (checkFull() || checkEnd()) throw gameEndException;
		if (checkTaken(row, col)) throw takenException;
		step++;
		bool res = false;
		checkWin(res, row, col);
		changePlayer();
		if (res) {
			gameEnd = true;
			step = 0;
		}
		return res;
	}
};