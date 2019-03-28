set(FIND_JNALINK_PATHS /Users/casperskjaerris/Documents/cApp/JNALink)
#set(FIND_DYLIB /Users/casperskjaerris/Documents/cApp)

find_path(JNALink_INCLUDEDIR  JNALink.h SimulatorLink.h PATH_SUFFIXES include PATHS ${FIND_JNALINK_PATHS})

find_library(JNALink_LIBRARY NAMES JNALink PATH_SUFFIXES lib PATHS ${FIND_JNALINK_PATHS})
#find_library(JNALink_LIBRARY NAMES JNALink PATHS ${FIND_DYLIB})