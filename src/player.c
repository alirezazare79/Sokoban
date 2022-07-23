#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"
#include "sdl2.h"


void point_cible(Grid *g){
    if(g->goal_number == 0){
        printf("\nBien jeu,Vous avez gagné et réussi à mettre toutes les cases en place 🏆\n");
        exit(1);
    }  
}



void move_player(Grid *g,Direction d){

    if (d == TOP)
    {
        if (g->player.x-1 >= 0 && g->game_grid[g->player.x-1][g->player.y]!=WALL)
        {
            if(g->game_grid[g->player.x-1][g->player.y]!=BOX)
            {
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x-1][g->player.y] = PLAYER;
                g->player.x--;                
            }
            else{
                if(g->player.x-1 >= 0 && g->game_grid[g->player.x-2][g->player.y]!=WALL){
                if (g->game_grid[g->player.x-2][g->player.y] == GOAL )
                {
                    g->goal_number--;
                }
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x-1][g->player.y] = PLAYER;
                g->game_grid[g->player.x-2][g->player.y] = BOX;
                g->player.x--;
                if (g->player.x == g->goal.x && g->player.y == g->goal.y)
                {
                g->game_grid[g->player.x][g->player.y] = GOAL;
                g->game_grid[g->player.x-1][g->player.y] = PLAYER;
                g->game_grid[g->player.x-2][g->player.y] = BOX;
                g->player.x--;
                    }
                }
            } 
        } 
    }
     if (d == BOTTOM)
    {
        if (g->player.x+1 >= 0 && g->game_grid[g->player.x+1][g->player.y]!=WALL)
        {
            if(g->game_grid[g->player.x+1][g->player.y]!=BOX)
            {
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x+1][g->player.y] = PLAYER;
                g->player.x++;                 
            }
            else{
                  if(g->player.x-1 >= 0 && g->game_grid[g->player.x+2][g->player.y]!=WALL){
                 if (g->game_grid[g->player.x+2][g->player.y] == GOAL)
                {
                    g->goal_number--;
                }
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x+1][g->player.y] = PLAYER;
                g->game_grid[g->player.x+2][g->player.y] = BOX;
                g->player.x++;
                
                }

            }
        }
    }
     if (d == LEFT)
    {
        if (g->player.y-1 >= 0 && g->game_grid[g->player.x][g->player.y-1]!=WALL)
        {
            if(g->game_grid[g->player.x][g->player.y-1]!=BOX)
            {
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x][g->player.y-1] = PLAYER;
                g->player.y--;                
            }
            else{
                if(g->player.y+1 >= 0 && g->game_grid[g->player.x][g->player.y-2]!=WALL){
                    if (g->game_grid[g->player.x][g->player.y-2] == GOAL )
                {
                    g->goal_number--;
                }
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x][g->player.y-1] = PLAYER;
                g->game_grid[g->player.x][g->player.y-2] = BOX;
                g->player.y--;
                
                } 
            }
        }
    }
    if (d == RIGHT)
    {
        if (g->player.y-1 >= 0 && g->game_grid[g->player.x][g->player.y+1]!=WALL)
        {
            if(g->game_grid[g->player.x][g->player.y+1]!=BOX)
            {
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x][g->player.y+1] = PLAYER;
                g->player.y++;                
            }
            else
            {
            if(g->player.y-1 >= 0 && g->game_grid[g->player.x][g->player.y+2]!=WALL){
                 if (g->game_grid[g->player.x][g->player.y+2] == GOAL)
                {
                    g->goal_number--;
                }
                g->game_grid[g->player.x][g->player.y] = NONE;
                g->game_grid[g->player.x][g->player.y+1] = PLAYER;
                g->game_grid[g->player.x][g->player.y+2] = BOX;
                g->player.y++;
                
                } 
            }
            
        }
    }
}