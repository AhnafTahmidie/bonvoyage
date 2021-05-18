#include "initiateCoinsEffect.h"

void coinseffectload(void)
{
    //sky
    for (int i = 0; i < 5; i++)
    {
        window.surface = IMG_Load("images/levelone/100.png");

        if (!window.surface)
        {
            printf("coinseffect[i]_BUTTON Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelOneWindowCoinsEffect[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!levelOneWindowCoinsEffect[i].tex)
        {
            printf("coins[i]effects_  Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(levelOneWindowCoinsEffect[i].tex, NULL, NULL, &levelOneWindowCoinsEffect[i].rect.w, &levelOneWindowCoinsEffect[i].rect.h);
        levelOneWindowCoinsEffect[i].rect.w = (int)0;
        levelOneWindowCoinsEffect[i].rect.h = (int)0;
        levelOneWindowCoinsEffect[i].rect.x = (int)0;
        levelOneWindowCoinsEffect[i].rect.y =  levelOneWindowCoins[i].rect.y;
    }
}

void coinseffectCleanUp()
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(levelOneWindowCoinsEffect[i].tex);
    }

    IMG_Quit();
}