ADD_LIBRARY( sqlitepp SHARED binders.cpp exception.cpp query.cpp session.cpp statement.cpp string.cpp transaction.cpp )
target_link_libraries( sqlitepp ${SQLITE3_LIBRARY_RELEASE} )
set_target_properties( sqlitepp  PROPERTIES
	  VERSION 0.5.5
	  SOVERSION 0.5.5
	)
install( TARGETS sqlitepp
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
)
