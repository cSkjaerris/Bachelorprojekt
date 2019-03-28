set(FIND_DSSD_PATHS /Users/casperskjaerris/Documents/cApp/dssd_util)

find_path(DSSD_INCLUDE_DIRS  dssd PATH_SUFFIXES include PATHS ${FIND_DSSD_PATHS})

find_library(DSSD_LIBRARY NAMES dssd_util PATH_SUFFIXES lib PATHS ${FIND_DSSD_PATHS})
