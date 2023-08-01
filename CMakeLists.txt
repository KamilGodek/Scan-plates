cmake_minimum_required(VERSION 3.14)
project(scanplates VERSION 0.1.0)

# Wyszukaj bibliotekę OpenCV
find_package(OpenCV REQUIRED)

if(NOT EXISTS ${CMAKE_BINARY_DIR}/Debug)    # Sprawdź istnienie folderu Debug
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)     # Jeśli folder nie istnieje, utwórz go
endif()

# Pobierz wszystkie pliki źródłowe .cpp z folderu src
file(GLOB_RECURSE SOURCES src/*.cpp)

# Dodaj pliki źródłowe do celu wykonawczego
add_executable(${PROJECT_NAME} ${SOURCES})

# Dodaj folder src do ścieżki include
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Podłącz bibliotekę OpenCV do projektu
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME}) # Ustaw nazwę projektu i wersję dla CPack
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
