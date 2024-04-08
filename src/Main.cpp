#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "Download.h"
#include "OutputColors.h"
#include "GlobalVariables.h"

static void getHomePath() {
#ifdef _WIN32
    const char* homePath = std::getenv("USERPROFILE");
    if (homePath == nullptr) {
        OutputColors::setTextColor(4);
        std::cout << "Wystapil blad, przy wyszukiwaniu sciezki Home, napisz do mnie @prod.mustang!\n";
        OutputColors::setTextColor(7);
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#else
    const char *homePath = std::getenv("HOME");
    if (homePath == nullptr) {
        std::cout << "\033[31m";
        std::cout << "Wystąpił błąd, przy wyszukiwaniu ścieżki Homepath, napisz do mnie @prod.mustang!\n";
        std::cout << "\033[0m";
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#endif
}

static void displayWelcomeUI() {
#ifdef _WIN32
    std::system("cls");
    OutputColors::setTextColor(8);
    std::cout << "> BeatFlipper 2.0 - by Mustang <\n";
    OutputColors::setTextColor(7);
#else
    std::system("clear");
    std::cout << "\033[90m";
    std::cout << "> BeatFlipper 2.0 - by Mustang <\n";
    std::cout << "\033[0m";
#endif
}

int main() {
    getHomePath();
    std::string userInput;
#ifdef _WIN32
    displayWelcomeUI();
    do {
        std::cout << "Wybierz co chcesz pobierac (wprowadz cyferke):\n";
        std::cout << "1. Audio.\n";
        std::cout << "2. Video.\n";

        OutputColors::setTextColor(8);
        std::cout << "> ";
        OutputColors::setTextColor(7);

        std::getline(std::cin,userInput);

        if (userInput == "1") {
            Download::downloadAudioWindows();
            break;
        }
        else if (userInput == "2") {
            Download::downloadVideoWindows();
            break;
        }
        else {
            std::system("cls");
            OutputColors::setTextColor(4);
            std::cout << "Wprowadzono niepoprawna cyferke!\n";
            OutputColors::setTextColor(7);
            sleep(1);
            displayWelcomeUI();
        }

    } while (true);
#else
    displayWelcomeUI();
    do {
        std::cout << "Wybierz co chcesz pobierać:\n";
        std::cout << "1. Audio.\n";
        std::cout << "2. Video.\n";

        std::cout << "\033[90m";
        std::cout << "> ";
        std::cout << "\033[0m";

        std::getline(std::cin, userInput);

        if (userInput == "1") {
            Download::downloadAudioMacOs();
            break;
        } else if (userInput == "2") {
            Download::downloadVideoMacOs();
            break;
        } else {
            std::system("clear");
            std::cout << "\033[31m";
            std::cout << "Wprowadzono niepoprawna cyferkę!\n";
            std::cout << "\033[0m";
            sleep(1);
            displayWelcomeUI();
        }

    } while (true);
#endif

    return 0;
}