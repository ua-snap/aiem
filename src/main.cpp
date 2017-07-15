#include "main.h"

StatArray* RunStats;
AIEM* aiem;
int main(int argc, char* argv[]){
	#ifdef MPI_VERSION
	int rank;
	int numtasks;
	MPI::Init ( argc, argv );
	rank = MPI::COMM_WORLD.Get_rank();
	numtasks = MPI::COMM_WORLD.Get_size();
	#endif
	

	ArgParse* args = new ArgParse();
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
		_simulation->setup("/home/UA/apbennett/aiem/", args->getFifName(), "/home/UA/apbennett/aiem", repRand);
		RunStats->setFirstYear(_simulation->fif().root["Simulation"]["FirstYear"].asInt());
	}
	/* GIPL */
	GIPL* gipl = new GIPL();
	if (args->getRunGIPL()){
		gipl->init();

	}
	time_t stime;
	time_t etime;
	/* TEM SETUP */
	//Runner regner;
  	Json::Value controldata = temutil::parse_control_file(args->getTEMControlName());
	ModelData modeldata(controldata);
	Runner regner(modeldata, false, 0, 0);

	regner.cohort.climate.prepare_daily_driving_data(0, "eq");

          regner.cohort.initialize_internal_pointers(); // sets up lots of pointers to various things
          regner.cohort.initialize_state_parameters();  // sets data based on values in cohort lookup



	std::vector< std::vector<int> > run_mask = temutil::read_run_mask(modeldata.runmask_file);
	if (args->getRunTEM()){

		stime=time(0);
		cout << "run TEM stand-alone - start @" << ctime(&stime) << "\n";
	}
	/* Main Control Loop */
	for (int i = args->getStartYear(); i <= args->getEndYear(); i++){
		if (args->getRunALFRESCO()){
			_simulation->runOneYear(0,i);
			std::cout << "Year " << i << " Complete\n";
		}
		#ifdef MPI_VERSION
		MPI::COMM_WORLD.Barrier();
		#endif
		for (int j = 0; j < 12; j++){
			if (args->getRunTEM()){
				std::cout << j << std::endl;
				regner.run_years(args->getStartYear(), args->getEndYear(), "eq-run");
			//	regner.runSpatially(i - args->getStartYear(),j);
				gipl->run();
			}
			#ifdef MPI_VERSION
			MPI::COMM_WORLD.Barrier();
			#endif
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
	#ifdef MPI_VERSION
	MPI::Finalize();
	#endif
	std::cout << "Model complete" << std::flush << std::endl;
	return 0;
}
