#ifndef AIEM_H
#define AIEM_H
#include <iostream>
#include <sstream>
#include <ogr_geometry.h>

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

		/* ALFRESCO set methods */
		void setFireSeverity(int x, int y, int v);
		void setVegetationType(int x, int y, int v);
		void setTimeSinceLastFire(int x, int y, int v);

		/* GIPL set variables */

		/* TEM set methods */
		void setSoilTemperature(int x, int y, int v);
		void setSoilBiomass(int x, int y, int v);

		/* Spatial translation */
		double* getAlbers(double lat, double lon); // Takes DD, returns NAD83 x,y array
	private:
		/* Internal variables, data structures, etc. */
		int XULCorner;
		int YULCorner;
		int domainXOffset;
		int domainYOffset;
                int domainWidth;
                int domainHeight;

		/* ALFRESCO set variables */
                int** fireSeverity;
                int** vegetationType;
                int** timeSinceLastFire;

		/* TEM set variables */
                float** soilTemperature;
                float** soilBiomass;

};

#endif
