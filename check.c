/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:12 by terabu            #+#    #+#             */
/*   Updated: 2023/01/31 15:54:14 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pre(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		print_error_msg(ERROR_ARGS);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error_msg(ERROR_FILE);
		exit(0);
	}
	close(fd);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		print_error_msg(ERROR_BER);
		exit(0);
	}
}

static int	open_file(const char *filepath)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		print_error_msg(ERROR_FILE);
		exit(0);
	}
	return (fd);
}

void	check_map(char **argv)
{
	int		fd;
	int		flg;
	char	*s;

	fd = open_file(argv[1]);
	s = get_next_line(fd);
	flg = 0;
	while (s)
	{
		if (!ft_strncmp(s, "\n", 1))
		{
			printf("k\n");
			if (flg == 1)
				check_error_map(s, fd, ERROR_CLOSEMAP);
			free(s);
			s = get_next_line(fd);
			continue ;
		}
		flg = 1;
		printf("%s\n", s);
		check_rect_wall(fd, s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

void	check_rect_wall(int fd, char *s)
{
	size_t			i;
	static size_t	len;

	printf("len:%zu\n", len);
	if (len == 0)
	{
		len = ft_strlen(s);
		i = 0;
		while (s[i] != '\n')
		{
			if (s[i] != '1')
				check_error_map(s, fd, ERROR_WALL);
			i++;
		}
	}
	else
	{
		if (len != ft_strlen(s))
			check_error_map(s, fd, ERROR_RECT);
		if (s[0] != '1' || s[len - 1 - 1] != '1')
			check_error_map(s, fd, ERROR_WALL);
	}
}

// void	check_item(int fd, char *s)
// {

// }
