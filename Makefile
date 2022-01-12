##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## yo
##

SRCS =	src/project_csfml_main.c \
		src/project_csfml_utils.c \
		src/project_csfml_utils_2.c \
		src/project_csfml_basic_utils.c \
		src/project_csfml_basic_utils_2.c \
		src/project_csfml_init_struct.c \
		src/my_runner_init_struct_2.c \
		src/my_runner_init_struct3.c \
		src/project_csfml_run_window.c \
		src/project_csfml_event.c \
		src/my_runner_smalls_event.c \
		src/my_runner_draw_sk_stage2.c \
		src/project_csfml_clockers.c \
		src/project_csfml_leave.c \
		src/project_csfml_split.c \
		src/my_runner_cust_character.c \
		src/my_runner_draw_stage_sub1.c \
		src/my_runner_sk_draw_stagesub2.c \
		src/my_runner_draw_stage_sub2.c \
		src/my_runner_draw_stage1.c \
		src/my_runner_draw_stage2.c \
		src/my_runner_parralax.c \
		src/my_runner_parralax_clocker.c \
		src/parsing/my_runner_get_map.c \
		src/parsing/my_runner_infinit_get.c \
		src/parsing/my_runner_read.c \
		src/parsing/my_runner_highscore.c \
		src/parsing/my_runner_print_map.c \
		src/physics/my_runner_gravity.c \
		src/infinity/my_runner_concat_maps.c \
		src/infinity/my_strjoin.c \

OBJS = ${SRCS:.c=.o}

NAME = my_runner

CC = gcc

RM = rm -f

CSFMLFAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

CRITERION_F = --coverage -lcriterion -I include

${NAME}:	${OBJS}
			${CC} -o ${NAME}  ${OBJS} ${CSFMLFAGS}

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	${CC} -o unit_tests my_putchar.c tests/*.c ${CRITERION_F}

tests_run: test_criterion
	./unit_tests

.PHONY: all clean fclean re
