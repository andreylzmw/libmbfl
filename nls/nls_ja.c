#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif

#include "../mbfl/mbfilter.h"
#include "nls_ja.h"

const mbfl_language mbfl_language_japanese = {
	mbfl_no_language_japanese,
	"Japanese",
	"ja",
	NULL,
	mbfl_no_encoding_2022jp,
	mbfl_no_encoding_base64,
	mbfl_no_encoding_7bit
};
