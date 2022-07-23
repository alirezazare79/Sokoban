#ifndef GRID_HEADER
#define GRID_HEADER
#include "player.h"
/**
 * @enum 
 * @brief Cet enum contient les éléments incluent les joueurs,
 * le box ,player,wall,goal,..
 */

typedef enum {
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
} CaseType;
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
	int goal_number; //< Nombre de Goals
	int* goal_position;
	struct Player player;
	struct Goal goal;
	int counter;

} Grid;

/**
* @brief la fonction de lecture de fichier
* @param *file_path , *g 
*/
void init_level(const char* file_path, Grid *g);

/**
* @brief Elle permet d'afficher le niveau
* @param g
* afficher le niveau
*/
void display(Grid *g);


/**
* @brief Libère un bloc alloué par `malloc', `realloc' ou `calloc'.
* @param *f
* Libère un bloc
*/
void free_all(Grid* f );

#endif
