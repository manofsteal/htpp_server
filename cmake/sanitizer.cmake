#copyright: dungnd

#note: thread and memory check cannot be together

option(MEMORY_SANITIZER_ENABLE "enable memory sanitizer" ON)
option(THREAD_SANITIZER_ENABLE "enable thread sanitizer" OFF)


set(ADDRESS_CHECK "-fsanitize=address")
set(LEAK_CHECK "-fsanitize=leak")
set(UNDEFINED_CHECK "-fsanitize=undefined")

set(MEMORY_SANITIZER_FLAGS "${ADDRESS_CHECK} ${LEAK_CHECK} ${UNDEFINED_CHECK} -g")
set(THREAD_SANITIZER_FLAGS "-fsanitize=thread -g")

#more verbose info
# set(ENV{ASAN_OPTIONS} symbolize=1)
# set(ENV{ASAN_SYMBOLIZER_PATH} /usr/bin/llvm-symbolizer-6.0)

set(SANITIZER_FLAGS "")

if (MEMORY_SANITIZER_ENABLE)
    message("NOTE: MEMORY_SANITIZER_ENABLE=ON")
    set(SANITIZER_FLAGS ${MEMORY_SANITIZER_FLAGS})
    
    if (THREAD_SANITIZER_ENABLE)
        message("NOTE: THREAD_SANITIZER_ENABLE is set OFF because MEMORY_SANITIZER_ENABLE=ON")
    endif()
    
elseif(THREAD_SANITIZER_ENABLE)
    set(SANITIZER_FLAGS ${THREAD_SANITIZER_FLAGS})
else()
    set(SANITIZER_FLAGS "")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${SANITIZER_FLAGS}")
