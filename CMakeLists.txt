# system
cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 11)

# project
project(client C)

# sources
set(source_files
        source/Init.c
        )

# build
add_executable(client source/Init.c source/Services/TimeService.c source/Services/TimeService.h source/Services/MessageService.c source/Services/MessageService.h source/Services/ConnectService.c source/Services/ConnectService.h source/Services/RunService.c source/Services/RunService.h source/Services/AuthService.c source/Services/AuthService.h source/Services/UserEntety.c source/Services/UserEntety.h)
target_link_libraries(client ws2_32)