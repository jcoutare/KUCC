/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:20:13 by jcoutare          #+#    #+#             */
/*   Updated: 2017/10/09 14:05:51 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ICI printf("ici\n")
# define LA printf("la\n")
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <wchar.h>
typedef struct			s_struct
{
	int					fail;
	size_t					c_kc;
	int					precfail;
	int					modif;
	int					f_sharp;
	int					f_zero;
	int					f_plus;
	int					f_moins;
	int					f_space;
	int					conv;
	int					larg;
	int					prec;
	char				*sarg;
	unsigned long long	arg;
	va_list				*ap;
	char				*flags;
	char				*resolved;
	char				*fstring;
	void				(*flag_tab[127])(struct s_struct *data);
}						t_struct;

int						ft_printf(char *str, ...);
void					flag_bigc(t_struct *data);
void					flag_bigs(t_struct *data);
void					make_o_sharp(t_struct *data);
char					*do_normal_prec(t_struct *data, char *str);
char					*do_plus_prec(t_struct *data, char *str);
char					*do_neg_prec(t_struct *data, char *str);
char					*do_sharp_zero_prec(t_struct *data, char *str);
void					le_the(t_struct *data);
void					le_cafe(t_struct *data);
int						check_signe(t_struct *data);
int						check_char(t_struct *data, char c);
char					*ft_itoa_ull(unsigned long long n);
void					prec_s(t_struct *data);
void					prec_hexa(t_struct *data, int base);
int						strcheck(char *str, char *check);
void					make_zero(t_struct *data);
void					make_moins(t_struct *data);
void					prec(t_struct *data);
void					modif_l(t_struct *data);
void					modif_h(t_struct *data);
void					modif_j(t_struct *data);
void					modif_z(t_struct *data);
void					make_sharp(t_struct *data);
int						flag_prec(t_struct *data, char *flags);
void					larg_moins(t_struct *data);
char					*ft_strnfjoin(char const *s1, char const *s2);
char					*ft_strnjoin(char const *s1, char const *s2, int n);
int						strichr(char *str, char c);
int						strichr_str(char *str, char *chr);
char					*ft_itoa_base(unsigned long long nbr,
										unsigned int base);
t_struct				*fill_struct(t_struct *data, va_list *ap);
void					fill_struct2(t_struct *data);
void					larg(t_struct *data);
void					flag_bigd_signed(t_struct *data);
void					flag_bigu_unsigned(t_struct *data);
void					flag_pourcent(t_struct *data);
void					flag_zero(t_struct *data);
int						flag_larg(t_struct *data, char *flags);
void					flag_moins(t_struct *data);
void					flag_p(t_struct *data);
void					flag_plus(t_struct *data);
void					flag_space(t_struct *data);
void					flag_diese(t_struct *data);
void					flag_d_signed(t_struct *data);
void					flag_d_unsigned(t_struct *data);
void					flag_o_unsigned(t_struct *data);
void					flag_hex_unsigned(t_struct *data);
void					flag_hex_unsigned_maj(t_struct *data);
void					flag_s(t_struct *data);
void					flag_c(t_struct *data);
#endif
