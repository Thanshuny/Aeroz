#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pasajeroData.h"
using namespace std;

void registro_del_pasajero();
void registro_de_ventas();
void datos_del_usuario();

int main(){
	
	cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl ;
	cout << endl <<"--------------------------------------------------------------------" << endl << endl;
	cout << "Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
	cout << endl << "(1) Registrar un pasajero." << endl;
	cout << "(2) Registro de ventas realizadas." << endl;
	cout << "(3) Consultar datos de usuarios registrados" << endl;
	
	int dat;
	cin >> dat;
	
	switch(dat){
		
		case 1:
			registro_del_pasajero();
		break;
			
		case 2: 
			registro_de_ventas();
		break;
		
		case 3:
			datos_del_usuario();
		break;
		
	}
	
	cin.ignore();
	cin.get();
	exit(1);
	
	return 0;
}

 void registro_del_pasajero(){		/*Registro del usuario en el sistema*/
 	
	//para comensar el registro selecione 1
	cout << endl << "Desea realizar el registro de un pasajero?" << endl;
	cout << "1) Confimar." << endl;
	cout << "2) No confimar." << endl;
	int confirm;
	cin >> confirm;
	
	if (confirm == 1){
		cout << endl <<"#-Comezando el registro de pasajero-#" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
	}else{
		
	//llamada al menu
	cout << endl <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
	
	if (dat == 1){
		
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl ;
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
		cout << endl << "(1) Registrar un pasajero." << endl;
		cout << "(2) Registro de ventas realizadas." << endl;
		cout << "(3) Consultar datos de usuarios registrados" << endl;
		cin >> menu;
		
			switch(menu){
			
				case 1:
					registro_del_pasajero();
				break;
					
				case 2: 
					registro_de_ventas();
				break;
				
				case 3:
					datos_del_usuario();
				break;
			
			}
		
	}
	
	if (dat == 2){ //buscar como cerrar el programa
		cout << endl << "#-Seccion termindada-#";
		exit(1);
	}	
}
	 	
	
	//cedula del pasajero
	int cedula; 
	cout << endl << "Cedula del pasajero: Cel.";
	cin >> cedula;										//dat_01.getPasajeroDataCel();
	pasajero_data dat_01 (cedula);
	
	//pasaporte del pasajero
	long long int pasaporte;
	cout << endl << "Pasaporte del pasajero: ";
	cin >> pasaporte;
	//pasajero_data dat_02 (pasaporte); 
	
	
	//Nombres
	string user_name_first;					
	cout << endl << "1er Nombre del pasajero: " << user_name_first;
	cin >> user_name_first;
	
	string user_name_secon;
	cout <<  "2do Nombre del pasajero: " << user_name_secon;
	cin >> user_name_secon;
	
	//Apellidos
	string user_firts_lastname;				
	cout << endl << "1er Apellido del pasajero: " << user_firts_lastname ;
	cin >> user_firts_lastname;
	
	string user_secon_lastname;
	cout << "2do Apellido del pasajero: " << user_secon_lastname ;
	cin >> user_secon_lastname;

	//edad
	int edad; 			
	cout << endl << "Edad del pasajero: ";
	cin >> edad;
	
	//numeros telefonicos
	cout << endl << "Cantidad de numero telefonicos del pasajero\npara registrar. (max 03)" << endl;	
    int val_numeros;
	string numbs[] = {"", "", ""};
	cin >> val_numeros;
	
	
	/*switch (val_numeros){
		
		case 1:
			cout << endl << "1er) Numero del pasajero: " << numbs[0];
			cin >> numbs[0];
		break;
		
		case 2:
			cout << endl << "1er) Numero del pasajero: " << numbs[0];
			cin >> numbs[0];
			cout << "2er) Numero del pasajero: " << numbs[1];
			cin >> numbs[1];
		break; 
		
		case 3:
			cout << endl << "1er) Numero del pasajero: " << numbs[0];
			cin >> numbs[0];
			cout << "2er) Numero del pasajero: " << numbs[1];
			cin >> numbs[1];
			cout << "3er) Numero del pasajero: " << numbs[2];
			cin >> numbs[2];
		break;
		
}*/

	for (int n = 0; n <= val_numeros; n++){
		cout << endl << "("<< n << ") Numero del pasajero: " << numbs[n];
		cin >> numbs[n];
	}
	
	//correo electronico
	string emay;
	cout << endl << "Correo electronico: " << emay;
	cin >> emay;
	
	//ciudad de origen
	string city;
	cout << endl << "Ciudad de provenecia : Cd. " << city;
	cin >> city;
	
	//pais de origen
	string country;
	cout << endl << "Pais de origen: " << country;
	cin >> country;
	
	//fin del registro
	cout << endl << "#-registro finalizado-#" << endl;
	cout << endl <<"--------------------------------------------------------------------" << endl;
	
	
	
	//llamada al menu
	cout << endl <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
	
	if (dat == 1){
		
		cout << endl <<"--------------------------------------------------------------------" << endl << endl;
		cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
		cout << endl << "(1) Registrar un pasajero." << endl;
		cout << "(2) Registro de ventas realizadas." << endl;
		cout << "(3) Consultar datos de usuarios registrados" << endl;
		cin >> menu;
		
			switch(menu){
			
				case 1:
					registro_del_pasajero();
				break;
					
				case 2: 
					registro_de_ventas();
				break;
				
				case 3:
					datos_del_usuario();
				break;
			
			}
				
}

if (dat == 2){
	cout << endl <<"#-Cerrando el programa-#";
	exit(1);
}

/* if (dat == 2){
	cout << endl << "#-Seccion termindada-#";
}*/
	
	//registro de datos en el fichero ser_data.dat
	ofstream data("user_data.txt");
	data << "Datos del pasajero: " << endl << endl;
	data << "Nombres: " << user_name_first << ", " << user_name_secon << endl;
	data << "Apellidos: " << user_firts_lastname << ", " << user_secon_lastname << endl;
	data << "Cedula: " << cedula << endl;
	data << "Pasaporte: " << pasaporte << endl;
	data << "Edad: " << edad << " A�os" << endl;  /*<< edad_2 << edad_3 << edad_4*/
	data << "Cantidad de Numero asignandos: " << val_numeros << endl;
	data << "Numeros del pasajero: " << endl << numbs[0] << endl << numbs[1] << endl << numbs[2] << endl;
	data << "Correo: Cd. " << emay << endl;
	data << "Ciudad: " << city << endl;
	data << "Pais: " << country;
	data.close();
	

}

