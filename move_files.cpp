
#include "move_files.hpp"



void move_file_to(std::filesystem::path destination, std::filesystem::path origin) {
    try {
        std::filesystem::rename("from.txt", "to.txt");
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }
}