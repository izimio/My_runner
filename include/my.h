/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** oui
*/

#ifndef _MY_H_
    #define _MY_H_
    #define _MY_H_
    #include "stddef.h"
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/ConvexShape.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/FontInfo.h>
    #include <SFML/Graphics/Glyph.h>
    #include <SFML/Graphics/Image.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/RenderTexture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Shader.h>
    #include <SFML/Graphics/Shape.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Transformable.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Graphics/VertexArray.h>
    #include <SFML/Graphics/VertexBuffer.h>
    #include <SFML/Graphics/View.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Window.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    typedef struct s_boy {
        sfSprite *sprite;
        sfIntRect rect;
        int alive;
        int jump;
        int fast;
        int trig;
        sfVector2f pos;
    } t_boy;
    typedef struct s_each_coord {
        char id;
        int x;
        int y;
    } t_each_coord;
    typedef struct s_parralax_sprite {
        int width;
        sfSprite *sprite;
        sfIntRect rect;
    } t_parralax_sprite;
    typedef struct s_parralax {
        t_parralax_sprite *p_distant;
        t_parralax_sprite *p_near;
        t_parralax_sprite *p_clouds;
        t_parralax_sprite *p_front;
        sfClock *distant;
        sfClock *front;
        sfClock *near;
        sfClock *clouds;
    } t_parralax;
    typedef struct s_clocks {
        sfClock *sprite_rec;
        sfClock *sprite_mouv;
        sfClock *window_mov;
        sfClock *jump;
        sfClock *transition;
        sfClock *animations;
        sfClock *music;
        sfClock *coin;
    } t_clocks;
    typedef struct s_text {
        sfSprite *stone;
        sfSprite *rock;
        sfSprite *grass;
        sfSprite *grass1;
        sfSprite *float1;
        sfSprite *wood;
    } t_text;
    typedef struct s_infinit {
        char **m1;
        char **m3;
        char **m4;
        char **m5;
        char **m6;
        char **m7;
        char **m2;
        char **m8;
        char **m9;
        char **m10;
    } t_infinit;
    typedef struct s_render {
        int game;
        int deaths;
        int trig;
        int infinity;
        int trans_sign;
        sfVector2f pos_sign;
        int fast;
        float volum;
        int x_coord;
        int map_h;
        int map_x;
        int x_towin;
        char *high;
        int changing_state;
        int pop_anim;
        int nb_of_coins;
        float pop_state;
        float gravity;
        char *mapp;
        t_text *text;
        sfIntRect skin_rec;
        sfIntRect coin_rec;
        sfSprite *skin_granny;
        sfSprite *skin_blob;
        sfSprite *skin_meat;
        sfSprite *skin_steve;
        sfSprite *sign;
        sfSprite *coin;
        sfSprite *skull;
        sfSprite *grave;
        sfText *play;
        sfText *customize;
        sfText *coins_txt;
        sfText *percent;
        sfText *polecho;
        sfText *death_txt;
        sfText *resume;
        sfText *home;
        sfText *highscore;
        sfText *replay;
        sfText *quit;
        sfText *back;
        sfText *pause;
        sfFont *font;
        sfMusic *mshub;
        sfSoundBuffer *buffer;
        sfSoundBuffer *buffer1;
        sfSoundBuffer *buffer2;
        sfSound *msdeath;
        sfSound *mscoin;
        sfSound *mswin;
        sfMusic *msgame;
        t_clocks *clocker;
        t_parralax *par;
        sfView *view;
        sfRenderWindow *win;
        sfVector2u screen;
        t_boy *boy;
        t_each_coord **map;
    } t_render;
    /* basics */
    int my_getnbr(char *str);
    int get_coin_nb(char *s);
    int my_strlen(char *s, int flag);
    void my_putstr(char *str);
    int in_charset(char c, char *charset);
    char *my_itoa(int n);
    int my_strcmp(char *s1, char *s2);
    char *my_strdup(char *src);
    char *my_strcat(char *dest, char *src);
    int count_int_len(int nb);
    int my_getnbr(char *str);
    char **my_split(char *str, char *charset);
    /* csfml basics */
    sfSprite *load_sprite(char *s, int flag);
    sfIntRect get_rect(int left, int top, int width, int height);
    sfFloatRect get_rectf(int left, int top, int width, int height);
    sfVector2f get_pos(int x, int y);
    sfVector2f get_posf(float x, float y);
    sfBool is_clicked_sprite(sfRenderWindow *window, sfSprite *sprite);
    sfBool is_clicked_txt(sfRenderWindow *window, sfText *txt);
    void init_sprite(t_render *render);
    void more_inits(t_render *render);
    /* inits */
    void customize_chara(t_render *render, char *str);
    t_render *init_render(sfRenderWindow *window, char **argv, t_render *r);
    void init_txt(t_render *render);
    t_parralax *init_parralax_big(t_render *render);
    void init_music(t_render *render);
    void init_txt_template(t_render *r, int size, char *c, sfText *txt);
    void fix_origin(t_render *render);
    void create_the_map(t_render *r, char *file, int i, int j);
    void create_the_map_inf(t_render *r, char *s, int i, int j);
    /* drawing windows */
    void draw_ground(t_render *render);
    void draw_window(sfRenderWindow *window, t_render *render, sfEvent e);
    void run_window(
    sfRenderWindow *window, sfEvent event, char **av, t_render *render);
    char *write_on_file(char *str, char *score, t_render *render);
    void print_the_map(t_render *render, sfRenderWindow *win);
    void my_useles_stage_2(t_render *render);
    void infinit_handler(t_render *render);
    /* drawing stages */
    void draw_stage_one(sfRenderWindow *window, t_render *r, sfEvent e);
    void draw_stage_two(t_render *render , sfEvent event);
    void draw_stage_mineone(sfRenderWindow *window, t_render *render);
    void draw_stage_mintwo(
    sfRenderWindow *window, t_render *render, sfEvent event);
    /* animations */
    void clock_sign(t_render *render);
    void clock_reverse_sign(t_render *render);
    void clock_pop(t_render *render);
    void clock_pop_reverse(t_render *render);
    void music_transition(sfMusic *music, int flag, float *v, t_render *r);
    /* other draws */
    void print_percent(t_render *render);
    void draw_parralax(sfRenderWindow *window, t_render *render);
    /* events handler */
    void reset_game(t_render *render);
    void reddit(t_render *render, sfText *txt, sfEvent event);
    void analyse_events(sfRenderWindow *window, sfEvent event, t_render *r);
    /* clocks */
    void clocker(sfRenderWindow *window, t_render *render);
    void clock_all_sprites(t_render *render);
    /* maths and more */
    void gravity(t_render *render);
    void collision(t_render *render);
    int is_on_floor(t_render *render);
    void fix_coin_nb(t_render *render);
    void reset_map(t_render *render);
    char *concat_double_tab(void);
    int get_percent(t_render *render);
    char *my_strjoin(int size, char **strs, char *sep);
    /* maps */
    char *my_get_map_in_str(char *str);
    int check_map(char *s, char *name, t_render *render);
    /* leaving */
    void clear_n_leave(t_render *render);
#endif
