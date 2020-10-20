#pragma once
#include <filesystem>
#include <iostream>
#include <regex>
#include <boost/program_options.hpp>

struct Program_Options {
	bool sortExt = false;
	bool sortDate = false;
	bool moveFiles = false;
	bool help = false;
	std::filesystem::path inputFolder = "";
	std::filesystem::path outputFolder = "";
};

Program_Options parse_command_line(const int argc,  char *argv[]);