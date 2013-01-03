//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_SYSTEM_ID_H_INCLUDED
#define YGG_COMMON_SYSTEM_ID_H_INCLUDED

namespace ygg {
namespace system {

/**
 * Get a string identifier for the platform (such as "android-4.1.2-arm")
 */
const char * get_platform_id();

/**
 * Get a unique identifier for this installation of the application.
 */
const char * get_install_id();

/**
 * Get a unique identifier for this device hardware configuration.
 *
 * This identifier should be identical every time it is run on the same device.
 * This identifier should be different for two different devices.
 */
const char * get_device_id();

} /* namespace ygg::system */
}

#endif /* YGG_COMMON_SYSTEM_ID_H_INCLUDED */
