#ifndef AIEM_H
#define AIEM_H
#include "ArgHandler.h"
#include "alfresco.h"
//#include "GIPL2.h"
#include "dostem.h"
#define AIEM_MODEL

class AIEM{
	public:
		AIEM();
		void initialize();
	
		int** fireSeverity;
		int** vegetationType;
		int** timeSinceLastFire;

		int domainWidth;
		int domainHeight;
};

#endif
