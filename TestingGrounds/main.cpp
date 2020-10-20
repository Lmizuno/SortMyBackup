#include <filesystem>
#include <iostream>


using namespace std;
using namespace std::filesystem;

int main(int argc, char* argv[])
{
    cout << "==================================================" << endl;
    cout << "Testing Grouds:" << endl;
    cout << "Argc: " << argc << endl;
    cout << "Argv: " << endl;

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }


    cout << "=================================================="<< endl;
    if (argc <= 3 && argc > 1) {

        path o = argv[1]; //origin
        path d = argv[2]; //destiny

        cout << "Origin: ";
        cout << o.string() << endl;
        cout << "Destiny: ";
        cout << d.string() << endl;

        //test if file we want to have is there
        if (!exists(o)) {
            cout << "File origin does not exist" << endl;
            return 1;
        }


        
        //Edit the destination path
        d = d.replace_filename(o.filename());

        cout << "Destiny2: ";
        cout << d.string() << endl;

        //test if there is a file where you want to move the new one

        if (exists(d)) {
            cout << "File destiny already exists" << endl;
            return 1;
        }

        


        try {
            std::filesystem::rename(o, d);
        }
        catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
        }
    }



  
}