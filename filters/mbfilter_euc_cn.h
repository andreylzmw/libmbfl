/*
 * "streamable kanji code filter and converter"
 * Copyright (c) 1998-2002 HappySize, Inc. All rights reserved.
 *
 * LICENSE NOTICES
 *
 * This file is part of "streamable kanji code filter and converter",
 * which is distributed under the terms of GNU Lesser General Public 
 * License (version 2) as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with "streamable kanji code filter and converter";
 * if not, write to the Free Software Foundation, Inc., 59 Temple Place,
 * Suite 330, Boston, MA  02111-1307  USA
 *
 * The author of this file:
 *
 */
/*
 * The source code included in this files was separated from mbfilter_euc_cn.h
 * by Moriyoshi Koizumi <moriyoshi@php.net> on 4 Dec 2002.
 *
 */

#ifndef MBFL_MBFILTER_EUC_CN_H
#define MBFL_MBFILTER_EUC_CN_H

#include "../mbfl/mbfilter.h"

extern const mbfl_encoding mbfl_encoding_euc_cn;
extern const struct mbfl_identify_vtbl vtbl_identify_euccn;
extern const struct mbfl_convert_vtbl vtbl_euccn_wchar;
extern const struct mbfl_convert_vtbl vtbl_wchar_euccn;

int mbfl_filt_conv_euccn_wchar(int c, mbfl_convert_filter *filter);
int mbfl_filt_conv_wchar_euccn(int c, mbfl_convert_filter *filter);

#endif /* MBFL_MBFILTER_EUC_CN_H */
