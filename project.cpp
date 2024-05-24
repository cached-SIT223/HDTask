
/* HD Task Awesome Project*/

/*

This is a simple C++ program that prints "Hello, World!" and the current date and time.

It also prints "This is an awesome project!" to the file: ~/Desktop/awesome_project.txt

*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <pwd.h>

int main() {
    // Print "Hello, World!"
    std::cout << "Hello, World!" << std::endl;

    // Get the current date and time
    time_t now = time(0);
    char* dt = ctime(&now);

    // Print the current date and time
    std::cout << "The local date and time is: " << dt << std::endl;

    // Write "This is an awesome project!" to the file: awesome_project.txt that resides on the users Desktop

    // get env variable HOME
    const char *homedir;

    // get the value of HOME
    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }

    // create the file path
    std::string file_path = std::string(homedir) + "/Desktop/HDTask/awesome_project.txt";
    std::ofstream file;

    // write to the file
    file.open(file_path);
    file << "This is an awesome project!";
    file.close();

    return 0;
}