/*void datos_del_usuario(){
	
	pasajero_data dat_01;
	
	//consulta de datos
	cout << "consultar datos de usuarios" << endl << endl;
	cout << "(1er) Usuario" << endl;
	int val_selec_user;
	cin >> val_selec_user;

	//llamada a los datos del usuario
	switch(val_selec_user){
	
		case 1:
			cout << "Cedula: Cd. " << dat_01.getPasajeroDataCel();			
		break;

	}
	
	//fin de revision de registro
	cout << endl << "#-consulta de registro terminado-#" << endl;
	cout << endl <<"--------------------------------------------------------------------" << endl;
	
	//llamada al menu
	cout <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
	
	if (dat = 1){
	
		cout << endl <<"--------------------------------------------------------------------" << endl << endl;	
		cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
		cout << endl << "(1) Registrar un pasajero." << endl;
		cout << "(2) Registro de ventas realizadas." << endl;
		cout << "(3) Consultar datos de usuarios registrados" << endl;
		cin >> menu;
		
			switch(menu){
			
				case 1:
					registro_del_pasajero();
				break;
					
				case 2: 
					registro_de_ventas();
				break;
				
				case 3:
					datos_del_usuario();
				break;
			
			}
		
	}
	
if (dat == 2){
		cout << endl <<"#-Cerrando el programa-#";
		exit(1);
	}
}
*/

