// File: DiasVividos.cpp
// Description : Programa que contea cuantos años, meses y dias has vivido
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int main ()
{
	//Variables para el calculo de la estadistica final
	float total_users = 0, mayor_edad_user = 0;
	
	/*
	* Obtenemos la fecha del sistema
	*/	
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int dia_current = aTime->tm_mday;
	int mes_current = aTime->tm_mon + 1; 
	int anio_current = aTime->tm_year + 1900; 

	// Variable que fuarda la opcion para determinar si seguimos o no, ejecutando el programa
	char opc;
	do
	{
		
		//Borro la pantalla
		system("cls");
		
		/*
		* Muestro la fecha actual por pantalla
		*/
		cout << "*****************************************************************************************" << endl;
		cout << "La fecha actual es: " << dia_current << "/" << mes_current << "/" << anio_current << endl;
		cout << "*****************************************************************************************" << endl;
		
		char nombre [30];
		char apellido [50];
		
		int dia_user, mes_user, anio_user;		
		bool error = false;
		
		/*
		* Pedimos los datos necesarios
		*/
				
		cout << "Introduzca su nombre             : ";
		cin >> nombre;
		
		cout << "Introduzca su apellido           : ";
		cin >> apellido;
				
		cout << "Introduzca su dia de nacimiento  : ";
		cin >> dia_user;
		
		cout << "Introduzca su mes de nacimiento  : ";
		cin >> mes_user; 

		cout << "Introduzca su anio de nacimiento : ";
		cin >> anio_user;
		
		/*
		* Comprobamos si los datos introducidos son correctos
		*/
				
		//Comprobamos el año
		if(anio_user > anio_current)
		{
			error = true;
		}
		else if(anio_user == anio_current)
		{
			if(mes_user > mes_current)
			{
				error = true;
			}
			else if(mes_user == mes_current)
			{
				if(dia_user > dia_user)
				{
					error = true;
				}
			}
		}	
		
		//Comprobamos el mes
		if(mes_user <= 0 || mes_user > 12)
		{
			error = true;
		}
		
		//Comprobamos el dia
		//En caso de que tenga 31 dias
		if(dia_user > 31)
		{
			error = true;
		} 
		else if(dia_user == 31)
		{
			switch (mes_user)
			{
				case 2:
					error = true;
					break;
					
				case 4:
					error = true;
					break;	
					
				case 6:
					error = true;
					break;
						
				case 7:
					error = true;
					break;
					
				case 9:
					error = true;
					break;
					
				case 11:
					error = true;
					break;
					
			
			}
			
			
		}
		//En caso de que el mes elegido sea 2
		else if(mes_user == 2)
		{
			if((anio_user % 4 == 0 && anio_user % 100 != 0) || anio_user % 400 == 0)
			{
				if(dia_user > 29)
				{
					error = true;
				}
			
			}
			else 
			{
				if(dia_user > 28)
				{	
					error = true;
				}
			}
			
		}
		
		
		if(error == true)
		{
			cout << "Ha habido un error con tu fecha: " << dia_user << "/" << mes_user << "/" << anio_user << endl;
			cout << "La fecha actual es: " << dia_current << "/" << mes_current << "/" << anio_current << endl;
		}		
		/*
		* Realizamos el proceso del conteo de dias
		*/
		else
		{
			
			int anios_actuales = anio_current - anio_user;
			int meses_actuales = mes_current - mes_user;
			int dias_actuales = dia_current - dia_user;
			
			if(mes_user > mes_current) // La resta de meses no se puede hacer
			{
				anios_actuales--;
				meses_actuales = 12 - meses_actuales;
				if(dia_user > dia_current)
				{
					dias_actuales = 30 - abs(dias_actuales); //Establecemos que por defecto todos los meses tienen 30 dias
				}
			}
			else if(mes_user == mes_current) //Comprobamos los dias
			{
				if(dia_user > dia_current)
				{
					anios_actuales--;
					meses_actuales = 12 - meses_actuales;
					dias_actuales = 30 - abs(dias_actuales); //Establecemos que por defecto todos los meses tienen 30 dias
				}
				
			} else if(dia_user > dia_current)
			{
				dias_actuales = 30 - abs(dias_actuales); //Establecemos que por defecto todos los meses tienen 30 dias
			}
			
			
			cout << endl;
			cout << " ********* FICHA DEL HABITANTE ***********" << endl;
			cout << " NOMBRE              : " << nombre << endl;
			cout << " APELLIDO            : " << apellido << endl;
			cout << " EDAD                : " << anios_actuales << " anios, " << meses_actuales << " meses y " << dias_actuales << " dias." << endl;
			cout << " FECHA DE NACIMIENTO : " << dia_user << "/" << mes_user << "/" << anio_user << endl;
			cout << " *****************************************" << endl << endl;			
			
			
			//Contabilizamos los usuarios mayores de edad
			if(anios_actuales >= 18)
			{
				mayor_edad_user++;
			}
			
			total_users++;			
			
		}
		
		
		/*
		* Preguntamos si deseamos repetir el proceso
		*/
		bool error_opc = false;
		
		do
		{
			
			if(error_opc)
			{
				cout << "El valor introducido no es valido. Introduzca otro valor." << endl;
			}
			
			cout << "Desea repetir el proceso? (y/n): ";
			cin >> opc;
			
			error_opc = (opc != 'Y' && opc != 'y' && opc != 'n' && opc != 'N');
			
		} while (error_opc == true);
		
		
	} while(opc == 'Y' || opc == 'y');
	
	
	//Borramos la pantalla
	system("cls");
	
	/*
	* Mostramos la estádistica final
	*/
	cout << "Se han introducido " << total_users << " usuarios, de los cuales " << mayor_edad_user << " son mayores de edad (" << ( (mayor_edad_user / total_users) * 100 ) << "%)." << endl;
	
	return 0;
	
}
