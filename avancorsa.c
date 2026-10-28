#include <stdio.h>
#include <math.h>



int main()
{
    int PolliciRuota;
    float DiametroC, Raggio1C, Raggio2C, RaggioC, RaggioCPilota, OffSet, Caster, L, H, Pressione, Errore;
    float Avancorsa, AvancorsaPilota, AvancorsaReale;
    float CasterRad;
    float DiffAnt, DiffPost, Interasse;
    char Risposta;


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
    CasterRad = Caster * (3.141 / 180);

    //calcolo avancorsa
    Avancorsa = ((RaggioC * sin(CasterRad)) - OffSet) / cos(CasterRad);

    printf("\n");
    printf("La tua avancorsa e': %g mm\n", Avancorsa);

    printf("\n");
    printf("Vuoi calcolare l'avancorsa con il tuo peso? [Y/N]\n");
    printf("(ti serviranno delle misure fatte a mano)\n");
    scanf(" %c", &Risposta);

    if (Risposta == 'Y' || Risposta == 'y')
    {
        printf("Inserisci l'affondamento in millimetri delle sospensioni anteriori: ");
        scanf("%g", &DiffAnt);

        printf("Inserisci l'affondamento in millimetri delle sospensioni posteriori: ");
        scanf("%g", &DiffPost);

        printf("Inserisci la misura dell'interasse in millimetri: ");
        scanf("%g", &Interasse);

        AvancorsaPilota = Avancorsa + (((DiffPost - DiffAnt) / Interasse) * RaggioC);

        printf("Inserisci la pressione in bar del tuo pneumatico anteriore: ");
        scanf("%g", &Pressione);

        if (Pressione >= 2.25 && Pressione <= 2.5)
        {
            AvancorsaReale = AvancorsaPilota - 4;
            printf("La tua avancorsa compresa del tuo peso misura circa: %g\n", AvancorsaReale);
        }
        else if (Pressione >= 2.05 && Pressione <= 2.25)
        {
            AvancorsaReale = AvancorsaPilota - 6;
            printf("La tua avancorsa compresa del tuo peso misura circa: %g\n", AvancorsaReale);
        }
        else if (Pressione >= 1.9 && Pressione <= 2.05)
        {
            AvancorsaReale = AvancorsaPilota - 9;
            printf("La tua avancorsa compresa del tuo peso misura circa: %g\n", AvancorsaReale);
        }
        else 
        {
            printf("Non posso aiutarti a calcolare la tua Avnacorsa con il tuo peso sommato.\n");
        }
    }

    else 
    {
    printf("Okk! Buon divertimento!\n");
    }

return 0;
}