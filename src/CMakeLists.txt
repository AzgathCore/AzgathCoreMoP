# Copyright 2023 AzgathCore
# 
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_subdirectory(genrev)
add_subdirectory(server)

if(TOOLS)
  if( MSVC )
    add_subdirectory(tools)
  else()
    add_definitions(-std=c++11)
    add_subdirectory(tools)
  endif()
endif(TOOLS)

if (UPDATER)
  add_subdirectory(updater)
endif()

if ( ELUNA )
  add_subdirectory(LuaEngine)
endif(ELUNA)
