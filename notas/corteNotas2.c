#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TITULO "\t*** Listado de promedios ***\n"

/*Declaración de tipos de datos personalizados*/
typedef char tString [50];

typedef struct {
	int nroLibreta;
	tString nombreAlumno;
	int codMateria;
	float nota;
}tRegistroAlumno;

/*Declaración de prototipo*/
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unaLibreta();
void finCorte();

/*Declaración de variables globales*/
tRegistroAlumno alumno, alumnoAnt;

FILE * archAlumno;

int totalAlumnos, contadorMaterias;
float  promedio, acumNotas;
float mayorPromAlumno;
tString mayorPromedioAlumno = "";
/*Función principal*/
int main(){
	inicializacion();
	procesoCorte();
	finalizacion();	
	return 0;
}
/*Implementación de funciones*/
void inicializacion(){
	/*Abre el archivo*/
	archAlumno = fopen ("Notas.dat" , "rb");
	
	if(archAlumno != NULL){
		/*Lee el primer archivo*/
		fread(&alumno, sizeof(tRegistroAlumno), 1, archAlumno);
	}else{
		printf("No existe el archivo\n");
		exit (EXIT_FAILURE);
	}
	/*Guarda el registro anterior*/
	alumnoAnt = alumno;
	/*Inicializacion de cont/acu totales*/
	totalAlumnos = 0;

	promedio = 0.0;
	/*TITULOS*/
	printf("%s", TITULO);
	printf("----------------------------------------\n");
	printf("Numero de libreta \t Nota promedio |\n");	
	printf("----------------------------------------\n");	
	
}

void procesoCorte(){
	while (!feof(archAlumno)){
		principioCorte();
		while(!feof(archAlumno) && alumno.nroLibreta == alumnoAnt.nroLibreta){
		
			unaLibreta();
			fread(&alumno, sizeof(tRegistroAlumno), 1, archAlumno);
		}
		finCorte();
	}
}

void principioCorte(){
	acumNotas = 0.0;
	contadorMaterias = 0;
}

void unaLibreta(){

	contadorMaterias = contadorMaterias + 1;
	acumNotas = acumNotas + alumno.nota;
	if (acumNotas > mayorPromAlumno){
		mayorPromAlumno = acumNotas;
		strcpy(mayorPromedioAlumno , alumno.nombreAlumno);
	}

}
void finCorte(){
	promedio = ((float)acumNotas / contadorMaterias);
	printf("\t %d \t\t   %.2f \n", alumnoAnt.nroLibreta, promedio);
		
	alumnoAnt = alumno;	
	
	totalAlumnos = totalAlumnos + 1;	


}

void finalizacion(){
	printf("----------------------------------------\n");
	printf("Total de alumnos: %d \n", totalAlumnos);
	printf("El alumno con mayor promedio es: %s . Obtuvo: %.2f\n", mayorPromedioAlumno, mayorPromAlumno/3);
	fclose(archAlumno);
}
