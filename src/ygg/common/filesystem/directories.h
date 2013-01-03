//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_FILESYSTEM_DIRECTORIES_H_INCLUDED
#define YGG_COMMON_FILESYSTEM_DIRECTORIES_H_INCLUDED

namespace ygg {
namespace filesystem {

/**
 * Get the path to a directory where configuration files may be stored for this application
 */
const char * get_user_config_dir();

} /* namespace ygg::filesystem */
}

#endif /* YGG_COMMON_FILESYSTEM_DIRECTORIES_H_INCLUDED */
