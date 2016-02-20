/*
    The following program implements a command-line game of life, originally
    introduced by John Conway in 1970.

    This program is licensed under a GNU GPL 3.0 License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the GNU GPL 3.0 License along with this
    program. If not, see <http://www.gnu.org/licenses/gpl.html>.

    Copyright (c) 2013 Romain Gauthier
*/

#ifndef DEF_PATTERNS
#define DEF_PATTERNS
#include <stdlib.h>
#include <stdio.h>

typedef struct Grid{
    int **g;
    int size;
    int zoomfactor;
} Grid;


void initGrid(Grid *grid, int size, int zoomfactor);
void loadPatternToGrid(Grid *pattern, Grid *grid, int x, int y);
void freeGrid(Grid *pattern);
void loadPatternFromFile(const char* path, Grid *pattern);
void generateRandomPatternOnGrid(Grid *grid, double live);

#endif
