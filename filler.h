/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:04:40 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/31 16:04:42 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft_printf/includes/ft_printf.h"
# include <fcntl.h>

typedef	struct	s_struct {
	char		**plateau;
	int			plateau_row;
	int			plateau_col;
	char		**piece;
	int			piece_row;
	int			piece_col;
	int			player_number;
	char		*player_symbols;
	int			**matr;
}				t_struct;

int				g_row;
int				g_col;
int				g_val;

int				fill_t_struct(t_struct *t_str);
void			check_and_fill_player(t_struct *t_str);
int				fill_plateau_size(t_struct *t_str, char **line);
int				fill_plateau(t_struct *t_str);
int				fill_piece_size(t_struct *t_str, char **line);
int				fill_piece(t_struct *t_str);
void			craete_int_matr(t_struct *t_str);
void			fill_enemy_matr(t_struct *t_str);
void			fill_length(t_struct *t_str);
void			print_cord(void);
void			zero_cord(void);
void			count_length(int row, int col, t_struct *t_str);
void			re_line_plateau(char **str, char *line);
void			re_line_piece(char **str, char *line);
void			my_byzero(char **str, int cnt, int len);
void			byzero(char **str, int len);
void			cut_piece(t_struct *t_str);
int				find_width(t_struct t_str, int width, int j);
int				find_height(t_struct t_str);
int				find_x(t_struct t_str);
int				find_y(t_struct t_str);
int				fill_piece_first(t_struct *t_str);
int				fill_plateau_first(t_struct *t_str);
int				check_invalid_position(char plateau_pos, char piece_pos,
	t_struct t_str);
int				check_valid_position(char plateau_pos,
	char piece_pos, t_struct t_str);
void			fill_cord(int val, int counter, int row, int col);
int				check_t_str(t_struct t_str);
int				count_enemy(t_struct *t_str);
void			find_coordinates(t_struct *t_str);
void			check_coordinates(t_struct t_str, int row, int col);
int				validation(char c, char a, t_struct t_str, int *counter);

#endif
