/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:28 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/18 15:37:45 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*str;
	int			octet;

	str = "";
	octet = read(fd, buffer, BUFFER_SIZE);
	buffer[octet] = '\0';
	str = ft_strjoin(str, buffer);
	while (octet != 0)
	{
		octet = read(fd, buffer, BUFFER_SIZE);
		buffer[octet] = '\0';
		str = ft_strjoin(str, buffer);
	}
	printf("%s", str);
	return (str);
}

int main()
{	
	int fd = open("jambon.txt", O_RDONLY);

	get_next_line(fd);
	// printf("%s",get_next_line(fd));
	return (0);
}
