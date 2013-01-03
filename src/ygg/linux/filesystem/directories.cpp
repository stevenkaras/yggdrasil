//
// See doc/LICENSE.md for license terms
//

/**
 * Get the path to a directory where files may be stored for this application
 */
const char * ygg::filesystem::get_user_config_dir() {
    //TODO: have this return the program's name inside the .config dir
    return "~/.config";
}
