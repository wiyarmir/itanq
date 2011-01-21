/* 
 * File:   objeto.cpp
 * Author: guillermo
 * 
 * Created on 8 de mayo de 2009, 10:51
 */
enum TipoObjeto {
    INVISIBLE, OBSTACULO, RECOGIBLE
};

#include "objeto.h"

Objeto::Objeto() {
    img = NULL;
    inicializado = false;
}

Objeto::Objeto(SDL_Surface *pantalla, const char* pic, Uint16 iw, Uint16 ih, float lax, float lay, Uint16 i_f, Uint16 i_c) {
    img_fil = i_f;
    img_col = i_c;
    img = IMG_Load(pic);
    img = SDL_DisplayFormat(img);
    Uint32 colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
    SDL_SetColorKey(img, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    h = corte.h = ih;
    w = corte.w = iw;
    x = lax;
    y = lay;
    inicializado = true;
}

Objeto::Objeto(const Objeto& orig) {
#    ifdef DEB
    cout << "Constructor copia: Objeto" << endl;
#    endif
    img_fil = orig.img_fil;
    img_col = orig.img_col;
    if (orig.img != NULL) {
        this->img = creaSuperficieVacia(orig.img->w, orig.img->h);
        SDL_BlitSurface(orig.img, NULL, this->img, NULL);
        //        Uint32 colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
        //        SDL_SetColorKey(img, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    } else {
        img = NULL;
    }
    h = corte.h = orig.h;
    w = corte.w = orig.w;
    x = orig.x;
    y = orig.y;
    inicializado = orig.inicializado;
}

void Objeto::inicializa(SDL_Surface *pantalla, const char* pic, Uint16 iw, Uint16 ih, float lax, float lay, Uint16 i_f, Uint16 i_c) {
#    ifdef DEB
    cout << "inicializa: objeto" << endl;
#    endif
    img_fil = i_f;
    img_col = i_c;
    if (img != NULL) {
#        ifdef DEB
        cout << "habia algo, libero " << img << endl;
#        endif
        SDL_FreeSurface(img);
    }
    img = IMG_Load(pic);
    img = SDL_DisplayFormat(img);
#    ifdef DEB
    cout << "he creado en " << img << endl;
#    endif
    Uint32 colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
    SDL_SetColorKey(img, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    h = corte.h = ih;
    w = corte.w = iw;
    x = lax;
    y = lay;
    inicializado = true;
#    ifdef DEB
    cout << "objeto inicializado" << endl;
#    endif
}

Objeto::~Objeto() {
#    ifdef DEB
    cout << "destructor: objeto" << endl;
#    endif
    if (img != NULL) {
#        ifdef DEB
        cout << "libero " << img << endl;
#        endif
        SDL_FreeSurface(img);
        img = NULL;
    }
}

void Objeto::dibujate(SDL_Surface *pantalla) {
#    ifdef DEB
    cout << "Clase objeto: dibujate" << endl;
#    endif
    if (inicializado) {
        SDL_Rect sitio;
        corte.x = corte.w * img_col;
        corte.y = corte.h * img_fil;
        sitio.x = (int) x;
        sitio.y = (int) y;
        sitio.h = corte.h;
        sitio.w = corte.w;
        SDL_BlitSurface(this->img, &corte, pantalla, &sitio);
    } else {
#        ifdef DEB
        cout << "Objeto no inicializado!" << endl;
#        endif
    }
}

SDL_Surface* creaSuperficieVacia(int w, int h) {
    SDL_Surface *basis = SDL_GetVideoSurface();
    basis = SDL_CreateRGBSurface(basis->flags, w, h,
            basis->format->BitsPerPixel,
            basis->format->Rmask,
            basis->format->Gmask,
            basis->format->Bmask,
            basis->format->Amask);
    return basis;
}