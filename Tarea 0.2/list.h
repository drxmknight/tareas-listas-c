#ifndef LIST_H
#define LIST_H

#include "course.h"

void initCourseList(struct course_list *myCourse);
void newGrade__node(struct grade_list *mylist, int grade, double weight);
void newStudent__node(struct student_list *mylist, char *firstame, char *lastname);
void newCourse__node(struct course_list *mylist, char *name);

void printCourses(const struct course_list *mylist);


#endif