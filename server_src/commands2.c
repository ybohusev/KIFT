/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:40:54 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:41:02 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*music(int fd)
{
	system("osascript ./scripts/play_music.scpt &>/dev/null");
	system("osascript -e \'say \"Yeah lets rock\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Yeah lets rock");
}

char	*stop_music(int fd)
{
	system("osascript ./scripts/stop_music.scpt &>/dev/null");
	system("osascript -e \'say \"No more music, MY LORD!\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: No more music, MY LORD!");
}

char	*play_next(int fd)
{
	system("osascript ./scripts/play_next.scpt &>/dev/null");
	system("osascript -e \'say \"Next track is here, BOSS!\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Next track is here, BOSS!");
}

char	*play_prev(int fd)
{
	system("osascript ./scripts/play_prev.scpt &>/dev/null");
	system("osascript -e \'say \"Previous track just for you, BOSS!\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Previous track just for you, BOSS!");
}

char	*quit_itunes(int fd)
{
	system("osascript ./scripts/quit_itunes.scpt &>/dev/null");
	system("osascript -e \'say \"iTunes is dead, BOSS\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: iTunes is dead, BOSS");
}
