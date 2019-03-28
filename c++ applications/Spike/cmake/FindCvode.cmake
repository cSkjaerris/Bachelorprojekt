set(FIND_Cvode_PATHS /usr/local/sundials/builddir/src/cvode)

find_path(CVODE_INCLUDE_DIRS cvode.h PATH_SUFFIXES include PATHS ${FIND_Cvode_PATHS})

find_library(CVODE_LIBRARIES NAMES sundials_cvode PATHS ${FIND_Cvode_PATHS})

