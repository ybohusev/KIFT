/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:10:46 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:10:49 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "common.h"
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include <ncurses.h>
#include <sys/ioctl.h>

typedef struct				s_interface
{
	WINDOW					*win;
	int						height;
	int						weight;
}							t_interface;	

typedef struct				s_windows
{
	t_interface				mess;
	t_interface				t;
	t_interface				help;
}							t_windows;

typedef struct				s_mess
{
	int						x;
	int						y;
	char					*you;
	char					*mees;
	char					*del;
	struct	s_mess			*next;
}							t_mess;

typedef struct				s_sphinx
{
	ps_decoder_t			*ps;
	cmd_ln_t				*config;
	ad_rec_t				*ad;
}							t_sphinx;

typedef struct				s_sock
{
	struct sockaddr_in		address;
	struct sockaddr_in		serv_addr;
	int						sock;
	int						valread;
	char					buffer[1024];
}							t_sock;

t_sock						init_sock(void);
t_sphinx					init_sphinx(void);
const 						char* recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad, t_interface help);
int							send_command(char const *decoded_speech, char *answer);
void						interface(char const *command, char *answer, t_interface inter, t_mess	**l);

t_windows					init_ncur(void);
void						print_list_commands(t_interface inter);
void						del_windows(t_windows del);
t_mess						*new_mess(char *you, char *mees, t_interface inter);
void						add_mess(t_mess **l, char *you, char *mees, t_interface inter);
void						del_mess(t_mess *l);
void						del_all(t_mess *l);

#endif
