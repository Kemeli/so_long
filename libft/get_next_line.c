/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:26 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/11/04 01:11:17 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(char *hold, int fd)
{
	int		bytes_r;
	char	*temp;
	char	*aux;

	bytes_r = 1;
	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	while (bytes_r > 0)
	{
		bytes_r = read (fd, aux, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			free(aux);
			free(hold);
			return (NULL);
		}
		aux[bytes_r] = '\0';
		temp = ft_strjoin(hold, aux);
		free(hold);
		hold = temp;
	}
	free(aux);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*hold;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (!next_line)
		next_line = ft_strdup("");
	hold = read_file(next_line, fd);
	return (hold);
}
