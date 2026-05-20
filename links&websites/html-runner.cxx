#include <iostream>
#include <string>
#include <cstdlib>

void openHtmlInBrowser(const std::string& filePath) {
    std::string command;
    
    #ifdef _WIN32
        command = "start \"\" \"" + filePath + "\"";
    #elif __APPLE__
        command = "open \"" + filePath + "\"";
    #else
        command = "xdg-open \"" + filePath + "\"";
    #endif

    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "Error: Could not open the HTML file." << std::endl;
    }
}

int main() {
    std::string htmlFile = "index.html";
    
    std::cout << "Opening " << htmlFile << " in your default browser..." << std::endl;
    openHtmlInBrowser(htmlFile);

    return 0;
}
