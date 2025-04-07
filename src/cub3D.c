/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/02/20 12:31:20 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Constantes do jogo
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH     24
#define MAP_HEIGHT    24
#define MOVE_SPEED    0.1
#define ROT_SPEED     0.05
#define PI            3.1415926535

// Mapa do mundo (0 = vazio, >0 = parede com diferentes IDs)
static int world_map[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// Estrutura para dados gráficos
typedef struct s_graphics {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_graphics;

// Estrutura para o jogador
typedef struct s_player {
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
} t_player;

// Estrutura principal do jogo
typedef struct s_game {
    t_graphics graphics;
    t_player player;
    struct timeval last_frame;
} t_game;

// Função para desenhar um pixel na imagem
void put_pixel(t_graphics *graphics, int x, int y, int color) {
    char *pixel = graphics->img_data + (y * graphics->line_length + x * (graphics->bits_per_pixel / 8));
    *(unsigned int *)pixel = color;
}

// Inicializa o raycasting para uma coluna da tela
void cast_ray(t_game *game, int x, double *ray_dir_x, double *ray_dir_y, int *map_x, int *map_y) {
    double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
    *ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
    *ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
    *map_x = (int)game->player.pos_x;
    *map_y = (int)game->player.pos_y;
}

// Calcula a distância até a parede e retorna a altura da linha
int calculate_wall_distance(t_game *game, double ray_dir_x, double ray_dir_y, int map_x, int map_y, int *side) {
    double delta_dist_x = fabs(1 / ray_dir_x);
    double delta_dist_y = fabs(1 / ray_dir_y);
    double side_dist_x, side_dist_y;
    int step_x, step_y, hit = 0;

    if (ray_dir_x < 0) {
        step_x = -1;
        side_dist_x = (game->player.pos_x - map_x) * delta_dist_x;
    } else {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - game->player.pos_x) * delta_dist_x;
    }
    if (ray_dir_y < 0) {
        step_y = -1;
        side_dist_y = (game->player.pos_y - map_y) * delta_dist_y;
    } else {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - game->player.pos_y) * delta_dist_y;
    }

    while (!hit) {
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            *side = 0;
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            *side = 1;
        }
        if (world_map[map_x][map_y] > 0) hit = 1;
    }

    double perp_wall_dist = (*side == 0) ? 
        (map_x - game->player.pos_x + (1 - step_x) / 2) / ray_dir_x :
        (map_y - game->player.pos_y + (1 - step_y) / 2) / ray_dir_y;
    return (int)(SCREEN_HEIGHT / perp_wall_dist);
}

// Renderiza uma coluna da tela
void render_column(t_game *game, int x, int line_height, int side) {
    int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
    if (draw_start < 0) draw_start = 0;
    int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;
    int wall_color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        if (y < draw_start)
            put_pixel(&game->graphics, x, y, 0x87CEEB); // Céu
        else if (y > draw_end)
            put_pixel(&game->graphics, x, y, 0x333333); // Chão
        else
            put_pixel(&game->graphics, x, y, wall_color); // Parede
    }
}

// Função principal de renderização
void render_frame(t_game *game) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        double ray_dir_x, ray_dir_y;
        int map_x, map_y, side;
        cast_ray(game, x, &ray_dir_x, &ray_dir_y, &map_x, &map_y);
        int line_height = calculate_wall_distance(game, ray_dir_x, ray_dir_y, map_x, map_y, &side);
        render_column(game, x, line_height, side);
    }
    mlx_put_image_to_window(game->graphics.mlx_ptr, game->graphics.win_ptr, game->graphics.img_ptr, 0, 0);
}

// Move o jogador para frente ou para trás
void move_player(t_game *game, int direction) {
    double move_x = game->player.dir_x * MOVE_SPEED * direction;
    double move_y = game->player.dir_y * MOVE_SPEED * direction;

    if (!world_map[(int)(game->player.pos_x + move_x)][(int)game->player.pos_y])
        game->player.pos_x += move_x;
    if (!world_map[(int)game->player.pos_x][(int)(game->player.pos_y + move_y)])
        game->player.pos_y += move_y;
}

// Rotaciona o jogador no sentido horário ou anti-horário
void rotate_player(t_game *game, int direction) {
    double angle = ROT_SPEED * direction;
    double old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
    game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
    double old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
    game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
}

// Manipula eventos de teclado
int handle_keypress(int keycode, t_game *game) {
    if (keycode == 65362) // Seta para cima
        move_player(game, 1);
    else if (keycode == 65364) // Seta para baixo
        move_player(game, -1);
    else if (keycode == 65363) // Seta para direita
        rotate_player(game, -1);
    else if (keycode == 65361) // Seta para esquerda
        rotate_player(game, 1);
    else if (keycode == 65307) { // ESC
        mlx_destroy_window(game->graphics.mlx_ptr, game->graphics.win_ptr);
        exit(0);
    }
    return 0;
}

// Atualiza o estado do jogo e renderiza o frame
int update_game(t_game *game) {
    game->last_frame = game->last_frame; // Mantém para futuro controle de FPS
    gettimeofday(&game->last_frame, NULL);
    mlx_clear_window(game->graphics.mlx_ptr, game->graphics.win_ptr);
    render_frame(game);
    return 0;
}

// Inicializa o jogo
t_game init_game(void) {
    t_game game = {
        .player = {
            .pos_x = 22.0,
            .pos_y = 12.0,
            .dir_x = -1.0,
            .dir_y = 0.0,
            .plane_x = 0.0,
            .plane_y = 0.66
        }
    };

    game.graphics.mlx_ptr = mlx_init();
    if (!game.graphics.mlx_ptr)
        exit(1);
    game.graphics.win_ptr = mlx_new_window(game.graphics.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycaster");
    game.graphics.img_ptr = mlx_new_image(game.graphics.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
    game.graphics.img_data = mlx_get_data_addr(game.graphics.img_ptr, &game.graphics.bits_per_pixel,
                                              &game.graphics.line_length, &game.graphics.endian);
    gettimeofday(&game.last_frame, NULL);
    return game;
}

int main(void) {
    t_game game = init_game();

    mlx_hook(game.graphics.win_ptr, 2, 1L << 0, handle_keypress, &game);
    mlx_loop_hook(game.graphics.mlx_ptr, update_game, &game);
    mlx_loop(game.graphics.mlx_ptr);

    return 0;
}
