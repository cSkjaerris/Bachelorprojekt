set(FIND_JNALink_PATH /Users/casperskjaerris/Documents/cApp/JNALink)
set(FIND_DYLIB /Users/casperskjaerris/Documents/cApp)

find_path(JNALink_INCLUDEDIR SimulatorLink.h PATH_SUFFIXES include PATHS ${FIND_JNALink_PATH})

find_library(JNALink_LIBRARY NAMES JNALink PATH_SUFFIXES lib PATHS ${FIND_JNALink_PATH})