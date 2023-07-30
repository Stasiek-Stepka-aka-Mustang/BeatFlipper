#include <string>
#include <iostream>
#include <unistd.h>
#include "Pobieraj.h"
#include "OutputColors.h"
#include "ZmienneGlobalne.h"

/** Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników MacOs (sprawdzane na MacOs Ventura i Monterey).*/
void Pobieraj::pobierajAudioMacOs() {
    std::string link;
    std::string outputSciezka;

    std::system("clear");
    std::cout << "Wprowadz link do Beat'u:\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma się pobrac Beat (sciezka):\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, outputSciezka);

    std::string command = '"' + folderPath.string()+"/yt-dlp" + '"' +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "'" + outputSciezka + "/%(title)s.%(ext)s'" + " 'ytsearch:" + link + "'";

    /** Usunięcie outputu z YT-DLP. */
    command += " > /dev/null";

    cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    cout << "\n";
    std::cout << "\033[92m";
    std::cout << "Pobrano plik!\nOkno zakmnie sie automatycznie za 3 sekundy :)";
    std::cout << "\033[0m";

    sleep(3);

}

void Pobieraj::pobierajVideoMacOs() {
    // do implementacji...
}
/** Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników Windows (sprawdzane na Windowsie 10 oraz 11).*/
void Pobieraj::pobierajAudioWindows() {
    std::string link;
    std::string outputSciezka;

    std::system("cls");
    std::cout << "Wprowadz link do Beat'u:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma się pobrac Beat (sciezka):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputSciezka);

    std::string command = "\"\"" + folderPath.string()+"\\yt-dlp.exe" + "\"" +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "\"" + outputSciezka + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nOkno zakmnie sie automatycznie za 3 sekundy :)";
    OutputColors::setTextColor(7);
    sleep(3);
}

void Pobieraj::pobierajVideoWindows() {
    std::string link;
    std::string outputSciezka;

    std::system("cls");
    std::cout << "Wprowadz link do Filmiku:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma się pobrac Filmik (sciezka):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputSciezka);

    std::string command = "\"\"" + folderPath.string()+"\\yt-dlp.exe" + "\"" +
                          " -S ext:mp4:m4a --no-playlist --output "
                          + "\"" + outputSciezka + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    cout << "\n";
    std::cout << "Pobieram plik...\n";
    std::cout << "Przy dluzszych filmikach moze potrwac to chwilke dluzej!\n";

    std::system(command.c_str());

    cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nOkno zakmnie sie automatycznie za 3 sekundy :)";
    OutputColors::setTextColor(7);
    sleep(3);
}
