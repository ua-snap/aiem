#include <iostream>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

using namespace std;


class ArgHandler{
	boost::program_options::options_description desc;
	boost::program_options::variables_map varmap;
	string fifFile;
	string temControlFile;
	bool debug;
	bool help;
	bool version;

	/* Time loop control */
	int startYear;
	int endYear;

	/* Model enable/disable */
	bool runALFRESCO;
	bool runGIPL;
	bool runTEM;
public:
	ArgHandler();
	void parse(int argc, char** argv);
	void showHelp();
	string getFifName();
	string getTEMControlName();
	inline const bool getDebug(){ return debug; }
	inline const bool getHelp() const { return help; }
	inline const bool getVersion() const { return version; }
	inline const bool getStartYear() const { return startYear; }
	inline const bool getEndYear() const { return endYear; }
	inline const bool getRunALFRESCO() const { return runALFRESCO; }
	inline const bool getRunGIPL() const { return runGIPL; }
	inline const bool getRunTEM() const { return runTEM; }
};
