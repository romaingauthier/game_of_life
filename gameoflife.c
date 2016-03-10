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

#include "gameoflife.h"

int checkRuleFixedBorder(Grid *grid, int x, int y){
    int **g = grid->g;
    int sizex = grid->sizex;
    int sizey = grid->sizey;
    if ( x > 0 && x < sizex-1 && y > 0 && y < sizey-1) {
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
                       + g[1][1]
                       + g[1][0];
              }
              else if (y == sizey-1) {
		  return g[0][sizey-2]
                       + g[1][sizey-1]
                       + g[1][sizey-2];
              }
	      else return g[0][y-1]
                        + g[1][y-1]
		        + g[1][y] + g[1][y+1]
		        + g[0][y+1];
    }
    else if (x == sizex-1) {
	      if (y == sizey-1) {
		  return g[sizex-1][sizey-2]
		       + g[sizex-2][sizey-2]
		       + g[sizex-2][sizey-1];
              }
              else if (y == 0) {
		  return g[sizex-1][1]
		       + g[sizex-2][0]
		       + g[sizex-2][1];
              }
              else return g[sizex-1][y-1]
                        + g[sizex-1][y+1]
                        + g[sizex-2][y-1]
                        + g[sizex-2][y]
                        + g[sizex-2][y+1];
    }
    else if (y == sizey-1) {
	return g[x-1][sizey-1]
             + g[x-1][sizey-2]
	     + g[x][sizey-2]
             + g[x+1][sizey-2]
	     + g[x+1][sizey-1];
    }
    else return g[x-1][0]
              + g[x-1][1]
              + g[x][1]
              + g[x+1][1]
              + g[x+1][0];
}

int checkRuleNoBorder(Grid *grid, int x, int y){
    int **g = grid->g;
    int sizex = grid->sizex;
    int sizey = grid->sizey;
    int xm1 = (x-1) > -1 ? x-1 : sizex-1;
    int ym1 = (y-1) > -1 ? y-1 : sizey-1;
    int xp1 = (x+1) > sizex-1 ? 0 : x+1;
    int yp1 = (y-1) > sizey-1 ? 0 : y+1;
    return g[xm1][ym1]
         + g[xm1][y]
         + g[xm1][yp1]
         + g[x][ym1]
         + g[x][yp1]
         + g[xp1][ym1]
         + g[xp1][y]
         + g[xp1][yp1];
}

void update(Grid *from, Grid *to, int (*checkRule)(Grid*, int, int)) {
    int i,j,res;
    int sizex = from->sizex;
    int sizey = from->sizey;
    for ( i = 0 ; i < sizex ; i++)
        for ( j = 0 ; j < sizey ; j++) {
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
    for ( i = 0 ; i < grid->sizex ; i++)
        for ( j = 0 ; j < grid->sizey ; j++) {
	    if (grid->g[i][j] == 1) mvwaddch(window, j, i, cell);
	    else mvwaddch(window, j, i, ' ');
	}
}
