#include "aiem.h"

AIEM::AIEM(){
	domainWidth = 5528;
	domainHeight = 2223;
}
void AIEM::initialize(){
	fireSeverity = new int*[domainWidth];
	vegetationType = new int*[domainWidth];
	timeSinceLastFire = new int*[domainWidth];
	for (int i = 0; i < domainWidth; i++){
		fireSeverity[i] = new int[domainHeight];
		vegetationType[i] = new int[domainHeight];
		timeSinceLastFire[i] = new int[domainHeight];
		for (int j = 0; j < domainHeight; j++){
			fireSeverity[i][j] = 0;
			vegetationType[i][j] = 0;
			timeSinceLastFire[i][j] = 0;
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
