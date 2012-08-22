#include "ArgHandler.h"
#include "aiem.h"
#include "alfresco.h"
//#include "GIPL2.h"
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
	//GIPL* gipl = new GIPL();
	//gipl->init();
	//gipl->run();

	/* ALFRESCO */
	RunStats = new StatArray();
	CustomFresco* _simulation = new CustomFresco(false);
	_simulation->setIsStopped(false);
	srand(1234763211);
	long repRand = rand();
	_simulation->setup("/home/apbennett/aiem/", args->getFifName(), "/home/apbennett/aiem", repRand);
	RunStats->setFirstYear(_simulation->fif().nGet("FirstYear"));
	for (int i = _simulation->fif().nGet("FirstYear"); i <= _simulation->fif().nGet("LastYear"); i++){
		_simulation->runOneYear(0,i);
		std::cout << "Year " << i << " Complete\n";
		for (int j = 0; j < 4000; j++){
			for (int k = 0; k < 2000; k++){
				if (aiem->fireSeverity[j][k] > 0){
					std::cout << "Cell[" << j << "][" << k << "] = " << aiem->fireSeverity[j][k] << "\n";
				}
			}
		}
		aiem->clearCells();
	}
	//_simulation->runEnd();
	_simulation->clear();
	delete _simulation; _simulation = 0;
	std::cout << "Rep " << 0 << " of " << 0 << " complete" << std::endl;
	RunStats->writeStats();

	return 0;

	/* TEM */	
	time_t stime;
	time_t etime;
	stime=time(0);
	cout<<"run TEM stand-alone - start @"<<ctime(&stime)<<"\n";

	string controlfile="";
	if(argc==1){ //if there is no control file specified
		controlfile ="config/controlfile_site.txt";
	} else if(argc ==2) {
		controlfile =argv[1];
	}

	Runner siter;

	siter.initInput(controlfile, "siter");
	siter.initOutput();

	siter.setupData();

	//
	siter.run();

	etime=time(0);
	cout <<"run TEM stand-alone - done @"<<ctime(&etime)<<"\n";
	cout <<"total seconds: "<<difftime(etime, stime)<<"\n";
	return 0;
}