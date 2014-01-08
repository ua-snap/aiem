#ifndef AIEM_H
#define AIEM_H
#include <iostream>
#include <sstream>
#include <ogr_geometry.h>
#include "modelData.h"

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
		modelData<int> fireSeverity;
		modelData<int> vegetationType;
                modelData<int> timeSinceLastFire;

		/* TEM set variables */
		modelData<int> soilTemperature;
		modelData<int> soilBiomass;
};

#endif
