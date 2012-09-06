#ifndef AIEM_H
#define AIEM_H
#include <iostream>
#include <sstream>

class AIEM {
	public:
		/* Initialization, maintenance functions */
		AIEM();
		void initialize();
		void clearCells();
	
		bool boundsCheck(int x, int y);
		bool inputCheck(int x, int y, int v);

		/* Data fetch methods */
		int getFireSeverity(int x, int y);
		int getVegetationType(int x, int y);
		int getTimeSinceLastFire(int x, int y);

		float getSoilTemperature(int x, int y);
		float getSoilBiomass(int x, int y);

		/* Internal variables, data structures, etc. */	
		int domainWidth;
		int domainHeight;

		/* ALFRESCO set variables */
		int** fireSeverity;
		int** vegetationType;
		int** timeSinceLastFire;

		void setFireSeverity(int x, int y, int v);
		void setVegetationType(int x, int y, int v);
		void setTimeSinceLastFire(int x, int y, int v);

		/* GIPL set variables */

		/* TEM set variables */
		float** soilTemperature;
		float** soilBiomass;

		void setSoilTemperature(int x, int y, int v);
		void setSoilBiomass(int x, int y, int v);
};

#endif
