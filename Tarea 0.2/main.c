#include <stdio.h>
#include <stdlib.h>

#include "course.h"
#include "list.h"


int main()
{
	struct course_list myCourses;
	course_load_file("input.txt", &myCourses);
	printCourses(&myCourses);

	int avg1;
	struct student student1 = myCourses.first->course.students.first->student;
	avg1 = course_student_waverage(&student1);
	printf("El promedio de %s %s es: %d\n", student1.first_name, student1.last_name, avg1);

	course_clean(&myCourses);
	
	return 0;
}