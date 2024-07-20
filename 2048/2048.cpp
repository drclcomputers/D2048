#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

long long V[4][4];

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* zero;
SDL_Texture* n0;
SDL_Texture* n1;
SDL_Texture* n2;
SDL_Texture* n3;
SDL_Texture* n4;
SDL_Texture* n5;
SDL_Texture* n6;
SDL_Texture* n7;
SDL_Texture* n8;
SDL_Texture* n9;
SDL_Texture* n10;
SDL_Texture* n11;
SDL_Texture* n12;
SDL_Texture* n13;
SDL_Texture* n14;
SDL_Texture* n15;
SDL_Texture* n16;
SDL_Texture* n17;
SDL_Texture* n18;
SDL_Texture* n19;
SDL_Texture* n20;
SDL_Texture* n21;
SDL_Texture* n22;
SDL_Texture* n23;
SDL_Texture* n24;
SDL_Texture* n25;
SDL_Texture* n26;
SDL_Texture* n27;
SDL_Texture* n28;
SDL_Texture* n29;
SDL_Texture* n30;
SDL_Texture* n31;
SDL_Texture* n32;

bool board_full() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!V[i][j]) return 0;
    return 1;
}

bool valid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (V[i][j] == 0) return 1;
            if (i < 4 - 1 && V[i][j] == V[i + 1][j]) return 1;
            if (j < 4 - 1 && V[i][j] == V[i][j + 1]) return 1;
        }
    }
    return 0;
}

void get_random(int& i, int& j) {
    if (!board_full())
        do {
            i = rand() % 4;
            j = rand() % 4;
        } while (V[i][j] != 0);
}

void init();
void play();
void render();

int WinMain() {
	init();
	play();
	return 0;
}

void init() {
	srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("D2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    surface = IMG_Load("0.png");
    zero = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1.png");
    n0 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2.png");
    n1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("4.png");
    n2 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("8.png");
    n3 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("16.png");
    n4 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("32.png");
    n5 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("64.png");
    n6 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("128.png");
    n7 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("256.png");
    n8 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("512.png");
    n9 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1024.png");
    n10 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2048.png");
    n11 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("4096.png");
    n12 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("8192.png");
    n13 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("16384.png");
    n14 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("32768.png");
    n15 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("65536.png");
    n16 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("131072.png");
    n17 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("262144.png");
    n18 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("524288.png");
    n19 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1048576.png");
    n20 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2097152.png");
    n21 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("4194304.png");
    n22 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("8388608.png");
    n23 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("16777216.png");
    n24 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("33554432.png");
    n25 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("67108864.png");
    n26 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("2^27.png");
    n27 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2^28.png");
    n28 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2^29.png");
    n29 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2^30.png");
    n30 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2^31.png");
    n31 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("2^32.png");
    n32 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1.png");
    n0 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("1.png");
    n0 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

}

void play() {
    bool quit = 0, key_pressed = 0;
	int i, j;

	get_random(i, j);
	V[i][j] = 1;

    SDL_Event e;

	while (!quit) {
        if (!valid() && board_full()) {
            SDL_SetWindowTitle(window, "Game Over! Press 'r' to restart.");
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = 1;
                    break;
                }
                else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                    case SDLK_q:
                        quit = 1;
                        break;
                    case SDLK_r:
                        SDL_SetWindowTitle(window, "D2048");
                        for (int i = 0; i < 4; i++)
                            for (int j = 0; j < 4; j++)
                                V[i][j] = 0;
                        get_random(i, j);
                        V[i][j] = 1;
                    }
                }
            }
        }
        else {

            get_random(i, j);
            V[i][j] = 1;

            render();

            key_pressed = 0;

            while (!key_pressed) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        key_pressed = 1;
                        quit = 1;
                        break;
                    }
                    else if (e.type == SDL_KEYDOWN) {
                        key_pressed = 1;
                        switch (e.key.keysym.sym) {
                        case SDLK_q:
                            quit = 1;
                            break;
                        case SDLK_UP:
                            for (int h = 0; h < 4; h++) {
                                int temp[4] = { 0 }, l = 0;
                                for (int k = 0; k < 4; k++)
                                    if (V[k][h] != 0)
                                        temp[l++] = V[k][h];
                                for (int k = 0; k < 3; k++)
                                    if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                        temp[k] *= 2;
                                        temp[k + 1] = 0;
                                    }
                                l = 0;
                                for (int k = 0; k < 4; k++)
                                    if (temp[k] != 0)
                                        V[l++][h] = temp[k];
                                while (l < 4)
                                    V[l++][h] = 0;
                            }
                            break;
                        case SDLK_DOWN:
                            for (int h = 0; h < 4; h++) {
                                int temp[4] = { 0 }, l = 0;
                                for (int k = 3; k >= 0; k--)
                                    if (V[k][h] != 0)
                                        temp[l++] = V[k][h];
                                for (int k = 0; k < 3; k++)
                                    if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                        temp[k] *= 2;
                                        temp[k + 1] = 0;
                                    }
                                l = 0;
                                for (int k = 3; k >= 0; k--)
                                    if (temp[k] != 0)
                                        V[3 - (l++)][h] = temp[k];
                                while (l < 4)
                                    V[3 - (l++)][h] = 0;
                            }
                            break;
                        case SDLK_LEFT:
                            for (int h = 0; h < 4; h++) {
                                int temp[4] = { 0 }, l = 0;
                                for (int k = 0; k < 4; k++)
                                    if (V[h][k] != 0)
                                        temp[l++] = V[h][k];
                                for (int k = 0; k < 3; k++)
                                    if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                        temp[k] *= 2;
                                        temp[k + 1] = 0;
                                    }
                                l = 0;
                                for (int k = 0; k < 4; k++)
                                    if (temp[k] != 0)
                                        V[h][l++] = temp[k];
                                while (l < 4)
                                    V[h][l++] = 0;
                            }
                            break;
                        case SDLK_RIGHT:
                            for (int h = 0; h < 4; h++) {
                                int temp[4] = { 0 }, l = 0;
                                for (int k = 3; k >= 0; k--)
                                    if (V[h][k] != 0)
                                        temp[l++] = V[h][k];
                                for (int k = 0; k < 3; k++)
                                    if (temp[k] == temp[k + 1] && temp[k] != 0) {
                                        temp[k] *= 2;
                                        temp[k + 1] = 0;
                                    }
                                l = 0;
                                for (int k = 3; k >= 0; k--)
                                    if (temp[k] != 0)
                                        V[h][3 - (l++)] = temp[k];
                                while (l < 4)
                                    V[h][3 - (l++)] = 0;
                            }
                            break;
                        case SDLK_r:
                            for (int i = 0; i < 4; i++)
                                for (int j = 0; j < 4; j++)
                                    V[i][j] = 0;
                            get_random(i, j);
                            V[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
}

