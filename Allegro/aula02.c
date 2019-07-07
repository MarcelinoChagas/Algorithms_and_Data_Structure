#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h> // Inserir desenhos primitivos
#include <allegro5/allegro_font.h> // funcoes para utilizar textos
#include <allegro5/allegro_ttf.h> // para ler tipo de fonte
#include <allegro5/events.h>
#include <allegro5/keyboard.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(){

    bool done = false;
    float altera_y = 0;
    float altera_line = 0;

    // Objetos do allegro
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;


    if(!al_init())
        return -1;   // Erro ao inicializar o allegro

    display = al_create_display(WIDTH, HEIGHT);

    // Para Inicializar Addons do Allegro
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();

    if(!display)
        return -1;

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue , al_get_keyboard_event_source());

    font = al_load_font("angelina.ttf",20,0); // Carregar a fonte

   while(!done){

       ALLEGRO_EVENT ev;
       al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                altera_y -= 10;
                altera_line -= 2;
            }
        }
        if(ev.type == ALLEGRO_EVENT_KEY_UP){
            if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
                altera_y += 10;
                altera_line += 2;
            }
        }

       al_clear_to_color(al_map_rgb(255, 255, 255)); // Coloca a cor da janela
                        //400       //300                       //200                   //200
       al_draw_line(WIDTH/2, HEIGHT/2 + altera_y,WIDTH/4 + altera_y, HEIGHT/3,al_map_rgb(0,0,0),0);
       al_draw_text(font, al_map_rgb(0,0,0),300 + altera_line,250 + altera_line,ALLEGRO_ALIGN_INTEGER, "40 KM");

       al_draw_filled_circle(WIDTH/2, HEIGHT/2 + altera_y, 30, al_map_rgb(0,0,0));
       al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2 + altera_y, ALLEGRO_ALIGN_CENTRE, "Recife");

       al_draw_filled_circle(WIDTH/4 + altera_y, HEIGHT/3, 30, al_map_rgb(0,0,0));
       al_draw_text(font, al_map_rgb(255,255,255), WIDTH/4 + altera_y, HEIGHT/3, ALLEGRO_ALIGN_CENTRE, "Cabo");
       al_flip_display(); // Para exibir Display
    }


    al_destroy_display(display);
    al_destroy_font(font);
    al_destroy_event_queue(event_queue);

    return 0;
}
