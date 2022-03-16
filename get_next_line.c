/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:28 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/16 17:25:14 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	int			i;
	char	str[BUFFER_SIZE];
	char		c;

	read(fd, str, BUFFER_SIZE);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i + 1] = '\0';
	return (str);
}

int main()
{
	printf("%s", get_next_line(open("jambon.txt", O_RDONLY)));
	printf("%s", get_next_line(open("jambon.txt", O_RDONLY)));

	return (0);
}
