#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
#include "player.h"


void init_level(const char* file_path, Grid *g){
	// ouverture du fichier en mode lecture
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;/// nombre de Goal
	// struct Player p;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	g->column_number=number_column;
	g->row_number=number_row;
	g->goal_number = number_goals;
	g->game_grid=(CaseType**)malloc(sizeof(CaseType*)* g->row_number);
	for (int i = 0; i < g->row_number; i++)
	{
		g->game_grid[i]=(CaseType*)malloc(sizeof(CaseType)*g->column_number);

	}
	
	int current_row = 0;
	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			g->game_grid[current_row][current_column]=*buffer;
			if(*buffer==PLAYER){
				g->player.x = current_row;
				g->player.y = current_column;
			}
			current_column += 1;
			buffer+=1;
		}		 
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
}






void display(Grid *g){
for (int i = 0; i < g->row_number; i++)
{
	for (int j = 0; j < g->column_number; j++)
	{
		printf("%c",g->game_grid[i][j]);
	}
	printf("\n");
	
}
}

void free_all(Grid* f ){
	for (int i = 0; i < f->row_number; i++)
	{
		free(f->game_grid[i]);
	}
	free(f->game_grid);
}