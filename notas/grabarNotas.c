#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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
void grabar();
void finalizacion();

void registrarDatos();

/*Declaración de variables globales*/
tRegistroAlumno alumno;
FILE * archAlumno;

/*Función principal*/
int main(){
	 inicializacion();
	 grabar();
	 finalizacion();
	return 0;
}

/*Implementacion de funciones*/

void inicializacion(){
	
	archAlumno = fopen ("Notas.dat", "wb");
}

void grabar(){
	char respuesta, respuesta2;

	printf("Desea registrar un alumno? S/N: ");
	fflush(stdin);
	scanf("%c", &respuesta);
	while (respuesta != 'n' ){
		registrarDatos();		
		fwrite(&alumno, sizeof(tRegistroAlumno), 1, archAlumno);
		printf("Nota del alumno registrada!\n");
		Sleep(2000);
		
		printf("Desea ingresar otra nota con el mismo numero de libreta? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta2);
	
		while (respuesta2 != 'n' ){
			
			printf ("1. Algoritmo y Estructura de Datos II \n 2.Logica y Matematica Computacional \n 3. Sistemas y Organizaciones\n");
			printf("Seleccione un codigo de materia: ");
			scanf("%d", &alumno.codMateria);
			printf("Nota obtenida: ");
			scanf("%f", &alumno.nota);	
			
			printf("Nota del alumno registrada!\n");
			Sleep(2000);			
	
			printf("Desea ingresar otra nota con el mismo numero de libreta? S/N: ");
			fflush(stdin);
			scanf("%c", &respuesta2);	
		
			fwrite(&alumno, sizeof(tRegistroAlumno), 1, archAlumno);
		}
		
		printf("\nEl registro del alumno fue exitoso!\n");
		Sleep(2000);
		system("pause");
		system("cls");
		printf("Desea registrar un alumno? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta);

	}

}


void registrarDatos(){

		printf("*********************************\n");
		printf("Ingrese los siguientes datos por alumno: \n");
		printf("Numero de libreta: ");
		scanf("%d", &alumno.nroLibreta);
		printf("Nombre y apellido del alumno: ");
		fflush(stdin);
		gets(alumno.nombreAlumno);
		printf ("1. Algoritmo y Estructura de Datos II \n 2.Logica y Matematica Computacional \n 3. Sistemas y Organizaciones\n");
		printf("Seleccione un codigo de materia: ");
		scanf("%d", &alumno.codMateria);
		printf("Nota obtenida: ");
		scanf("%f", &alumno.nota);	
	
}

void finalizacion(){
	fclose(archAlumno);
}

