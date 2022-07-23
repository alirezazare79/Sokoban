#pragma once
#include "SDL2/SDL.h"
#include "grid.h"
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;
/* @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
SDLContext context;



/**
* @brief la fonction de initialiser le SDL2
* @param void
* initialiser le SDL2
*/
void sdl_init();
/**
 * nettoie la variable global context 
 */





/**
* @brief la fonction de arreter le SDL2
* @param void
* arreter le SDL2
*/
void sdl_quit();


/**
* @brief la fonction qui prend en paramètre la grille à afficher et qui va afficher le niveau mais avec la SDL2
* @param *g 
* afficher le niveau  avec la SDL2
*/
void display_sdl2(struct Grid * grid);

SDL_KeyboardEvent key;



/**
 * @enum 
 * @brief  L'enum Event devra comporter 6 champs (Quit, Left, Right, Up, Down, None).
 */
typedef enum {
  Top,
  Bottom,
  Left,
  Right,
  Quit,
  None,
} Event;




