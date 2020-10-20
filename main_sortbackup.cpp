//! \author: Luis Mizuno
//  \Date: 2020-08-16
//  \name of the file: sortbackup.cpp : 
//  \purpose: This file contains the 'main' function. Program execution begins and ends there.
//  Program to distribute and organize the contents of a file

#include <iostream>
#include <map>
#include <filesystem>
#include "parse_program_options.hpp"
#include <boost/program_options.hpp>

using namespace std;
using namespace std::filesystem;
using namespace boost::program_options;



int main(int argc, char* argv[])
{
 
	//Parse the command
	Program_Options pOptions = parse_command_line(argc, argv);
	cout << "Help: " << pOptions.help << endl;
	cout << "Sort by date: " << pOptions.sortDate << endl;
	cout << "Sort by extension: " << pOptions.sortExt << endl;
	cout << "Move files: " << pOptions.moveFiles << endl;
	cout << "Canonical Input Path: " << endl << pOptions.inputFolder << endl;
	cout << "Canonical Output Path: " << endl << pOptions.outputFolder << endl;


	//Function call: read inputFolder files

	//Function call: organize how the output will be

	//Function call: output files
	//optimization ideas: create a file to guide us and save it for the future run

	
	
	
	/*char oldname[] = "C:\\Users\\file_old.txt";
	char newname[] = "C:\\Users\\New Folder\\file_new.txt";*/

	/*	Deletes the file if exists */
	/*if (rename(oldname, newname) != 0)
		perror("Error moving file");
	else
		cout << "File moved successfully";*/


}


