#include "aiem.h"
StatArray* RunStats;
int main(int argc, char* argv[]){
	Runner *region;
	RunStats = new StatArray();
	GIPL* gipl = new GIPL();
	gipl->init();
	gipl->run();
	int startYear = 1901;
	int transitionYear = 2009;
	int endYear = 2099;
	for (int i = startYear; i < endYear; i++){
		for (int j = 0; j < 12; j++){

		}
	}
	RunStats = new StatArray();

	CustomFresco* _simulation = new CustomFresco(false);
	_simulation->setIsStopped(false);
	srand(437893);
	long repRand = rand();
	_simulation->setup("/home/apbennett/aiem/", "test.fif", "/home/apbennett/aiem", repRand);
	RunStats->setFirstYear(_simulation->fif().nGet("FirstYear"));
	_simulation->runRep(1, _simulation->fif().nGet("FirstYear")); 
	_simulation->runEnd();
	_simulation->clear();
	delete _simulation; _simulation = 0;
	std::cout << "Rep " << 0 << " of " << 0 << " complete" << std::endl;
	RunStats->writeStats();
	return 0;
}
