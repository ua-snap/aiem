#ifndef AIEM_H
#define AIEM_H
#include <iostream>
#include <sstream>
#include <ogr_geometry.h>
#include "ModelData.h"

class AIEM {
	public:
		/* Initialization, maintenance functions */
		AIEM();
		void initialize();
		void clearCells();	
	
		bool boundsCheck(int x, int y);


	private:
		/* Internal variables, data structures, etc. */
		int XULCorner;
		int YULCorner;
		int domainXOffset;
		int domainYOffset;
                int domainWidth;
                int domainHeight;

		/* ALFRESCO data structures */
		ModelData<int> fireSeverity;
		ModelData<int> vegetationType;
                ModelData<int> timeSinceLastFire;

		/* TEM set variables */
		ModelData<int> soilTemperature;
		ModelData<int> soilBiomass;
};

#endif
