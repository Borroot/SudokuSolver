make: sudoku_solver

sudoku_solver: SudokuSolver.cpp
	g++ -o SudokuSolver SudokuSolver.cpp

clean: 
	rm SudokuSolver
