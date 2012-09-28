#include "ArgHandler.h"
#include "aiem.h"
#include "alfresco.h"
#include "GIPL2.h"
#include "dostem.h"

StatArray* RunStats;
ArgHandler* args = new ArgHandler();
AIEM* aiem;
int main(int argc, char* argv[]){
	aiem = new AIEM();
	aiem->initialize();
	args->parse(argc, argv);
	if (args->getHelp()){
		args->showHelp();
		return 0;
	}
	int startYear = 1901;
	int transitionYear = 2009;
	int endYear = 2099;

	for (int i = startYear; i < endYear; i++){
		for (int j = 0; j < 12; j++){

		}
	}
	/* GIPL */
	if (args->getRunGIPL()){
		GIPL* gipl = new GIPL();
		gipl->init();
		gipl->run();
	}

	/* ALFRESCO SETUP */
	RunStats = new StatArray();
	CustomFresco* _simulation = new CustomFresco(false);
	if (args->getRunALFRESCO()){
		_simulation->setIsStopped(false);
		srand(1234763211);
		long repRand = rand();
		_simulation->setup("/home/apbennett/aiem/", args->getFifName(), "/home/apbennett/aiem", repRand);
		RunStats->setFirstYear(_simulation->fif().nGet("FirstYear"));
	}
	time_t stime;
	time_t etime;
	Runner regner;
	/* TEM SETUP */
	if (args->getRunTEM()){

		stime=time(0);
		cout<<"run TEM stand-alone - start @"<<ctime(&stime)<<"\n";

		regner.initInput(args->getTEMControlName(), "regner2");
                regner.initOutput();
                regner.setupData();
                regner.setupIDs();
		regner.runmode3();
	}
	//	for (int i = _simulation->fif().nGet("FirstYear"); i <= _simulation->fif().nGet("LastYear"); i++){
		for (int i = 1901; i <= 1909; i++){
			if (args->getRunALFRESCO()){
				_simulation->runOneYear(0,i);
			}
			std::cout << "Year " << i << " Complete\n";
			for (int j = 0; j < 12; j++){
				if (args->getRunTEM()){
					regner.runSpatially(i - 1901,j);
				}
			}
			aiem->clearCells();
		}
	/* ALFRESCO CLEANUP */
	if (args->getRunALFRESCO()){
		//_simulation->runEnd();
		_simulation->clear();
		delete _simulation; _simulation = 0;
		std::cout << "Rep " << 0 << " of " << 0 << " complete" << std::endl;
		RunStats->writeStats();
	}

	/* TEM CLEANUP */	
	if (args->getRunTEM()){
		etime=time(0);
		cout <<"run TEM stand-alone - done @"<<ctime(&etime)<<"\n";
		cout <<"total seconds: "<<difftime(etime, stime)<<"\n";
	}
	return 0;
}
