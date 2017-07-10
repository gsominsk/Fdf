/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:01:47 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:15:24 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <stddef.h>
# include <wchar.h>
# include "../src_lib/libft.h"

# define KNRM  					"\x1B[0m"
# define KRED  					"\x1B[91m"
# define KGRN  					"\x1B[92m"
# define KYEL  					"\x1B[93m"
# define KBLU  					"\x1B[94m"
# define KMAG  					"\x1B[95m"
# define KCYN  					"\x1B[96m"
# define KWHT  					"\x1B[97m"

typedef unsigned long long int	t_ulli;

/*
**			-=DESCRIBING_FLAGS_STRUCTURE
*/

typedef struct		s_get_flag
{
	char	zero;
	char	sharp;
	char	minus;
	char	plus;
	char	space;
	int		p;
	int		width;
	size_t	length;
	va_list	*arg;
}					t_get_flag;

/*
**				-=MAIN_FUNCTIONS=-
*/
size_t				ft_printf(char *format, ...);

/*
**				-=PRINTF_TOOLS=-
*/
void				check_flag_compatability(t_get_flag *descr, char c);
void				full_destruction(t_get_flag *p);

/*
**			-=FIND_FLAGS "#-+0 etc."=-
*/
int					find_flag_precision(char *str, int *start,
										t_get_flag *descr);
int					find_flag_character(char *str, int *start,
										t_get_flag *descr);
int					find_flag_symbol(char *str, int *start, t_get_flag *descr);
int					find_flag_width(char *str, int *start, t_get_flag *descr);
int					validation(char *str, int *start, t_get_flag *descr);

/*
**					-=OUTPUT=-
*/
void				shs(t_get_flag *descr, char *o_str, int value);
void				o_l_s(t_get_flag *descr, char *o_str);
void				output_1(t_get_flag *d, char *o_str);
void				std_space(int value, t_get_flag *descr, char **o_str);
int					std_str(char *o_str, t_get_flag *descr);

/*
**				-=SHOW_DETAILS=-
*/
void				show_struct(t_get_flag *p);

/*
**				-=UNDEFINED_BEHAVIOR=-
*/
int					undef_beh(char *str, int *i, t_get_flag *descr);

/*
**					-=VALIDATION=-
*/
int					check_size_specifier(char *str, int *start);

/*
**					-=FUNCTIONS=-
*/
int					func_wstring(t_get_flag *descr);
int					func_hex_small(t_get_flag *d, int type);
int					func_hex_big(t_get_flag *d, int type);
int					func_octa(t_get_flag *d, int type);
int					func_octa_big(t_get_flag *d, int type);
int					func_binary(t_get_flag *descr, int type);
int					func_char(t_get_flag *descr);
int					func_wchar(t_get_flag *descr);
int					func_pointer(t_get_flag *descr);
int					func_percent(t_get_flag *descr);
int					func_int(t_get_flag *descr, int type);
int					func_float_small(t_get_flag *d);
int					func_float_big(t_get_flag *descr, int type);
int					func_long_decimal(t_get_flag *descr);
int					func_unsigned(t_get_flag *d, int type);
int					func_unsigned_big(t_get_flag *d, int type);
int					func_string(t_get_flag *descr);

/*
**					-=TOOLS=-
*/
char				*i_b(uintmax_t value, int base, int size);
int					ft_putnstr(char *str, t_get_flag *descr);
char				*ftoa_d(long double num, int precision);
char				*ft_itoa_u(unsigned long long int n);
char				*ftoa_f(float num, int precision);
size_t				ft_strlen_w(const wchar_t *s);
void				ft_putwstr(wchar_t *str);
char				*ft_itoa(long long int n);
void				ft_putwchar(wchar_t w);
int					ft_putnwstr(wchar_t *str, t_get_flag *descr);

#endif
