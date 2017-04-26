#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "list.h"

#define MAXLINE 256 

int course_load_file(const char *filename, struct course_list* courses)
{
	FILE *courseFile;
	char line[MAXLINE];
	initCourseList(courses);

	if ((courseFile = fopen(filename, "r")) == NULL) {
		printf("Failed to open the file\n");
		return -1;
	}

	int studentFlag = 0;

	while (fgets(line, MAXLINE, courseFile) != NULL) {

		if (strstr(line, "Curso")) {
			fgets(line, MAXLINE, courseFile);
			char *temp = line;
			char *courseName = strsep(&temp, "\n");
			newCourse_node(courses, (struct course){strdup(courseName), {NULL, NULL, 0}});
			studentFlag = 0;
		}

		if (studentFlag) {
			char *temp = &line[1];
			char *firstname = strsep(&temp, " ");
			char *lastname = strsep(&temp, "\"");
			newStudent_node(&courses->last->course.students, (struct student){strdup(firstname), strdup(lastname), {NULL, 0}});
			while (temp != NULL) {
				temp = temp + 4;
				char *fullgrade = strsep(&temp, ",");
				char *grade = strsep(&fullgrade, " ");
				char *percent = strsep(&fullgrade, "%%");
				newGrade_node(&courses->last->course.students.last->student.grades, (struct grade){strtol(grade, NULL, 10), (double)strtol(percent, NULL, 10)/100});
			}
		}

		if (strstr(line, "Alumnos")) {
			studentFlag = 1;
		}
	}

	fclose(courseFile);
	return 0;
}


int course_student_waverage(const struct student* student)
{
	double average = 0;
	struct grade_node *temp = student->grades.first;

	while (temp != NULL) {
		average += (temp->grade.grade)*(temp->grade.weight);
		temp = temp->next;
	}
	return (int)(average + 0.5);
}


/*struct student_list course_top_students(const struct course_list* courses, unsigned top)
{
	struct student_list top_list;
	struct course_node *courseTemp = courses->first;

	while (courseTemp != NULL) {
		struct student_list studentListTemp = copyStudentList(&courses->first->course.students);
		desc_bubbleSort(&studentListTemp);
		struct student_node *studentTemp = studentListTemp.first;

		int it = studentListTemp.length - top;
		struct student_node *lastTemp = studentListTemp.last;
		
		while (it) {
			studentListTemp.last = lastTemp->prev;
			free(lastTemp);
			lastTemp = studentListTemp.last;
			it--;
		}
		courseTemp = courseTemp->next;
	}	

	return top_list;
}
*/

void course_clean(struct course_list *course_list)
{
	struct course_node *courseTemp = course_list->first;

	while (courseTemp != NULL) {

		struct student_node *studentTemp = courseTemp->course.students.first;
		struct student_node *studentHead = studentTemp;

		while (studentTemp != NULL) {

			struct grade_node *gradeTemp = studentTemp->student.grades.first;
			struct grade_node *gradeHead = gradeTemp;

			while (gradeTemp != NULL) {
				gradeHead = gradeTemp->next;
				free(gradeTemp);
				gradeTemp = gradeHead;	
			}

			studentHead = studentTemp->next;
			free(studentTemp->student.first_name);
			free(studentTemp->student.last_name);
			free(studentTemp);
			studentTemp = studentHead;

		}

		course_list->first = courseTemp->next;
		free(courseTemp->course.name);
		free(courseTemp);
		courseTemp = course_list->first;
	}
}