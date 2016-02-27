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

#include "cmdline.h"
#include <string.h>

static int help_tag;
void usage(void) {
    printf("Usage: gameOfLife [options...]\n");
    printf("   --size       -s size of the squared grid (default: 30)\n");
    printf("   --delay      -d time between two iterations in ms (default: 100)\n");
    printf("   --cell       -c character used to draw a cell (default: '#')\n");
    printf("   --nbiter     -n number of iterations (default: 0 (infinite))\n");
    printf("   --border     -b border of the grid (0 = no border (default), 1 = fixed border)\n");
    printf("   --pattern    -p path to the pattern file\n");
    printf("   --help          display this help\n");
}

void initParams(Params *params) {
    params->size   = -1;
    params->sizex  = -1;
    params->sizey  = -1;
    params->delay  = 0;
    params->cell   = '#';
    params->nbiter = 0;
    params->filename[0] = '\0';
}

void parseOptions(int argc, char **argv, Params *params) {
    int c;
    while(1) {

        static struct option long_options[] =
        {
            {"help",      no_argument      , &help_tag, 0 },
            {"size",      required_argument, 0, 's'},
            {"delay",     required_argument, 0, 'd'},
            {"cell",      required_argument, 0, 'c'},
            {"nbiter",    required_argument, 0, 'n'},
            {"border",    required_argument, 0, 'b'},
            {"pattern",   required_argument, 0, 'p'},
            {0,0,0,0}
        };
        int option_index = 0;
        c = getopt_long(argc, argv, "s:d:c:n:b:p:g:h:", long_options, &option_index);
        if (c == -1)
            break;
        switch(c) {
          case 0:
            usage();
            exit(0);
          case 's':
            params->size  = atoi(optarg);
            break;
          case 'p':
            strcpy(params->filename, optarg);
            break;
          case 'd':
            params->delay = atol(optarg);
            break;
          case 'c':
            params->cell  = optarg[0];
            break;
          case 'b':
            params->border  = atoi(optarg);
            break;
          case 'n':
            params->nbiter  = atoi(optarg);
            break;
        }
    }
}
