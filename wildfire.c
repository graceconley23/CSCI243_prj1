// File: wildfire.c
// Description: tbd
//
// @author Grace Conley
////////////////////////////////////////////////////////////////////////

#define _DEFAULT_SOURCE

#include <stdio.h>
#include "display.h"
#include "wildfire.h"

static float burningProp; 	// 0.01 to 1.0 - default 0.1 - bN
static float catchingProb; 	// 0.01 to 1.0 - default 0.3 - cN
static float density; 		// 0.01 to 1.0 - default 0.5 - dN
static float neighborEffect;	// 0.01 to 1.0 - default 0.5 - nN
static int size; 		// 5    to 40  - default 10  - sN

static int steps;		// no default - pN
static int printMode;		// default 0 - pN


static void printForest(char forest[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", forest[i][j]);
        }
        printf("\n");
    }
}

static void initialize(char forest[size][size]) {
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			forest[i][j] = TREE;
		}
	}
	printForest(forest);
}

int main() {
	// Assume no flags for now
	burningProp = 0.1;
	catchingProb = 0.3;
	density = 0.5;
	neighborEffect = 0.5;
	size = 10;
	char forest[size][size];

	initialize(forest);

}
