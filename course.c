//Author: Hanh Kieu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "course.h"
#include "vector.h"



void read_courses(char ***course, char ***course_num, int **crn, int *size, FILE *fp)
{
  char  line[200], *temp_string;
  int  i ;

  if(fp == NULL)
  {
    printf("(null) not readable.\n");
    exit(1);
  } // if the file cannot be read

  initialize(course, course_num, crn); //malllocs



  for( i = 0; fgets( line, 200, fp) ; )
  {
    if( i == *size )
    {  
      resize(course, course_num, crn, size); // ***FUNCTION NEEDS TO BE WRITTEN AND PARAMETERS DEFINED
    }//if i extends the limit of array


    if(isdigit(line[4]) && isdigit(line[3]) && isdigit(line[2]) && 
      isdigit(line[1]) && isdigit(line[0]))
    {
      temp_string = strtok(line, "\t^");
      (*crn)[i] = atoi(temp_string);

      temp_string = strtok(NULL, "\t^");
      strcpy((*course)[i], temp_string);

      temp_string = strtok(NULL, "\t^");
      strcpy((*course_num)[i], temp_string);

      i++;
    }//if the first 5 are digits then start parsing
  
  }//parses

}//reads courses



void  find_CRN(char **course, char **course_num, int *crn, int *size)
{ 
  int i, k = 0, crn_input; 
  printf("Please enter a CRN: ");
  scanf("%d", &crn_input);

  for(i = 0;  i < (*size) ; i++)
  {  

    if( crn[i] == crn_input)
    {


      printf("%s %s\n", course[i], course_num[i]);
      k++;
      break;

    }//get out of there if you find the crn
  }//finds the crn number , prints the matching parallel arrays then breaks;

  if( k == 0)
  {
    printf("CRN %d not found.\n", crn_input );
  }//print crn not found if it wasnt found

}//finds class based on crn and also displays that class;






void find_subject(char **course, char **course_num, int *crn, int *size)
{

  int i, k = 0;
  char temp_string[5];

  printf("Please enter a subject: ");
  scanf("%s", temp_string);


//printf("%s\n", course[i] );
  for(i = 0; i < (*size) ; i++)
  {
   
    if(strcmp(course[i], temp_string) == 0)
    {

      printf("%d %s %s \n", crn[i], course[i], course_num[i]);
      k++;

    }//if the strings are th same print it
    
  }//find string


   if(k == 0)
      printf("No courses were found for %s.\n", temp_string);
  


}//find_subject