#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "course.h"

void initCourseList(struct course_list *myCourse)
{
	myCourse->first = NULL;
	myCourse->last = NULL;
	myCourse->length = 0;
}


void newGrade_node(struct grade_list *grades, struct grade grade) 
{
	struct grade_node *newgrade = malloc(sizeof(struct grade_node));
	newgrade->grade = grade;
	newgrade->next = NULL;

	if(grades->first == NULL) {
		grades->first = newgrade;
	}
	else {
		struct grade_node *temp = grades->first;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newgrade;
	}	
	grades->length++;
}


void newStudent_node(struct student_list *students, struct student student)
{
	struct student_node *newstudent = malloc(sizeof(struct student_node));
	newstudent->next = NULL;
	newstudent->prev = students->last;
	newstudent->student = student;
	if (students->last != NULL) {
		students->last->next = newstudent;
	}
	else {
		students->first = newstudent;
	}

	students->last = newstudent;
	students->length++;
}


void newCourse_node(struct course_list *courses, struct course course) 
{
	struct course_node *newcourse = malloc(sizeof(struct course_node));
	newcourse->next = NULL;
	newcourse->prev = courses->last;
	newcourse->course = course;

	if (courses->last != NULL) {
		courses->last->next = newcourse;
	}
	else {
		courses->first = newcourse;
	}
	courses->last = newcourse;
	courses->length++;
}


void printCourses(const struct course_list *courses)
{
	struct course_node *courseTemp = courses->first;

	if (courseTemp == NULL) {
		printf("the course list is empty!\n");
		return;
	}

	while (courseTemp != NULL) {
		printf("%s\n", courseTemp->course.name);
		struct student_node *studentTemp = courseTemp->course.students.first;

		while(studentTemp != NULL) {
			int i = 1;
			printf("%s %s ", studentTemp->student.first_name, studentTemp->student.last_name);
			struct grade_node *gradeTemp = studentTemp->student.grades.first;

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


void printStudentList(const struct student_list *students)
{
	struct student_node *studentTemp = students->first;

	while (studentTemp != NULL) {
		printf("%s %s \n", studentTemp->student.first_name, studentTemp->student.last_name);
		studentTemp = studentTemp->next;
	}	
	printf("\n");
}


struct student_list copyStudentList(const struct student_list *students)
{
	struct student_list newStudentList;	
	newStudentList.first = NULL;
	newStudentList.last = NULL;
	newStudentList.length = 0;
	struct student_node *studentTemp = students->first;

	while(studentTemp != NULL) {
		struct grade_node *gradeTemp = studentTemp->student.grades.first;
		struct grade_list newGradeList;
		newGradeList.length = 0;
		newGradeList.first = NULL;

		while(gradeTemp != NULL) {
			newGrade_node(&newGradeList, (struct grade){gradeTemp->grade.grade, gradeTemp->grade.weight});
			gradeTemp = gradeTemp->next;
		}
		newStudent_node(&newStudentList, (struct student){strdup(studentTemp->student.first_name), strdup(studentTemp->student.last_name), newGradeList});
		studentTemp = studentTemp->next;
	}
	
	return newStudentList;
}


void desc_bubbleSort(struct student_list *students)
{
	struct student_node *temp = students->first;	

	if (students->length <= 1) {
		return;
	}

	int i;
	int swapped;
	int n = (int)students->length;

	do {
		swapped = 0;
		temp = students->first;
		for (i = 1; i < n; i++) {
			if (course_student_waverage(&temp->student) < course_student_waverage(&temp->next->student)){
				swapStudent(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		n = n - 1;
	} while (swapped);
}

void swapStudent(struct student_node *s1, struct student_node *s2)
{
	struct student temp = s1->student;
	s1->student = s2->student;
	s2->student = temp;
}


struct student_list mergeList(struct student_list *l1, struct student_list *l2)
{
	if (l1->first == NULL) {
		return *l2;
	}

	l1->last->next = l2->first;
	l1->last = l2->last;

	return *l1;
}