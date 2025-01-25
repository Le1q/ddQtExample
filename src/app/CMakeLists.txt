qt_add_executable(helloworld
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

target_link_libraries(helloworld PRIVATE businesslogic Qt6::Widgets ${OpenCV_LIBS})
target_include_directories(helloworld PRIVATE ${OpenCV_INCLUDE_DIRS})
# set_target_properties(helloworld PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )