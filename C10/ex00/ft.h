/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:34:45 by afaby             #+#    #+#             */
/*   Updated: 2022/03/04 16:40:12 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define ERR_NO_ARGS "File name missing.\n"
# define ERR_TM_ARGS "Too many arguments.\n"
# define ERR_NOT_READABLE "Cannot read file.\n"

#endif
