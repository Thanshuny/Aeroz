#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int setRegistreUser();
int setRegistreSelf();
int getRegistreData();
int getMenu();

void confirmSection(int c);
void endingSections(int n); 

int main() {
	
	cout << "---Sofware de registro de pasajeros (Version: 1.0)---" << endl << endl;
	
	cout << "Para seleccionar una opcion, insete el numero \ncorrespondiente a la opcion deseada." << endl << endl;
	
	
	cout << "(1) Registro de pasajero" << endl;
	cout << "(2) Registrar la venta de un boleto aereo" << endl;
	cout << "(3) Ver usuarios registrados y ventas registradas"<< endl;
	cout << "(4) Finalizar el programa"<< endl;
	
	int sel;
	cin >> sel;
	
	switch (sel){
		case 1:
			confirmSection(sel);
			setRegistreUser();
			endingSections(sel);
		break;
		
		case 2:
			confirmSection(sel); 
			setRegistreSelf();
			endingSections(sel);
		break;
		
		case 3:
			confirmSection(sel);
			getRegistreData();
			endingSections(sel);
		break;
		
		case 4:
			confirmSection(sel);
			exit(1);
		break;
		
		default:
		 printf ("ERROR 001 - Character unklond");
		 return 0;		
	}
	
	return 0;
}

//llamado a menu
int getMenu(){
	cout << endl << "desea volver al menu? \n(1)Si \n(2)No" << endl;
		
		int confirm;
		cin >> confirm;
		
		try{
			if (confirm == 1){
				cout << endl;
				main();
			}else if (confirm == 2){
				cout << endl << "---Programa finalizando---";
				exit(1);
			}
			
			if (confirm != 1 || confirm != 2){
				throw 0;
			}
			
		}catch(int x){
			printf ("ERROR 001 - Character unklond");
			exit(1);	
	}
}

//confirmacion de secciones
void confirmSection(int c){
	
	try{
		if (c >= 1){
			cout << endl << "Confirmar opcion? \n(1)Si \n(2)No" << endl;
			int sel;
			cin >> sel;
			
			if (sel == 2){
			//llamado a getMenu
				getMenu();
			}
			
			if (sel >= 3){
				throw 0;
			}
		} 		
		
	}catch(int x){
		printf ("ERROR 001 - Character unklond");
		exit(1); 
	}
}

//finalizadon se secciones 
void endingSections(int n){
	
	if (n == 1){
		
		cout << endl << "---Registro de datos concluido!---" << endl;
		getMenu();	
		
	}else if (n == 2){
			
		cout << endl << "---Registro de venta de boleto aereo concluido!---" << endl;
		getMenu();	
		
	}else if (n == 3){
		
		cout << endl << "---Revision de datos de usuario concluido!---" << endl;
		getMenu();
		
	}else{
		printf ("ERROR 002 - Ending section fail");
		exit(-1); 
	}
}

