set(FIND_ARGOS_PATHS /Users/casperskjaerris/Documents/cApp/Argos)

find_path(ARGOS_INCLUDEDIR argos3 PATH_SUFFIXES include PATHS ${FIND_ARGOS_PATHS})

find_library(ARGOS_LIBRARY NAMES argos3core_simulator PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(FOOTBOT_LIBRARY NAMES argos3plugin_simulator_footbot PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(MEDIA_LIBRARY NAMES argos3plugin_simulator_media PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(ENTITY_LIBRARY NAMES argos3plugin_simulator_entities PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(GENERIC_ROBOT_LIBRARY NAMES argos3plugin_simulator_genericrobot PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(DYNAMICS_2D_LIBRARY NAMES argos3plugin_simulator_dynamics2d PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})

find_library(QT_LIBRARY NAMES argos3plugin_simulator_qtopengl PATH_SUFFIXES lib PATHS ${FIND_ARGOS_PATHS})
