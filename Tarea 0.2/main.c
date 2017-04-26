#include <stdio.h>
#include <stdlib.h>

#include "course.h"
#include "list.h"


int main()
{
	struct course_list myCourses;

	if (!course_load_file("input.txt", &myCourses)) {
		printCourses(&myCourses);		
		
		struct student_node *student1 = myCourses.first->course.students.first;
		struct student_node *student2 = myCourses.first->course.students.first->next;

		int avg1 = course_student_waverage(&student1->student);
		printf("El promedio de %s %s es: %d\n", student1->student.first_name, student1->student.last_name, avg1);
		
		int avg2 = course_student_waverage(&student2->student);
		printf("El promedio de %s %s es: %d\n", student2->student.first_name, student2->student.last_name, avg2);
		
		printCourses(&myCourses);

		//struct student_list top_list = course_top_students(&myCourses, 1);
		//printStudentList(&top_list);

		course_clean(&myCourses);
	}
	
	return 0;
}