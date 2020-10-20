#include "parse_program_options.hpp"

using namespace boost::program_options;
using namespace std;
using namespace std::filesystem;
/*
sortbackup.exe -[d|e|m|h] [inputFolder] [outputFolder]


-d sort by date -> month directories nested in year directories
-e sort by extension
-m move the files instead of copying
-h show help output

inputFolder - path to folder where the unsorted backup is stored
outputFolder - path to folder where the result will be stored

*/
string onlyKnownSwitches = "^(?:([demh])(?!.*\1))*$";
string shortSwitches = "^[-][^-]";

Program_Options parse_command_line(int argc, char* argv[]) {
	if (argc < 2) {
		cerr << "Error: Not enough command line arguments" << endl;
		exit(EXIT_FAILURE);
	}

	if (argc > 4) {
		cerr << "Error: Maximum number of command line arguments exceeded" << endl;
		exit(EXIT_FAILURE);
	}
	Program_Options pOptions;


	list<string> args;
	for (int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	if (regex_search(args.front(), regex(shortSwitches))) {
		//short switches, no duplicates, multiples allowed


		auto shortSwitch = args.front().substr(1); //cuts the first char '-'  from the string
		args.pop_front();

		//checks for mistakes
		//only known switches
		if (!regex_search(shortSwitch, regex(onlyKnownSwitches))) {
			cerr << "Error: Unkown switch used." << endl;
			exit(EXIT_FAILURE);
		}
		else {
			//check for (h)help 
			if (regex_search(shortSwitch, regex("[h]"))) {
				pOptions.help = true;
				return pOptions;
			}
			//check for (h)help 
			if (regex_search(shortSwitch, regex("[d]"))) {
				pOptions.sortDate = true;
			}
			if(regex_search(shortSwitch, regex("[e]"))) {
				pOptions.sortExt = true;
			}
			if (regex_search(shortSwitch, regex("[m]"))) {
				pOptions.moveFiles = true;
			}
		}
	}
	
	if (args.size() < 2) {
		cerr << "Not enough command line arguments. Type '-h' to see help" << endl;
		exit(EXIT_FAILURE);
	}
	//INPUTFILE
	path input;
		
	try {
		input = canonical(args.front());
	}
	catch (filesystem_error& ex) {
		cout << "Error: " << ex.what() << endl;
		exit(EXIT_FAILURE);
	}
	args.pop_front();

	//validade input
	try {
		if (is_directory(input)) {
			pOptions.inputFolder = input;
		}
	}
	catch (filesystem_error fe) {
		cout << fe.what()<<endl;
		exit(EXIT_FAILURE);
	}
		
	//OUPUT FILE
	path output;
		
	try {
		output = canonical(args.front());
	}
	catch (filesystem_error& ex) {
		cout << "Error: " << ex.what() << endl;
		exit(EXIT_FAILURE);
	}
	args.pop_front();

	//validate output
	try {
		if (is_directory(output)) {
			pOptions.outputFolder = output;
		}
	}
	catch (filesystem_error fe) {
		cout << fe.what()<<endl;
		exit(EXIT_FAILURE);
	}
	
	return pOptions;
}