//registro de pasajero en el sistema
int setRegistreUser(){
	
	//Nombres
	string name1, name2;
	cout << endl << "--Datos del pasajero-- \nPrimer nombre: ";
	cin >> name1;
	cout << "Segundo nombre: ";
	cin >> name2;
	
	//Apellidos
	string lastName1, lastName2;
	cout << "Primer apellido: ";
	cin >> lastName1;
	cout << "Segundo apellido: ";
	cin >> lastName2;
	
	//cedula y pasaporte
	long int ced, pass;
	cout << "Cedula de indentidad: Nro. ";
	cin >> ced;
	cout << "Pasaporte: Nro. ";
	cin >> pass;
	
	//edad
	int age;
	cout << "Edad del pasajero: ";
	cin >> age;

	//numero telefonico
	cout << endl << "Cuantos numeros a registrar? (max: 03)" << endl;
	int numsSize;
	string nums[3] = {"","",""};
	cin >> numsSize;
	cout << endl; 	//salto de linea
	
	switch (numsSize){
		case 1:
			cout << "Ingrese numero a registrar: ";
			cin >> nums[0];
		break;
		
		case 2:
			cout << "(1er) Ingrese numero a registrar: ";
			cin >> nums[0];
			cout << "(2er) Ingrese numero a registrar: ";
			cin >> nums[1];
		break;
		
		case 3:
			cout << "(1er) Ingrese numero a registrar: ";
			cin >> nums[0];
			cout << "(2er) Ingrese numero a registrar: ";
			cin >> nums[1];
			cout << "(3er) Ingrese numero a registrar: ";
			cin >> nums[2];
		break;
		
		default:
			printf ("ERROR 004 - Signed fail");
			exit(1); 
	}
		
	//correos electronicos
	cout << endl << "Cuantos correos desea registrar? (max: 03)" << endl;
	int emailSize;
	string emails[2] = {"",""};
	cin >> emailSize;
	cout << endl; 	//salto de linea
	
	switch (emailSize){
		case 1:
			cout << "Ingrese el email a registrar: ";
			cin >> emails[0];
		break;
		
		case 2:
			cout << "(1er) Ingrese el email a registrar: ";
			cin >> emails[0];
			cout << "(2er) Ingrese el email a registrar: ";
			cin >> emails[1];
		break;
		
		default:
			printf ("ERROR 004 - Signed fail");
			exit(1);
	}
	
	//ciudad y pais de provinensia
	string city, country;
	cout << endl <<"Pais de provinencia: ";
	cin >> country;
	cout << "Ciudad de provinencia: Cd. ";
	cin >> city;

	
	//registro de datos
	ofstream userData;
	userData.open("userData.txt", ios::out);
	if (userData.is_open()){
		userData << "Nombres: " << name1 << ' ' << name2 << '\n' << "Apellidos: " << lastName1 << ' ' << lastName2 << endl;
		userData << "Cedula de identidad: "<< ced << '\n' << "Pasaporte: " << pass << '\n' << "Edad: " << age << '\n' << endl;
		userData << "Numeros telefonicos: \n" << nums[0] << '\n' << nums[1] << '\n' << nums[2] << endl;
		userData << "Correos electronicos: \n" << emails[0] << '\n' << emails[1] << endl;
		userData << "Pais de provinencia: " << country << '\n' << "Ciudad de provinencia: " << city;
	}else{
		printf ("ERROR 005 - File no found");
		exit(1);
	}
	userData.close();
}

