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


#include "graph.h"

GraphU* createGraphU() {
    GraphU *g      = (GraphU*)malloc(sizeof(GraphU));
    g->win          = NULL;
    return g;
}

PtList* createPtList(unsigned int maxNbPts) {
    PtList *p = (PtList*)malloc(sizeof(PtList));
    p->maxNbPts = maxNbPts;
    p->pt     = (SDL_Point*)malloc(maxNbPts * sizeof(SDL_Point));
    p->count  = -1;
    return p;
}


void initGraphU(GraphU *g, unsigned int width, unsigned int height){
    g->win = SDL_CreateWindow("game of life",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width,
                            height,
                            0);
    g->renderer = SDL_CreateRenderer(g->win,
                                     -1,
                                     SDL_RENDERER_ACCELERATED);
}

void fillPtList(PtList *p, Grid *grid) {
    for(int w = 0; w < grid->size ; w++)
        for (int h = 0; h < grid->size; h++)
            if (grid->g[w][h]){
                p->pt[++(p->count)].x = w;
                p->pt[p->count].y     = h;
            }

}

void clearPtList(PtList *p) {
    memset(p->pt, 0, p->maxNbPts);
    p->count = -1;
}


void destroyGraphU(GraphU* g){
    SDL_DestroyRenderer(g->renderer);
    SDL_DestroyWindow(g->win);
    free(g);
}

void destroyPtList(PtList *p) {
    free(p->pt);
    free(p);
}


void drawGrid(GraphU *graphU, PtList *p) {
    SDL_SetRenderDrawColor(graphU->renderer,
                           255,
                           255,
                           255,
                           255);
    SDL_RenderClear(graphU->renderer);
    SDL_SetRenderDrawColor(graphU->renderer,
                           0,
                           0,
                           0,
                           255);
    SDL_RenderDrawPoints(graphU->renderer,
                         p->pt,
                         p->count);
    SDL_RenderPresent(graphU->renderer);
    clearPtList(p);
}
