Eduardo Hales Jimenez 201030003-K

Tarea 0.2 LP:

La tarea consiste en implementar un programa que sea capaz de cargar, a partir de un archivo input.txt, los datos de un Curso, con su lista de Alumnos y sus respectivas Notas.

-- Supuestos -- 

+ Puede haber un curso vacio, o un alumno sin notas. Por lo tanto, para crear estos, se necesita solo el nombre del curso o el nombre y apellido del alumno. Los otros parametros se inicializan en NULL o 0 segun corresponda.

+ Las inserciones de nodos se hacen al final de la listas.

+ Para la funcion "course_load_file", se uso un flag para poder separar las caracteristicas de un Curso y de un Alumno. No se debe alterar el orden de los if (3), ya que cambia el funcionamiento de la funcion.

+ Para la funcion "course_clean", se limpio desde adentro hacia afuera (notas->alumnos->cursos) los nodos correspondiente a las listas. Tambien se tuvo cuidado en limpiar la memoria pedida con "strdup" para los nombres.

+ Para la implementacion de la funcion "course_top_students":
	* Se copiaron todas las listas de estudiantes (para no modificar las originales).
	* Se ordenaron de mayor a menor (segun promedio usando bubblesort).
	* Se dejaron los nodos acordes al parametro "top". El resto se libera.
	* Se juntarons las listas.
	* Se volvio a ordenar de mayor a menor.

-- Compilacion y Ejecucion --

+ Para compilar, se debe ejecutar el comando "make" en el directorio del programa. Este genera el ejecutable "main", que puede ser ejecutado con el comando "./main".

+ El archivo de entrada DEBE tener el nombre "input.txt", de lo contrario, no cargara los datos.

