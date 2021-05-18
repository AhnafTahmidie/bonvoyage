#include "initiateLevelTwoCoins.h"

void Level2CoinsPopup()
{
    
    window.surface = IMG_Load("images/level2obstacles/point.png");

    if (!window.surface)
    {
        printf("coin_point_popup Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoCoinPointPopUp.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);

    if (!levelTwoCoinPointPopUp.tex)
    {
        printf("coin_point_popup Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    levelTwoCoinPointPopUp.rect;
    SDL_QueryTexture(levelTwoCoinPointPopUp.tex, NULL, NULL, &levelTwoCoinPointPopUp.rect.w, &levelTwoCoinPointPopUp.rect.h);
    levelTwoCoinPointPopUp.rect.w = (int)0;
    levelTwoCoinPointPopUp.rect.h = (int)0;
    levelTwoCoinPointPopUp.rect.x = (int)WINDOW_WIDTH / 2;
    levelTwoCoinPointPopUp.rect.y = (int)WINDOW_HEIGHT / 2;
}


 

void LevelTwoCoinsload(void)
{
    window.surface = IMG_Load("images/level2obstacles/coinsprite.png");

    if (!window.surface)
    {
        printf("BOX Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoCoin1.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    levelTwoCoin2.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);

    if (!levelTwoCoin1.tex)
    {
        printf("BOX TEXTURE ERROR%s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    levelTwoCoin1.rect;
    levelTwoCoin2.rect;
    
    SDL_QueryTexture(levelTwoCoin1.tex, NULL, NULL, &levelTwoCoin1.rect.w, &levelTwoCoin1.rect.h);
    SDL_QueryTexture(levelTwoCoin2.tex, NULL, NULL, &levelTwoCoin2.rect.w, &levelTwoCoin2.rect.h);
    
    levelTwoCoin1.rect.w = (int)40;
    levelTwoCoin1.rect.h = (int)40;
    levelTwoCoin1.rect.x = (int) levelTwoBox.rect.x + 50;
    levelTwoCoin1.rect.y = (int) levelTwoBox.rect.y - 70;

    levelTwoCoin2.rect.w = (int)40;
    levelTwoCoin2.rect.h = (int)40;
    levelTwoCoin2.rect.x = (int) levelTwoBox.rect.x + 50;
    levelTwoCoin2.rect.y = (int) levelTwoBox.rect.y - 70;


 
    SDL_QueryTexture(levelTwoCoin1.tex , NULL, NULL, &COIN_TEXTURE_HEIGHT, &COIN_TEXTURE_WIDTH);
    SDL_QueryTexture(levelTwoCoin2.tex , NULL, NULL, &COIN_TEXTURE_HEIGHT, &COIN_TEXTURE_WIDTH);

    int COIN_FRAME_WIDTH = COIN_TEXTURE_WIDTH / 2;
    int COIN_FRAME_HEIGHT =COIN_TEXTURE_HEIGHT / 2;

    levelTwoRotatingCoin.rect.w = (int)COIN_FRAME_WIDTH;
    levelTwoRotatingCoin.rect.h = (int)COIN_FRAME_HEIGHT;
    levelTwoRotatingCoin.rect.x = (int)0;
    levelTwoRotatingCoin.rect.y = (int)0;
 
    Level2CoinsPopup();

}

void LevelTwoCoinsCleanUp()
{
     
 
    // SDL_FreeSurface(levelTwoWindow.level2Coin.surface);
    SDL_DestroyTexture(levelTwoCoin1.tex);
    SDL_DestroyTexture(levelTwoCoin2.tex);
    IMG_Quit();
}

void Level2CoinsPopCleanUp()
{
     
 
    // SDL_FreeSurface(levelTwoWindow.level2Coin.surface);
    SDL_DestroyTexture(levelTwoCoinPointPopUp.tex);
    IMG_Quit();
}

