#include <iostream>
#include <string>
#include <filesystem>
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
            std::cout << "Wystąpił błąd, przy wyszukiwaniu ścieżki Home, napisz do mnie @prod.mustang!\n";
            OutputColors::setTextColor(7);
        }
        folderPath = std::filesystem::path(homePath) / "Biblioteki";
#else
    /** Wyznaczenie ścieżki Home na MacOs, do której kopiowane są zasoby. Dodatkowo sprawdzam, czy takowy
     * folder już istenieje (do późniejszego użytkowania programu).*/
    const char* homePath = std::getenv("HOME");
    if (homePath == nullptr) {
        OutputColors::setTextColor("\033[31m");
        std::cout << "Wystąpił błąd, przy wyszukiwaniu ścieżki Home, napisz do mnie @prod.mustang!\n";
        OutputColors::setTextColor("\033[0m");
    }
    folderPath = std::filesystem::path(homePath) / "Biblioteki";
#endif
}

int main() {
    #ifdef _WIN32
        std::system("cls");
        OutputColors::setTextColor(6);
        std::cout << "> BeatFlipper by Mustang <\n";
        OutputColors::setTextColor(7);
    #else
        std::system("clear");
        OutputColors::setTextColor("\033[33m");
        std::cout << "♫ BeatFlipper by Mustang ♫\n";
        OutputColors::setTextColor("\033[0m");
    #endif



    okreslSciezke();

#ifdef _WIN32
    Pobieraj::pobierajWindows();
    /** Kod, który pozwala na pobieranie kilku plików bez zamykania programu do przyszłej implementacji. */
    /*  std::string input;
    bool flaga = false;
    do {
        if (!flaga) {
            pobierajWin();
            flaga = false;
        }

        std::cout << "Czy chcesz dalej pobrać jeszcze coś (wpisz T albo N)?\n";
        std::cout << "> ";
        std::getline(std::cin,input);

        if (input == "T") {
            std::system("cls");
        }
        else if (input == "N") {
            std::cout << "\033[33m";
            std::cout << "Zamykam program!\n";
            std::cout << "\033[0m";
            break;
        }
        else  {
            std::cout << "\033[31m";
            std::cout << "Wprowadzwono niepoprawną opcję, upewnij się, że wprowadzasz T lub N!\n";
            std::cout << "\033[0m";
            flaga = true;
        }

    } while (true);*/
#else
    Pobieraj::pobierajMacOs();
    /** Kod, który pozwala na pobieranie kilku plików bez zamykania programu do przyszłej implementacji. */
/*   std::string input;
    bool flaga = false;
    do {
        if (!flaga) {
            Pobieraj::pobierajMacOs();
            flaga = false;
        }

        std::cout << "Czy chcesz dalej pobrać jeszcze coś (wpisz T albo N)?\n";
        std::cout << "> ";
        std::getline(std::cin,input);

        if (input == "T") {
            std::system("clear");
            flaga = false;
        }
        else if (input == "N") {
            std::cout << "\033[33m";
            std::cout << "Zamykam program!\n";
            std::cout << "\033[0m";
            flaga = true;
            break;
        }
        else  {
            std::cout << "\033[31m";
            std::cout << "Wprowadzwono niepoprawną opcję, upewnij się, że wprowadzasz T lub N!\n";
            std::cout << "\033[0m";
            flaga = false;
        }

    } while (true);*/
#endif

    return 0;
}