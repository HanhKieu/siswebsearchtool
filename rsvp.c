//Author: Hanh Kieu
#include <stdio.h>
#include "course.h"
#include "vector.h"

int get_choice(char **course, char **course_num, int *crn, int *size);
void display_info(char **course, char **course_num, int *crn, int *size);

int main(int argc, char *argv[])
{
  FILE *fp;

  int *crn, size = 100;
  char **course, **course_num;

  fp = fopen(argv[1] , "r");

  read_courses( &course, &course_num, &crn, &size, fp);

  //for( i = 0; i < size ; i++)
  //printf("%s  ", course[i]);
  display_info(course, course_num, crn, &size);
  deallocate(course, course_num, crn , &size);
  
  fclose(fp);

  return 0;
} // main function


void display_info(char **course, char **course_num, int *crn, int *size)
{
  int number = get_choice(course, course_num, crn, size);

   switch(number)
  {


    case 0: break;

    case 1: find_CRN(course, course_num, crn, size);display_info(course, course_num, crn, size); break;

    case 2: find_subject(course, course_num, crn, size); display_info(course, course_num, crn, size); break;
  }//disploys choice
}//display info


int get_choice(char **course, char **course_num, int *crn, int *size)
{
  int user_choice;

  printf("\n"); 
  printf("RSVP Menu\n");
  printf("0. Done.\n");
  printf("1. Find by CRN.\n");
  printf("2. Find by subject.\n");
  printf("Your choice (0 - 2): ");
  scanf("%d", &user_choice);
  
  if( user_choice > 2 || user_choice < 0)
  {
    printf("Your choice is outside the acceptable range.  Please try again.\n");
    display_info(course, course_num, crn, size);
  }//if its not valid

  return user_choice;

   // if the user enters a number that it out of acceptable range (0-2)
  //return user_choice;

} //function gets how the user wants to search by course, returns it to display which returns to main.


