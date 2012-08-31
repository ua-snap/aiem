#include "aiem.h"

AIEM::AIEM(){
	domainWidth = 5528;
	domainHeight = 2223;
}
void AIEM::initialize(){
	fireSeverity = new int*[domainWidth];
	vegetationType = new int*[domainWidth];
	timeSinceLastFire = new int*[domainWidth];

	soilBiomass = new float*[domainWidth];
	soilTemperature = new float*[domainWidth];
	for (int i = 0; i < domainWidth; i++){
		fireSeverity[i] = new int[domainHeight];
		vegetationType[i] = new int[domainHeight];
		timeSinceLastFire[i] = new int[domainHeight];
	
		soilBiomass[i] = new float[domainHeight];
		soilTemperature[i] = new float[domainHeight];
		for (int j = 0; j < domainHeight; j++){
			fireSeverity[i][j] = 0;
			vegetationType[i][j] = 0;
			timeSinceLastFire[i][j] = 0;

			soilBiomass[i][j] = 0;
			soilTemperature[i][j] = 0;
		}
	}
}
void AIEM::clearCells(){
	for (int i = 0; i < domainWidth; i++){
		for (int j = 0; j < domainHeight; j++){
			fireSeverity[i][j] = 0;
			vegetationType[i][j] = 0;
			timeSinceLastFire[i][j] = 0;
		}
	}
}
int AIEM::getFireSeverity(int x, int y){
	return fireSeverity[x][y];	
}
int AIEM::getVegetationType(int x, int y){
	return vegetationType[x][y];	
}
int AIEM::getTimeSinceLastFire(int x, int y){
	return timeSinceLastFire[x][y];	
}
void AIEM::setFireSeverity(int x, int y, int v){
	fireSeverity[x][y] = v; 
}
void AIEM::setVegetationType(int x, int y, int v){
	vegetationType[x][y] = v; 
}
void AIEM::setTimeSinceLastFire(int x, int y, int v){
	timeSinceLastFire[x][y] = v; 
}

float AIEM::getSoilBiomass(int x, int y){
	return soilBiomass[x][y];	
}
float AIEM::getSoilTemperature(int x, int y){
	return soilTemperature[x][y];	
}
void AIEM::setSoilBiomass(int x, int y, int v){
	soilBiomass[x][y] = v; 
}
void AIEM::setSoilTemperature(int x, int y, int v){
	soilTemperature[x][y] = v; 
}
