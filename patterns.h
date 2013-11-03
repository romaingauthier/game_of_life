/*
    The following program implements a command-line game of life, originally
    introduced by John Conway in 1970.

    This program is licensed under a Creative Commons Attribution 3.0 License.
    This license lets you distribute, remix, tweak, and build upon this work,
    even commercially, as long as you credit its author(s) for the original
    creation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the Creative Commons Attribution 3.0
    License along with this program.
    If not, see <http://creativecommons.org/licenses/by/3.0/legalcode>.

    Copyright (c) 2013 Romain Gauthier <rj.gauthier@laposte.net>
*/

#ifndef DEF_PATTERNS
#define DEF_PATTERNS
#include <stdlib.h>
#include <stdio.h>

typedef struct Grid{
    int **g;
    int size;
} Grid;


void initGrid(Grid *grid, int size);
void loadPatternToGrid(Grid *pattern, Grid *grid, int x, int y);
void freeGrid(Grid *pattern);
void loadPatternFromFile(const char* path, Grid *pattern);
void loadDefaultPatternToGrid(Grid *grid);

#endif
