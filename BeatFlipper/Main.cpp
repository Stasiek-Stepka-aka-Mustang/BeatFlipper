#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "Pobieraj.h"
#include "OutputColors.h"
#include "ZmienneGlobalne.h"

/** Metoda determinuje Homepath na komputerze użytkownika, do którego kopiuje
 * niezbędne do funkcjojnowania programu zasoby tj. ffmpeg i yt-dlp. */
static void okreslSciezke() {
#ifdef _WIN32
    /** Wyznaczenie ścieżki Home na Windowsie, do której kopiowane sa zasoby. */
        const char* homePath = std::getenv("USERPROFILE");
        if (homePath == nullptr) {
            OutputColors::setTextColor(4);
            std::cout << "Wystapil blad, przy wyszukiwaniu sciezki Home, napisz do mnie @prod.mustang!\n";
            OutputColors::setTextColor(7);
        }
        folderPath = std::filesystem::path(homePath) / "Biblioteki";
#else
    /** Wyznaczenie ścieżki Home na MacOs, do której kopiowane są zasoby. Dodatkowo sprawdzam, czy takowy
     * folder już istenieje (do późniejszego użytkowania programu).*/
    const char* homePath = std::getenv("HOME");
    if (homePath == nullptr) {
        std::cout << "\033[31m";
        std::cout << "Wystapil blad, przy wyszukiwaniu sciezki Home, napisz do mnie @prod.mustang!\n";
        std::cout << "\033[0m";
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#endif
}

static void wyswietlInformacje() {
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
    okreslSciezke();

    std::string wyborProgramu;
    #ifdef _WIN32
        wyswietlInformacje();
        do {
            std::cout << "Wybierz co chcesz pobierac (wprowadz cyferke):\n";
            std::cout << "1. Audio.\n";
            std::cout << "2. Video.\n";

            OutputColors::setTextColor(8);
            cout << "> ";
            OutputColors::setTextColor(7);

            std::getline(cin,wyborProgramu);

            if (wyborProgramu == "1") {
                Pobieraj::pobierajAudioWindows();
                break;
            }
            else if (wyborProgramu == "2") {
                Pobieraj::pobierajVideoWindows();
                break;
            }
            else {
                std::system("cls");
                OutputColors::setTextColor(4);
                std::cout << "Wprowadzono niepoprawna cyferke!\n";
                OutputColors::setTextColor(7);
                sleep(1);
                wyswietlInformacje();
            }

        } while (true);
    #else
        wyswietlInformacje();
        do {
            std::cout << "Wybierz co chcesz pobierac (wprowadz cyferke):\n";
            std::cout << "1. Audio.\n";
            std::cout << "2. Video.\n";

            std::cout << "\033[90m";
            cout << "> ";
            std::cout << "\033[0m";

            std::getline(cin,wyborProgramu);

            if (wyborProgramu == "1") {
                Pobieraj::pobierajAudioMacOs();
                break;
            }
            else if (wyborProgramu == "2") {
                Pobieraj::pobierajVideoMacOs();
                break;
            }
            else {
                std::system("clear");
                std::cout << "\033[31m";
                std::cout << "Wprowadzono niepoprawna cyferke!\n";
                std::cout << "\033[0m";
                sleep(1);
                wyswietlInformacje();
            }

        } while (true);
    #endif

    return 0;
}