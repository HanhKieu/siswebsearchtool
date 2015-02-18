
//Author: Hanh Kieu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
void initialize(char ***course, char ***course_num, int **crn)
{
 

  int i;

  (*course) = (char**)malloc(sizeof(char*) * 100);
  (*course_num) = (char**)malloc(sizeof(char*) * 100);
  *crn = (int*)malloc(sizeof(int) * 100);
  

  for(i = 0; i < 100; i ++)
  {	
    (*course)[i] = (char*)malloc(sizeof(char) * 4);
    (*course_num)[i] = (char*)malloc(sizeof(char) * 6);
  }//mallocs for rows
  


}//mallocs intializes

void resize(char ***course, char ***course_num, int **crn, int *size)
{
  char **temp_course, **temp_course_num;
  int *temp_crn, i;
 //step 1------ MALLOC WITHOUT LOOP
  temp_course = (char**)malloc(sizeof(char*) * (2 * (*size)) );
  temp_course_num = (char**)malloc(sizeof(char*) * (2 * (*size)) );
  temp_crn = (int*)malloc(sizeof(int) * (2 * (*size)) );
//mallocs for temp arrays
  for(i = 0; i < (2 * (*size)); i ++)
  { 
    temp_course[i] = (char*)malloc(sizeof(char) * 4);
    temp_course_num[i] = (char*)malloc(sizeof(char) * 6);

  }//mallocs the temp arrays
  
//step 2------TRANSFERS ADDRESSED AND THEN EXTENDS MEMORY OF ORIGINAL
  
for( i = 0; i < (*size) ; i++)
  {
      temp_crn[i] = (*crn)[i];
      temp_course_num[i] = (*course_num)[i];
      temp_course[i] = (*course)[i];

  }//transfers addressses of crn,course, course_num to their respective temps
 


/*for(i = *size; i < 2 * *size; i++)
  {
    course_num[i] = (char**)malloc(sizeof(char*) * 4);
    course[i] = (char**)malloc(sizeof(char*) * 6);
    crn[i] = (int*)malloc(sizeof(int));
  } // extension loop
*/



    free(*crn);
    free(*course);
    free(*course_num);




    *crn = temp_crn;
    *course = temp_course;
    *course_num = temp_course_num;

    *size *= 2;

 }//RESIZE UP IN DIS BITCH



void deallocate( char **course, char **course_num, int *crn, int *size)
{

  int i;

  for(i = 0; i < *size; i++)
  {
    free(course[i]);
    free(course_num[i]);  
  } // frees allocated memory in 2nd dimension

  free(course);
  free(course_num);
  free(crn); 

} // function deallocates memory
