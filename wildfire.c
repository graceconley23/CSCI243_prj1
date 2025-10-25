// File: wildfire.c
// Description: tbd
//
// @author Grace Conley
////////////////////////////////////////////////////////////////////////

#define _DEFAULT_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "display.h"
#include "wildfire.h"

static float burningProp; 	// 0.01 to 1.0 - default 0.1 - bN
static float catchingProb; 	// 0.01 to 1.0 - default 0.3 - cN
static float density; 		// 0.01 to 1.0 - default 0.5 - dN
static float neighborEffect;	// 0.01 to 1.0 - default 0.5 - nN
static int size; 		// 5    to 40  - default 10  - sN

static int steps;		// no default - pN
static int printMode;		// default 0 - pN

static int directions[8][2] = {	{-1, -1}, {-1, 0}, {-1, 1},
				{ 0, -1},          { 0, 1},
				{ 1, -1}, { 1, 0}, { 1, 1}	};


static int randInt(int min, int max) {
	int range = max - min + 1;
	return (min + random() % range);
}

static void printForest(char forest[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%c ", forest[i][j]);
		}
		printf("\n");
	}
}

static void initialize(char forest[size][size]) {
	// Calculate the correct number of each symbol
	int spaces = size*size;
	char symbols[spaces+1];
	int trees = (int)roundf(spaces*density);
	int burning = (int)roundf(trees*burningProp);
	trees = trees - burning;

	// Fill an array with the appropriate number of each symbol
	int sym = 0;
	for (; sym<trees; sym++) {
		symbols[sym] = TREE;
	}
	for (; sym < trees+burning; sym++) {
		symbols[sym] = BURNING;
	}
	for (; sym < spaces; sym++) {
		symbols[sym] = EMPTY;
	}

	// Shuffle the symbols
	for (int k=spaces - 1; k>0; k--) {
        	int rand = random() % (k + 1);
        	char temp = symbols[k];
        	symbols[k] = symbols[rand];
        	symbols[rand] = temp;
    	}

	// Fill the forest with the symbols
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			forest[i][j] = symbols[i*size + j];
		}
	}
}

static int burn(char forest[size][size], int i, int j) {
	int neighbors = 0;
	int burning = 0;

	for (int v=0; v<8; v++) {
		// Get total neighbors and burning neighbors
		int neighbori = i + directions[v][0];
		int neighborj = j + directions[v][1];
		if (neighbori > 0 && neighbori < size && neighborj > 0 && neighborj < size) {
			neighbors++;
			if (forest[neighbori][neighborj] == BURNING) {
				burning++;
			}
		}
	}
	return burning;

}

static void printBurn(char forest[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", burn(forest,i,j));
        }
        printf("\n");
    }
}

int main() {
	srandom(41);

	// Assume no flags for now
	burningProp = 0.1;
	catchingProb = 0.3;
	density = 0.5;
	neighborEffect = 0.5;
	size = 10;
	char forest[size][size];

	initialize(forest);
	printForest(forest);
	printBurn(forest);
}
