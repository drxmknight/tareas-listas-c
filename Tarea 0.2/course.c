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
			char *temp = strdup(line);
			char *courseName = strsep(&temp, "\n");
			newCourse__node(courses, courseName);
			studentFlag = 0;
		}

		if (studentFlag) {
			char *temp = strdup(&line[1]);
			char *firstname = strsep(&temp, " ");
			char *lastname = strsep(&temp, "\"");
			newStudent__node(&courses->last->course.students, firstname, lastname);

			while (temp != NULL) {
				temp = temp + 4;
				char *fullgrade = strsep(&temp, ",");
				char *grade = strsep(&fullgrade, " ");
				char *percent = strsep(&fullgrade, "%%");
				newGrade__node(&courses->last->course.students.last->student.grades, strtol(grade, NULL, 10), (double)strtol(percent, NULL, 10)/100);
			}
		}

		if (strstr(line, "Alumnos")) {
			studentFlag = 1;
		}
	}

	return 0;
}
