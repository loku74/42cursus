/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:11:25 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/28 13:11:27 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define OR ||
# define AND &&

typedef enum e_bool			t_bool;
typedef enum e_exit			t_exit;

// FALSE 0, TRUE 1
enum e_bool
{
	FALSE,
	TRUE
};

// SUCCESS 0, ERROR 1
enum e_exit
{
	SUCCESS,
	ERROR
};

#endif
