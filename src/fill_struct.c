/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:09:20 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/31 17:09:22 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	check_and_fill_player(t_struct *t_str)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return ;
	if (ft_strstr(line, "pmartyny.filler"))
		t_str->player_number = (ft_strstr(line, "p1") ? 1 : 2);
	else
		t_str->player_number = (ft_strstr(line, "p1") ? 2 : 1);
	t_str->player_symbols = ft_strdup(t_str->player_number == 1 ? "oO" : "xX");
	ft_strdel(&line);
}

int		fill_plateau_size(t_struct *t_str, char **line)
{
	if (t_str->plateau != NULL)
		if (t_str->plateau_row != ft_atoi(ft_strchr((*line), ' ')) ||
			t_str->plateau_col != ft_atoi(ft_strrchr((*line), ' ')))
			return (-1);
	t_str->plateau_row = ft_atoi(ft_strchr((*line), ' '));
	t_str->plateau_col = ft_atoi(ft_strrchr((*line), ' '));
	ft_strdel(line);
	return (fill_plateau(t_str));
}

int		fill_plateau(t_struct *t_str)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	ft_strdel(&line);
	if (t_str->plateau == NULL)
	{
		if (fill_plateau_first(t_str) == -1)
			return (-1);
	}
	else
	{
		while (i < t_str->plateau_row)
		{
			if (get_next_line(0, &line) < 0)
				return (-1);
			re_line_plateau(&t_str->plateau[i], line);
			ft_strdel(&line);
			i++;
		}
	}
	return (0);
}

int		fill_piece_size(t_struct *t_str, char **line)
{
	t_str->piece_row = ft_atoi(ft_strchr((*line), ' '));
	t_str->piece_col = ft_atoi(ft_strrchr((*line), ' '));
	ft_strdel(line);
	return (fill_piece(t_str));
}

int		fill_piece(t_struct *t_str)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (t_str->piece == NULL)
	{
		if (fill_piece_first(t_str) == -1)
			return (-1);
	}
	else
	{
		my_byzero(t_str->piece, t_str->plateau_row, t_str->plateau_col);
		while (i < t_str->piece_row)
		{
			if (get_next_line(0, &line) < 0)
				return (-1);
			re_line_piece(&t_str->piece[i], line);
			ft_strdel(&line);
			i++;
		}
	}
	return (0);
}
