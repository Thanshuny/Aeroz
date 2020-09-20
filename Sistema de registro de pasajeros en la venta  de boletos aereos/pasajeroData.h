#ifndef MYDATA_H
#define MYDATA_H
#include <iostream>
using namespace std;

class pasajero_data{
	
	public:
		
		//cedula
		pasajero_data(int val_01){
			setPasajeroDataCel(val_01);
		}
		
		//pasaporte
		pasajero_data(long int val_02){
			setPasajeroDataPasp(val_02);
		}
		
		//guardadondo datos (numericos)
		int setPasajeroDataCel(long long int val_a){
			cedula = val_a;
		}
		
		int setPasajeroDataPasp(long long int val_b){
			pasaporte = val_b;
		}
		
		//obtener datos ()
		int getPasajeroDataCel(){
			return cedula;	
		}
		
		int getPasajeroDataPast(){
			return pasaporte;
		}
		
	private: 
	
		long long int cedula;
		long long int pasaporte;
	
};


#endif
