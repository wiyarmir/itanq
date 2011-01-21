#ifndef _BOTON_H_
#define _BOTON_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Boton {
public:
    Boton(SDL_Surface *p, const char *bi, const char *ba, int x, int y);
    ~Boton();
    bool encima(Uint16 rx, Uint16 ry);
    void ponX(Uint16 x);
    void ponY(Uint16 y);
    // Pone el Boton en pantalla teniendo en cuenta si está el ratón sobre él
    void dibujate(SDL_Surface *p, Uint16 rx, Uint16 ry);
private:
    SDL_Surface *pantalla;
    SDL_Surface *bOFF; // Imagen del Boton activo
    SDL_Surface *bON; // Imagen del Boton inactivo
    // Coordenadas del Boton en la pantalla
    int x, y;
    bool activo;

};

#endif
