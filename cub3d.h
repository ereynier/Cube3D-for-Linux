/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 13:40:56 by ereynier     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:23:43 by ereynier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef CUB3D_H
#	define CUB3D_H
#	include "minilibX/mlx.h"
#	include "libft/libft.h"
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include <unistd.h>
#	include <stdlib.h>
#	include <stdio.h>
#	include <string.h>
#	include <math.h>
#	include <X11/X.h>
#	define LEFT 65361
#	define RIGHT 65363
#	define BACK 115
#	define FORWARD 122
#	define STRAFL 113
#	define STRAFR 100
#	define FOV 60
#	define T_LENGTH 64
#	define MAX_SCREEN_L 2560
#	define MAX_SCREEN_H 1400
#	define MIN_SCREEN_L 25
#	define MIN_SCREEN_H 25

typedef struct			s_scene
{
	int					res[2];
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*sprite_path;
	int					f_rgb[3];
	int					c_rgb[3];
	void				*mlx_ptr;
	void				*win_ptr;
	double				x;
	double				y;
	double				angle;
	char				**map;
	double				screen_dist;
	void				*img_so;
	void				*img_ea;
	void				*img_no;
	void				*img_we;
	void				*img_sp;
	void				*img_ptr;
	int					bits_per_pixel;
	int					size_line_texture;
	int					size_line;
	int					endian;
	int					left;
	int					right;
	int					strafl;
	int					strafr;
	int					back;
	int					forward;
}						t_scene;

typedef struct			s_ray
{
	double				x_xa;
	double				x_ya;
	double				y_xa;
	double				y_ya;
	double				x_dist;
	double				y_dist;
	double				xx;
	double				xy;
	double				yx;
	double				yy;
	double				angle;
	int					col;
	double				decallage;
	double				dist;
	double				height;
	int					top;
	double				spx;
	double				spy;
}						t_ray;

typedef struct			s_sprite
{
	double				x;
	double				y;
	double				x2;
	double				y2;
	double				centre[2];
	double				p;
	double				p2;
	double				angle;
}						t_sprite;

typedef struct			s_header
{
	unsigned char		bitmap_type[2];
	int					file_size;
	short				reserved1;
	short				reserved2;
	unsigned int		offset_bits;
}						t_header;

typedef struct			s_header2
{
	unsigned int		size_header;
	unsigned int		width;
	unsigned int		height;
	short int			planes;
	short int			bit_count;
	unsigned int		compression;
	unsigned int		image_size;
	unsigned int		ppm_x;
	unsigned int		ppm_y;
	unsigned int		clr_used;
	unsigned int		clr_important;
}						t_header2;

int						parsing(int fd, char ***map, t_scene *elem);
int						check_extension(char *str);
int						append(char **s, char c);
int						check_res(char *line, t_scene *elem, int i);
int						check_rgb(int i, char *line, t_scene *elem);
int						check_texture(int i, char *line, t_scene *elem);
int						free_elem(t_scene *elem);
int						free_scene(char **scene);
int						valid_map(char **map);
int						ft_len_map(char *str);
char					*mapdup(char *line);
int						init_window(t_scene *elem);
void					get_spawn(t_scene *elem);
void					free_all(t_scene *elem);
int						holdinput(int key, t_scene *elem);
void					get_screen_dist(t_scene *elem);
int						ft_close(t_scene *elem);
void					setup_ray(t_scene *elem, t_ray *ray);
int						wall_hit(t_scene *elem, t_ray *ray, char c, char hit);
void					calc_dist(double *dist_x, double *dist_y, t_scene *elem,
		t_ray *ray);
void					display_col(t_scene *elem, t_ray *ray, double dist_y,
		double dist_x);
void					ray_casting(t_scene *elem);
void					init_variables(t_scene *elem);
void					first_init(t_scene *elem);
void					display_sprite(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y);
int						get_wall_hit(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y);
int						is_on_player(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y);
void					setup_ray_sp(t_ray *ray, double dist_x, double dist_y);
void					calc_dist_sp(double *dist_x, double *dist_y,
		t_ray *ray);
void					get_wall_hit_sp(t_scene *elem, t_ray *ray,
		double dist_x,
		double dist_y);
void					disp_sprite(t_scene *elem, t_ray *ray, double dist_x,
		double dist_y);
void					calc_centre(double *x, double *y, double (*centre)[2],
		t_ray *ray);
void					calc_centre_2(double *x, double *y, double (*centre)[2],
		t_ray *ray);
int						releaseinput(int key, t_scene *elem);
int						apply_input(t_scene *elem);
void					strafr(t_scene *elem);
void					strafl(t_scene *elem);
void					forward(t_scene *elem);
void					back(t_scene *elem);
void					save_bitmap(const char *filename, t_scene *elem);
void					ray_casting_2(t_scene *elem, t_ray *ray, double *dist_x,
		double *dist_y);
int						wall_hit_2(t_scene *elem, t_ray *ray, char hit);

#	endif
