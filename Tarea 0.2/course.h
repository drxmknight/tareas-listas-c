#ifndef COURSE_H
#define COURSE_H

#include <stdlib.h>

struct grade { //variable
    int grade;
    double weight;
};

struct grade_node { //lista enlazada
    struct grade grade;
    struct grade_node *next;
};

struct grade_list { //variable
    struct grade_node *first;
    size_t length;
};

struct student { //variable
    char *first_name;
    char *last_name;
    struct grade_list grades;
};

struct student_node { // lista doblemente enlazada
    struct student student;
    struct student_node *prev;
    struct student_node *next;
};

struct student_list { // variable
    struct student_node *first;
    struct student_node *last;
    size_t length;
};

struct course { //variable
    char *name;
    struct student_list students;
};

struct course_node { //lista doblemente enlazada
    struct course course;
    struct course_node *prev;
    struct course_node *next;
};

struct course_list { //variable
    struct course_node *first;
    struct course_node *last;
    size_t length;
};

/*
 * This function loads a file given its *filename*
 * and generates a course list. Each course in the list
 * will contain students in that course, as each
 * student will contain each grade that he/she has
 *
 * @filename name of the file to load
 * @courses course_list to fill
 *
 * Returns:
 *  0 upon success, -1 otherwise
 */
int course_load_file(const char *filename, struct course_list* courses);

/*
 * This function generates a list of top students among
 * courses. For this, it will create a top list of
 * at most *top* students for each course, then it
 * merges them and filters the *top* (or less) students.
 * In other words it filters the best of the best.
 *
 * @courses to get the data from
 * @top indicates the maximum number of students to
 *  consider in this top list
 *
 * Returns:
 *  The top *top* list, ordered in descending order
 *  according to the weighted average
 */
struct student_list course_top_students(const struct course_list* courses, unsigned top);

/*
 * It calculates and returns given student's weighted
 * average
 */
int course_student_waverage(const struct student* student);

/*
 * Cleans (frees the heap) of a course list and all its
 * underlying content
 */
void course_clean(struct course_list *course_list);

#endif /* end of include guard: COURSE_H */