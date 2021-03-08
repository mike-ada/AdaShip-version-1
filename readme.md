### Overall Program - Epic Style Task Breakdown

#### 1. External Config File 

Read and parse a specified plain text config file (adaship_config.ini), the file is structure in the format (parsing process should remove and trim an unwanted whitespace automatically to minimise later issues):

> Board: 10x10
> Boat: Carrier, 5
> Boat: Battleship, 4
> boat: Destroyer, 3
> Boat: Submarine, 3
> Boat: Patrol Boat, 2
> Boat: Submarine, 3

Read each line and extract the following data:

- Width of the board.
- Height of the board.
- Each boat (boat name and length).



#### 2. Board 

Each 'player' will need two boards; boards will need to provide and support:

- An effective 2D grid of x by y 'tiles'.
- A method to initialise the board based on a dynamic size being provided during run-time; details will be extracted from the external config file.
- A method to update and access each of the board's tiles.
- A method to translate a coordinate reference (e.g., A1, A2, B4, ..) to a suitable column and row index (e.g., A = 1, AA = 27) and vice-versa.
- A method to translate a 2D index (x, y) in to 1D index and vice-versa.
- A method to render any board; including adding coordinate references to columns (A, B, C..) and rows (1, 2, 3..).
- A method to specify whether a tile is: available or occupied.
- A method to auto (randomly) select any single 'available' tile. 





### Notes on development setup and structure

#### Separating header and Implementation Files

C++ classes and function prototypes can be split into two files; header files (example.h) used to declare classes and functions; for example (in addition, optional parameters or default values should also be specified in the header):

```c++
 int sum (int x, int y = 10);
```

The definition and implementation of classes and functions should be written into the associated sources file (example.cpp); for example:

```c++
int sum (int x, int y) { 
	return (x + y); 
}
```

Adopting this type of separation can help optimise and potentially reduce the need and time (especially in larger projects) to recompile unchanged files.



##### Avoiding redefinition issues

Sometimes header file can end up being included multiple times potentially causing or creating redefinitions errors – to avoid this us a pragma directive

```c++
#pragma once

int sum (int x, int y);
```

The directive should be added to the top of each header file; essentially, it’s a message to the compiler telling it to ‘ignore the following if it has already been defined’.

