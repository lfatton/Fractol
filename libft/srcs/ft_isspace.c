/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 20:04:58 by lfatton           #+#    #+#             */
/*   Updated: 2018/04/25 20:44:20 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (ft_isblank(c) || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}
