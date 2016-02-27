# GAME OF LIFE v0.1

## PRESENTATION

This tiny program is a very simple to use command-line tool to play around with
game of life patterns within your terminal. The game of life is a very popular
example of a cellular automaton that was introduced by the mathematician John
Conway in 1970.

## HOW TO BUILD & RUN THE PROGRAM

* The ncurses library is required to build.

* For Linux users, a makefile is provided to build the project.

* To run the program, several parameters can be specified as arguments:

```
   --size     -s size of the squared grid (default: rectangular grid, dimensions of the terminal)
   --delay    -d time between two iterations in ms (default: 100)
   --cell     -c character used to draw a cell (default: '#')
   --nbiter   -n number of iterations (default: 0 (infinite))
   --border   -b border of the grid (0 = no border (default), 1 = fixed border)
   --pattern  -p path to the pattern file
   --help        display this help
```
* A couple of patterns are already available in the patterns directory.

example :
```
$ ./gameOfLife -p 'patterns/pentadecathlon.pat'
```

## PATTERNS FORMAT

For now, the only way you can play around with patterns of you own is by adding
or editing existing files according to the following model.

```
size 2
01
10
```

On the above example, the first line specifies the size of the pattern. The
following lines describes the two lines of the pattern (living=1, dead=0).

## LICENSE

Please refer to the GNU GPL 3.0 License (see gpl.txt).
