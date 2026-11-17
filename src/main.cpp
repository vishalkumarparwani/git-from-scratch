#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int cmdInit(const std::vector<std::string>& arguments) {
    if (std::filesystem::exists(".git")) {
        std::cerr << ".git folder already exists\n";
        return 1;
    }
    bool repository_created = false;

    try {
        std::filesystem::create_directories(".git/hooks");
        repository_created = true;
        std::filesystem::create_directories(".git/info");
        std::filesystem::create_directories(".git/objects/info");
        std::filesystem::create_directories(".git/objects/pack");
        std::filesystem::create_directories(".git/refs/heads");
        std::filesystem::create_directories(".git/refs/tags");

        std::ofstream head_file(".git/HEAD");
        if(!head_file) throw std::runtime_error("Could not write HEAD");

        head_file << "ref: refs/heads/main\n";
        head_file.close();

        std::ofstream config_file(".git/config");
        if(!config_file) throw std::runtime_error("Could not write config");
        config_file << R"([core]
        repositoryformatversion = 0
        filemode = false
        bare = false
        logallrefupdates = true
    )";
        config_file.close();
    
        std::ofstream description_file(".git/description");
        if(!description_file) throw std::runtime_error("Could not write description");
        description_file << "Unnamed repository; edit this file 'description' to name the repository.\n";
        description_file.close();

        std::cout << "Initialized empty repository\n";
        return 0;
    }
    catch (const std::exception& error) {
        std::cerr << "Initialization failed: " << error.what() << "\n";
        if(repository_created) std::filesystem::remove_all(".git");
        return 1;
    }
}



int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cerr << "Usage: minigit <command>\n";
        return 1;
    }

    std::string command = argv[1]; //git init => argv[0] argv[1]
    std::vector<std::string> arguments(argv + 2, argv + argc);

    if(command == "init") {
        return cmdInit(arguments);
    }

    std::cerr << "unknown command: " << command << "\n";
    return 1;
}