Logging with Yggdrasil
======================
To use logging from yggdrasil, you'll need to do 2 things:

  - `#include "ygg/common/logging/logging_macros.h"` from any file you want to use the logging macros in
  - implement this function:
      void ygg::logging::platform_log(int logLevel, const char* tag, const char* filename, int linenumber, const char* message);

To log something, just use the LOG_X macros, where X is one of the following log levels:
  
  * E - error
  * W - warning
  * I - info
  * D - debug
  * V - verbose

You can set the log level by defining LOG_LEVEL before you include the logging_macros header. You can also customize the tag associated with the logs via the LOG_TAG define.