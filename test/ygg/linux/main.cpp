//
// See doc/LICENSE.md for license terms
//

#include "ygg/common/unit_tests.h"
#include "ygg/posix/posix_unit_tests.h"
#include "ygg/linux/linux_unit_tests.h"

int main(void) {
    unit_tests();
    posix_unit_tests();
    linux_unit_tests();
}
