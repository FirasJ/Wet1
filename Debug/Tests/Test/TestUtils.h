#ifndef _TESTUTILS_H
#define _TESTUTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using std::setw;

std::string location; // Used for finding the origin of an exception

#define FAIL(message) do { \
		std::ostringstream os; \
		os << __LINE__; \
		location = std::string(__FILE__) + ":" + os.str() + " " + message; \
		return false; \
	} while (0)

#define ASSERT_TRUE(expression) do { \
		if (!((expression))) {\
			std::ostringstream s;	\
			s << #expression << " is false"; \
			FAIL(s.str()); \
		} \
	} while (0)

#define ASSERT_FALSE(expression) do { \
		if ((expression)) {\
			FAIL("expression is false"); \
		} \
	} while (0)

#define ASSERT_EQUALS(expected,actual) do {     \
		if (!((expected) == (actual))) {\
			FAIL("values not equal"); \
		} \
	} while (0)

#define ASSERT_NOT_EQUALS(expected,actual) do { \
		if ((expected) == (actual)) {\
			FAIL("values not equal"); \
		} \
	} while (0)

#define EPSILON 1e-10
#define ASSERT_DOUBLE_EQUALS(expected, actual) do { \
		if (!(((expected)+EPSILON >= actual) && ((expected)-EPSILON <= actual))) {\
			FAIL("expression not true"); \
		} \
	} while (0)

#define ASSERT_NO_THROW(command) do {\
			try {\
			(command); \
		} catch (std::exception& e) {\
			FAIL("caught " + e.what()); \
		} catch (...) {\
			FAIL("caught unknown object"); \
		} \
	} while (0)

#define ASSERT_THROWS(exception_type,command) do {\
		try {\
			(command); \
			FAIL("missing exception"); \
		} catch (exception_type&) {	\
			\
		} catch (std::exception& e) { \
			FAIL("caught " + e.what()); \
		} catch (...) {	\
			FAIL("caught unknown object"); \
		} \
	} while (0)

#define RUN_TEST(b) do {\
		try { \
			if (b()) std::cerr << std::setw(30) << std::left << #b << ":" << "OK" << std::endl; \
			else std::cerr << setw(30) << std::left << #b << ":" << "Failed (" << location << ")" << std::endl; \
		} catch (...) { \
			std::cerr << std::setw(30) << std::left << #b << ":" << "Failed (" << location << ")" << std::endl; \
		} \
	} while (0)

#define RUN_SETUP(c) do {\
		try { \
			if (!c) return false; \
		} catch (...) {	\
			return false; \
		} \
	} while (0)

#endif