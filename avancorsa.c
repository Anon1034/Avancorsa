#include <stdio.h>
#include <math.h>

//Inclusione pigreco per calcolare l'angolo in radianti
#ifndef Pi
#define Pi 3.141
#endif


int main()
{
    int PolliciRuota;
    float DiametroC, Raggio1C, OffSet, Caster, RaggioC, Raggio2C, L, H;
    float Avancorsa;
    float CasterRad;


    printf("Inserisci le specifiche del tuo pneumatico (separate da uno spazio): ");
    scanf("%f %f %d", &L, &H, &PolliciRuota);

    printf("Inserisci l'angolo del canotto di sterzo (o angolo di Caster): ");
    scanf("%g", &Caster);

    if (Caster > 32)
    {
        Caster = 90 - Caster;
    }

    printf("Inserisci l'OffSet piastra: ");
    scanf("%g", &OffSet);


    Raggio1C = (PolliciRuota * 25.4) / 2;
    Raggio2C = L * (H / 100);
    RaggioC = Raggio1C + Raggio2C;
    //printf("Il tuo raggio e': %g mm\n", RaggioC);

    //calcolo Caster in radianti
    CasterRad = Caster * (Pi / 180);

    //calcolo avancorsa
    Avancorsa = ((RaggioC * sin(CasterRad)) - OffSet) / cos(CasterRad);

    printf("\n");
    printf("La tua avancorsa e': %g mm\n", Avancorsa);


return 0;
}