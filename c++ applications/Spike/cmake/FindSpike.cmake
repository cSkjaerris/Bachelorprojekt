set(FIND_Spike_PATHS /Users/casperskjaerris/Documents/cApp/Spike)

find_path(Spike_INCLUDEDIR  spsim PATH_SUFFIXES include PATHS ${FIND_Spike_PATHS})

find_library(Spike_LIBRARY NAMES spsim_sr PATH_SUFFIXES lib PATHS ${FIND_Spike_PATHS})