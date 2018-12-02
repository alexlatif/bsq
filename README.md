# bsq
A maximum square problem for finding largest area of a two dimensional map free of obstacle characters.
See bsq_subject.pdf for project information.

## Implementation

Implemented with recursive backtracking and dynamic programing in C. Allowed functions include open, close, read, write, malloc, free.

## Use

To use the program, first clone the repository. In the directory into which the repo was cloned, run the executable bsq with a map from the test_maps directory as in thefollowing command:
```
./bsq test_maps/500_500.txt
```
![alt text](https://github.com/robertnowell/bsq/blob/master/misc/Screen%20Shot%202017-01-19%20at%2012.44.21%20PM.png "Usage")

### Creating New Maps

There is a perl script in the test_maps directory which enables the creation of new test maps. With perl installed, the script can be used in the following way:
```
./generator.pl map_rows map_columns density > new_map.txt
```
The first argument is an integer for the desired number of rows in the new map, the second argument is for columns, and the third specifies the density of obstacles in the map. About 4 is a nice density.


## Authors

* **Alessandro Latif** (https://github.com/alexlatif)
* **Bexultan A. Myrzatayev** (https://github.com/bexuma)

## Acknowledgments

* This project was completed at School 42, Fremont
