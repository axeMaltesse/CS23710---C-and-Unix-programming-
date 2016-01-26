#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

/*@param comp - pointer to tree node
 * @param pointer - pointer to function
 */

void traverse(competitor_node_ptr comp,void(* pointer)(competitor_node_ptr)){
    //now the same fuction as in part one with printing nodes
    if (comp -> left !=NULL){
        traverse(comp ->left, pointer);
    }
    pointer(comp);
    
    if(comp ->right != NULL){
        traverse(comp->right, pointer);
    }
}
