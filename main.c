/*
    The following program implements a command-line game of life, originally
    introduced by John Conway in 1970.

    This program is licensed under a GNU GPL 3.0 License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the GNU GPL 3.0 License along with this
    program. If not, see <http://www.gnu.org/licenses/gpl.html>.

    Copyright (c) 2013 Romain Gauthier <rj.gauthier@laposte.net>
*/

#include "gameoflife.h"
#include "cmdline.h"
#include "patterns.h"
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <SDL/SDL.h>

int main(int argc, char **argv){

    /* Parse options */
    Params p;
    initParams(&p);
    parseOptions(argc, argv, &p);

    /* Terminal settings */
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int termsize = (w.ws_row > w.ws_col) ? w.ws_col : w.ws_row;
    if( p.size < 0 || p.size > termsize) p.size = termsize;

    /* Allocate memory */
    int startx, starty;
    Grid grid, grid2;
    initGrid(&grid, p.size);
    initGrid(&grid2, p.size);

    /* Set refresh rate */
    struct timespec req, rem;
    int factms = 1000000;
    if (!p.delay) {
        req.tv_sec  = 0;
        req.tv_nsec = 100 * factms;
    }
    else if (p.delay < 1000) {
        req.tv_sec  = 0;
        req.tv_nsec = p.delay * factms;
    }
    else {
        req.tv_sec = p.delay / 1000;
        req.tv_nsec = (p.delay - 1000 * (p.delay / 1000)) * factms;
    }

    unsigned int iteration = 0, nbiter = 0;
    if (p.nbiter) nbiter = p.nbiter;

    /* Graphics */
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Quit();

    /* Console pattern loading */

    Grid pattern;

    if(strlen(p.filename)) {
        loadPatternFromFile(p.filename, &pattern);
        loadPatternToGrid(&pattern, &grid, -1, -1);
    }
    else loadDefaultPatternToGrid(&grid);


    /* Start curses mode */
    initscr();
    cbreak();

    starty = (LINES - p.size) / 2;
    startx = (COLS - p.size) /2;

    refresh();
    WINDOW *window;
    window = newwin(p.size, p.size, starty, startx);
    box(window, 0, 0);


    curs_set(0);

    while (iteration < nbiter || !p.nbiter){
	if (iteration % 2 == 0){
	    update(&grid, &grid2);
	    drawToWindow(&grid2, window, p.cell);
	}
	else {
	    update(&grid2, &grid);
	    drawToWindow(&grid, window, p.cell);
	}
	wrefresh(window);
	nanosleep(&req, &rem);
	iteration++;
    }

    endwin();

    /* Deallocate memory */
    freeGrid(&grid);
    freeGrid(&grid2);
}
