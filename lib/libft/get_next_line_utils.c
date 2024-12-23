/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:08:41 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/23 09:55:58 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief srcをdstに文字数srcsizeまでコピーします 
 *
 * @param [out] dst		: コピー先の文字列領域
 * @param [in]	src 	: コピーする文字列
 * @param [in]	srcsize	: コピーサイズ
 * @return char* 		: dstの先頭ポインタ
 */
char	*gnl_strncpy(char *dst, const char *src, size_t srcsize)
{
	size_t	i;

	i = 0;
	while (i < srcsize && *src)
		dst[i++] = *src++;
	if (i < srcsize)
		dst[i] = '\0';
	return (dst);
}

/**
 * @brief lineの中の文字列を解放してNULLをセットします。
 * 
 * @param line		: 行の情報を管理する構造体
 * @return void*	: NULLを返します
 */
void	*gnl_line_free(t_string *line)
{
	if (line->str)
	{
		free(line->str);
		line->str = NULL;
	}
	return (NULL);
}

/**
 * @brief putcとgetcの状態からgnlの状態を設定します
 *
 * @param [out]	status	: 状態管理用の構造体
 * @return t_sts*		: gnlの状態適用後のstatus
 * @note	GNL_READ	: 行読み取り中
 * @note	GNL_EOF		: EOFに達した
 * @note	GNL_ERR		: 処理中にエラーが発生
 */
t_sts	*set_sts(t_sts *status)
{
	if (status->getc_sts == GETC_OTHER && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_READ;
	else if (status->getc_sts == GETC_LF && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_LF;
	else if (status->getc_sts == GETC_EOF && status->putc_sts == PUTC_OK)
		status->gnl_sts = GNL_EOF;
	else
		status->gnl_sts = GNL_ERR;
	return (status);
}
