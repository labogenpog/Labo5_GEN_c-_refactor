set(core_SRCS Customer.h Movie.cpp testing/mock_Movie.h)

add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)