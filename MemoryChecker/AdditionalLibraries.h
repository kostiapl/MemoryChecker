#pragma once



#include <climits>
#include <cwchar>
#include <cwctype>


// Block minwindef.h min/max macros to prevent <algorithm> conflict
#define NOMINMAX

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <regex>



// WIL



#include <wil/common.h>
#include <wil/result.h>
#include <wil/resource.h>
#include <wil/wistd_memory.h>
#include <wil/stl.h>
#include <wil/com.h>
#include <wil/filesystem.h>
#include <wil/win32_helpers.h>

