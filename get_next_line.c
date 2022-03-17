/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:28 by tkempf-e          #+#    #+#             */
/*   Updated: 2022/03/17 17:35:47 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static int	i;
	int			j;
	char		buffer[BUFFER_SIZE];
	char		*str;
	char		*stocker;

	//buffer de 1 prend cara par cara pour afficher toute la ligne
	//buffer de 1000 prend tout le txt pour afficher que la 1ere ligne
	//affiche ligne 2 en cas de rappelle
	//lire et sauvegarder en meme temps
	read(fd, buffer, BUFFER_SIZE);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	stocker = malloc(sizeof(char) * BUFFER_SIZE);
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i + 1] = 0;
	j = 0;
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		while (buffer[i + j])
		{
			stocker[j] = buffer[i + j];//met reste buffer dans stocker
			j++;
		}
	}
	printf("\n\nstocker : %s\n\n", stocker);
	return (str);
}

int main()
{	
	int fd = open("jambon.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));


	return (0);
}
