
#include <SDL/SDL_image.h>

#include "cifra.h"

Cifra::Cifra(const char* pic, Uint8 cmax, Sint16 lax, Sint16 lay) {
    x = lax;
    y = lay;
    img = IMG_Load(pic);
    src = NULL;
    nact = 0;
    nant = 0;
    cifmax = cmax;
}

Cifra::Cifra(const Cifra& orig) { }

Cifra::~Cifra() {
    SDL_FreeSurface(img);
}

void Cifra::dibujate(SDL_Surface* pantalla) {
    if (src == NULL || nact != nant) {
        actImg(pantalla);
        nant = nact;
    }
    if (src != NULL) {
        SDL_Rect sitio;
        sitio.x = x;
        sitio.y = y;
        sitio.h = h;
        sitio.w = w;
        SDL_BlitSurface(src, NULL, pantalla, &sitio);
    }
}

void Cifra::actImg(SDL_Surface *pantalla) {
    char* cad = new char[cifmax + 1];
    cad[cifmax] = '\0';
    int i = cifmax - 1;
    int n = nact;
    char c;
    while (i >= 0) {
        switch (n % 10) {
            case 0: c = '0';
                break;
            case 1: c = '1';
                break;
            case 2: c = '2';
                break;
            case 3: c = '3';
                break;
            case 4: c = '4';
                break;
            case 5: c = '5';
                break;
            case 6: c = '6';
                break;
            case 7: c = '7';
                break;
            case 8: c = '8';
                break;
            case 9: c = '9';
                break;
        }
        cad[i] = c;
        n /= 10;
        i--;
    }
#    ifdef DEB
    cout << "cifra>actImg>cad=" << cad << endl;
#    endif
    i = 0;
    SDL_Rect numero, poscifra;
    numero.h = imgh;
    numero.w = imgw;
    numero.y = 0;
    poscifra.h = imgh;
    poscifra.w = imgw;
    poscifra.y = 0;
    SDL_Surface *temp = SDL_CreateRGBSurface(SDL_HWSURFACE, imgw*cifmax, imgh, 32, 0, 0, 0, 0);
    while (i < cifmax) {
        switch (cad[i]) {
            case '0':
                numero.x = 0;
                break;
            case '1':
                numero.x = imgw;
                break;
            case '2':
                numero.x = 2 * imgw;
                break;
            case '3':
                numero.x = 3 * imgw;
                break;
            case '4':
                numero.x = 4 * imgw;
                break;
            case '5':
                numero.x = 5 * imgw;
                break;
            case '6':
                numero.x = 6 * imgw;
                break;
            case '7':
                numero.x = 7 * imgw;
                break;
            case '8':
                numero.x = 8 * imgw;
                break;
            case '9': numero.x = 9 * imgw;
                break;
        }
        poscifra.x = i*imgw;
        SDL_BlitSurface(img, &numero, temp, &poscifra);
        i++;
    }
    delete[] cad;
    temp = SDL_DisplayFormat(temp);
    Uint32 colorkey = SDL_MapRGB(pantalla->format, 0, 0, 0);
    SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    if (src != NULL) {
        SDL_BlitSurface(temp, NULL, src, NULL);
        SDL_FreeSurface(temp);
    } else {
        src = temp;
    }

}

void Cifra::incrementa() {
    nact++;
}

void Cifra::resetea() {
    nact = 0;
}
