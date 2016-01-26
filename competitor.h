/* 
 * File:   competitor.h
 * Author: luw19
 *
 * Created on December 1, 2015, 6:01 PM
 */

//#define	COMPETITOR_H

#define MAX_LINE_LENGTH 80
#define MAX_LENGHT_OF_THE_FILE 30
#define NUM_OF_INCHES_IN_FOOT 12
//Structure of the competitor 
    typedef struct competitor_node {
        char name[MAX_LINE_LENGTH];
        char adress[MAX_LINE_LENGTH];
        char phone_number[MAX_LINE_LENGTH];
        int competitior_number;
        float cucamber;
        float carrot;
        float runner_bean;
        struct competitor_node * left;//shorter length
        struct competitor_node * right;//longer length   
    } competitor_node;
    
typedef competitor_node *competitor_node_ptr;
    
void get_file_name();
    
competitor_node_ptr get_competitor_table(FILE * file, char* competition_name,
char * competition_date);

competitor_node_ptr check_node(FILE * node);

float getLength(float inches, int feets);

void addNode(competitor_node_ptr current, competitor_node_ptr new);

//void print_competitor_table(competitor_node_ptr tree_top, char * last_update);

int getFeet(float length);
float getInches(float length);

void print_a_node(competitor_node_ptr comp);

void print_competitor_nodes(competitor_node_ptr competitor_node_ptr);

void print_table(competitor_node_ptr tree_top, char* competition_name,
        char* competition_date);

FILE * open_file(char* competition_name);

float get_total_length(competitor_node_ptr);

void contact_details(competitor_node_ptr competitor);

void print_all_contact(competitor_node_ptr tree_top, char* competition_name, char* competition_date);

