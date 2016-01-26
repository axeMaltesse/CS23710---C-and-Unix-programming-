/* 
 * File:   main.c
 * Author: luw19
 *
 * Created on December 1, 2015, 5:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"


/*
 * 
 */
int main(int argc, char** argv) {
    
    char competition_name[MAX_LINE_LENGTH]; //name of the competition
    char competition_date[MAX_LINE_LENGTH]; //date of the competition
    
    competitor_node_ptr tree_top; //pointer to the top of the tree

	//reading the name of the file from the console
	char file_name[MAX_LINE_LENGTH];
        (void)get_file_name(file_name);

	FILE * file;
        
        file = open_file(file_name);
        
        if (file == NULL)
            return(EXIT_FAILURE);

	tree_top = get_competitor_table(file, competition_name, competition_date);
        
        fclose(file);
        
        print_table(tree_top, competition_name, competition_date);
        print_all_contact(tree_top, competition_name, competition_date);
        
        return (EXIT_SUCCESS);
}

    

    

