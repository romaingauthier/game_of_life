/*
    The following program implements a command-line game of life, originally
    introduced by John Conway in 1970.

    This program is licensed under a GNU GPL 3.0 License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the GNU GPL 3.0 License along with this
    program. If not, see <http://www.gnu.org/licenses/gpl.html>.

    Copyright (c) 2013 - 2016 Romain Gauthier
*/

#include "patterns.h"
#include <regex.h>
#include <time.h>

void initGrid(Grid *grid, int sizex, int sizey) {
    grid->sizex = sizex;
    grid->sizey = sizey;
    grid->g = (int**)malloc(sizex * sizeof(int*));
    for(int i = 0; i < sizex ; i++)
      grid->g[i] = (int*)calloc(sizey,sizeof(int));
}

void loadPatternToGrid(Grid *pattern, Grid *grid, int x, int y) {
    if (pattern->sizex > grid->sizex || pattern->sizey > grid->sizey) {
        fprintf(stderr, "ERROR: the pattern size is larger than the grid size. \
                \n");
        exit(EXIT_FAILURE);
    }

    if (y+pattern->sizey > grid->sizey-1 || x+pattern->sizex > grid->sizex-1) {
        fprintf(stderr, "ERROR: the offset is too large for the grid.\n");
        exit(EXIT_FAILURE);
    }
    int x_offset = x, y_offset = y;

    if (x < 0 || y < 0) {
        x_offset = (grid->sizex - pattern->sizex) / 2;
        y_offset = (grid->sizey - pattern->sizey) / 2;
    }

    for(int i = 0; i < pattern->sizex; i++)
        for(int j = 0; j < pattern->sizey; j++)
            grid->g[x_offset+i][y_offset+j] = pattern->g[i][j];
}

void loadPatternFromFile(const char* path, Grid *pattern) {
    FILE *file = NULL;
    file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "ERROR: unable to open file '%s'.\n", path);
        exit(EXIT_FAILURE);
    }
    int size = 0, counter = 0;
    char line[2048];
    regex_t regex;
    int ret = regcomp(&regex, "[01]", 0);

    int scanTest = fscanf(file, "size %d", &size);
    if (!size || !scanTest) {
        fprintf(stderr, "ERROR: unable to read pattern from file '%s'.\n", path);
        exit(EXIT_FAILURE);
    }

    initGrid(pattern, size, size);
    while(fgets(line, 2048, file) != NULL) {
        ret = regexec(&regex, line, 0, NULL, 0);
        if (!ret) {
            for (int i = 0; i < size ; i++)
                pattern->g[i][counter] = line[i] - '0';
            counter++;
        }
    }
    fclose(file);
}

void generateRandomPatternOnGrid(Grid *grid, double live) {
    double l = live;
    srand(time(NULL));
    if ( l <= 0 || l >=1 )
        l = 0.5;
    for (int w = 0; w < grid->sizex ; w++)
        for (int h = 0; h < grid->sizey ; h++) {
            if((double)rand()/(double)RAND_MAX <= l)
                grid->g[w][h] = 1;
            else grid->g[w][h] = 0;
        }
}

void freeGrid(Grid *pattern) {
    for (int i = 0; i < pattern->sizey; i++)
        free(pattern->g[i]);
    free(pattern->g);
}
