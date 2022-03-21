/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:28 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/21 16:33:52 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2[j])
	{
		join[i + j] = *(char *)(s2 + j);
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_line(char *str)
{
	int static	i = 0;
	char		*line;
	int			j;

	j = 0;
	while (str[i + j] && str[i + j] != '\n')
		j++;
	line = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i] != '\n' && str[i])
	{
		line[j] = str[i];
		j++;
		i++;
	}
	while (str[i] == '\n')
	{
		line[j] = '\n';
		j++;
		i++;
	}
	line[j] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*str;
	char		*line;
	int static	octet = -2;

	if (!str)
	{
		str = malloc(sizeof(char));
		str = "";
	}
	while (octet != 0)
	{
		octet = read(fd, buffer, BUFFER_SIZE);
		if (octet != 0)
		{
			buffer[octet] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	line = ft_line(str);
	return (line);
}

// int main()
// {	
// 	int fd = open("jambon.txt", O_RDONLY);

// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
