#ifndef LIST_H
#define LIST_H

#include "course.h"

void initCourseList(struct course_list *myCourse);
void newGrade_node(struct grade_list *mylist, struct grade grade);
void newStudent_node(struct student_list *mylist, struct student student);
void newCourse_node(struct course_list *mylist, struct course course);
void printCourses(const struct course_list *mylist);

struct student_list copyStudentList(const struct student_list *students);
void printStudentList(const struct student_list *students);
void descendingBubbleSort(struct student_list *students);
void swapStudent(struct student_node *s1, struct student_node *s2);
void mergeStudentList(struct student_list *l1, struct student_list *l2);

#endif