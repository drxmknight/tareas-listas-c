#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initCourseList(struct course_list *myCourse)
{
	myCourse->first = NULL;
	myCourse->last = NULL;
	myCourse->length = 0;
}
void newGrade__node(struct grade_list *mylist, int grade, double weight) 
{
	struct grade_node *newgrade = malloc(sizeof(struct grade_node));
	newgrade->grade = (struct grade){grade, weight};
	newgrade->next = NULL;
	if(mylist->first == NULL) {
		mylist->first = newgrade;
	}
	else {
		struct grade_node *temp = mylist->first;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newgrade;
	}	
	mylist->length++;
}

void newStudent__node(struct student_list *mylist, char *firstame, char *lastname)
{
	struct student_node *newstudent = malloc(sizeof(struct student_node));
	newstudent->next = NULL;
	newstudent->prev = mylist->last;
	newstudent->student = (struct student){strdup(firstame), strdup(lastname), {NULL, 0}};

	if (mylist->last != NULL) {
		mylist->last->next = newstudent;
	}
	else {
		mylist->first = newstudent;
	}
	mylist->last = newstudent;
	mylist->length++;
}

void newCourse__node(struct course_list *mylist, char *name) 
{
	struct course_node *newcourse = malloc(sizeof(struct course_node));
	newcourse->course = (struct course){strdup(name), {NULL, NULL, 0}};
	newcourse->next = NULL;
	newcourse->prev = mylist->last;
	if (mylist->last != NULL) {
		mylist->last->next = newcourse;
	}
	else {
		mylist->first = newcourse;
	}
	mylist->last = newcourse;
	mylist->length++;

	/*
	struct course c;
	c.name = strdup(name);
	memset(&c.students, 0, sizeof(struct course));
	newcourse->course = c;
	*/

	/*
	struct course c = {strdup(name), {NULL, NULL, 0}};
	newcourse->course = c;
	*/
}

void printCourses(const struct course_list *mylist)
{
	struct course_node *courseTemp = mylist->first;
	if (courseTemp == NULL) {
		printf("the course list is empty!\n");
		return;
	}
	while (courseTemp != NULL) {
		printf("%s\n", courseTemp->course.name);
		struct student_node *studentTemp = courseTemp->course.students.first;
		while(studentTemp != NULL) {
			printf("%s %s ", studentTemp->student.first_name, studentTemp->student.last_name);
			struct grade_node *gradeTemp = studentTemp->student.grades.first;
			int i = 1;
			while(gradeTemp != NULL) {
				printf("C%d %d %.1lf%%, ", i++, gradeTemp->grade.grade, gradeTemp->grade.weight);
				gradeTemp = gradeTemp->next;
			}
			studentTemp = studentTemp->next;
			printf("\n");
		}
		courseTemp = courseTemp->next;
		printf("\n");
	}
}




