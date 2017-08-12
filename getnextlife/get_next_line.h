/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 08:05:57 by jcoutare          #+#    #+#             */
/*   Updated: 2017/08/12 11:34:51 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(const int fd, char **line);

#endif
