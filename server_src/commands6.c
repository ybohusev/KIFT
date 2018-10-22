/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:09:44 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/22 14:47:14 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*party(int fd)
{
	system("osascript -e \'say \"Lets start the party!!!\" \
			using \"Victoria\"\'");
	system("osascript ./scripts/party.scpt &>/dev/null");
	return ("Mr. MEESEEKS: Lets start the party!!!");
}

char	*joke(int fd)
{
	system("osascript -e \'say \"We will conquer the world\" \
			using \"Victoria\"\'");
	system("osascript ./scripts/joke.scpt &>/dev/null");
	return ("Mr. MEESEEKS: WE WILL CONQUER THE WORLD!");
}

char	*open_terminal(int fd)
{
	system("osascript -e \'say \"Terminal is ready\" \
			using \"Victoria\"\'");
	system("osascript ./scripts/open_terminal.scpt &>/dev/null");
	return ("Mr. MEESEEKS: Terminal is ready, MY LORD!");
}

char	*show_cameras(int fd)
{
	system("osascript -e \'say \"Cameras are here, boss\" \
			using \"Victoria\"'");
	system("osascript ./scripts/show_cameras.scpt &>/dev/null");
	return ("Mr. MEESEEKS: Cameras are here, boss!");
}
