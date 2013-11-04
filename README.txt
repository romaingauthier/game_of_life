###############################################################################
###############################################################################
##############################  GAME OF LIFE v0.1  ############################
###############################################################################
###############################################################################

1. PRESENTATION

This tiny program is a very simple to use command-line tool to play around with
game of life patterns within your terminal. The game of life is a very popular
example of a cellular automaton that was introduced by the mathematician John
Conway in 1970.

-------------------------------------------------------------------------------
2. HOW TO BUILD & RUN THE PROGRAM

* The ncurses library is required to build the program.

* For Linux users, a makefile is provided to build the project.

* To run the program, several parameters can be specified as arguments:

   --size,    -s size of the squared grid (default: 30)
   --delay,   -d time between two iterations in ms (default: 100)
   --cell,    -c character used to draw a cell (default: '#')
   --nbiter,  -n number of iterations (default: 0 (infinite))
   --pattern, -p path to the pattern file
   --help,       display this help

* A couple of patterns are already available in the patterns directory.
  -> working example : ./gameOfLife -p 'patterns/pentadecathlon.pat'

-------------------------------------------------------------------------------
3. AUTHOR

Romain Gauthier               <rj.gauthier@laposte.net>

-------------------------------------------------------------------------------
4. LICENSE

Please refer to the GNU GPL 3.0 License (see gpl.txt).
