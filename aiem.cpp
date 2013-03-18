#include "aiem.h"

AIEM::AIEM(){
	domainWidth = 5528;
	domainHeight = 2223;
	domainXOffset = 0;
	domainYOffset = 0;
	XULCorner = -1725223.205807;
	YULCorner = 2544412.932644;
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
bool AIEM::boundsCheck(int x, int y){
	std::stringstream errmsg;
	if (x < 0 || x >= domainWidth){
		errmsg << "\terror in domainWidth\n";
	}
	if (y < 0 || y >= domainHeight){
		errmsg << "\terror in domainHeight\n";
	}
	if (errmsg.str().length() > 0){
		std::cout << "boundsCheck(" << x << "," << y << ") fails:\n" << errmsg.str();
		return false;
	}
	return true;
}
bool AIEM::inputCheck(int x, int y, int v){

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
	if(boundsCheck(x,y)){
		fireSeverity[x][y] = v; 
	}
}
void AIEM::setVegetationType(int x, int y, int v){
	if(boundsCheck(x,y)){
		vegetationType[x][y] = v; 
	}
}
void AIEM::setTimeSinceLastFire(int x, int y, int v){
	if(boundsCheck(x,y)){
		timeSinceLastFire[x][y] = v; 
	}
}

float AIEM::getSoilBiomass(int x, int y){
	return soilBiomass[x][y];	
}
float AIEM::getSoilTemperature(int x, int y){
	return soilTemperature[x][y];	
}
void AIEM::setSoilBiomass(int x, int y, int v){
	if(boundsCheck(x,y)){
		soilBiomass[x][y] = v; 
	}
}
void AIEM::setSoilTemperature(int x, int y, int v){
	if(boundsCheck(x,y)){
		soilTemperature[x][y] = v; 
	}
}
double* AIEM::getAlbers(double lat, double lon){
	/* 
 	* Taking in Decimal Degrees (DD), and returning the X,Y location of the pixel in
 	* Alaska Albers (NAD83) projection, offset by ALFRESCO Origin and Offset of
 	* Bounding Box
 	*/ 
	OGRSpatialReference poSRS;
	poSRS.importFromEPSG( 4326 ); //Reference the incoming WGS84 Decimal Degree Format

	OGRSpatialReference poTRS;
	poTRS.importFromEPSG( 3338 ); //Reference the outgoing NAD83 Alaskan Albers projection

	OGRCoordinateTransformation *poCT;
	poCT = OGRCreateCoordinateTransformation( &poSRS, &poTRS );

	double* albers = new double[2];  //Hold the output in x,y format rather than incoming lat,long
	albers[0] = lon;
	albers[1] = lat;
	poCT->Transform(1, &albers[0], &albers[1]);
	albers[0] = round((albers[0] - XULCorner) / 1000) + domainXOffset;
	albers[1] = round((YULCorner - albers[1]) / 1000) + domainYOffset;

	return albers;
}
