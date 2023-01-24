/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:37:43 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/13 16:36:32 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

// main function
int	ft_printf(const char *input, ...);

// other functions
int	ft_treat_char(int c);
int	ft_treat_hexa(unsigned int num, int format);
int	ft_treat_int(int num);
int	ft_treat_ptr(void *ptr);
int	ft_treat_string(char *str);
int	ft_treat_uint(unsigned int num);

#endif
