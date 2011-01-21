#include "colisiones.hpp"

namespace Colisiones {

    TColision ColisionGenerica(float ax, float ay, Sint16 aw, Sint16 ah, float bx, float by, Sint16 bw, Sint16 bh) {
        TColision ret;
        ret.col = 0;
        ret.zona = 0;
        bool arr = false, aba = false, izq = false, der = false;
        if ((ay + ah >= by) && (by + (bh / 2) >= ay + ah)) { //por arriba
            arr = true;
        }
        if ((by + bh > ay) && (by + (bh / 2) < ay)) { //por abajo
            aba = true;
        }
        if ((bx + bw >= ax) && (bx + (bw / 2) <= ax)) {//por la derecha
            der = true;
        }
        if ((ax + aw > bx) && (bx + (bw / 2) > ax + aw)) { //por la izquierda
            izq = true;
        }
        if ((ay + ah >= by) && (by + bh > ay) && (bx + bw >= ax) && (ax + aw > bx)) {
            ret.col = 1;
        }
        if (aba && der) {
            ret.zona = 1;
            //            ret.col = 1;
        } else if (aba && izq) {
            ret.zona = 2;
            //            ret.col = 1;
        } else if (arr && der) {
            ret.zona = 3;
            //            ret.col = 1;
        } else if (arr && izq) {
            ret.zona = 4;
            //            ret.col = 1;
        }

        return ret;
    }
}