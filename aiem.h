#ifndef AIEM_H
#define AIEM_H

class AIEM {
	public:
		AIEM();
		void initialize();
		void clearCells();
	
		int** fireSeverity;
		int** vegetationType;
		int** timeSinceLastFire;

		int domainWidth;
		int domainHeight;
};

#endif
