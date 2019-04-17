set(FIND_ARGOS_PATHS /Users/casperskjaerris/Documents/cApp/Argos)

find_path(ARGOS_INCLUDEDIR argos3 PATH_SUFFIXES include PATHS ${FIND_ARGOS_PATHS})

find_library(ARGOS_LIBRARY NAMES argos3core_simulator PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})