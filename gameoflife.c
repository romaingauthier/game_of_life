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

#include "gameoflife.h"

int checkRule(Grid *grid, int x, int y){
    int **g = grid->g;
    int size = grid->size;
    if ( x > 0 && x < size-1 && y > 0 && y < size-1) {
	return g[x-1][y-1]
             + g[x-1][y]
             + g[x-1][y+1]
	     + g[x][y-1]
             + g[x][y+1]
	     + g[x+1][y-1]
             + g[x+1][y]
             + g [x+1][y+1];
    }
    else if (x == 0) {
	      if (y == 0) {
                  return g[0][1]
                       + g [1][1]
                       + g[1][0];
              }
              else if (y == size-1) {
		  return g[0][size-2]
                       + g[1][size-1]
                       + g[1][size-2];
              }
	      else return g[0][y-1]
                        + g[1][y-1]
		        + g[1][y] + g[1][y+1]
		        + g[0][y+1];
    }
    else if (x == size-1) {
	      if (y == size-1) {
		  return g[size-1][size-2]
		       + g[size-2][size-2]
		       + g[size-2][size-1];
              }
              else if (y == 0) {
		  return g[size-1][1]
		       + g[size-2][0]
		       + g[size-2][1];
              }
              else return g[size-1][y-1]
                        + g[size-1][y+1]
                        + g[size-2][y-1]
                        + g[size-2][y]
                        + g[size-2][y+1];
    }
    else if (y == size-1) {
	return g[x-1][size-1]
             + g[x-1][size-2]
	     + g[x][size-2]
             + g[x+1][size-2]
	     + g[x+1][size-1];
    }
    else return g[x-1][0]
              + g[x-1][1]
              + g[x][1]
              + g[x+1][1]
              + g[x+1][0];
}


void update(Grid *from, Grid *to) {
    int i,j,res;
    int size = from->size;
    for ( i = 0 ; i < size ; i++)
        for ( j = 0 ; j < size ; j++) {
	    res = checkRule(from, i, j);
	    switch(res){
		case 2 :
		    if (from->g[i][j] == 0) to->g[i][j] = 0;
		    else to->g[i][j] = 1;
		    break;
		case 3 :
		    to->g[i][j] = 1;
		    break;
		default :
		    to->g[i][j] = 0;
		    break;
	    }
	}
}


void drawToWindow(Grid *grid, WINDOW *window, char cell){
    int i,j;
    for ( i = 0 ; i < grid->size ; i++)
        for ( j = 0 ; j < grid->size ; j++) {
	    if (grid->g[i][j] == 1) mvwaddch(window, j, i, cell);
	    else mvwaddch(window, j, i, ' ');
	}
}


