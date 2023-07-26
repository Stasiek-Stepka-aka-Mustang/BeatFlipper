#include <string>
#include <iostream>
#include "Pobieraj.h"
#include "OutputColors.h"
#include "ZmienneGlobalne.h"

/** Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników MacOs (sprawdzane na MacOs Ventura i Monterey).*/
void Pobieraj::pobierajMacOs() {
    std::string link;
    std::cout << "Wprowadź link do Beat'u:\n";
    std::cout << "▶ ";
    std::getline(std::cin, link);

    std::string outputSciezka;
    std::cout << "Wprowadź, gdzie ma się pobrać Beat (ścieżka):\n▶ ";
    std::getline(std::cin, outputSciezka);

    std::string command = '"' + folderPath.string()+"/yt-dlp_macos" + '"' +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "'" + outputSciezka + "/%(title)s.%(ext)s'" + " 'ytsearch:" + link + "'";

    /** Usunięcie outputu z YT-DLP. */
    command += " > /dev/null";


    std::cout << "Pobieram plik!\n";
    std::cout << "\033[0m";
    std::system(command.c_str());
    std::cout << "\033[32m";
    std::cout << "Pobrano plik!\n";
    std::cout << "\033[0m";
}

/** Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników Windows (sprawdzane na Windowsie 10 oraz 11).*/
void Pobieraj::pobierajWindows() {
    std::string link;
    std::cout << "Wprowadz link do Beat'u:\n";
    std::cout << "> ";
    std::getline(std::cin, link);

    std::string outputSciezka;
    std::cout << "Wprowadz, gdzie ma się pobrac Beat (sciezka):\n> ";
    std::getline(std::cin, outputSciezka);

    std::string command = "\"\"" + folderPath.string()+"\\yt-dlp.exe" + "\"" +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "\"" + outputSciezka + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    OutputColors::setTextColor(4);
    std::cout << "Pobieram plik!\n";
    OutputColors::setTextColor(7);
    std::system(command.c_str());
    OutputColors::setTextColor(2);
    std::cout << "Pobrano plik!\n";
    OutputColors::setTextColor(7);
}
