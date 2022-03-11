/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:43:41 by rogerio           #+#    #+#             */
/*   Updated: 2022/03/11 12:53:45 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_convert(t_params *params, va_list args)
{
	int		char_count;
	char	*pointer;
	char	czero;

	czero = 0;
	pointer = ft_apply_specifiers(params, args);
	if (pointer == NULL)
		return (0);
	if (params->specifier == 'c')
		ft_czero(&pointer[0], &czero);
	if (params->precision_bool)
		pointer = ft_apply_precision(pointer, params);
	pointer = ft_apply_flag(pointer, params);
	return (pointer);
}