//registro de venta de boletos aereos
int setRegistreSelf(){
	srand (time(0)); 
	
	int i;
	printf("\nDesea hacer un nuevo registro de un pasajero? \n(1)Si \n(2)No \n");
	cin >> i;
	
	if (i == 1){
		setRegistreUser(); //llamando nuevamente al registro de usuario
		cout << endl << "---usuario registrado---" << endl << endl;
		
	}else if (i >= 3){
		printf ("ERROR 001 - Character unklond");
		exit (-1);
	}
	
	printf ("\n---Registro de venta de pasajero (Iniciando)--- \n");

	//origen y destino del viaje 
	string originCountry, originCity, destinyCountry, dentinyCity;
	
	//Origne del viaje
	printf ("Origen del viaje: \n");
	
	printf ("Pais: ");
	cin >> originCountry;
	printf ("Ciudad: Cd. ");
	cin >> originCity;
	
	//Destino del viaje
	printf  ("\nDestino del viaje: \n");
	
	printf ("Pais: ");
	cin >> destinyCountry;
	printf ("Ciudad: Cd. ");
	cin >> dentinyCity;
	
	//aerorinea
	string aerolines[5] = {"Aereo 1", "Aereo 2", "Aereo 3", "Aereo 4", "Aereo 5"};
	cout << endl << "Estas son las aerorineas disponibles: " << endl;
	int a;
	int aereoConfirm;
	
	for (int n = 0; n < 5; n++){
		a++;
		cout << endl << "(" << a << ") " << aerolines[n];
	}
	
	cout << endl << endl << "Seleccione la aerorinea deseada: ";
	cin >> aereoConfirm; 
	
	if (aereoConfirm > 5){
		printf ("ERROR 001 - Character unklond");
		exit (-1);
	}
	
	//Clases de pasajero
	string clasesGenerales[3] = {"Primera Clase", "Segunda Clase", "Clase economica"};
	printf ("\nQue clase desea quedarse? \n");
	printf ("(1)Primera Clase \n(2)Segunda Clase \n(3)Clase economica \n");
	int classSelect;
	cin >> classSelect;
	
	if (classSelect > 3){
		printf ("ERROR 001 - Character unklond");
		exit (-1);
	}
	
	//asiento del pasajero
	int asientos[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int selectAsient;
	printf ("\nSeleciene el numero del haciento (Debe ser un numero del 1 al 12)\n");
	cin >> selectAsient;
	
	if (selectAsient > 12){
		printf ("ERROR 006 - Numero muy alto");
		exit (-1);
	}
	
	printf ("\n-----------------------------");
	
	//imprimiendo todos las seleciones
	switch (classSelect){
		case 1:
			cout << endl << clasesGenerales[0] << endl;
		break;
		
		case 2:
			cout << endl << clasesGenerales[1] << endl;
		break;
		
		case 3:
			cout << endl << clasesGenerales[2] << endl;
		break;
		
		default:
		printf ("ERROR 007 - Print fail");
		exit (-1);
	}

	//asiento del pasajero
	cout << "numero de asiento: " << asientos[selectAsient - 1] << endl;
	
	//numero de ticket
	int tiket_nums = (rand () % 999);
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

	cout << "Localizador del ticket: " << alfb[row][cols] << alfb[row_2][cols_2] << alfb[row_3][cols_3];
	cout << alfb[row_4][cols_4] << alfb[row_5][cols_5] << alfb[row_6][cols_6] << endl << endl;

	//costos de servicio
	int prices[5] = {100,200,300,400,500};
	cout << "Costo de servicios: " << endl;
	
	switch (aereoConfirm){
		
		case 1:
			cout << "Aerorinea: " << "\"" << aerolines[0] << "\"" << " --- " << prices[0] << "$ ";
		break;
		
		case 2:
			cout << "Aerorinea: " << "\"" << aerolines[1] << "\"" << " --- " << prices[1] << "$ ";
		break;
		
		case 3:
			cout << "Aerorinea: " << "\"" << aerolines[2] << "\"" << " --- " << prices[2] << "$ ";
		break;
		
		case 4:
			cout << "Aerorinea: " << "\"" << aerolines[3] << "\"" << " --- " << prices[3] << "$ ";
		break;
		
		case 5:
			cout << "Aerorinea: " << "\"" << aerolines[4] << "\"" << " --- " << prices[4] << "$ ";
		break;
		
		default:
			printf ("ERROR 003 - Selection error");
			exit(-1);
			
	}
	printf ("\n-----------------------------\n\n");
	
	//revicion si se decea continuar con la compra del ticket
	int confirm_price;
	cout << "Realizar canselacion de gastos?" << endl << endl;
	cout << "(1)Confimar \n(2)Denegar" << endl;
	cin >> confirm_price;
	
	if (confirm_price == 1){
		switch (aereoConfirm){
		
		case 1:
			cout << endl << "Gasto total:" << " --- " << prices[0] << "$ "<< endl;
		break;
		
		case 2:
			cout << endl << "Gasto total:" << " --- " << prices[1] << "$ "<< endl ; 
		break;
		
		case 3:
			cout << endl << "Gasto total:" << " --- " << prices[2] << "$ "<< endl;
		break;
		
		case 4:
			cout << endl << "Gasto total:" << " --- " << prices[3] << "$ "<< endl ; 
		break;
		
		case 5:
			cout << endl << "Gasto total:" << " --- " << prices[4] << "$ "<< endl;
		break;
		
		default:
			printf ("ERROR 003 - Selection error");
			exit(-1);
		}
	
	//registro de venta en archivo
	ofstream registreSelfData;
	registreSelfData.open("SelfData.txt", ios::out);
		
		if (registreSelfData.is_open()){ 
				registreSelfData << "Origen del viaje: \n" << "Pais: " << originCountry << '\n' << "Ciudad: " << originCity << '\n' << endl;
				registreSelfData << "Destino del viaje: \n" << "Pais: " << destinyCountry << '\n' << "Ciudad: " << dentinyCity << '\n' << endl;
	      		registreSelfData << "Aerolinea: " << aerolines[aereoConfirm - 1] << endl;
	      		registreSelfData << "Clase: " << clasesGenerales[classSelect - 1] << endl;
				registreSelfData << "Numero del asiento: " <<  asientos[selectAsient - 1] << endl;
	      		registreSelfData << "Numero de ticket: " << '#' << "00" << tiket_nums<< endl;
	      		registreSelfData << "Localizador del ticket: " << '#' << alfb[row][cols] << alfb[row_2][cols_2] << alfb[row_3][cols_3] << alfb[row_4][cols_4] << alfb[row_5][cols_5] << alfb[row_6][cols_6] << endl;
	      		registreSelfData << "Precio de gastos en total: " << prices[aereoConfirm - 1] << '$';
		}else{
			printf ("ERROR 005 - File no found");
		}
		
		//cerrando el archivo
		registreSelfData.close(); 
	
		
	}else if (confirm_price == 2){	//canselacio de transacion
		printf ("#-Transacion cancelada-#");
		printf ("\n-----------------------------\n");
			
	}else{
		printf ("ERROR 001 - Character unklond");
		exit (-1);
	}
}

int getRegistreData(){
	
	printf ("\nSeleccione la opcion deseada \n(1)Pasajeros registrados \n(2)Ventas registradas \n");
	int select;
	cin >> select;
	
	ifstream userData("userData.txt", ios::in);
	string users[3] = {"User 1"};
	
	try{
		if (select == 1){
			//usuarios registrados
			printf ("\n--Usuarios registrados-- \n");
				
			if (userData.is_open()){
			cout << endl << users[0] << " --Registrado--";
				
		    int usersSelect;
			cout << endl << endl << "cual datos de usuario desea ver?" << endl;
			cin >> usersSelect;
			
			if (usersSelect == 1){
				cout << endl << "--Datos del usuario *" << users[0] << "*--" << endl;
				string line;
					while (getline(userData, line)){
						cout << line << "\n";
					}
					
				userData.close();
				//funcion para llamar a los datos correspondientes al orden de registro
			}
		
			printf ("------------------------------\n\n");
			printf ("Desea terminar la revision de registros? \n(1)Si \n(2)No \n");
			int i;
			cin >> i;
				
			if (i == 1){
				exit(1);
			}else if (i == 2){
				getRegistreData();
			}	
			
			}else{
				printf ("\nNothing file registre\n");
				getMenu();
			}
				
		}else if (select == 2){	//ventas registra
		
			string self[3] = {"Self 1"};
			printf ("\n--Ventas registradas-- \n");
			
			ifstream registreSelfData("SelfData.txt", ios::in);
			
			if (registreSelfData.is_open()){
				cout << endl << self[0] << " --Registrada--";
				
			}else{
				printf ("\nNothing file registre\n");
				getMenu();
			}
			
			int selfSelect;
			cout << endl << endl << "cual de las ventas registradas desea ver?" << endl;
			cin >> selfSelect;
			
			if (selfSelect == 1){
				cout << endl << "--Datos dela venta *" << self[0] << "*--" << endl;
				string line;
				
					while (getline(registreSelfData, line)){
						cout << line << "\n";
					}	
					
				registreSelfData.close();
				
			}else{   
				printf ("\nNothing file registre\n");
				getMenu();
			}
			
			printf ("------------------------------\n\n");
			printf ("Desea terminar la revision de registros? \n(1)Si \n(2)No \n");
			int i;
			cin >> i;
			
			if (i == 2){
				getRegistreData();
			}
			
		}else if (select >= 3){
			throw 0;
		}
		
	}catch(int x){
		printf ("ERROR 001 - Character unklond");
		exit(-1);
	}
}
