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
	bool debug;
	bool help;
	bool version;
public:
	ArgHandler();
	void parse(int argc, char** argv);
	void showHelp();
	string getFifName();
	inline const bool getDebug(){ return debug; }
	inline const bool getHelp() const { return help; }
	inline const bool getVersion() const { return version; }
};
