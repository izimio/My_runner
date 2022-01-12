/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_leave.c
*/

#include "../include/my.h"

void clear_sprite(t_render *render)
{
    sfSprite_destroy(render->par->p_clouds->sprite);
    sfSprite_destroy(render->par->p_distant->sprite);
    sfSprite_destroy(render->par->p_front->sprite);
    sfSprite_destroy(render->par->p_near->sprite);
}

void clear_clocks(t_render *render)
{
    sfClock_destroy(render->clocker->jump);
    sfClock_destroy(render->clocker->sprite_mouv);
    sfClock_destroy(render->clocker->sprite_rec);
    sfClock_destroy(render->clocker->transition);
    sfClock_destroy(render->clocker->window_mov);
    sfClock_destroy(render->par->clouds);
    sfClock_destroy(render->par->distant);
    sfClock_destroy(render->par->front);
    sfClock_destroy(render->par->near);
}

void clear_music(t_render *render)
{
    sfMusic_destroy(render->msgame);
    sfMusic_destroy(render->mshub);
    sfSound_destroy(render->mswin);
    sfSound_destroy(render->msdeath);
    sfSound_destroy(render->mscoin);
    sfSoundBuffer_destroy(render->buffer);
    sfSoundBuffer_destroy(render->buffer1);
    sfSoundBuffer_destroy(render->buffer2);
}

void clear_n_leave(t_render *render)
{
    clear_clocks(render);
    clear_sprite(render);
    clear_music(render);
}
