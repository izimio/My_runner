/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_init_struct_2.c
*/

#include "../include/my.h"

void init_txt_template(t_render *render, int size, char *content, sfText *txt)
{
    sfText_setString(txt, content);
    sfText_setFont(txt, render->font);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, size);
}

void init_txt(t_render *render)
{
    render->font = sfFont_createFromFile("assets/font/meat-boy-font.otf");
    render->play = sfText_create();
    render->customize = sfText_create();
    render->quit = sfText_create();
    render->back = sfText_create();
    render->death_txt = sfText_create();
    render->pause = sfText_create();
    render->resume = sfText_create();
    render->replay = sfText_create();
    render->home = sfText_create();
    init_txt_template(render, 70, "PLAY", render->play);
    init_txt_template(render, 40, "CUSTOMIZE", render->customize);
    init_txt_template(render, 40, "QUIT", render->quit);
    init_txt_template(render, 60, "RESUME", render->resume);
    init_txt_template(render, 40, "BACK", render->back);
    init_txt_template(render, 30, "0", render->death_txt);
    init_txt_template(render, 110, "PAUSE", render->pause);
    init_txt_template(render, 60, "REPLAY", render->replay);
    init_txt_template(render, 60, "HOME", render->home);
    more_inits(render);
}

void fix_origin(t_render *render)
{
    sfSprite_setOrigin(render->skin_blob, get_pos(35, 37));
    sfSprite_setOrigin(render->skin_steve, get_pos(35, 37));
    sfSprite_setOrigin(render->skin_granny, get_pos(35, 37));
    sfSprite_setOrigin(render->skin_meat, get_pos(35, 37));
    sfSprite_setOrigin(render->coin, get_pos(26, 24));
}

void init_sprite_game(t_render *render)
{
    t_text *t = malloc(sizeof(t_render));
    t->grass = load_sprite("assets/grass.png", 0);
    t->grass1 = load_sprite("assets/grass1.png", 0);
    t->float1 = load_sprite("assets/float1.png", 0);
    t->rock = load_sprite("assets/rock.png", 0);
    t->stone = load_sprite("assets/stone.png", 0);
    t->wood = load_sprite("assets/wood.png", 0);
    render->text = t;
}

void init_music(t_render *render)
{
    render->buffer1 = sfSoundBuffer_createFromFile("assets/musics/death.ogg");
    render->buffer2 = sfSoundBuffer_createFromFile("assets/musics/coin.ogg");
    render->msgame = sfMusic_createFromFile("assets/musics/soundtrack.ogg");
    sfMusic_setLoop(render->msgame, sfTrue);
    sfMusic_setVolume(render->msgame, 60);
    render->mshub = sfMusic_createFromFile("assets/musics/hub.ogg");
    sfMusic_setLoop(render->mshub, sfTrue);
    sfMusic_setVolume(render->mshub, 60);
    render->mswin = sfSound_create();
    render->msdeath = sfSound_create();
    render->mscoin = sfSound_create();
    render->buffer = sfSoundBuffer_createFromFile("assets/musics/win.ogg");
    sfSound_setBuffer(render->mswin, render->buffer);
    sfSound_setBuffer(render->msdeath, render->buffer1);
    sfSound_setBuffer(render->mscoin, render->buffer2);
    init_sprite_game(render);
}
