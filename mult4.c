#include <stdio.h>
#include "genpat.h"

#define step 400000LL
#define delay 400000LL

char intToStr(inteiro)
int inteiro; {
    charstr;
    str = (char) mbkalloc(32sizeof(char));
    sprintf(str, "%d", inteiro);

    return (str);
}

int main() {
    int i;
    int j;
    int k;
    int time = 0;
    int cout = 0;

    DEF_GENPAT("mult4_genpat");
    DECLAR("a", ":2", "X", IN, "3 downto 0", "");
    DECLAR("b", ":2", "X", IN, "3 downto 0", "");
    DECLAR("product", ":2", "X", OUT, "7 downto 0", "");
    DECLAR("cout", ":2", "B", OUT, "", "");
    DECLAR("vdd", ":2", "B", IN, "", "");
    DECLAR("vss", ":2", "B", IN, "", "");

    LABEL("multiplicacao");
    AFFECT("0", "vdd", "0b1");
    AFFECT("0", "vss", "0b0");

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            k = i*j;
            AFFECT(intToStr(time), "a", intToStr(i));
            AFFECT(intToStr(time), "b", intToStr(j));
            time += delay;
            AFFECT(intToStr(time), "product", intToStr(k&0xf));

            if (k < 9) {
                AFFECT(intToStr(time), "cout", "0");
            } else {
                AFFECT(intToStr(time), "cout", "1");
                time += step;
            }
        }
    }

    SAV_GENPAT();

    return 0;
}
