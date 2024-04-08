#include <string>
#include <iostream>
#include <unistd.h>
#include "../include/Download.h"
#include "../include/OutputColors.h"
#include "../include/GlobalVariables.h"

/* Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników MacOs (sprawdzane na MacOs Ventura i Monterey). */
void Download::downloadAudioMacOs() {
    std::string link;
    std::string outputPath;

    std::system("clear");
    std::cout << "Wprowadź link do Beat'u:\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadź, gdzie ma się pobrać Beat (ścieżka):\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, outputPath);

    std::string command = '"' + folderPath.string() + "/yt-dlp_macos" + '"' +
                          " -f bestaudio -x --audio-format wav --ffmpeg-location " + '"' + folderPath.string() + '"' +
                          " --no-playlist --quiet --ignore-errors --output "
                          + "'" + outputPath + "/%(title)s.%(ext)s'" + " \"" + link + "\"";

    std::cout << command << '\n';

    // Usunięcie outputu z YT-DLP.
    // command += " > /dev/null";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    std::cout << "\n";
    std::cout << "\033[92m";
    std::cout << "Pobrano plik!\nOkno zamknie się automatycznie za 3 sekundy :)";
    std::cout << "\033[0m";
    sleep(3);
}

/* Metoda pobiera wyznaczony przez użytkownika Filmik, natywnie wybiera format mp4,
 * z Audio w codecu m4a/wav, w zależności od dostępnego formatu, metoda strice pod MacOs/Unix. */
void Download::downloadVideoMacOs() {
    std::string link;
    std::string outputPath;

    std::system("clear");
    std::cout << "Wprowadź link do Filmiku:\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadź, gdzie ma się pobrać filmik (ścieżka):\n";

    std::cout << "\033[90m";
    std::cout << "> ";
    std::cout << "\033[0m";
    std::getline(std::cin, outputPath);

    std::string command = '"' + folderPath.string() + "/yt-dlp_macos" + '"' +
                          " -S ext:mp4:m4a --no-playlist --output "
                          + "'" + outputPath + "/%(title)s.%(ext)s'" + " \"" + link + "\"";

    // Usunięcie outputu z YT-DLP.
    command += " > /dev/null";

    std::cout << "\n";
    std::cout << command << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    std::cout << "\n";
    std::cout << "\033[92m";
    std::cout << "Pobrano plik!\nOkno zamknie się automatycznie za 3 sekundy :)";
    std::cout << "\033[0m";
    sleep(15);
}

/* Metoda pobiera wyznaczony przez użytkownika Bit, metoda jak sama nazwa wskazuje
 * zdefiniowana stricte pod użytkowników Windows (sprawdzane na Windowsie 10 oraz 11). */
void Download::downloadAudioWindows() {
#ifdef _WIN32
    std::string link;
    std::string outputPath;

    std::system("cls");
    std::cout << "Wprowadz link do Beat'u:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma sie pobrac Beat (sciezka):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputPath);

    std::string command = "\"\"" + folderPath.string() + "\\yt-dlp.exe" + "\"" +
                          " -f bestaudio -x --audio-format wav --no-playlist --output "
                          + "\"" + outputPath + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    std::cout << "\n";
    std::cout << "Pobieram plik...\n";

    std::system(command.c_str());

    std::cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nOkno zakmnie sie automatycznie za 3 sekundy :)";
    OutputColors::setTextColor(7);
    sleep(3);
}

#endif
}

/* Metoda pobiera wyznaczony przez użytkownika Filmik, natywnie wybiera format mp4,
 * z Audio w kodeku m4a/wav, w zależności od dostępnego formatu, metoda stricte pod Windows. */
void Download::downloadVideoWindows() {
#ifdef _WIN32
    std::string link;
    std::string outputPath;

    std::system("cls");
    std::cout << "Wprowadz link do Filmiku:\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, link);

    std::cout << "\n";
    std::cout << "Wprowadz, gdzie ma sie pobrac filmik (sciezka):\n";

    OutputColors::setTextColor(8);
    std::cout << "> ";
    OutputColors::setTextColor(7);
    std::getline(std::cin, outputPath);

    std::string command = "\"\"" + folderPath.string() + "\\yt-dlp.exe" + "\"" +
                          " -S ext:mp4:m4a --no-playlist --output "
                          + "\"" + outputPath + "\\%(title)s.%(ext)s\" " + "\"" + link + "\" > NUL\"";

    cout << "\n";
    std::cout << "Pobieram plik...\n";
    std::cout << "Przy dluzszych filmikach moze potrwac to chwilke dluzej!\n";

    std::system(command.c_str());

    cout << "\n";
    OutputColors::setTextColor(10);
    std::cout << "Pobrano plik!\nOkno zamknie sie automatycznie za 3 sekundy :)";
    OutputColors::setTextColor(7);
    sleep(3);
#endif
}
