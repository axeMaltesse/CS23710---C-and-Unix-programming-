#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

void print_a_node(competitor_node_ptr comp){
    float total_length = get_total_length(comp);

	printf("%s\t%d \t\t %dft %.1fin \t %dft %.1fin \t %dft %.1fin \t %dft %.1fin \n",
                comp ->name, comp ->competitior_number, 
		
                getFeet(comp->cucamber), getInches(comp->cucamber),
                getFeet(comp->carrot), getInches(comp->carrot),
                getFeet(comp->runner_bean), getInches(comp->runner_bean),
                getFeet(total_length), getInches(total_length));
}

int getFeet(float length){
    return (int)(length) / 12;
}
float getInches(float length){
    return length - ((int) (length)/12)*12;
}

void print_table(competitor_node_ptr tree_top, char* competition_name, char* competition_date)
{
    if(tree_top != NULL) {
	printf("Competition: %s\tDate: %s\n", competition_name,
				competition_date);
	printf("NAME\t Competitor number\t Cucumber\t Carrot\t         Runner Bean\t Total Length\n");
        printf("================================================================================================\n");

	traverse(tree_top, print_a_node);
    }
}

void contact_details(competitor_node_ptr competitor){
    printf("Competitor Name: %s\n"
            "Postal Address: %s\n"
            "Telephone: %s\n\n",
            competitor->name, competitor->adress, competitor->phone_number );
}

void print_all_contact(competitor_node_ptr tree_top, char* competition_name, char* competition_date){
    printf("\nCompetition: %s\tDate: %s\n", competition_name, competition_date);
    printf("Competitor Contact Details\n\n");
    traverse(tree_top, contact_details);
}

/*void print_competitor_nodes(competitor_node_ptr competitor_node_ptr){
    if(competitor_node_ptr -> left != NULL){
        //have to print left side first
        print_competitor_nodes(competitor_node_ptr -> left);
    }
    print_a_node(competitor_node_ptr);
    
    if(competitor_node_ptr->right != NULL){
        //printing right side of the tree
        print_competitor_nodes(competitor_node_ptr->right);
    }
}*/
