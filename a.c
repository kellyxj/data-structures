#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **matrix;
int numrows = 20;
int numcols = 20;

int main(int argc, char *argv[]) {
    
    matrix = (int **) calloc(numrows, sizeof(int));
    for(int i = 0; i < 20; i++) {
    	matrix[i] = (int*) calloc(numcols, sizeof(int));
    	for(int j = 0; j < 20; j++) {
    	    matrix[i][j] = 0;
    	}
    	printf("\n");
    }
}

//fill board with n mines, avoiding placing mines at row y, col x
//after mines are placed, increment all tiles adjacent to mines
//to correct values
void populate(int n, int y, int x) {

}

//reveal the tile at row y, col x
//check end of game conditions
int guess(int y, int x) {

}
