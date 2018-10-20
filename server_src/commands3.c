/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:41:16 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:41:24 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*close_browser(int fd)
{
	system("osascript -e \'say \"Okey I\'ll close the browser\" \
			using \"Victoria\"\'");
	system("osascript ./scripts/close_browser.scpt &>/dev/null");
	return ("Mr. MEESEEKS: Okey I'll close the browser");
}

char	*inc_bright(int fd)
{
	system("osascript ./scripts/inc_bright.scpt &>/dev/null");
	system("osascript -e \'say \"Brightness is increased\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Brightness is increased");
}

char	*dec_bright(int fd)
{
	system("osascript ./scripts/dec_bright.scpt &>/dev/null");
	system("osascript -e \'say \"Brightness is decreased\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Brightness is decreased");
}

char	*inc_vol(int fd)
{
	system("osascript ./scripts/increase_volume.scpt &>/dev/null");
	system("osascript -e \'say \"Volume is increased\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Volume is increased");
}

char	*dec_vol(int fd)
{
	system("osascript ./scripts/decrease_volume.scpt &>/dev/null");
	system("osascript -e \'say \"Volume is decreased\" \
			using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Volume is decreased");
}
