/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl1_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 09:42:43 by jgigault          #+#    #+#             */
/*   Updated: 2014/12/10 13:54:31 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "gnl.h"

int				main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			ret;
	int			count;
	char		*filename;
	int			errors;

	filename = "gnl5_1.txt";
	fd = 0;
	if (argc && argv)
	{
		count = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count == 0 && strcmp(line, "123") != 0)
				errors++;
			count++;
		}
		if (errors > 0)
		{
			printf("\"%s\" was read instead of \"123\"", line);
		}
		else
		{
			printf("OK");
		}
	}
	else
	{
		printf("An error occured while reading file %s through STDIN", filename);
	}
	return (0);
}