/*
    The following program implements a command-line game of life, originally
    introduced by John Conway in 1970.

    This program is licensed under a GNU GPL 3.0 License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    You should have received a copy of the GNU GPL 3.0 License along with this
    program. If not, see <http://www.gnu.org/licenses/gpl.html/>.

    Copyright (c) 2013 Romain Gauthier
*/

#ifndef DEF_CMDLINE
#define DEF_CMDLINE

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct Params{
    int  size;
    int  sizex;
    int  sizey;
    int  border;
    long delay;
    char cell;
    unsigned int nbiter;
    int graphmode;
    char filename[1024];
} Params;

void usage(void);
void parseOptions(int argc, char **argv, Params *params);
void initParams(Params *params);

#endif
