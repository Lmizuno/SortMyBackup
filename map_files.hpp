#pragma once
#include <filesystem>
#include <iostream>
#include <map>


std::multimap<std::filesystem::path, std::string> map_folder_files(std::filesystem::path folder);
