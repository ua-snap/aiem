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
	fireSeverity.setDomain(domainWidth, domainHeight);
	vegetationType.setDomain(domainWidth, domainHeight);
	timeSinceLastFire.setDomain(domainWidth, domainHeight);
	soilBiomass.setDomain(domainWidth, domainHeight);
	soilTemperature.setDomain(domainWidth, domainHeight);
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
void AIEM::clearCells(){
	fireSeverity.clearData();
	vegetationType.clearData();
	timeSinceLastFire.clearData();
	soilBiomass.clearData();
	soilTemperature.clearData();
}
