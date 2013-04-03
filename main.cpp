#include "ArgHandler.h"
#include "aiem.h"
#include "alfresco.h"
#include "GIPL2.h"
#include "dvmdostem.h"

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
	int transitionYear = 2009;

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
	/* GIPL */
	GIPL* gipl = new GIPL();
	if (args->getRunGIPL()){
		gipl->init();

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
	/* Main Control Loop */
	for (int i = args->getStartYear(); i <= args->getEndYear(); i++){
		if (args->getRunALFRESCO()){
			_simulation->runOneYear(0,i);
		}
		std::cout << "Year " << i << " Complete\n";
		for (int j = 0; j < 12; j++){
			if (args->getRunTEM()){
				regner.runSpatially(i - args->getStartYear(),j);
				gipl->run();
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
