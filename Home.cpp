// C++17 code to rename multiple files in a folder
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string folder;
    std::cout << "Enter folder name: ";
    std::getline(std::cin, folder);

    // Check if folder exists and is a directory
    if (!fs::exists(folder) || !fs::is_directory(folder)) {
        std::cerr << "Folder not found or not a directory!\n";
        return 1;
    }

    int count = 0;
    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            std::string old_path = entry.path().string();
            std::string new_name = "Hostel " + std::to_string(count++) + ".jpg";
            std::string new_path = folder + "/" + new_name;

            try {
                fs::rename(old_path, new_path);
            } catch (const fs::filesystem_error& e) {
                std::cerr << "Error renaming file: " << e.what() << "\n";
            }
        }
    }

    std::cout << "Renaming completed successfully.\n";
    return 0;
}
