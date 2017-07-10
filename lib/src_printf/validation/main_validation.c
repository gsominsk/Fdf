/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:08 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:06:54 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ===========================================
**				-=VALIDASHKA=-
** ===========================================
*/

int		ffc_1(char *str, int *start, t_get_flag *descr, int type)
{
	int flag;

	flag = 0;
	str[*start] == '%' ? flag = func_percent(descr) : 0;
	str[*start] == 's' ? flag = func_string(descr) : 0;
	str[*start] == 'S' ? flag = func_wstring(descr) : 0;
	str[*start] == 'p' ? flag = func_pointer(descr) : 0;
	str[*start] == 'd' ? flag = func_int(descr, type) : 0;
	str[*start] == 'D' ? flag = func_long_decimal(descr) : 0;
	str[*start] == 'i' ? flag = func_int(descr, type) : 0;
	str[*start] == 'f' ? flag = func_float_small(descr) : 0;
	str[*start] == 'F' ? flag = func_float_big(descr, type) : 0;
	str[*start] == 'u' ? flag = func_unsigned(descr, type) : 0;
	str[*start] == 'U' ? flag = func_unsigned_big(descr, type) : 0;
	str[*start] == 'o' ? flag = func_octa(descr, type) : 0;
	str[*start] == 'O' ? flag = func_octa_big(descr, type) : 0;
	str[*start] == 'c' ? flag = func_char(descr) : 0;
	str[*start] == 'C' ? flag = func_wchar(descr) : 0;
	str[*start] == 'b' ? flag = func_binary(descr, type) : 0;
	str[*start] == 'x' ? flag = func_hex_small(descr, type) : 0;
	str[*start] == 'X' ? flag = func_hex_big(descr, type) : 0;
	return (flag);
}

void	ffc_2(char *str, int *start, t_get_flag *descr)
{
	int type;

	type = -1;
	descr->minus == 1 ? ft_putchar(str[*start]) : 0;
	while (++type < (int)(descr->width) - 1)
	{
		descr->zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		descr->length++;
	}
	descr->minus == 0 ? ft_putchar(str[*start]) : 0;
	descr->length++;
}

int		find_flag_character(char *str, int *start, t_get_flag *descr)
{
	int type;
	int flag;

	type = 0;
	flag = 0;
	check_flag_compatability(descr, str[*start]);
	type = check_size_specifier(str, start);
	if (!(str[*start] >= 'a' && str[*start] <= 'z')
		&& !(str[*start] >= 'A' && str[*start] <= 'Z') && !(str[*start] >= '%'))
		find_flag_symbol(str, start, descr);
	flag = ffc_1(str, start, descr, type);
	if (flag == 0 && str[*start] != '\0')
		ffc_2(str, start, descr);
	if (flag == 1)
		return (0);
	return (-1);
}

int		val_1(char *str, int *start, t_get_flag *descr)
{
	int temp;

	if (find_flag_symbol(str, start, descr) == 1)
		validation(str, start, descr);
	else if (find_flag_width(str, start, descr) == 1)
		validation(str, start, descr);
	else if ((temp = find_flag_precision(str, start, descr)) == 1)
	{
		if (str[*start] == '%')
		{
			if (find_flag_character(str, start, descr) == -1)
				return (-1);
		}
		else
			validation(str, start, descr);
	}
	else if (temp == -1)
		return (-1);
	else if (find_flag_character(str, start, descr) == -1)
		return (-1);
	return (0);
}

int		validation(char *str, int *start, t_get_flag *descr)
{
	if ((str[*start] >= 'a' && str[*start] <= 'z')
		|| (str[*start] >= 'A' && str[*start] <= 'Z'))
	{
		if (find_flag_character(str, start, descr) == -1)
			return (-1);
	}
	else if (val_1(str, start, descr) == -1)
		return (-1);
	return (0);
}