void render() {
    SDL_RenderClear(renderer);

    SDL_Rect patrat;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            patrat = { j * 100, i * 100, 100, 100 };
            switch (V[i][j]) {
            case 0:
                SDL_RenderCopy(renderer, zero, NULL, &patrat);
                break;
            case 1:
                SDL_RenderCopy(renderer, n0, NULL, &patrat);
                break;
            case 2:
                SDL_RenderCopy(renderer, n1, NULL, &patrat);
                break;
            case 4:
                SDL_RenderCopy(renderer, n2, NULL, &patrat);
                break;
            case 8:
                SDL_RenderCopy(renderer, n3, NULL, &patrat);
                break;
            case 16:
                SDL_RenderCopy(renderer, n4, NULL, &patrat);
                break;
            case 32:
                SDL_RenderCopy(renderer, n5, NULL, &patrat);
                break;
            case 64:
                SDL_RenderCopy(renderer, n6, NULL, &patrat);
                break;
            case 128:
                SDL_RenderCopy(renderer, n7, NULL, &patrat);
                break;
            case 256:
                SDL_RenderCopy(renderer, n8, NULL, &patrat);
                break;
            case 512:
                SDL_RenderCopy(renderer, n9, NULL, &patrat);
                break;
            case 1024:
                SDL_RenderCopy(renderer, n10, NULL, &patrat);
                break;
            case 2048:
                SDL_RenderCopy(renderer, n11, NULL, &patrat);
                break;
            case 4096:
                SDL_RenderCopy(renderer, n12, NULL, &patrat);
                break;
            case 8192:
                SDL_RenderCopy(renderer, n13, NULL, &patrat);
                break;
            case 16384:
                SDL_RenderCopy(renderer, n14, NULL, &patrat);
                break;
            case 32768:
                SDL_RenderCopy(renderer, n15, NULL, &patrat);
                break;
            case 65536:
                SDL_RenderCopy(renderer, n16, NULL, &patrat);
                break;
            case 131072:
                SDL_RenderCopy(renderer, n17, NULL, &patrat);
                break;
            case 262144:
                SDL_RenderCopy(renderer, n18, NULL, &patrat);
                break;
            case 524288:
                SDL_RenderCopy(renderer, n19, NULL, &patrat);
                break;
            case 1048576:
                SDL_RenderCopy(renderer, n20, NULL, &patrat);
                break;
            case 2097152:
                SDL_RenderCopy(renderer, n21, NULL, &patrat);
                break;
            case 4194304:
                SDL_RenderCopy(renderer, n22, NULL, &patrat);
                break;
            case 8388608:
                SDL_RenderCopy(renderer, n23, NULL, &patrat);
                break;
            case 16777216:
                SDL_RenderCopy(renderer, n24, NULL, &patrat);
                break;
            case 33554432:
                SDL_RenderCopy(renderer, n25, NULL, &patrat);
                break;
            case 67108864:
                SDL_RenderCopy(renderer, n26, NULL, &patrat);
                break;
            case 134217728:
                SDL_RenderCopy(renderer, n27, NULL, &patrat);
                break;
            case 268435456:
                SDL_RenderCopy(renderer, n28, NULL, &patrat);
                break;
            case 536870912:
                SDL_RenderCopy(renderer, n29, NULL, &patrat);
                break;
            case 1073741824:
                SDL_RenderCopy(renderer, n30, NULL, &patrat);
                break;
            case 2147483648:
                SDL_RenderCopy(renderer, n31, NULL, &patrat);
                break;
            case 4294967296:
                SDL_RenderCopy(renderer, n32, NULL, &patrat);
                break;
            }
        }
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(33);
}