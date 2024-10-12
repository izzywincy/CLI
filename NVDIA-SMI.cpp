#include <ncurses.h>
#include <string>
#include <iomanip>

void printBar() {
    attron(COLOR_PAIR(1)); 
    printw("|");
    attroff(COLOR_PAIR(1)); 
}

void printGPUInfo() {
    attron(COLOR_PAIR(1));  // Use color pair 1 for GPU info
    printw("+--------------------------------------------------------------------------------------------+\n");
    printw("| NVIDIA-SMI 551.86                  Driver Version: 551.86            CUDA Version: 12.4    |\n");
    printw("+------------------------------------------+--------------------------+----------------------+\n");
    attroff(COLOR_PAIR(1));  // Turn off color pair 1
    printBar();
    attron(COLOR_PAIR(2));   // Use color pair 2 for other info
    printw(" GPU  Name                      TCC/WDDM  "); printBar(); printw(" Bus-Id            Disp-A "); printBar();
    printw(" Volatile Uncorr. ECC "); printBar(); printw("\n");
    printBar(); printw(" Fan  Temp  Perf            Pwr:Usage/Cap "); printBar(); printw("             Memory-Usage ");
    printBar(); printw(" GPU-Util  Compute M. "); printBar(); printw("\n");
    printBar(); printw("                                          "); printBar();
    printw("                          "); printBar(); printw("               MIG M. "); printBar(); printw("\n");
    attroff(COLOR_PAIR(2));  // Turn off color pair 2
    attron(COLOR_PAIR(1));  // Turn off color pair 2
    printw("|==========================================+==========================+======================|\n");
    attroff(COLOR_PAIR(1));  // Turn off color pair 2
}

std::string truncateProcessName(const std::string& name) {
    if (name.length() > 15) return name.substr(0, 12) + "...";
    return name;
}

void printProcesses() {
    attron(COLOR_PAIR(1));  // Use color pair 1 for process list
    printw("+--------------------------------------------------------------------------------------------+\n");
    printw("| Processes:                                                                                 |\n");
    printw("| GPU    GI    CI     PID     TYPE     Process Name                               GPU Memory |\n");
    printw("|        ID    ID                                                                 Usage      |\n");
    printw("|============================================================================================|\n");

    attroff(COLOR_PAIR(1));  // Turn off color pair 1
    attron(COLOR_PAIR(2));   // Use color pair 2 for process details
    for (int i = 1; i <= 5; ++i) {
        std::string processName = "Dummy Process " + std::to_string(i);
        printBar();
        printw("  0     N/A   N/A   %d     C/C++    %-15s                              N/A      ",
               i * 1000, truncateProcessName(processName).c_str());
        printBar(); printw("\n");
    }
    attroff(COLOR_PAIR(2));  // Turn off color pair 2

    attron(COLOR_PAIR(1));   // Use color pair 1 for footer
    printw("+--------------------------------------------------------------------------------------------+\n");
    attroff(COLOR_PAIR(1));
}

int main() {
    // Initialize ncurses
    initscr();            // Start ncurses mode
    start_color();        // Enable colors
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Color pair 1: Green text on black background
    init_pair(2, COLOR_WHITE, COLOR_BLACK);  // Color pair 2: White text on black background

    printGPUInfo();
    printProcesses();

    refresh();  // Refresh to show the content on screen
    getch();    // Wait for user input
    endwin();   // End ncurses mode

    return 0;
}
