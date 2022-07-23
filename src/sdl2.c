#include "sdl2.h"
#include "grid.h"
#include <stdio.h>
void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return ;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban_ZARE_Alireza", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
      SDL_Quit();
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}
void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

void display_sdl2(struct Grid * grid){
  float x = 0;
  float y = 0;
  float w = context.width /grid->column_number; // Largeur d'une boite.
  float h = context.height / grid->row_number; // Hauteur d'une boite
  SDL_Rect rec;
  SDL_SetRenderDrawColor(context.renderer,126, 126, 126, 255); // On choisit la couleur sable
	SDL_RenderClear(context.renderer);// Efface la cible de rendu actuelle avec la couleur de dessine
  int index_row, index_column;
  for (index_row = 0; index_row < grid->row_number;index_row++)
  {
    for(index_column = 0; index_column< grid->column_number; index_column++){
      char positionActuelle = grid->game_grid[index_row][index_column];
      switch(positionActuelle){
        case WALL:{ // Mur
          SDL_SetRenderDrawColor(context.renderer, 163, 0, 0, 255); // Definir la couleur rouge
          rec.x = x, rec.y = y, rec.w = w, rec.h = h;
          SDL_RenderFillRect(context.renderer, &rec);// remmplir un rectangle sur la cible de rendu
          break;
        }
        case PLAYER:{ // Joueur
          SDL_SetRenderDrawColor(context.renderer,25, 25, 112, 255);// Definir la couleur violet
          rec.x = x, rec.y = y, rec.w = w, rec.h = h;
          SDL_RenderFillRect(context.renderer, &rec); // Remplir un rectangle sur la cible de rendu
          break;
        }
        case BOX:{ // Boîte
          SDL_SetRenderDrawColor(context.renderer,20,94,203,255);
          rec.x = x, rec.y = y, rec.w = w, rec.h = h;
          SDL_RenderFillRect(context.renderer,&rec);
          break;
        }
        case GOAL:{
          SDL_SetRenderDrawColor(context.renderer,20, 203, 81, 255);// Definir la couleur vert
          rec.x = x, rec.y = y, rec.w = w, rec.h = h;
          SDL_RenderFillRect(context.renderer, &rec); // Remplir un rectangle sur la cible de rendu
          break;
        }
        default:
          break;
      }
      x = x + w;// Ajouter la langeur.
    }
    y = y + h; //Ajouter la hauteur.
    x = 0; // Pour éviter de la sortir de la fenétre.
  }
  SDL_RenderPresent(context.renderer);
}


