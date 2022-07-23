#include "event.h"

Event event(){
Event action;
  unsigned entry = fgetc(stdin);
  switch(entry){
      case 'q':
        return Quit;
        break;
      case 'l':
        action = Top;
        break;
      case 'j':
        action = Bottom;
        break;
      case 'k':
        action = Left;
        break;
      case 'h':
        action = Right;
        break;
      default:
        action = None;
        break;
  }
  return action;
}

Event event_sdl2(){
  SDL_Event event;
  Event action;
  SDL_WaitEvent(&event);
  switch (event.type)
  {
    case SDL_QUIT :{
      action = Quit;
      break;
    }
    case SDL_KEYUP: 
    switch (event.key.keysym.sym)
    {
      case SDLK_UP:{
        action  = Top;
        break;
      }
      case SDLK_DOWN: {
        action = Bottom;
        break;
      }
      case SDLK_RIGHT: {
        action = Right;
        break;
      }
      case SDLK_LEFT: {
        action = Left;
        break;
      }
      default :{
        action = None;
      }
    }
  }
  return action;
}