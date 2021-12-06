
#include<stdio.h>
#include<stdlib.h>
#define MAX_ALUMNOS 50
#define N 20


/*
-Programa  que les pida un numero de alumnos de una materia
-Despues que pida las calficaciones de cada uno de los alumnos (solo una por alumno)
-Los almacene en un arreglo y despues de el promedio de las calificaciones y lo muestre
*/


void LeeCalificaciones(int alumnos,float calif[MAX_ALUMNOS]);
float promedio(float *CalPromedio, int estudiantes);



int main()
{
int NumAlumnos;

float calificaciones[MAX_ALUMNOS];
float promedioAlumnos;







/*
if (cerrado==EOF)
{
    printf("El archivo no cerro bien");
}
*/

do{
printf("Dime el numero de alumnos: \n");
scanf("%d",&NumAlumnos);


if(NumAlumnos>MAX_ALUMNOS)

printf("\n El numero maximo es 50 \n");
printf("\n");

}while(NumAlumnos>MAX_ALUMNOS);


LeeCalificaciones(NumAlumnos,calificaciones);
promedio(calificaciones,NumAlumnos);

printf("\n El promedio del grupo es: %.2f",promedioAlumnos);


return 0;




}









void LeeCalificaciones(int alumnos,float calif[MAX_ALUMNOS])    //  float calif[MAX_ALUMNOS] = float *calif
{

    char nombre[N];
    FILE *archivo;
    int cerrado;
    archivo = fopen("ALUMNOS.txt","r"); //abriendo archivo
    archivo = fopen("ALUMNOS.txt","w");

    if(archivo==NULL)
    {
        printf("No se pudo crear el archivo: ");
    }



    int i;
    for(i=0;i<alumnos;i++)    //i=i+1
    {
        printf("Dime el nombre del Alumno %d: ",i+1);
        scanf("%s",nombre);
       printf("Calificacion: ");
       scanf("%f",&calif[i]);
       printf("\n");
        fprintf(archivo,"alumno:%s  ",nombre);
        fprintf(archivo,"calificacion: %f",calif[i]);
        fprintf(archivo,"\n");


    }

cerrado = fclose(archivo);

if(cerrado==EOF)
{
    printf("No se cerro bien el archivo");
}

}




float promedio(float *CalPromedio, int estudiantes)     //float *CalPromedio = CalPromedio[MAX_ALUMNOS]
{
    int i;
    int suma=0;
    float promedio;

    FILE *archivo;
    int cerrado;
    archivo = fopen("ALUMNOS.txt","r"); //abriendo archivo
    archivo = fopen("ALUMNOS.txt","a");

    for(i=0;i<estudiantes;i++)
    {

        suma=suma+CalPromedio[i];
    }

        promedio=suma/estudiantes;


        printf("\n El promedio es %.2f ",promedio);

        fprintf(archivo,"\n El promedio del grupo es %.2f",promedio);

    cerrado = fclose(archivo);


       return promedio;
}

