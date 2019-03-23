#include <iostream>

using namespace std;

const int N = 9;

struct Position {
	int x; 
	int y;
};

int board[N][N] = {
	{4, 0, 0, 0, 5, 0, 0, 0, 2},
	{5, 7, 0, 0, 0, 0, 8, 4, 0},
	{0, 0, 0, 3, 0, 0, 0, 0, 1},
	{0, 0, 9, 6, 0, 0, 0, 0, 0},
	{0, 0, 0, 5, 0, 8, 0, 0, 0},
	{0, 0, 0, 0, 0, 3, 4, 0, 0},
	{1, 0, 0, 0, 0, 7, 0, 0, 0},
	{0, 9, 2, 0, 0, 0, 0, 5, 8},
	{3, 0, 0, 0, 2, 0, 0, 0, 6}
};

void print(int board[N][N]){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(board[y][x] != 0)
				cout << board[y][x] << " ";
			else 
				cout << ". ";
		}
		cout << endl;
	}
}

void initUsed(bool used[N]){
	for(int i = 0; i < N; i++)
		used[i] = false;
}

bool isDouble(int value, bool used[N]){
	if(value == 0)
		return false;

	value--;
	if(used[value])
		return true;
	else 
		used[value] = true;
	return false;
}

bool validSquare(int board[N][N], const int X, const int Y){
	bool used[N];
  	initUsed(used);

	for(int y = Y; y < N/3 + Y; y++){
		for(int x = X; x < N/3 + X; x++){
			if(isDouble(board[y][x], used))
				return false;
		}
	}	
	return true;
}

bool validSquares(int board[N][N]){
	for(int y = 0; y < N; y += 3){
		for(int x = 0; x < N; x+= 3){
			if(!validSquare(board, x, y))
				return false;
		}
	}
	return true;
}

bool validRows(int board[N][N]){
	bool used[N];
  	initUsed(used);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(isDouble(board[y][x], used))
				return false;
		}
		initUsed(used);
	}
	return true;
}

bool validColumns(int board[N][N]){
	bool used[N];
  	initUsed(used);

	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			if(isDouble(board[y][x], used))
				return false;
		}
		initUsed(used);
	}
	return true;
}

bool isValid(int board[N][N]){
	return validSquares(board) && validRows(board) && validColumns(board);
}

void nextPosition(Position *pos){
	if(pos->x == N-1){
		pos->x = 0;
		pos->y++;
	}else{
		pos->x++;
	}
}

void previousPosition(Position *pos){
	if(pos->x == 0){
		pos->x = N-1;
		pos->y--;
	}else{
		pos->x--;
	}
}

void solve(int board[N][N], Position *pos){
	if(pos->y == N){
		if(isValid(board))
			print(board);
		return;
	}
	if(!isValid(board))
		return;

	if(board[pos->y][pos->x] != 0){
		nextPosition(pos);
		solve(board, pos);
		previousPosition(pos);
	}else{
		int temp = board[pos->y][pos->x];
		for(int i = 1; i <= N; i++){
			board[pos->y][pos->x] = i;
			nextPosition(pos);
			solve(board, pos);
			previousPosition(pos);
		}
		board[pos->y][pos->x] = temp;
	}	
}

int main(){
	print(board);

	Position pos = {0, 0};
	solve(board, &pos);
}
