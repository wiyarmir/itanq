
#include "boton.h"

Boton::Boton(SDL_Surface *p, const char *bi, const char *ba, int bx, int by) {
    Uint32 colorkey;
    pantalla = p;
    bOFF = IMG_Load(bi);
    bOFF = SDL_DisplayFormat(bOFF);
    colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
    SDL_SetColorKey(bOFF, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    bON = IMG_Load(ba);
    bON = SDL_DisplayFormat(bON);
    colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
    SDL_SetColorKey(bON, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    x = bx;
    y = by;
}

Boton::~Boton() {
    SDL_FreeSurface(bOFF);
    SDL_FreeSurface(bON);
}

bool Boton::encima(Uint16 rx, Uint16 ry) {
    bool ret;
    ret = (rx > x && rx < (x + bOFF->w) && ry > y && ry < (y + bOFF->h));
    return ret;
}

void Boton::ponX(Uint16 dx) {
    x = dx;
}

void Boton::ponY(Uint16 dy) {
    y = dy;
}

void Boton::dibujate(SDL_Surface *p, Uint16 rx, Uint16 ry) {
    SDL_Rect dest; // Destino de la imagen en la pantalla
    dest.x = x;
    dest.y = y;
    dest.w = bOFF->w;
    dest.h = bOFF->h;
    if (encima(rx, ry)) {
        SDL_BlitSurface(bON, NULL, p, &dest);
    } else {
        SDL_BlitSurface(bOFF, NULL, p, &dest);
    }
}

