#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include "grid.h"
typedef struct Grid Grid;


/**
 * @struct 
 * @brief Cette structure contient les positions x , y
 */

struct Player
{
    int x;// La position x
    int y;// La position y
};

struct Goal
{
	int x;// La position x
    int y;// La position y
};


/**
 * @enum 
 * @brief Cet enum contient les éléments incluent les déplacement,
 * vers la gauche,le bas,le haut,la droit
 */
typedef enum {
	TOP = 'l',
	LEFT = 'k',
	BOTTOM = 'j',
	RIGHT = 'h',
	
} Direction;

/**
* @brief la fonction pour les movements de player
* @param *g , d
* movement de player
*/

void move_player(Grid *g,Direction d);



/**
* @brief la fonction pour le fin de jeu
* @param *g 
* condition de fin de jeu
*/
void point_cible(Grid *g);

#endif