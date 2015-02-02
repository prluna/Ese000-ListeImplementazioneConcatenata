#include <stdio.h>
#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) 
{
    LLElement * nuovo; 
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    if(nuovo != NULL) 
    {
        nuovo->key = key;
        nuovo->next = first;
        first = nuovo;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) 
{
   LLElement *nuovo;
   LLElement **temp;
   nuovo = (LLElement*)malloc(sizeof(LLElement));
   if(nuovo != NULL)
   {
       temp = &first;
       while(*temp != NULL)
           temp = &((*temp)->next);
       nuovo->key = key;
       nuovo->next = NULL;
       *temp = nuovo;
   }
    return first;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) 
{
    LLElement *nuovo;
    LLElement **temp;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    int i;
    if(nuovo != NULL)
    {
        temp = &first;
        for(i=0; i<position; i++)
            temp = &((*temp)->next);
        nuovo->key=key;
        nuovo->next=*temp;
        *temp= nuovo;        
    }   
    return first;
   }

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) 
{
    int i=0;
    while(first != NULL)
    {
        first=first->next;
        i++;
    }    
    return i;
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) 
{
    int i;
    for(i=0;i<position;i++)
    {
        first=first->next;
    }
    return first->key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) 
{
    int r = -1;
    int i;
    for(i=0; i<startPosition; i++) 
    {
        first = first->next;
    }
    while(r==-1 && first != NULL ) 
    {
        if(first->key == key)
            r = i;
        i++;
        first = first->next;
    }
    return r;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) 
{
    LLElement *rimuovere;
    if(first != NULL)
    {
        rimuovere = first;
        free(rimuovere);
        first = first->next;
    }
     return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) 
{
    LLElement **rimuovere;
    if(first != NULL)
    {
        rimuovere = &first;
        while((*rimuovere)->next != NULL)
            rimuovere= &((*rimuovere)->next);
        free(*rimuovere);
        *rimuovere=NULL;
    }
return first;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) 
{
    int i;
    LLElement ** temp;
    LLElement * rimuovere;
    temp = &first;
    for(i=0; i<position; i++)
        temp = &((*temp)->next);
    rimuovere = *temp;
    if((*temp)->next != NULL) 
        *temp = (*temp)->next;
    free(rimuovere);
    
    return first;
}

/* Empties the list */
LLElement * LLEmptyList(LLElement *first) 
{
    LLElement *rimuovere;
    while(first != NULL) 
    {
        rimuovere = first;
        first = first->next;
        free(rimuovere);
    }
    return NULL;
}