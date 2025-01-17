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
 * The source code included in this files was separated from mbfilter.c
 * by Moriyoshi Koizumi <moriyoshi@php.net> on 4 Dec 2002. The file
 * mbfilter.c is included in this package .
 *
 */

#ifndef MBFL_MBFILTER_BASE64_H
#define MBFL_MBFILTER_BASE64_H

#include "../mbfl/mbfilter.h"

extern const mbfl_encoding mbfl_encoding_base64;
extern const struct mbfl_convert_vtbl vtbl_b64_8bit;
extern const struct mbfl_convert_vtbl vtbl_8bit_b64;

int mbfl_filt_conv_base64enc(int c, mbfl_convert_filter *filter);
int mbfl_filt_conv_base64enc_flush(mbfl_convert_filter *filter);
int mbfl_filt_conv_base64dec(int c, mbfl_convert_filter *filter);
int mbfl_filt_conv_base64dec_flush(mbfl_convert_filter *filter);

#endif /* MBFL_MBFILTER_BASE64_H */
