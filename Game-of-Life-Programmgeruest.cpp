#include <iostream>

#define CIMGGIP_MAIN
#include "CImgGIP08.h"

using namespace std;
using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30;  // size der einzelnen Kaestchen (in Pixel)
const int border = 20;    // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

unsigned char* gip_rgb(int r, int g, int b) {
    static unsigned char color[3];
    color[0] = (unsigned char)r;
    color[1] = (unsigned char)g;
    color[2] = (unsigned char)b;
    return color;
}
// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

int count_live_neighbors(bool grid[][grid_size], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_x = x + i;
            int neighbor_y = y + j;

            if (neighbor_x >= 0 && neighbor_x < grid_size && neighbor_y >= 0 && neighbor_y < grid_size) {
                if (!(i == 0 && j == 0) && grid[neighbor_x][neighbor_y]) {
                    count++;
                }
            }
        }
    }
    return count;
}
int main()
{
    bool grid[grid_size][grid_size] = { 0 };
    bool next_grid[grid_size][grid_size] = { 0 };

    // Erstes Grid vorbelegen ...
    grid_init(grid);

    while (gip_window_not_closed())
    {
        gip_white_background();
        gip_stop_updates();
        // Spielfeld anzeigen ...
		// gip_stop_updates(); // ... schaltet das Neuzeichnen nach jeder Bildschirmänderung aus

        // TO DO

        for (int y = 0; y < grid_size; ++y) {
            for (int x = 0; x < grid_size; ++x) {
                if(grid[x][y]){
                    gip_draw_rectangle(border + x * box_size, border + y * box_size,
                                       border + (x + 1) * box_size, border + (y + 1) * box_size,
                                       gip_rgb(0, 255, 1)); // Draw a black rectangle for live cells
                }else{
                    gip_draw_rectangle(border + x * box_size, border + y * box_size,
                                       border + (x + 1) * box_size, border + (y + 1) * box_size,
                                       gip_rgb(255, 255, 255));
                }
            }
        }

		// gip_start_updates(); // ... alle Bildschirmänderungen (auch die nach dem gip_stop_updates() ) wieder anzeigen
        gip_start_updates();
        gip_sleep(1);

        for (int y = 0; y < grid_size; y++) {
            for (int x = 0; x < grid_size; x++) {
                int live_neighbors = count_live_neighbors(grid, x, y);

                if (grid[x][y]) {

                    if (live_neighbors < 2 || live_neighbors > 3) {
                        next_grid[x][y] = false;
                    } else {
                        next_grid[x][y] = true;
                    }
                } else {
                    if (live_neighbors == 3) {
                        next_grid[x][y] = true;
                    } else {
                        next_grid[x][y] = false;
                    }
                }
            }
        }

// Copy the next state into the current grid
        for (int y = 0; y < grid_size; y++) {
            for (int x = 0; x < grid_size; x++) {
                grid[x][y] = next_grid[x][y];
            }
        }



    }
    return 0;
}

void grid_init(bool grid[][grid_size])
{
    int eingabe = -1;
    do {
        cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
            << "0 - Zufall" << endl
            << "1 - Statisch" << endl
            << "2 - Blinker" << endl
            << "3 - Oktagon" << endl
            << "4 - Gleiter" << endl
            << "5 - Segler 1 (Light-Weight Spaceship)" << endl
            << "6 - Segler 2 (Middle-Weight Spaceship)" << endl
            << "? ";
        cin >> eingabe;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (eingabe < 0 || eingabe > 6);

    if (eingabe == 0)
    {


        for (int y = 0; y < grid_size; y++) {
            for (int x = 0; x < grid_size; x++) {
                grid[x][y] = gip_random(0, 1);
            }
        }


    }
    else if (eingabe == 1)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] = 
        {
            { '.', '*', '.' },
            { '*', '.', '*' },
            { '.', '*', '.' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+3] = true;
    }
    else if (eingabe == 2)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] =
        {
            { '.', '*', '.' },
            { '.', '*', '.' },
            { '.', '*', '.' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+3] = true;
    }
    else if (eingabe == 3)
    {
        const int pattern_size = 8;
        char pattern[pattern_size][pattern_size] =
        {
            { '.', '.', '.', '*', '*', '.', '.', '.' },
            { '.', '.', '*', '.', '.', '*', '.', '.' },
            { '.', '*', '.', '.', '.', '.', '*', '.' },
            { '*', '.', '.', '.', '.', '.', '.', '*' },
            { '*', '.', '.', '.', '.', '.', '.', '*' },
            { '.', '*', '.', '.', '.', '.', '*', '.' },
            { '.', '.', '*', '.', '.', '*', '.', '.' },
            { '.', '.', '.', '*', '*', '.', '.', '.' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+1] = true;
    }
    else if (eingabe == 4)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] =
        {
            { '.', '*', '.' },
            { '.', '.', '*' },
            { '*', '*', '*' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+3] = true;
    }
    else if (eingabe == 5)
    {
        const int pattern_size = 5;
        char pattern[pattern_size][pattern_size] =
        {
            { '*', '.', '.', '*', '.' },
            { '.', '.', '.', '.', '*' },
            { '*', '.', '.', '.', '*' },
            { '.', '*', '*', '*', '*' },
            { '.', '.', '.', '.', '.' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+3] = true;
    }
    else if (eingabe == 6)
    {
        const int pattern_size = 6;
        char pattern[pattern_size][pattern_size] =
        {
            { '.', '*', '*', '*', '*', '*' },
            { '*', '.', '.', '.', '.', '*' },
            { '.', '.', '.', '.', '.', '*' },
            { '*', '.', '.', '.', '*', '.' },
            { '.', '.', '*', '.', '.', '.' },
            { '.', '.', '.', '.', '.', '.' },
        };
        for (int y = 0; y < pattern_size; y++) 
            for (int x = 0; x < pattern_size; x++) 
                if (pattern[y][x] == '*') 
                    grid[x][y+3] = true;
    }
}
