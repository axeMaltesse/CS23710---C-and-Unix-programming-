#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

//Function which takes a name of the file
void get_file_name(char* name){
    printf("Enter name of the file \n");
    scanf("%s", name);
}

FILE * open_file(char* file_name){
    FILE * file;
    file = fopen(file_name, "r");
    if (file != NULL){
        return file;
    }else{
        printf("Filed to open your file");
        return NULL;
    }
}


//Function to create a binary tree from the file
competitor_node_ptr get_competitor_table(FILE * file, char* competition_name,
        char* competition_date){
    
    int lines = 1; //This variable is counting the lines in the file
    //pointer to the top of the tree and node which was created
    competitor_node_ptr tree_root;
    competitor_node_ptr temporary_node;
    
    //Name and date of the competition, Only once in file
    // http://stackoverflow.com/questions/20108334/traverse-file-line-by-line-using-fscanf
    //%80 because max line length in file is 80
    	if (fscanf(file, "%80[^\n]\n", competition_name) != 1)
		printf("Problem reading name of competitor");
	if (fscanf(file, "%80[^\n]\n", competition_date) != 1)
		printf("Problem reading date of competitor");
    
    if((tree_root = check_node(file)) != NULL)
        //Check node of the tree, and give the number
        tree_root ->competitior_number = lines;
    else{
        //no record in a file
        printf("No record about competitiors");
        return NULL;
    } 
    //read file until end of file.
    /*
     * f - file
     * e - end
     * o - of
     * f - file
     */
    while (!feof(file)){
        if ((temporary_node = check_node(file)) != NULL){
            //update the pointer to the second line
            lines++;
            temporary_node->competitior_number = lines;
            //adding node to the tree
            addNode(tree_root, temporary_node);
        }
    }
    //return the root of the tree
    return tree_root;
}

// Function to calculate the length in inches
float getLength(float inches, int feets) {
	return inches + (float) feets * NUM_OF_INCHES_IN_FOOT;
}

//Function which checking the node of the tree
competitor_node_ptr check_node(FILE * node){
    //creating temporary pointer to the node
    competitor_node * temporary_node;
    //request memory for this node
    temporary_node = calloc(1, sizeof(competitor_node));
    
    //temporary variables to store the length in feet and inches
    int feetCucumber, feetCarrot, feetBean;
    float inchesCucumber, inchesCarrot, inchesBean;
    
    // read other details from the file

    	if (fscanf(node, "%80[^\n]\n", temporary_node->name) != 1)
            // If the name wasn't read print an error
		printf("Problem reading name of competitor\n"); 
	if (fscanf(node, "%80[^\n]\n", temporary_node->adress) != 1)
		printf("Problem reading address of competitor\n");
	if (fscanf(node, "%80[^\n]\n", temporary_node->phone_number) != 1)
		printf("Problem reading phone number of competitor\n");
	if (fscanf(node, "%d %f\n", &feetCucumber,
			&inchesCucumber) != 2)
		printf("Problem reading length of cucumber\n");
	if (fscanf(node, "%d %f\n", &feetCarrot, &inchesCarrot)
			!= 2)
		printf("Problem reading length of carrot\n");
	if (fscanf(node, "%d %f\n", &feetBean, &inchesBean) != 2)
		printf("Problem reading length of bean\n");

	// Convert feet into inches 
	temporary_node->cucamber = getLength(inchesCucumber,
			feetCucumber);
	temporary_node->carrot = getLength(inchesCarrot,
			feetCarrot);
	temporary_node->runner_bean = getLength(inchesBean,
			feetBean);
	return temporary_node;
}
float get_total_length(competitor_node_ptr c){
    return c -> runner_bean + c -> cucamber + c -> carrot;      
}

//Function which adding a new node to the tree
void addNode(competitor_node_ptr current,competitor_node_ptr new){
   // get the length for new and current node
    float new_length = get_total_length(new);
    float current_length = get_total_length(current);
    
    if (new_length > current_length){
        //checking the roots of the subtree
        if(current -> right == NULL){
            //adding the node
            current -> right = new;
        } else {
            addNode(current -> right, new);
        }
    } else {
        if ( current ->left == NULL){
            current->left = new;
        }else{
            addNode(current -> left, new);
        }
    }
}
