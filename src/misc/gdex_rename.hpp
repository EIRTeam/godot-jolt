#pragma once

#ifdef GDEXTENSION
#define GDEX_FUNC_RENAME_U(func_name) _##func_name
#else
#define GDEX_FUNC_RENAME_U(func_name) func_name
#endif

#ifdef GDEXTENSION
#define GDEX_OVERRIDE_EX_ONLY override
#else
#define GDEX_OVERRIDE_EX_ONLY
#endif

#ifdef GDEXTENSION
#define GDEX_CONST_EX_ONLY const
#else
#define GDEX_CONST_EX_ONLY
#endif
