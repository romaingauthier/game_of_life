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


#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "patterns.h"
typedef struct GraphU {
    SDL_Window *win;
    SDL_Renderer *renderer;
} GraphU;

typedef struct PtList {
    SDL_Point *pt;
    int count;
    unsigned maxNbPts;
} PtList;

GraphU* createGraphU();
PtList* createPtList(unsigned int maxNbPts);
void initGraphU(GraphU *g, unsigned int width, unsigned int h);

void fillPtList(PtList *p, Grid *grid);
void clearPtList(PtList *p);
void drawGrid(GraphU *graphU, PtList *p);

void destroyGraphU(GraphU* g);
void destroyPtList(PtList *p);


#endif
