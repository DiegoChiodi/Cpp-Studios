#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

struct Vector2
{
    double x, y;
};

using Point = Vector2; 

class Entity
{
protected:
    Point pos;
    double speed;
    SDL_Rect rect;
public:
    Entity(SDL_Rect _rect, double _speed){
        this->rect = _rect;
        this->pos = {static_cast<double>(_rect.x), static_cast<double>(_rect.y)};
        this->speed = _speed;
    }
    virtual void update(double& delta_time) = 0;
    const SDL_Rect& get_rect() const
    {
        return this->rect;
    }
};

class Player : public Entity
{
public:
    Player(SDL_Rect _rect, double _speed) : Entity(_rect, _speed) {
    }

    void update(double& delta_time) override {
        this->rect.x = static_cast<int>(this->pos.x);
        this->rect.y = static_cast<int>(this->pos.y);
    }

    void handle_events(double& delta_time, const Uint8*& keyboard)
    {
        if (keyboard[SDL_SCANCODE_A])
        {
            this->pos.x -= (speed * delta_time);
        }
    
        if (keyboard[SDL_SCANCODE_D])
        {
            this->pos.x += (speed * delta_time);
        }

        if (keyboard[SDL_SCANCODE_W])
        {
            this->pos.y -= (speed * delta_time);
        }

        if (keyboard[SDL_SCANCODE_S])
        {
            this->pos.y += (speed * delta_time);
        }
    }
};



void update(double &delta_time, const Uint8*& keyboard, vector<Entity*> entities)
{
    for (Entity* entity : entities)
    {
        if (Player* player = dynamic_cast<Player*>(entity))
        {
            player->handle_events(delta_time, keyboard);
        }
        entity->update(delta_time);
    }
}

void render(SDL_Renderer*& renderer, vector<Entity*> entities)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    for (Entity* entity : entities)
    {
        SDL_RenderFillRect(renderer, &entity->get_rect());
    }

    SDL_RenderPresent(renderer);
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    double delta_time = 0.0;
    Uint32 lastTick = SDL_GetTicks();


    bool running = true;

    //World creation
    vector<Entity*> entities;

    
    /*Player player = Player({100, 100, 50, 50}, 200.0);
    Player player_2 = Player({200, 200, 50, 50}, 200.0);
    entities.push_back(&player);
    entities.push_back(&player_2);8*/

    // Cada Player funciona como um "pixel" do coração
    // Ajuste o tamanho/espaçamento se quiser um coração maior ou menor

    const int size = 50;
    const int spacing = 55;

    std::vector<Player> heartPlayers;
    heartPlayers.reserve(100);

    std::vector<std::string> heart = {
        "01100110",
        "11111111",
        "11111111",
        "11111111",
        "01111110",
        "00111100",
        "00011000"
    };

    int startX = 300;
    int startY = 100;

    for (int y = 0; y < heart.size(); y++)
    {
        for (int x = 0; x < heart[y].size(); x++)
        {
            if (heart[y][x] == '1')
            {
                heartPlayers.push_back(
                    Player(
                        {
                            startX + x * spacing,
                            startY + y * spacing,
                            size,
                            size
                        },
                        200.0
                    )
                );

                entities.push_back(&heartPlayers.back());
            }
        }
    }

    while(running)
    {
        SDL_Event event;
        const Uint8* keyboard = SDL_GetKeyboardState(NULL);

        while(SDL_PollEvent(&event))
        {   
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        Uint32 currentTick = SDL_GetTicks();
        delta_time = (currentTick - lastTick) / 1000.0;
        lastTick = currentTick;
 
        update(delta_time, keyboard, entities);
        render(renderer, entities);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