void registro_de_ventas(){
	srand (time(0)); 

	//para comensar el registro selecione 1
	cout << endl << "Desea realizar el registro de ventas?" << endl;
	cout << "1) Confimar." << endl;
	cout << "2) No confimar." << endl;
	int confirm;
	cin >> confirm;
		
	if (confirm == 1){
		cout << endl <<"#-Comezando el registro de ventas-#" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
	}else{
			
	//llamada al menu
	cout << endl <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
		
	if (dat == 1){
			
			cout << endl <<"--------------------------------------------------------------------" << endl << endl;
			cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl ;
			cout << endl <<"--------------------------------------------------------------------" << endl;
			cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
			cout << endl << "(1) Registrar un pasajero." << endl;
			cout << "(2) Registro de ventas realizadas." << endl;
			cout << "(3) Consultar datos de usuarios registrados" << endl;
			cin >> menu;
			
				switch(menu){
				
					case 1:
						registro_del_pasajero();
					break;
						
					case 2: 
						registro_de_ventas();
					break;
					
					case 3:
						datos_del_usuario();
					break;
				
				}
			
		}

	if (dat == 2){
		cout << endl <<"#-Cerrando el programa-#";
		exit(1);
	}
}

	string ciudad_de_origen;
	string pais_de_origen;
	cout << "Origen del viaje: " << endl;
	cout << "Pais: ";
	cin >> ciudad_de_origen;
	
	cout << "Ciudad: Cd. ";
	cin >> pais_de_origen;
	
	
	string pais_de_destino;
	string ciudad_de_destino;
	cout << endl << "Destino del viaje: " << endl;
	cout << "Pais: ";
	cin >> ciudad_de_origen;
	
	cout << "Ciudad: Cd. ";
	cin >> pais_de_origen;
	
	
	int aereo;
	string aereo_1 = "Aerolinea 1";
	string aereo_2 = "Aerolinea 2";
	string aereo_3 = "Aerolinea 3";
	
	cout << endl << "Seleccione el tipo de Aerolinea. " << endl;;
	cout << endl << "(1)" << aereo_1;
	cout << endl << "(2)" << aereo_2;
	cout << endl << "(3)" << aereo_3 << endl;
	cin >> aereo;
	
	switch (aereo){
		
		case 1:
			cout << endl << "\"Primera\" aerolinea selecionda" << endl << endl;
		break;
		
		case 2:
			cout << endl << "\"Segunda\" aerolinea selecionda" << endl << endl; 
		break;
		
		case 3:
			cout << endl << "\"Tercera\" aerolinea selecionda" << endl << endl;
		break;
			
	}
	
	//numero de ticket
	long int tiket_nums = (rand () % 999);
	cout << "Numero de ticket: #00" << tiket_nums << endl;
	
	//localizador del ticket
	char alfb [2][13] = {
	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
	{'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
	};
	
	int row = (rand() % 1);
	int cols = (rand () % 13);
	
	int row_2 = (rand() % 2);
	int cols_2 = (rand () % 10);
	
	int row_3 = (rand() % 1);
	int cols_3 = (rand () % 8);
	
	int row_4 = (rand() % 2);
	int cols_4 = (rand () % 6);
	
	int row_5 = (rand() % 1);
	int cols_5 = (rand () % 4);
	
	int row_6 = (rand() % 1);
	int cols_6 = (rand () % 2);
	
	cout << "Localizador del ticket: " << alfb[row][cols] << alfb[row_2][cols_2] << alfb[row_3][cols_3] << alfb[row_4][cols_4] << alfb[row_5][cols_5] << alfb[row_6][cols_6] << endl << endl;

	//costos de servicio
	int precio_1 = 100;
	int precio_2 = 200;
	int precio_3 = 350;
	cout << "Costo de servicios: " << endl;
	
	switch (aereo){
		
		case 1:
			cout << "Aerorinea: " << "\"" << aereo_1 << "\"" << " --- " << precio_1 << "$ "<< endl << endl;
		break;
		
		case 2:
			cout << "Aerorinea: " << "\"" << aereo_2 << "\"" << " --- " << precio_2 << "$ "<< endl << endl; 
		break;
		
		case 3:
			cout << "Aerorinea: " << "\"" << aereo_3 << "\"" << " --- " << precio_3 << "$ "<< endl << endl;
		break;
			
	}
	
	//revicion si se decea continuar con la compra del ticket
	int confirm_price;
	cout << "Realizar canselacion de gastos?" << endl << endl;
	cout << "(1)Confimar \n(2)Denegar" << endl;
	cin >> confirm_price;
	
	if (confirm_price == 1){
		switch (aereo){
		
		case 1:
			cout << endl << "Gasto total:" << " --- " << precio_1 << "$ "<< endl;
		break;
		
		case 2:
			cout << endl << "Gasto total:" << " --- " << precio_2 << "$ "<< endl ; 
		break;
		
		case 3:
			cout << endl << "Gasto total:" << " --- " << precio_3 << "$ "<< endl;
		break;
			
	}
	
	if (confirm_price == 2){	//canselacio de transacion
		cout << endl << "#-Transacion canselada-#" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
	
	//llamada al menu
	cout <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
	
	if (dat == 1){
	
		cout << endl <<"--------------------------------------------------------------------" << endl << endl;	
		cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
		cout << endl << "(1) Registrar un pasajero." << endl;
		cout << "(2) Registro de ventas realizadas." << endl;
		cout << "(3) Consultar datos de usuarios registrados" << endl;
		cin >> menu;
		
			switch(menu){
			
				case 1:
					registro_del_pasajero();
				break;
					
				case 2: 
					registro_de_ventas();
				break;
				
				case 3:
					datos_del_usuario();
				break;
			
			}
		
	}
	
	if (dat == 2){
			cout << endl <<"#-Cerrando el programa-#";
			exit(1);
		}
	}

}	
	//fin del registro de ventas
	cout << endl << "#-registro de ventas terminado-#" << endl;
	cout << endl <<"--------------------------------------------------------------------" << endl;
	
	//llamada al menu
	cout <<"desea volver al menu?" << endl;
	cout << "(1) Si\n(2) No" << endl;
	int dat;
	int menu;
	cin >> dat;
	
	if (dat == 1){
	
		cout << endl <<"--------------------------------------------------------------------" << endl << endl;	
		cout << "Sistema de registro, consultor y venta de voletos aereos. (Versio 1.0)" << endl;
		cout << endl <<"--------------------------------------------------------------------" << endl;
		cout << endl <<"Inserte el numero correspondiente para seleccionar \nla opcion deceada" << endl;
		cout << endl << "(1) Registrar un pasajero." << endl;
		cout << "(2) Registro de ventas realizadas." << endl;
		cout << "(3) Consultar datos de usuarios registrados" << endl;
		cin >> menu;
		
			switch(menu){
			
				case 1:
					registro_del_pasajero();
				break;
					
				case 2: 
					registro_de_ventas();
				break;
				
				case 3:
					datos_del_usuario();
				break;
			
			}
		
	}
	
if (dat == 2){
		cout << endl <<"#-Cerrando el programa-#";
		exit(1);
	}
}
