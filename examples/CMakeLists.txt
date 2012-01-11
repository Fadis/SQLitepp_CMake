ADD_EXECUTABLE( ex1 ex1.cpp )
ADD_EXECUTABLE( ex2 ex2.cpp )
target_link_libraries( ex1 sqlitepp )
target_link_libraries( ex2 sqlitepp )
