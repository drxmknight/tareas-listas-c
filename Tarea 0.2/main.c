#include <stdio.h>
#include <stdlib.h>

#include "course.h"
#include "list.h"


int main()
{
	
	struct course_list myCourses;
	course_load_file("input.txt", &myCourses);
	printCourses(&myCourses);

	return 0;
}