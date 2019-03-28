set(FIND_JNALink_PATHS /Users/casperskjaerris/Documents/cApp/JNALink)

find_path(JNALink_INCLUDEDIR  JNALink.h SimulatorLink.h PATH_SUFFIXES include PATHS ${FIND_JNALink_PATHS})

find_library(JNALink_LIBRARY NAMES JNALink PATH_SUFFIXES lib PATHS ${FIND_JNALink_PATHS})
