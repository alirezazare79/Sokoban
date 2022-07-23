#include "SDL2/SDL.h"
#include "grid.h"
#include "player.h"
#include "sdl2.h"
#include "event.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void aide(){
	printf("aide: \n Appuyez sur 'l' pour le haut\n Appuyez sur 'k' pour la gauche\n Appuyez sur 'j' pour le bas\n Appuyez sur 'h' pour la droite\n Appuyez sur 'q' pour quiter\n");
}

Event (*handle_event)() = &event_sdl2;
void (*display_handler)(Grid* game_grid) = &display_sdl2;

int main(int argc, char **argv) {
  bool sdl2 = argc > 1 && strcmp(argv[1], "sdl") != 0;
  if (sdl2)
    sdl_init();
  
  Grid game_grid;
  Event (*event_handler)() = sdl2 ? handle_event : event;
  void (*display_handler)(struct Grid *) =
      sdl2 ? display_sdl2 : display;
  bool run = true;
  init_level("./levels/level1.txt", &game_grid);
  display_handler(&game_grid);
  while (run) {
    switch (event_handler()) {
		case Quit:
			run = false;
			break;
		case Top: {
			move_player(&game_grid, TOP);
			system("clear");
			point_cible(&game_grid);
			aide();
			break;
		}
		case Right: {
			move_player(&game_grid, RIGHT);
			system("clear");
			point_cible(&game_grid);
			aide();
		  break;
		}
		case Bottom: {
			move_player(&game_grid, BOTTOM);
			system("clear");
			point_cible(&game_grid);
			aide();
			break;
		}
		case Left: {
			move_player(&game_grid, LEFT);
			system("clear");
			point_cible(&game_grid);
			aide();
			break;
		}
		case None: break;
    }
	system("clear");
    display_handler(&game_grid);
	aide();
  }
  free_all(&game_grid);
  if (sdl2)
    sdl_quit();
}

