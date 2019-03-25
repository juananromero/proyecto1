/* Ejemplo uso de la fecha y la hora del sistema.
 (c) Juan Antonio Romero. aromero@uco.es
 Depto. de Informatica y Analisis Numerico */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

char *mes_cadena(int n);

int main(void)
{
struct timeval fecha, FechaInicio, FechaFin;
struct tm *f;
char c='s';
long segundos, microsegundos;

gettimeofday(&FechaInicio,NULL); /*Registro la hora de comienzo del programa*/

while(c=='s' || c=='S')
     {
     printf("FECHA Y HORA DEL SISTEMA\n");
     printf("========================\n");
     gettimeofday(&fecha,NULL);
     printf("La fecha del sistema es: %s \n\n", ctime(&fecha.tv_sec));
     printf("Segundos desde 00:00:00  UTC,  January  1,  1970 = %ld \n", 
             fecha.tv_sec);
     printf("microsegundos = %ld \n", fecha.tv_usec);
     /*printf("timezone = %d \n", fecha.timezone);
       printf("dstflag = %d \n\n", fecha.dstflag); */
     f=localtime(&fecha.tv_sec);
     printf("Son las %d horas %d minutos %d segundos, \n", (*f).tm_hour, (*f).tm_min, (*f).tm_sec);
     printf("del dia %d de %s de %d \n \n", (*f).tm_mday, mes_cadena((*f).tm_mon+1), (*f).tm_year+1900);
     printf(" ¿Quiere ver de nuevo la fecha y la hora? \[s]");
     fflush(stdin);
     c=getchar();
     }
     
gettimeofday(&FechaFin,NULL); /*Registro la hora de finalizacion del programa*/

if(FechaInicio.tv_usec > FechaFin.tv_usec) 
   {
    segundos=FechaFin.tv_sec-FechaInicio.tv_sec-1;
    microsegundos=1000000-FechaInicio.tv_usec+FechaFin.tv_usec;
    }
else
    {
    segundos=FechaFin.tv_sec-FechaInicio.tv_sec;
    microsegundos=FechaFin.tv_usec-FechaInicio.tv_usec;    
    }    

printf("\n ###ATENCION:Ha estado utilizando el programa %ld segundos y \
        %ld microsegundos", segundos, microsegundos);
                        
printf("\n\n");     
return(0);
}

char *mes_cadena(int n)
{
switch (n)
  {
  case 1:return("Enero");
  case 2:return("Febrero");
  case 3:return("Marzo");
  case 4:return("Abril");
  case 5:return("Mayo");
  case 6:return("Junio");
  case 7:return("Julio");
  case 8:return("Agosto");
  case 9:return("Septiembre");
  case 10:return("Octubre");
  case 11:return("Noviembre");
  case 12:return("Diciembre");
  }
}
