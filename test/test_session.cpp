// $Id: test_session.cpp 83 2011-04-06 06:48:22Z pmed $

#include <stdio.h>
#include <tut.h>

#include "session_data.hpp"
#include <sqlitepp/exception.hpp>

using namespace sqlitepp;

session_data::session_data(sqlitepp::string_t const& name) : name_(name)
{
	// ensure remove previously used database
	remove(utf8(name_).c_str()); 
	se.open(name_);
}

session_data::~session_data()
{
	se.close();
	// ensure remove database
	remove(utf8(name_).c_str()); 
}

namespace tut {
	
typedef tut::test_group<session_data> session_test_group;
typedef session_test_group::object object;

session_test_group s_g("3. session");

// test open session
template<>template<>
void object::test<1>()
{
	ensure( "open", se.is_open() );
	ensure( "no active txn", !se.active_txn() );
}

// test close session
template<>template<>
void object::test<2>()
{
	se.close();
	ensure("closed", !se.is_open());
}

// test last error
template<>template<>
void object::test<3>()
{
	try
	{
		se << utf(L"select * from undefined_table");
		fail( "exception expected" );
	}
	catch(sqlitepp::exception const&)
	{
	}
}

} // namespace tut {
