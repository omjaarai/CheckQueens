////////////////////////////////////////////////////////////////////////////////
// Main File:        check_queens.c
// This File:        check_queens.c
// Other Files:      check1.txt, check2.txt, check3.txt
// Semester:         CS 354 SPRING 2019
//           
// Author:           Omjaa Rai
// Email:            orai@wisc.edu
// CS Login:         omjaa
//           
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//           
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//           
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>   
 
char *COMMA = ",";
  
/* COMPLETED:
 * Retrieves from the first line of the input file,
 * the number of rows and columns for the board.
 * 
 * fp: file pointer for input file
 * rows: pointer to number of rows
 * cols: pointer to number of columns
 */
void get_dimensions(FILE *fp, int *rows, int *cols) {  
        char *line = NULL;  
        size_t len = 0;  
        if (getline(&line, &len, fp) == -1) {  
                printf("Error in reading the file\n");  
                exit(1);  
        }  
           
        char *token = NULL; 
        token = strtok(line, C
        OMMA);
        *rows = atoi(token); 
           
        token = strtok(NULL, COMMA); 
        *cols = atoi(token);
}      


/* TODO:
 * Returns 1 if and only if there exists at least one pair
 * of queens that can attack each other.
 * Otherwise returns 0.
 * 
 * board: heap allocated 2D board
 * rows: number of rows
 * cols: number of columns
 */
int check_queens(int **board, int rows, int cols) {  

	 for(int i = 0; i < rows; i++){
		 for(int j = 0; j < cols; j++){
                        if(*(*(board + i) + j)){
                                //checks columns below the current position
                                for(int a = i+1; a < rows; a++){
                                        if(*(*(board + a) + j)==1){
                                                return 1;
                                        }
                                }
                                //checks rows to the right of the current position
                                for(int b = j+1; b < cols; b++){
                                        if(*(*(board + i) + b)==1){
                                                return 1;
                                        }
                                }
                                //checks leading diagonal of current position
                                for(int a = i+1, b = j+1; a < rows &&  b < cols; a++, b++){
                                        if(*(*(board + a) + b)==1){
                                                return 1;
                                        }
                                }
                                //checks non-leading diagonal of current position
                                for(int a = i+1, b = j-1; a < rows && b >= 0; a++, b--){
                                        if(*(*(board + a) + b)==1){
                                                return 1;
                                        }
                                }
                        }
                }
        }

        return 0;
}     


/* PARTIALLY COMPLETED:
 * This program prints true if the input file has any pair
 * of queens that can attack each other, and false otherwise
 * 
 * argc: CLA count
 * argv: CLA value 
 */
int main(int argc, char *argv[]) {        

        //Check if number of command-line arguments is correct.
        if(argc!=2){
		printf("Incorrect number of command arguments\n");
		exit(1);		
				}

        //Open the file and check if it opened successfully.
        FILE *fp = fopen(*(argv + 1), "r");
        if (fp == NULL) {
                printf("Cannot open file for reading\n");
                exit(1);
        }


        //Declare local variables.
        int rows, cols;


        //Call get_dimensions to retrieve the board dimensions.
	get_dimensions(fp,&rows,&cols);

        //Dynamically allocate a 2D array of dimensions retrieved above.
	int **board;
	board=malloc(sizeof(int*)*rows);
        for(int i=0; i<rows;i++)
		board[i]=malloc(sizeof(int)*cols);

        //Read the file line by line.
        //Tokenize each line wrt comma to store the values in your 2D array.
        char *line = NULL;
        size_t len = 0;
        char *token = NULL;
        for (int i = 0; i < rows; i++) {

                if (getline(&line, &len, fp) == -1) {
                        printf("Error while reading the file\n");
                        exit(1);        
                }

                token = strtok(line, COMMA);
                for (int j = 0; j < cols; j++) {
                        // Complete the line of code below
                        //to initialize your 2D array.
                        /* ADD ARRAY ACCESS CODE HERE */*(*(board+i)+j) = atoi(token);
                        token = strtok(NULL, COMMA);    
                }
        }

        // Call the function check_queens and print the appropriate
        //output depending on the function's return value.
       if( check_queens(board, rows, cols)==0)
	       printf("false\n");
       else
	       printf("true\n");
        
        //Free all dynamically allocated memory
	for(int i=0; i<rows;i++){
		free(board[i]);
	}
	free(board);
	board=NULL;

        //Close the file.
        if (fclose(fp) != 0) {
                printf("Error while closing the file\n");
                exit(1);        
        }

        return 0;
}     
