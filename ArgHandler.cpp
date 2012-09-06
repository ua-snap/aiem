#include "ArgHandler.h"


ArgHandler::ArgHandler(){
	fifFile = "default.fif";
	temControlFile = "config/controlfile_site.txt";
	boost::filesystem::path p = boost::filesystem::initial_path();
	debug = false;
	help = false;
	version = false;
	runALFRESCO = true;
	runTEM = true;
	runGIPL = true;
}
void ArgHandler::parse(int argc, char** argv){
	desc.add_options()
		("help,h", "produces helps message")
		("version,v", "show the version information")
		("debug,d", "enable debug mode")
		("disablealfresco", "disable tem run")
		("disablegipl", "disable giple run")
		("disabletem", "disable alfresco run")
		("fif", boost::program_options::value<string>(), "set the alfresco fif file")
		("temcontrol", boost::program_options::value<string>(), "set the TEM control file")
	;
	
	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), varmap);
	boost::program_options::notify(varmap);

	if (varmap.count("help")){
		help = true;
	}
	if (varmap.count("debug")){
		debug = true;
	}
	if (varmap.count("disablealfresco")){
		runALFRESCO = false;
	}
	if (varmap.count("disablegiple")){
		runGIPL = false;
	}
	if (varmap.count("disabletem")){
		runTEM = false;
	}
	if (varmap.count("fif")){
        	fifFile = varmap["fif"].as<string>();
	}
	if (varmap.count("temcontrol")){
        	temControlFile = varmap["temcontrol"].as<string>();
	}
}
string ArgHandler::getFifName(){
	return fifFile;
}
string ArgHandler::getTEMControlName(){
	return temControlFile;
}
void ArgHandler::showHelp(){
/**
 * Print out command help
 */
	std::cout << desc << std::endl;
}

