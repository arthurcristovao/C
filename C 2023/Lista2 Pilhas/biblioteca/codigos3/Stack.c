/* Replace "dll.h" with the name of your header */
#include "Stack.h"
#include <windows.h>

DLLIMPORT void push(int* array, int valor)
{
	
}

DLLIMPORT int pop(int* array)
{
	// implementar
	return 20;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
