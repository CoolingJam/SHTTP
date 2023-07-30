# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-src"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-build"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/tmp"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/src/sockpp-populate-stamp"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/src"
  "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/src/sockpp-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/src/sockpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Marcel/Documents/SHTTP/build/_deps/sockpp-subbuild/sockpp-populate-prefix/src/sockpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
