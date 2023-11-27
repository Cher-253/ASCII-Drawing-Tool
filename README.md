# ASCII Drawing Tool

This project involves creating an ASCII drawing tool in C. The tool operates with a 2D array of a maximum size of 20x20, allowing users to draw points, horizontal lines, and vertical lines. The program initializes the map, prints instructions, and continually prompts users for draw commands until they choose to quit. The program specifies the use of pointer notation for array manipulation and includes functions for initializing the map, printing instructions, printing the map, and drawing lines.

Key Components:

DrawTool.c: Contains functions to initialize the map, print instructions, print the map, and draw lines. Uses pointer notation for array manipulation.

DrawTool.h: Header file with prototypes for functions in DrawTool.c. Includes an include guard and defines for the maximum array size.

Code4.c: The main program that utilizes the functions from DrawTool.c. Parses user input, validates draw commands, and interacts with the drawing functions.

makefile: A makefile template is provided for compiling Code4.c and DrawTool.c.

Testing:
The program has been tested with both valid and invalid draw commands, checking for proper bounds validation.