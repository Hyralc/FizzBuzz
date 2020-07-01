
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Make found targets globally available.
if (Boost_FOUND)
	set_target_properties(Boost::unit_test_framework PROPERTIES IMPORTED_GLOBAL TRUE)
endif()
