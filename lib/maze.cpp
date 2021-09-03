//Libs to use 
#include <iostream>
#include <fstream>
#include "maze.h"

//Constructor
Maze::Maze(string pathFile){
	
	// Read the file 
	ifstream file(pathFile.c_str());
	string line;

	// Set the size of the matrix
	getline(file, line);
	this -> _size = stoi(line);
	this -> _matrix = (char **)malloc(this -> _size*sizeof(int *));
	for(int i = 0; i < this -> _size; i++){
		this -> _matrix[i] = (char *) malloc(this -> _size*sizeof(int *));
	}

	// Fill the matrix
	for(int row = 0; row < _size; row++){
		getline(file, line);
		for(int col = 0; col < _size; col++){
			this -> _matrix[row][col] = line[col];
			if(line[col] == '*'){
				// Initialize the player
				this -> jack = new Player(row, col);
			}
		}
	}
}

//Getters
int Maze::getSize(){
	return this -> _size;
}

char** Maze::getMaze(){
	return this -> _matrix;
}

