set(FIND_JNALINK_PATHS /Users/casperskjaerris/Documents/cApp/JNALink)

find_path(JNALink_INCLUDEDIR SimulatorLink.h PATH_SUFFIXES include PATHS ${FIND_JNALINK_PATHS})

find_library(JNALink_LIBRARY NAMES JNALink PATH_SUFFIXES lib PATHS ${FIND_JNALINK_PATHS})
