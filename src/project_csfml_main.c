/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_main.c
*/

#include "../include/my.h"

void read_any_file(char *path)
{
    char c;
    int fd = open(path, O_RDONLY);

    while (read(fd, &c, 1))
        write(1, &c, 1);
}

int my_usage(int argc, char **argv, char *path)
{
    char c;
    int fd = open("assets/my_usage.txt", O_RDONLY);

    if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == 'h' && !argv[1][2])) {
        read_any_file(path);
        return (0);
    }
    if (argc != 2)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    sfVideoMode m = {1280, 720, 32};
    sfRenderWindow *w;
    sfEvent event;
    t_render *render = malloc(sizeof(t_render));
    char *s;

    if (!my_usage(argc, argv, "assets/usage_n_errors/my_usage.txt"))
        return 84;
    render->infinity = (!my_strcmp("-i", argv[1]) ? 1 : 0);
    s = !render->infinity ? my_get_map_in_str(argv[1]) : NULL;
    if ((!s || !argv[1] || !check_map(s, argv[1], render)) &&
    !render->infinity) {
        read_any_file("assets/usage_n_errors/wrong_map.txt");
        return (84);
    }
    w = sfRenderWindow_create(m, "Super meat bros", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 240);
    init_render(w, argv, render);
    run_window(w, event, argv, render);
    return 0;
}
