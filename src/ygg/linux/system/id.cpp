//
// See doc/LICENSE.md for license terms
//

const char * ygg::system::get_platform_id() {
    return "linux";
}

#include <sys/stat.h>

const char * ygg::system::get_install_id() {
    //TODO: perhaps change signature to allow in path to module name?
    return "1234567890";
}

#include <unistd.h>

/**
 * On linux, this takes the MAC address of the network interface.
 * It will prefer these interfaces, and return NULL if none are found:
 *
 * wlan0
 * eth0
 */
const char * ygg::system::get_device_id() {
    //TODO: read the contents of /sys/class/net/eth0/address
    //TODO: read the contents of /sys/class/net/wlan0/address
    return "1234567890";
}
