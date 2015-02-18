//Author: Hanh Kieu

#ifndef COURSE_H
#define COURSE_H

void read_courses(char ***course, char ***course_num, int **crn, int *size, FILE *fp);
void find_CRN(char **course, char **course_num, int *crn, int *size);
void find_subject(char **course, char **course_num, int *crn, int *size);


#endif