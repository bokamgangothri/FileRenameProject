#include <iostream>
#include <string>
#include <dirent.h>  // for directory operations
#include <sys/types.h>
#include <cstdio>     // for rename()
#include <cstring>    // for strcmp

#ifdef _WIN32
#include <windows.h>  // for GetFullPathName on Windows
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

int main() {
    std::string folder;
    std::cout << "Enter folder name: ";
    std::getline(std::cin, folder);

    DIR* dir = opendir(folder.c_str());
    if (!dir) {
        std::cerr << "Error: Folder not found or can't be opened.\n";
        return 1;
    }

    struct dirent* entry;
    int count = 0;

    while ((entry = readdir(dir)) != nullptr) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build source and destination paths
        std::string old_name = folder + PATH_SEPARATOR + entry->d_name;
        std::string new_name = folder + PATH_SEPARATOR + "Hostel " + std::to_string(count++) + ".jpg";

        if (rename(old_name.c_str(), new_name.c_str()) != 0) {
            std::perror("Error renaming file");
        }
    }

    closedir(dir);
    std::cout << "Renaming completed.\n";
    return 0;
}
