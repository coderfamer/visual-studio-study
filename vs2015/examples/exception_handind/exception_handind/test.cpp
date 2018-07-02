#include <stdlib.h>
#include <iostream>
#include <crtdbg.h>

void myInvalidParameterHandler(
	const wchar_t* expression,
	const wchar_t* function,
	const wchar_t* file,
	unsigned int line,
	uintptr_t pReserved)
{
	wprintf(L"Invalid parameter detected in funcion %s.\n "
		L"File: %s.\n Line: %d\n", function, file, line);
	wprintf(L"Expression:%s\n", expression);
	abort();
}

int main()
{
	char* formatString;

	_invalid_parameter_handler oldHandler, newHandler;
	newHandler = myInvalidParameterHandler;
	oldHandler = _set_invalid_parameter_handler(newHandler);

	_CrtSetReportMode(_CRT_ASSERT, 0);

	formatString = NULL;
	printf(formatString);


	return 0;
}