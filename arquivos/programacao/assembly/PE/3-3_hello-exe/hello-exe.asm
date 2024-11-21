
hello-exe.exe:     file format pei-i386


Disassembly of section .text:

00401000 <___mingw_CRTStartup>:
  401000:	53                   	push   ebx
  401001:	83 ec 38             	sub    esp,0x38
  401004:	a1 b4 30 40 00       	mov    eax,ds:0x4030b4
  401009:	85 c0                	test   eax,eax
  40100b:	74 1c                	je     401029 <___mingw_CRTStartup+0x29>
  40100d:	c7 44 24 08 00 00 00 	mov    DWORD PTR [esp+0x8],0x0
  401014:	00 
  401015:	c7 44 24 04 02 00 00 	mov    DWORD PTR [esp+0x4],0x2
  40101c:	00 
  40101d:	c7 04 24 00 00 00 00 	mov    DWORD PTR [esp],0x0
  401024:	ff d0                	call   eax
  401026:	83 ec 0c             	sub    esp,0xc
  401029:	c7 04 24 0a 11 40 00 	mov    DWORD PTR [esp],0x40110a
  401030:	e8 7b 0a 00 00       	call   401ab0 <_SetUnhandledExceptionFilter@4>
  401035:	50                   	push   eax
  401036:	e8 99 04 00 00       	call   4014d4 <___cpu_features_init>
  40103b:	e8 6c 05 00 00       	call   4015ac <__fpreset>
  401040:	8d 44 24 28          	lea    eax,[esp+0x28]
  401044:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  401048:	a1 00 20 40 00       	mov    eax,ds:0x402000
  40104d:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  401054:	00 
  401055:	c7 44 24 04 04 50 40 	mov    DWORD PTR [esp+0x4],0x405004
  40105c:	00 
  40105d:	c7 04 24 00 50 40 00 	mov    DWORD PTR [esp],0x405000
  401064:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  401068:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  40106c:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  401070:	e8 db 09 00 00       	call   401a50 <___getmainargs>
  401075:	a1 34 50 40 00       	mov    eax,ds:0x405034
  40107a:	85 c0                	test   eax,eax
  40107c:	74 42                	je     4010c0 <___mingw_CRTStartup+0xc0>
  40107e:	8b 1d 10 61 40 00    	mov    ebx,DWORD PTR ds:0x406110
  401084:	a3 04 20 40 00       	mov    ds:0x402004,eax
  401089:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  40108d:	8b 43 10             	mov    eax,DWORD PTR [ebx+0x10]
  401090:	89 04 24             	mov    DWORD PTR [esp],eax
  401093:	e8 c0 09 00 00       	call   401a58 <__setmode>
  401098:	a1 34 50 40 00       	mov    eax,ds:0x405034
  40109d:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4010a1:	8b 43 30             	mov    eax,DWORD PTR [ebx+0x30]
  4010a4:	89 04 24             	mov    DWORD PTR [esp],eax
  4010a7:	e8 ac 09 00 00       	call   401a58 <__setmode>
  4010ac:	a1 34 50 40 00       	mov    eax,ds:0x405034
  4010b1:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4010b5:	8b 43 50             	mov    eax,DWORD PTR [ebx+0x50]
  4010b8:	89 04 24             	mov    DWORD PTR [esp],eax
  4010bb:	e8 98 09 00 00       	call   401a58 <__setmode>
  4010c0:	e8 9b 09 00 00       	call   401a60 <___p__fmode>
  4010c5:	8b 15 04 20 40 00    	mov    edx,DWORD PTR ds:0x402004
  4010cb:	89 10                	mov    DWORD PTR [eax],edx
  4010cd:	e8 dd 05 00 00       	call   4016af <__pei386_runtime_relocator>
  4010d2:	83 e4 f0             	and    esp,0xfffffff0
  4010d5:	e8 b4 07 00 00       	call   40188e <___main>
  4010da:	e8 89 09 00 00       	call   401a68 <___p__environ>
  4010df:	8b 00                	mov    eax,DWORD PTR [eax]
  4010e1:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  4010e5:	a1 04 50 40 00       	mov    eax,ds:0x405004
  4010ea:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4010ee:	a1 00 50 40 00       	mov    eax,ds:0x405000
  4010f3:	89 04 24             	mov    DWORD PTR [esp],eax
  4010f6:	e8 55 02 00 00       	call   401350 <_main>
  4010fb:	89 c3                	mov    ebx,eax
  4010fd:	e8 6e 09 00 00       	call   401a70 <__cexit>
  401102:	89 1c 24             	mov    DWORD PTR [esp],ebx
  401105:	e8 ae 09 00 00       	call   401ab8 <_ExitProcess@4>

0040110a <__gnu_exception_handler@4>:
  40110a:	56                   	push   esi
  40110b:	53                   	push   ebx
  40110c:	83 ec 14             	sub    esp,0x14
  40110f:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  401113:	8b 00                	mov    eax,DWORD PTR [eax]
  401115:	8b 00                	mov    eax,DWORD PTR [eax]
  401117:	3d 91 00 00 c0       	cmp    eax,0xc0000091
  40111c:	77 1f                	ja     40113d <__gnu_exception_handler@4+0x33>
  40111e:	3d 8d 00 00 c0       	cmp    eax,0xc000008d
  401123:	0f 83 bc 00 00 00    	jae    4011e5 <__gnu_exception_handler@4+0xdb>
  401129:	3d 05 00 00 c0       	cmp    eax,0xc0000005
  40112e:	74 32                	je     401162 <__gnu_exception_handler@4+0x58>
  401130:	3d 1d 00 00 c0       	cmp    eax,0xc000001d
  401135:	0f 85 fc 00 00 00    	jne    401237 <__gnu_exception_handler@4+0x12d>
  40113b:	eb 6a                	jmp    4011a7 <__gnu_exception_handler@4+0x9d>
  40113d:	3d 94 00 00 c0       	cmp    eax,0xc0000094
  401142:	74 17                	je     40115b <__gnu_exception_handler@4+0x51>
  401144:	3d 96 00 00 c0       	cmp    eax,0xc0000096
  401149:	74 5c                	je     4011a7 <__gnu_exception_handler@4+0x9d>
  40114b:	3d 93 00 00 c0       	cmp    eax,0xc0000093
  401150:	0f 85 e1 00 00 00    	jne    401237 <__gnu_exception_handler@4+0x12d>
  401156:	e9 8a 00 00 00       	jmp    4011e5 <__gnu_exception_handler@4+0xdb>
  40115b:	31 db                	xor    ebx,ebx
  40115d:	e9 88 00 00 00       	jmp    4011ea <__gnu_exception_handler@4+0xe0>
  401162:	c7 44 24 04 00 00 00 	mov    DWORD PTR [esp+0x4],0x0
  401169:	00 
  40116a:	c7 04 24 0b 00 00 00 	mov    DWORD PTR [esp],0xb
  401171:	e8 02 09 00 00       	call   401a78 <_signal>
  401176:	83 f8 01             	cmp    eax,0x1
  401179:	75 11                	jne    40118c <__gnu_exception_handler@4+0x82>
  40117b:	c7 44 24 04 01 00 00 	mov    DWORD PTR [esp+0x4],0x1
  401182:	00 
  401183:	c7 04 24 0b 00 00 00 	mov    DWORD PTR [esp],0xb
  40118a:	eb 43                	jmp    4011cf <__gnu_exception_handler@4+0xc5>
  40118c:	31 f6                	xor    esi,esi
  40118e:	85 c0                	test   eax,eax
  401190:	0f 84 a3 00 00 00    	je     401239 <__gnu_exception_handler@4+0x12f>
  401196:	c7 04 24 0b 00 00 00 	mov    DWORD PTR [esp],0xb
  40119d:	ff d0                	call   eax
  40119f:	83 ce ff             	or     esi,0xffffffff
  4011a2:	e9 92 00 00 00       	jmp    401239 <__gnu_exception_handler@4+0x12f>
  4011a7:	c7 44 24 04 00 00 00 	mov    DWORD PTR [esp+0x4],0x0
  4011ae:	00 
  4011af:	c7 04 24 04 00 00 00 	mov    DWORD PTR [esp],0x4
  4011b6:	e8 bd 08 00 00       	call   401a78 <_signal>
  4011bb:	83 f8 01             	cmp    eax,0x1
  4011be:	75 16                	jne    4011d6 <__gnu_exception_handler@4+0xcc>
  4011c0:	c7 44 24 04 01 00 00 	mov    DWORD PTR [esp+0x4],0x1
  4011c7:	00 
  4011c8:	c7 04 24 04 00 00 00 	mov    DWORD PTR [esp],0x4
  4011cf:	e8 a4 08 00 00       	call   401a78 <_signal>
  4011d4:	eb c9                	jmp    40119f <__gnu_exception_handler@4+0x95>
  4011d6:	31 f6                	xor    esi,esi
  4011d8:	85 c0                	test   eax,eax
  4011da:	74 5d                	je     401239 <__gnu_exception_handler@4+0x12f>
  4011dc:	c7 04 24 04 00 00 00 	mov    DWORD PTR [esp],0x4
  4011e3:	eb b8                	jmp    40119d <__gnu_exception_handler@4+0x93>
  4011e5:	bb 01 00 00 00       	mov    ebx,0x1
  4011ea:	c7 44 24 04 00 00 00 	mov    DWORD PTR [esp+0x4],0x0
  4011f1:	00 
  4011f2:	c7 04 24 08 00 00 00 	mov    DWORD PTR [esp],0x8
  4011f9:	e8 7a 08 00 00       	call   401a78 <_signal>
  4011fe:	83 f8 01             	cmp    eax,0x1
  401201:	75 22                	jne    401225 <__gnu_exception_handler@4+0x11b>
  401203:	c7 44 24 04 01 00 00 	mov    DWORD PTR [esp+0x4],0x1
  40120a:	00 
  40120b:	83 ce ff             	or     esi,0xffffffff
  40120e:	c7 04 24 08 00 00 00 	mov    DWORD PTR [esp],0x8
  401215:	e8 5e 08 00 00       	call   401a78 <_signal>
  40121a:	85 db                	test   ebx,ebx
  40121c:	74 1b                	je     401239 <__gnu_exception_handler@4+0x12f>
  40121e:	e8 89 03 00 00       	call   4015ac <__fpreset>
  401223:	eb 14                	jmp    401239 <__gnu_exception_handler@4+0x12f>
  401225:	31 f6                	xor    esi,esi
  401227:	85 c0                	test   eax,eax
  401229:	74 0e                	je     401239 <__gnu_exception_handler@4+0x12f>
  40122b:	c7 04 24 08 00 00 00 	mov    DWORD PTR [esp],0x8
  401232:	e9 66 ff ff ff       	jmp    40119d <__gnu_exception_handler@4+0x93>
  401237:	31 f6                	xor    esi,esi
  401239:	89 f0                	mov    eax,esi
  40123b:	83 c4 14             	add    esp,0x14
  40123e:	5b                   	pop    ebx
  40123f:	5e                   	pop    esi
  401240:	c2 04 00             	ret    0x4

00401243 <_mainCRTStartup>:
  401243:	83 ec 1c             	sub    esp,0x1c
  401246:	c7 04 24 01 00 00 00 	mov    DWORD PTR [esp],0x1
  40124d:	ff 15 08 61 40 00    	call   DWORD PTR ds:0x406108
  401253:	e8 a8 fd ff ff       	call   401000 <___mingw_CRTStartup>

00401258 <_WinMainCRTStartup>:
  401258:	83 ec 1c             	sub    esp,0x1c
  40125b:	c7 04 24 02 00 00 00 	mov    DWORD PTR [esp],0x2
  401262:	ff 15 08 61 40 00    	call   DWORD PTR ds:0x406108
  401268:	e8 93 fd ff ff       	call   401000 <___mingw_CRTStartup>

0040126d <_atexit>:
  40126d:	83 ec 0c             	sub    esp,0xc
  401270:	a1 24 61 40 00       	mov    eax,ds:0x406124
  401275:	83 c4 0c             	add    esp,0xc
  401278:	ff e0                	jmp    eax

0040127a <__onexit>:
  40127a:	83 ec 0c             	sub    esp,0xc
  40127d:	a1 14 61 40 00       	mov    eax,ds:0x406114
  401282:	83 c4 0c             	add    esp,0xc
  401285:	ff e0                	jmp    eax
  401287:	90                   	nop

00401288 <___gcc_register_frame>:
  401288:	55                   	push   ebp
  401289:	89 e5                	mov    ebp,esp
  40128b:	83 ec 18             	sub    esp,0x18
  40128e:	c7 04 24 00 30 40 00 	mov    DWORD PTR [esp],0x403000
  401295:	e8 26 08 00 00       	call   401ac0 <_GetModuleHandleA@4>
  40129a:	89 c2                	mov    edx,eax
  40129c:	b8 00 00 00 00       	mov    eax,0x0
  4012a1:	85 d2                	test   edx,edx
  4012a3:	51                   	push   ecx
  4012a4:	74 12                	je     4012b8 <___gcc_register_frame+0x30>
  4012a6:	89 14 24             	mov    DWORD PTR [esp],edx
  4012a9:	c7 44 24 04 13 30 40 	mov    DWORD PTR [esp+0x4],0x403013
  4012b0:	00 
  4012b1:	e8 12 08 00 00       	call   401ac8 <_GetProcAddress@8>
  4012b6:	52                   	push   edx
  4012b7:	52                   	push   edx
  4012b8:	85 c0                	test   eax,eax
  4012ba:	74 11                	je     4012cd <___gcc_register_frame+0x45>
  4012bc:	c7 44 24 04 08 50 40 	mov    DWORD PTR [esp+0x4],0x405008
  4012c3:	00 
  4012c4:	c7 04 24 00 40 40 00 	mov    DWORD PTR [esp],0x404000
  4012cb:	ff d0                	call   eax
  4012cd:	83 3d 0c 20 40 00 00 	cmp    DWORD PTR ds:0x40200c,0x0
  4012d4:	74 37                	je     40130d <___gcc_register_frame+0x85>
  4012d6:	c7 04 24 29 30 40 00 	mov    DWORD PTR [esp],0x403029
  4012dd:	e8 de 07 00 00       	call   401ac0 <_GetModuleHandleA@4>
  4012e2:	89 c2                	mov    edx,eax
  4012e4:	b8 00 00 00 00       	mov    eax,0x0
  4012e9:	85 d2                	test   edx,edx
  4012eb:	51                   	push   ecx
  4012ec:	74 12                	je     401300 <___gcc_register_frame+0x78>
  4012ee:	89 14 24             	mov    DWORD PTR [esp],edx
  4012f1:	c7 44 24 04 37 30 40 	mov    DWORD PTR [esp+0x4],0x403037
  4012f8:	00 
  4012f9:	e8 ca 07 00 00       	call   401ac8 <_GetProcAddress@8>
  4012fe:	52                   	push   edx
  4012ff:	52                   	push   edx
  401300:	85 c0                	test   eax,eax
  401302:	74 09                	je     40130d <___gcc_register_frame+0x85>
  401304:	c7 04 24 0c 20 40 00 	mov    DWORD PTR [esp],0x40200c
  40130b:	ff d0                	call   eax
  40130d:	c9                   	leave  
  40130e:	c3                   	ret    

0040130f <___gcc_deregister_frame>:
  40130f:	55                   	push   ebp
  401310:	89 e5                	mov    ebp,esp
  401312:	83 ec 18             	sub    esp,0x18
  401315:	c7 04 24 00 30 40 00 	mov    DWORD PTR [esp],0x403000
  40131c:	e8 9f 07 00 00       	call   401ac0 <_GetModuleHandleA@4>
  401321:	89 c2                	mov    edx,eax
  401323:	b8 00 00 00 00       	mov    eax,0x0
  401328:	85 d2                	test   edx,edx
  40132a:	51                   	push   ecx
  40132b:	74 12                	je     40133f <___gcc_deregister_frame+0x30>
  40132d:	89 14 24             	mov    DWORD PTR [esp],edx
  401330:	c7 44 24 04 4b 30 40 	mov    DWORD PTR [esp+0x4],0x40304b
  401337:	00 
  401338:	e8 8b 07 00 00       	call   401ac8 <_GetProcAddress@8>
  40133d:	52                   	push   edx
  40133e:	52                   	push   edx
  40133f:	85 c0                	test   eax,eax
  401341:	74 09                	je     40134c <___gcc_deregister_frame+0x3d>
  401343:	c7 04 24 00 40 40 00 	mov    DWORD PTR [esp],0x404000
  40134a:	ff d0                	call   eax
  40134c:	c9                   	leave  
  40134d:	c3                   	ret    
  40134e:	90                   	nop
  40134f:	90                   	nop

00401350 <_main>:
  401350:	55                   	push   ebp
  401351:	89 e5                	mov    ebp,esp
  401353:	83 e4 f0             	and    esp,0xfffffff0
  401356:	83 ec 10             	sub    esp,0x10
  401359:	e8 30 05 00 00       	call   40188e <___main>
  40135e:	c7 04 24 64 30 40 00 	mov    DWORD PTR [esp],0x403064
  401365:	e8 16 07 00 00       	call   401a80 <_puts>
  40136a:	b8 03 00 00 00       	mov    eax,0x3
  40136f:	c9                   	leave  
  401370:	c3                   	ret    
  401371:	90                   	nop
  401372:	90                   	nop
  401373:	90                   	nop

00401374 <___dyn_tls_dtor@12>:
  401374:	83 ec 1c             	sub    esp,0x1c
  401377:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  40137b:	85 c0                	test   eax,eax
  40137d:	74 05                	je     401384 <___dyn_tls_dtor@12+0x10>
  40137f:	83 f8 03             	cmp    eax,0x3
  401382:	75 18                	jne    40139c <___dyn_tls_dtor@12+0x28>
  401384:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  401388:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  40138c:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  401390:	89 54 24 08          	mov    DWORD PTR [esp+0x8],edx
  401394:	89 04 24             	mov    DWORD PTR [esp],eax
  401397:	e8 47 06 00 00       	call   4019e3 <___mingw_TLScallback>
  40139c:	b8 01 00 00 00       	mov    eax,0x1
  4013a1:	83 c4 1c             	add    esp,0x1c
  4013a4:	c2 0c 00             	ret    0xc

004013a7 <___dyn_tls_init@12>:
  4013a7:	53                   	push   ebx
  4013a8:	83 ec 18             	sub    esp,0x18
  4013ab:	8b 15 1c 61 40 00    	mov    edx,DWORD PTR ds:0x40611c
  4013b1:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4013b5:	83 3a 03             	cmp    DWORD PTR [edx],0x3
  4013b8:	0f 87 b1 00 00 00    	ja     40146f <___dyn_tls_init@12+0xc8>
  4013be:	c7 05 74 50 40 00 01 	mov    DWORD PTR ds:0x405074,0x1
  4013c5:	00 00 00 
  4013c8:	c7 04 24 78 30 40 00 	mov    DWORD PTR [esp],0x403078
  4013cf:	e8 fc 06 00 00       	call   401ad0 <_LoadLibraryA@4>
  4013d4:	85 c0                	test   eax,eax
  4013d6:	53                   	push   ebx
  4013d7:	a3 30 50 40 00       	mov    ds:0x405030,eax
  4013dc:	74 33                	je     401411 <___dyn_tls_init@12+0x6a>
  4013de:	c7 44 24 04 85 30 40 	mov    DWORD PTR [esp+0x4],0x403085
  4013e5:	00 
  4013e6:	89 04 24             	mov    DWORD PTR [esp],eax
  4013e9:	e8 da 06 00 00       	call   401ac8 <_GetProcAddress@8>
  4013ee:	a3 70 50 40 00       	mov    ds:0x405070,eax
  4013f3:	a1 30 50 40 00       	mov    eax,ds:0x405030
  4013f8:	51                   	push   ecx
  4013f9:	51                   	push   ecx
  4013fa:	c7 44 24 04 a0 30 40 	mov    DWORD PTR [esp+0x4],0x4030a0
  401401:	00 
  401402:	89 04 24             	mov    DWORD PTR [esp],eax
  401405:	e8 be 06 00 00       	call   401ac8 <_GetProcAddress@8>
  40140a:	52                   	push   edx
  40140b:	52                   	push   edx
  40140c:	a3 6c 50 40 00       	mov    ds:0x40506c,eax
  401411:	a1 30 50 40 00       	mov    eax,ds:0x405030
  401416:	85 c0                	test   eax,eax
  401418:	74 12                	je     40142c <___dyn_tls_init@12+0x85>
  40141a:	83 3d 70 50 40 00 00 	cmp    DWORD PTR ds:0x405070,0x0
  401421:	74 09                	je     40142c <___dyn_tls_init@12+0x85>
  401423:	83 3d 6c 50 40 00 00 	cmp    DWORD PTR ds:0x40506c,0x0
  40142a:	75 37                	jne    401463 <___dyn_tls_init@12+0xbc>
  40142c:	85 c0                	test   eax,eax
  40142e:	c7 05 6c 50 40 00 00 	mov    DWORD PTR ds:0x40506c,0x0
  401435:	00 00 00 
  401438:	c7 05 70 50 40 00 00 	mov    DWORD PTR ds:0x405070,0x0
  40143f:	00 00 00 
  401442:	74 09                	je     40144d <___dyn_tls_init@12+0xa6>
  401444:	89 04 24             	mov    DWORD PTR [esp],eax
  401447:	e8 8c 06 00 00       	call   401ad8 <_FreeLibrary@4>
  40144c:	50                   	push   eax
  40144d:	c7 05 30 50 40 00 00 	mov    DWORD PTR ds:0x405030,0x0
  401454:	00 00 00 
  401457:	c7 05 44 50 40 00 00 	mov    DWORD PTR ds:0x405044,0x0
  40145e:	00 00 00 
  401461:	eb 5f                	jmp    4014c2 <___dyn_tls_init@12+0x11b>
  401463:	c7 05 44 50 40 00 01 	mov    DWORD PTR ds:0x405044,0x1
  40146a:	00 00 00 
  40146d:	eb 53                	jmp    4014c2 <___dyn_tls_init@12+0x11b>
  40146f:	83 3d 44 50 40 00 02 	cmp    DWORD PTR ds:0x405044,0x2
  401476:	74 0a                	je     401482 <___dyn_tls_init@12+0xdb>
  401478:	c7 05 44 50 40 00 02 	mov    DWORD PTR ds:0x405044,0x2
  40147f:	00 00 00 
  401482:	83 f8 02             	cmp    eax,0x2
  401485:	74 21                	je     4014a8 <___dyn_tls_init@12+0x101>
  401487:	48                   	dec    eax
  401488:	75 38                	jne    4014c2 <___dyn_tls_init@12+0x11b>
  40148a:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  40148e:	c7 44 24 04 01 00 00 	mov    DWORD PTR [esp+0x4],0x1
  401495:	00 
  401496:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  40149a:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  40149e:	89 04 24             	mov    DWORD PTR [esp],eax
  4014a1:	e8 3d 05 00 00       	call   4019e3 <___mingw_TLScallback>
  4014a6:	eb 1a                	jmp    4014c2 <___dyn_tls_init@12+0x11b>
  4014a8:	bb 14 70 40 00       	mov    ebx,0x407014
  4014ad:	eb 0b                	jmp    4014ba <___dyn_tls_init@12+0x113>
  4014af:	8b 03                	mov    eax,DWORD PTR [ebx]
  4014b1:	85 c0                	test   eax,eax
  4014b3:	74 02                	je     4014b7 <___dyn_tls_init@12+0x110>
  4014b5:	ff d0                	call   eax
  4014b7:	83 c3 04             	add    ebx,0x4
  4014ba:	81 fb 14 70 40 00    	cmp    ebx,0x407014
  4014c0:	75 ed                	jne    4014af <___dyn_tls_init@12+0x108>
  4014c2:	b8 01 00 00 00       	mov    eax,0x1
  4014c7:	83 c4 18             	add    esp,0x18
  4014ca:	5b                   	pop    ebx
  4014cb:	c2 0c 00             	ret    0xc

004014ce <___tlregdtor>:
  4014ce:	31 c0                	xor    eax,eax
  4014d0:	c3                   	ret    
  4014d1:	90                   	nop
  4014d2:	90                   	nop
  4014d3:	90                   	nop

004014d4 <___cpu_features_init>:
  4014d4:	53                   	push   ebx
  4014d5:	9c                   	pushf  
  4014d6:	9c                   	pushf  
  4014d7:	58                   	pop    eax
  4014d8:	89 c2                	mov    edx,eax
  4014da:	35 00 00 20 00       	xor    eax,0x200000
  4014df:	50                   	push   eax
  4014e0:	9d                   	popf   
  4014e1:	9c                   	pushf  
  4014e2:	58                   	pop    eax
  4014e3:	9d                   	popf   
  4014e4:	31 d0                	xor    eax,edx
  4014e6:	a9 00 00 20 00       	test   eax,0x200000
  4014eb:	0f 84 b7 00 00 00    	je     4015a8 <___cpu_features_init+0xd4>
  4014f1:	31 c0                	xor    eax,eax
  4014f3:	0f a2                	cpuid  
  4014f5:	85 c0                	test   eax,eax
  4014f7:	0f 84 ab 00 00 00    	je     4015a8 <___cpu_features_init+0xd4>
  4014fd:	b8 01 00 00 00       	mov    eax,0x1
  401502:	0f a2                	cpuid  
  401504:	f6 c6 01             	test   dh,0x1
  401507:	74 07                	je     401510 <___cpu_features_init+0x3c>
  401509:	83 0d 38 50 40 00 01 	or     DWORD PTR ds:0x405038,0x1
  401510:	f6 c6 80             	test   dh,0x80
  401513:	74 07                	je     40151c <___cpu_features_init+0x48>
  401515:	83 0d 38 50 40 00 02 	or     DWORD PTR ds:0x405038,0x2
  40151c:	f7 c2 00 00 80 00    	test   edx,0x800000
  401522:	74 07                	je     40152b <___cpu_features_init+0x57>
  401524:	83 0d 38 50 40 00 04 	or     DWORD PTR ds:0x405038,0x4
  40152b:	f7 c2 00 00 00 01    	test   edx,0x1000000
  401531:	74 07                	je     40153a <___cpu_features_init+0x66>
  401533:	83 0d 38 50 40 00 08 	or     DWORD PTR ds:0x405038,0x8
  40153a:	f7 c2 00 00 00 02    	test   edx,0x2000000
  401540:	74 07                	je     401549 <___cpu_features_init+0x75>
  401542:	83 0d 38 50 40 00 10 	or     DWORD PTR ds:0x405038,0x10
  401549:	81 e2 00 00 00 04    	and    edx,0x4000000
  40154f:	74 07                	je     401558 <___cpu_features_init+0x84>
  401551:	83 0d 38 50 40 00 20 	or     DWORD PTR ds:0x405038,0x20
  401558:	f6 c1 01             	test   cl,0x1
  40155b:	74 07                	je     401564 <___cpu_features_init+0x90>
  40155d:	83 0d 38 50 40 00 40 	or     DWORD PTR ds:0x405038,0x40
  401564:	80 e5 20             	and    ch,0x20
  401567:	74 0a                	je     401573 <___cpu_features_init+0x9f>
  401569:	81 0d 38 50 40 00 80 	or     DWORD PTR ds:0x405038,0x80
  401570:	00 00 00 
  401573:	b8 00 00 00 80       	mov    eax,0x80000000
  401578:	0f a2                	cpuid  
  40157a:	3d 00 00 00 80       	cmp    eax,0x80000000
  40157f:	76 27                	jbe    4015a8 <___cpu_features_init+0xd4>
  401581:	b8 01 00 00 80       	mov    eax,0x80000001
  401586:	0f a2                	cpuid  
  401588:	85 d2                	test   edx,edx
  40158a:	79 0a                	jns    401596 <___cpu_features_init+0xc2>
  40158c:	81 0d 38 50 40 00 00 	or     DWORD PTR ds:0x405038,0x100
  401593:	01 00 00 
  401596:	81 e2 00 00 00 40    	and    edx,0x40000000
  40159c:	74 0a                	je     4015a8 <___cpu_features_init+0xd4>
  40159e:	81 0d 38 50 40 00 00 	or     DWORD PTR ds:0x405038,0x200
  4015a5:	02 00 00 
  4015a8:	5b                   	pop    ebx
  4015a9:	c3                   	ret    
  4015aa:	90                   	nop
  4015ab:	90                   	nop

004015ac <__fpreset>:
  4015ac:	db e3                	fninit 
  4015ae:	c3                   	ret    
  4015af:	90                   	nop

004015b0 <___report_error>:
  4015b0:	56                   	push   esi
  4015b1:	53                   	push   ebx
  4015b2:	83 ec 14             	sub    esp,0x14
  4015b5:	8b 1d 10 61 40 00    	mov    ebx,DWORD PTR ds:0x406110
  4015bb:	c7 04 24 b8 30 40 00 	mov    DWORD PTR [esp],0x4030b8
  4015c2:	8d 74 24 24          	lea    esi,[esp+0x24]
  4015c6:	83 c3 40             	add    ebx,0x40
  4015c9:	89 5c 24 04          	mov    DWORD PTR [esp+0x4],ebx
  4015cd:	e8 b6 04 00 00       	call   401a88 <_fputs>
  4015d2:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4015d6:	89 74 24 08          	mov    DWORD PTR [esp+0x8],esi
  4015da:	89 1c 24             	mov    DWORD PTR [esp],ebx
  4015dd:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4015e1:	e8 aa 04 00 00       	call   401a90 <_vfprintf>
  4015e6:	e8 ad 04 00 00       	call   401a98 <_abort>

004015eb <___write_memory>:
  4015eb:	55                   	push   ebp
  4015ec:	89 cd                	mov    ebp,ecx
  4015ee:	57                   	push   edi
  4015ef:	56                   	push   esi
  4015f0:	89 d6                	mov    esi,edx
  4015f2:	53                   	push   ebx
  4015f3:	89 c3                	mov    ebx,eax
  4015f5:	83 ec 3c             	sub    esp,0x3c
  4015f8:	85 c9                	test   ecx,ecx
  4015fa:	0f 84 a7 00 00 00    	je     4016a7 <___write_memory+0xbc>
  401600:	8d 44 24 10          	lea    eax,[esp+0x10]
  401604:	c7 44 24 08 1c 00 00 	mov    DWORD PTR [esp+0x8],0x1c
  40160b:	00 
  40160c:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  401610:	89 1c 24             	mov    DWORD PTR [esp],ebx
  401613:	e8 c8 04 00 00       	call   401ae0 <_VirtualQuery@12>
  401618:	83 ec 0c             	sub    esp,0xc
  40161b:	85 c0                	test   eax,eax
  40161d:	75 18                	jne    401637 <___write_memory+0x4c>
  40161f:	89 5c 24 08          	mov    DWORD PTR [esp+0x8],ebx
  401623:	c7 44 24 04 1c 00 00 	mov    DWORD PTR [esp+0x4],0x1c
  40162a:	00 
  40162b:	c7 04 24 d0 30 40 00 	mov    DWORD PTR [esp],0x4030d0
  401632:	e8 79 ff ff ff       	call   4015b0 <___report_error>
  401637:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  40163b:	83 f8 04             	cmp    eax,0x4
  40163e:	74 2c                	je     40166c <___write_memory+0x81>
  401640:	83 f8 40             	cmp    eax,0x40
  401643:	74 27                	je     40166c <___write_memory+0x81>
  401645:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  401649:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  40164d:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  401651:	c7 44 24 08 40 00 00 	mov    DWORD PTR [esp+0x8],0x40
  401658:	00 
  401659:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  40165d:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  401661:	89 04 24             	mov    DWORD PTR [esp],eax
  401664:	e8 7f 04 00 00       	call   401ae8 <_VirtualProtect@16>
  401669:	83 ec 10             	sub    esp,0x10
  40166c:	89 df                	mov    edi,ebx
  40166e:	89 e9                	mov    ecx,ebp
  401670:	f3 a4                	rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  401672:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  401676:	83 f8 04             	cmp    eax,0x4
  401679:	74 2c                	je     4016a7 <___write_memory+0xbc>
  40167b:	83 f8 40             	cmp    eax,0x40
  40167e:	74 27                	je     4016a7 <___write_memory+0xbc>
  401680:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  401684:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  401688:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  40168c:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  401690:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  401694:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  401698:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  40169c:	89 04 24             	mov    DWORD PTR [esp],eax
  40169f:	e8 44 04 00 00       	call   401ae8 <_VirtualProtect@16>
  4016a4:	83 ec 10             	sub    esp,0x10
  4016a7:	83 c4 3c             	add    esp,0x3c
  4016aa:	5b                   	pop    ebx
  4016ab:	5e                   	pop    esi
  4016ac:	5f                   	pop    edi
  4016ad:	5d                   	pop    ebp
  4016ae:	c3                   	ret    

004016af <__pei386_runtime_relocator>:
  4016af:	55                   	push   ebp
  4016b0:	57                   	push   edi
  4016b1:	56                   	push   esi
  4016b2:	53                   	push   ebx
  4016b3:	83 ec 2c             	sub    esp,0x2c
  4016b6:	83 3d 3c 50 40 00 00 	cmp    DWORD PTR ds:0x40503c,0x0
  4016bd:	0f 85 65 01 00 00    	jne    401828 <__pei386_runtime_relocator+0x179>
  4016c3:	b8 60 31 40 00       	mov    eax,0x403160
  4016c8:	2d 60 31 40 00       	sub    eax,0x403160
  4016cd:	83 f8 07             	cmp    eax,0x7
  4016d0:	c7 05 3c 50 40 00 01 	mov    DWORD PTR ds:0x40503c,0x1
  4016d7:	00 00 00 
  4016da:	0f 8e 48 01 00 00    	jle    401828 <__pei386_runtime_relocator+0x179>
  4016e0:	83 f8 0b             	cmp    eax,0xb
  4016e3:	bb 60 31 40 00       	mov    ebx,0x403160
  4016e8:	7e 21                	jle    40170b <__pei386_runtime_relocator+0x5c>
  4016ea:	83 3d 60 31 40 00 00 	cmp    DWORD PTR ds:0x403160,0x0
  4016f1:	75 18                	jne    40170b <__pei386_runtime_relocator+0x5c>
  4016f3:	83 3d 64 31 40 00 00 	cmp    DWORD PTR ds:0x403164,0x0
  4016fa:	75 0f                	jne    40170b <__pei386_runtime_relocator+0x5c>
  4016fc:	83 3d 68 31 40 00 00 	cmp    DWORD PTR ds:0x403168,0x0
  401703:	b8 6c 31 40 00       	mov    eax,0x40316c
  401708:	0f 44 d8             	cmove  ebx,eax
  40170b:	83 3b 00             	cmp    DWORD PTR [ebx],0x0
  40170e:	75 06                	jne    401716 <__pei386_runtime_relocator+0x67>
  401710:	83 7b 04 00          	cmp    DWORD PTR [ebx+0x4],0x0
  401714:	74 37                	je     40174d <__pei386_runtime_relocator+0x9e>
  401716:	8d 74 24 18          	lea    esi,[esp+0x18]
  40171a:	eb 24                	jmp    401740 <__pei386_runtime_relocator+0x91>
  40171c:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  40171f:	b9 04 00 00 00       	mov    ecx,0x4
  401724:	8d 82 00 00 40 00    	lea    eax,[edx+0x400000]
  40172a:	8b 92 00 00 40 00    	mov    edx,DWORD PTR [edx+0x400000]
  401730:	03 13                	add    edx,DWORD PTR [ebx]
  401732:	83 c3 08             	add    ebx,0x8
  401735:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  401739:	89 f2                	mov    edx,esi
  40173b:	e8 ab fe ff ff       	call   4015eb <___write_memory>
  401740:	81 fb 60 31 40 00    	cmp    ebx,0x403160
  401746:	72 d4                	jb     40171c <__pei386_runtime_relocator+0x6d>
  401748:	e9 db 00 00 00       	jmp    401828 <__pei386_runtime_relocator+0x179>
  40174d:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  401750:	83 f8 01             	cmp    eax,0x1
  401753:	74 0d                	je     401762 <__pei386_runtime_relocator+0xb3>
  401755:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  401759:	c7 04 24 01 31 40 00 	mov    DWORD PTR [esp],0x403101
  401760:	eb 77                	jmp    4017d9 <__pei386_runtime_relocator+0x12a>
  401762:	83 c3 0c             	add    ebx,0xc
  401765:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  401769:	e9 ae 00 00 00       	jmp    40181c <__pei386_runtime_relocator+0x16d>
  40176e:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  401771:	b8 00 00 40 00       	mov    eax,0x400000
  401776:	8b 3b                	mov    edi,DWORD PTR [ebx]
  401778:	03 43 04             	add    eax,DWORD PTR [ebx+0x4]
  40177b:	81 e2 ff 00 00 00    	and    edx,0xff
  401781:	83 fa 10             	cmp    edx,0x10
  401784:	8b af 00 00 40 00    	mov    ebp,DWORD PTR [edi+0x400000]
  40178a:	74 1e                	je     4017aa <__pei386_runtime_relocator+0xfb>
  40178c:	83 fa 20             	cmp    edx,0x20
  40178f:	74 2d                	je     4017be <__pei386_runtime_relocator+0x10f>
  401791:	83 fa 08             	cmp    edx,0x8
  401794:	75 30                	jne    4017c6 <__pei386_runtime_relocator+0x117>
  401796:	0f b6 08             	movzx  ecx,BYTE PTR [eax]
  401799:	f6 c1 80             	test   cl,0x80
  40179c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4017a0:	74 3c                	je     4017de <__pei386_runtime_relocator+0x12f>
  4017a2:	81 c9 00 ff ff ff    	or     ecx,0xffffff00
  4017a8:	eb 16                	jmp    4017c0 <__pei386_runtime_relocator+0x111>
  4017aa:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4017ad:	f6 c5 80             	test   ch,0x80
  4017b0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4017b4:	74 28                	je     4017de <__pei386_runtime_relocator+0x12f>
  4017b6:	81 c9 00 00 ff ff    	or     ecx,0xffff0000
  4017bc:	eb 02                	jmp    4017c0 <__pei386_runtime_relocator+0x111>
  4017be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4017c0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4017c4:	eb 18                	jmp    4017de <__pei386_runtime_relocator+0x12f>
  4017c6:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  4017cd:	00 
  4017ce:	89 54 24 04          	mov    DWORD PTR [esp+0x4],edx
  4017d2:	c7 04 24 33 31 40 00 	mov    DWORD PTR [esp],0x403133
  4017d9:	e8 d2 fd ff ff       	call   4015b0 <___report_error>
  4017de:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4017e2:	29 f9                	sub    ecx,edi
  4017e4:	81 e9 00 00 40 00    	sub    ecx,0x400000
  4017ea:	01 e9                	add    ecx,ebp
  4017ec:	83 fa 10             	cmp    edx,0x10
  4017ef:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4017f3:	74 11                	je     401806 <__pei386_runtime_relocator+0x157>
  4017f5:	83 fa 20             	cmp    edx,0x20
  4017f8:	74 13                	je     40180d <__pei386_runtime_relocator+0x15e>
  4017fa:	83 fa 08             	cmp    edx,0x8
  4017fd:	b9 01 00 00 00       	mov    ecx,0x1
  401802:	75 15                	jne    401819 <__pei386_runtime_relocator+0x16a>
  401804:	eb 0c                	jmp    401812 <__pei386_runtime_relocator+0x163>
  401806:	b9 02 00 00 00       	mov    ecx,0x2
  40180b:	eb 05                	jmp    401812 <__pei386_runtime_relocator+0x163>
  40180d:	b9 04 00 00 00       	mov    ecx,0x4
  401812:	89 f2                	mov    edx,esi
  401814:	e8 d2 fd ff ff       	call   4015eb <___write_memory>
  401819:	83 c3 0c             	add    ebx,0xc
  40181c:	81 fb 60 31 40 00    	cmp    ebx,0x403160
  401822:	0f 82 46 ff ff ff    	jb     40176e <__pei386_runtime_relocator+0xbf>
  401828:	83 c4 2c             	add    esp,0x2c
  40182b:	5b                   	pop    ebx
  40182c:	5e                   	pop    esi
  40182d:	5f                   	pop    edi
  40182e:	5d                   	pop    ebp
  40182f:	c3                   	ret    

00401830 <___do_global_dtors>:
  401830:	83 ec 0c             	sub    esp,0xc
  401833:	eb 09                	jmp    40183e <___do_global_dtors+0xe>
  401835:	ff d0                	call   eax
  401837:	83 05 08 20 40 00 04 	add    DWORD PTR ds:0x402008,0x4
  40183e:	a1 08 20 40 00       	mov    eax,ds:0x402008
  401843:	8b 00                	mov    eax,DWORD PTR [eax]
  401845:	85 c0                	test   eax,eax
  401847:	75 ec                	jne    401835 <___do_global_dtors+0x5>
  401849:	83 c4 0c             	add    esp,0xc
  40184c:	c3                   	ret    

0040184d <___do_global_ctors>:
  40184d:	53                   	push   ebx
  40184e:	83 ec 18             	sub    esp,0x18
  401851:	8b 1d 3c 1b 40 00    	mov    ebx,DWORD PTR ds:0x401b3c
  401857:	83 fb ff             	cmp    ebx,0xffffffff
  40185a:	75 1d                	jne    401879 <___do_global_ctors+0x2c>
  40185c:	31 db                	xor    ebx,ebx
  40185e:	eb 02                	jmp    401862 <___do_global_ctors+0x15>
  401860:	89 c3                	mov    ebx,eax
  401862:	8d 43 01             	lea    eax,[ebx+0x1]
  401865:	83 3c 85 3c 1b 40 00 	cmp    DWORD PTR [eax*4+0x401b3c],0x0
  40186c:	00 
  40186d:	75 f1                	jne    401860 <___do_global_ctors+0x13>
  40186f:	eb 08                	jmp    401879 <___do_global_ctors+0x2c>
  401871:	ff 14 9d 3c 1b 40 00 	call   DWORD PTR [ebx*4+0x401b3c]
  401878:	4b                   	dec    ebx
  401879:	85 db                	test   ebx,ebx
  40187b:	75 f4                	jne    401871 <___do_global_ctors+0x24>
  40187d:	c7 04 24 30 18 40 00 	mov    DWORD PTR [esp],0x401830
  401884:	e8 e4 f9 ff ff       	call   40126d <_atexit>
  401889:	83 c4 18             	add    esp,0x18
  40188c:	5b                   	pop    ebx
  40188d:	c3                   	ret    

0040188e <___main>:
  40188e:	83 ec 0c             	sub    esp,0xc
  401891:	83 3d 40 50 40 00 00 	cmp    DWORD PTR ds:0x405040,0x0
  401898:	75 0f                	jne    4018a9 <___main+0x1b>
  40189a:	c7 05 40 50 40 00 01 	mov    DWORD PTR ds:0x405040,0x1
  4018a1:	00 00 00 
  4018a4:	83 c4 0c             	add    esp,0xc
  4018a7:	eb a4                	jmp    40184d <___do_global_ctors>
  4018a9:	83 c4 0c             	add    esp,0xc
  4018ac:	c3                   	ret    
  4018ad:	90                   	nop
  4018ae:	90                   	nop
  4018af:	90                   	nop

004018b0 <___mingwthr_run_key_dtors>:
  4018b0:	56                   	push   esi
  4018b1:	53                   	push   ebx
  4018b2:	83 ec 14             	sub    esp,0x14
  4018b5:	a1 48 50 40 00       	mov    eax,ds:0x405048
  4018ba:	85 c0                	test   eax,eax
  4018bc:	74 4b                	je     401909 <___mingwthr_run_key_dtors+0x59>
  4018be:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  4018c5:	e8 26 02 00 00       	call   401af0 <_EnterCriticalSection@4>
  4018ca:	8b 1d 64 50 40 00    	mov    ebx,DWORD PTR ds:0x405064
  4018d0:	51                   	push   ecx
  4018d1:	eb 25                	jmp    4018f8 <___mingwthr_run_key_dtors+0x48>
  4018d3:	8b 03                	mov    eax,DWORD PTR [ebx]
  4018d5:	89 04 24             	mov    DWORD PTR [esp],eax
  4018d8:	e8 1b 02 00 00       	call   401af8 <_TlsGetValue@4>
  4018dd:	52                   	push   edx
  4018de:	89 c6                	mov    esi,eax
  4018e0:	e8 1b 02 00 00       	call   401b00 <_GetLastError@0>
  4018e5:	85 c0                	test   eax,eax
  4018e7:	75 0c                	jne    4018f5 <___mingwthr_run_key_dtors+0x45>
  4018e9:	85 f6                	test   esi,esi
  4018eb:	74 08                	je     4018f5 <___mingwthr_run_key_dtors+0x45>
  4018ed:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4018f0:	89 34 24             	mov    DWORD PTR [esp],esi
  4018f3:	ff d0                	call   eax
  4018f5:	8b 5b 08             	mov    ebx,DWORD PTR [ebx+0x8]
  4018f8:	85 db                	test   ebx,ebx
  4018fa:	75 d7                	jne    4018d3 <___mingwthr_run_key_dtors+0x23>
  4018fc:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  401903:	e8 00 02 00 00       	call   401b08 <_LeaveCriticalSection@4>
  401908:	50                   	push   eax
  401909:	83 c4 14             	add    esp,0x14
  40190c:	5b                   	pop    ebx
  40190d:	5e                   	pop    esi
  40190e:	c3                   	ret    

0040190f <____w64_mingwthr_add_key_dtor>:
  40190f:	53                   	push   ebx
  401910:	31 c0                	xor    eax,eax
  401912:	83 ec 18             	sub    esp,0x18
  401915:	8b 15 48 50 40 00    	mov    edx,DWORD PTR ds:0x405048
  40191b:	85 d2                	test   edx,edx
  40191d:	74 54                	je     401973 <____w64_mingwthr_add_key_dtor+0x64>
  40191f:	c7 44 24 04 0c 00 00 	mov    DWORD PTR [esp+0x4],0xc
  401926:	00 
  401927:	c7 04 24 01 00 00 00 	mov    DWORD PTR [esp],0x1
  40192e:	e8 6d 01 00 00       	call   401aa0 <_calloc>
  401933:	89 c3                	mov    ebx,eax
  401935:	83 c8 ff             	or     eax,0xffffffff
  401938:	85 db                	test   ebx,ebx
  40193a:	74 37                	je     401973 <____w64_mingwthr_add_key_dtor+0x64>
  40193c:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  401940:	89 03                	mov    DWORD PTR [ebx],eax
  401942:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  401946:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  401949:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  401950:	e8 9b 01 00 00       	call   401af0 <_EnterCriticalSection@4>
  401955:	50                   	push   eax
  401956:	a1 64 50 40 00       	mov    eax,ds:0x405064
  40195b:	89 1d 64 50 40 00    	mov    DWORD PTR ds:0x405064,ebx
  401961:	89 43 08             	mov    DWORD PTR [ebx+0x8],eax
  401964:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  40196b:	e8 98 01 00 00       	call   401b08 <_LeaveCriticalSection@4>
  401970:	31 c0                	xor    eax,eax
  401972:	53                   	push   ebx
  401973:	83 c4 18             	add    esp,0x18
  401976:	5b                   	pop    ebx
  401977:	c3                   	ret    

00401978 <____w64_mingwthr_remove_key_dtor>:
  401978:	53                   	push   ebx
  401979:	83 ec 18             	sub    esp,0x18
  40197c:	a1 48 50 40 00       	mov    eax,ds:0x405048
  401981:	8b 5c 24 20          	mov    ebx,DWORD PTR [esp+0x20]
  401985:	85 c0                	test   eax,eax
  401987:	74 53                	je     4019dc <____w64_mingwthr_remove_key_dtor+0x64>
  401989:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  401990:	e8 5b 01 00 00       	call   401af0 <_EnterCriticalSection@4>
  401995:	a1 64 50 40 00       	mov    eax,ds:0x405064
  40199a:	31 d2                	xor    edx,edx
  40199c:	51                   	push   ecx
  40199d:	eb 2c                	jmp    4019cb <____w64_mingwthr_remove_key_dtor+0x53>
  40199f:	8b 08                	mov    ecx,DWORD PTR [eax]
  4019a1:	39 d9                	cmp    ecx,ebx
  4019a3:	75 1f                	jne    4019c4 <____w64_mingwthr_remove_key_dtor+0x4c>
  4019a5:	85 d2                	test   edx,edx
  4019a7:	75 0b                	jne    4019b4 <____w64_mingwthr_remove_key_dtor+0x3c>
  4019a9:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4019ac:	89 15 64 50 40 00    	mov    DWORD PTR ds:0x405064,edx
  4019b2:	eb 06                	jmp    4019ba <____w64_mingwthr_remove_key_dtor+0x42>
  4019b4:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4019b7:	89 4a 08             	mov    DWORD PTR [edx+0x8],ecx
  4019ba:	89 04 24             	mov    DWORD PTR [esp],eax
  4019bd:	e8 e6 00 00 00       	call   401aa8 <_free>
  4019c2:	eb 0b                	jmp    4019cf <____w64_mingwthr_remove_key_dtor+0x57>
  4019c4:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4019c7:	89 c2                	mov    edx,eax
  4019c9:	89 c8                	mov    eax,ecx
  4019cb:	85 c0                	test   eax,eax
  4019cd:	75 d0                	jne    40199f <____w64_mingwthr_remove_key_dtor+0x27>
  4019cf:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  4019d6:	e8 2d 01 00 00       	call   401b08 <_LeaveCriticalSection@4>
  4019db:	52                   	push   edx
  4019dc:	31 c0                	xor    eax,eax
  4019de:	83 c4 18             	add    esp,0x18
  4019e1:	5b                   	pop    ebx
  4019e2:	c3                   	ret    

004019e3 <___mingw_TLScallback>:
  4019e3:	83 ec 1c             	sub    esp,0x1c
  4019e6:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4019ea:	83 f8 01             	cmp    eax,0x1
  4019ed:	74 09                	je     4019f8 <___mingw_TLScallback+0x15>
  4019ef:	72 29                	jb     401a1a <___mingw_TLScallback+0x37>
  4019f1:	83 f8 03             	cmp    eax,0x3
  4019f4:	75 4f                	jne    401a45 <___mingw_TLScallback+0x62>
  4019f6:	eb 48                	jmp    401a40 <___mingw_TLScallback+0x5d>
  4019f8:	a1 48 50 40 00       	mov    eax,ds:0x405048
  4019fd:	85 c0                	test   eax,eax
  4019ff:	75 0d                	jne    401a0e <___mingw_TLScallback+0x2b>
  401a01:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  401a08:	e8 03 01 00 00       	call   401b10 <_InitializeCriticalSection@4>
  401a0d:	52                   	push   edx
  401a0e:	c7 05 48 50 40 00 01 	mov    DWORD PTR ds:0x405048,0x1
  401a15:	00 00 00 
  401a18:	eb 2b                	jmp    401a45 <___mingw_TLScallback+0x62>
  401a1a:	e8 91 fe ff ff       	call   4018b0 <___mingwthr_run_key_dtors>
  401a1f:	a1 48 50 40 00       	mov    eax,ds:0x405048
  401a24:	48                   	dec    eax
  401a25:	75 1e                	jne    401a45 <___mingw_TLScallback+0x62>
  401a27:	c7 05 48 50 40 00 00 	mov    DWORD PTR ds:0x405048,0x0
  401a2e:	00 00 00 
  401a31:	c7 04 24 4c 50 40 00 	mov    DWORD PTR [esp],0x40504c
  401a38:	e8 db 00 00 00       	call   401b18 <_DeleteCriticalSection@4>
  401a3d:	50                   	push   eax
  401a3e:	eb 05                	jmp    401a45 <___mingw_TLScallback+0x62>
  401a40:	e8 6b fe ff ff       	call   4018b0 <___mingwthr_run_key_dtors>
  401a45:	b8 01 00 00 00       	mov    eax,0x1
  401a4a:	83 c4 1c             	add    esp,0x1c
  401a4d:	c3                   	ret    
  401a4e:	90                   	nop
  401a4f:	90                   	nop

00401a50 <___getmainargs>:
  401a50:	ff 25 fc 60 40 00    	jmp    DWORD PTR ds:0x4060fc
  401a56:	90                   	nop
  401a57:	90                   	nop

00401a58 <__setmode>:
  401a58:	ff 25 18 61 40 00    	jmp    DWORD PTR ds:0x406118
  401a5e:	90                   	nop
  401a5f:	90                   	nop

00401a60 <___p__fmode>:
  401a60:	ff 25 04 61 40 00    	jmp    DWORD PTR ds:0x406104
  401a66:	90                   	nop
  401a67:	90                   	nop

00401a68 <___p__environ>:
  401a68:	ff 25 00 61 40 00    	jmp    DWORD PTR ds:0x406100
  401a6e:	90                   	nop
  401a6f:	90                   	nop

00401a70 <__cexit>:
  401a70:	ff 25 0c 61 40 00    	jmp    DWORD PTR ds:0x40610c
  401a76:	90                   	nop
  401a77:	90                   	nop

00401a78 <_signal>:
  401a78:	ff 25 38 61 40 00    	jmp    DWORD PTR ds:0x406138
  401a7e:	90                   	nop
  401a7f:	90                   	nop

00401a80 <_puts>:
  401a80:	ff 25 34 61 40 00    	jmp    DWORD PTR ds:0x406134
  401a86:	90                   	nop
  401a87:	90                   	nop

00401a88 <_fputs>:
  401a88:	ff 25 2c 61 40 00    	jmp    DWORD PTR ds:0x40612c
  401a8e:	90                   	nop
  401a8f:	90                   	nop

00401a90 <_vfprintf>:
  401a90:	ff 25 3c 61 40 00    	jmp    DWORD PTR ds:0x40613c
  401a96:	90                   	nop
  401a97:	90                   	nop

00401a98 <_abort>:
  401a98:	ff 25 20 61 40 00    	jmp    DWORD PTR ds:0x406120
  401a9e:	90                   	nop
  401a9f:	90                   	nop

00401aa0 <_calloc>:
  401aa0:	ff 25 28 61 40 00    	jmp    DWORD PTR ds:0x406128
  401aa6:	90                   	nop
  401aa7:	90                   	nop

00401aa8 <_free>:
  401aa8:	ff 25 30 61 40 00    	jmp    DWORD PTR ds:0x406130
  401aae:	90                   	nop
  401aaf:	90                   	nop

00401ab0 <_SetUnhandledExceptionFilter@4>:
  401ab0:	ff 25 e8 60 40 00    	jmp    DWORD PTR ds:0x4060e8
  401ab6:	90                   	nop
  401ab7:	90                   	nop

00401ab8 <_ExitProcess@4>:
  401ab8:	ff 25 c8 60 40 00    	jmp    DWORD PTR ds:0x4060c8
  401abe:	90                   	nop
  401abf:	90                   	nop

00401ac0 <_GetModuleHandleA@4>:
  401ac0:	ff 25 d4 60 40 00    	jmp    DWORD PTR ds:0x4060d4
  401ac6:	90                   	nop
  401ac7:	90                   	nop

00401ac8 <_GetProcAddress@8>:
  401ac8:	ff 25 d8 60 40 00    	jmp    DWORD PTR ds:0x4060d8
  401ace:	90                   	nop
  401acf:	90                   	nop

00401ad0 <_LoadLibraryA@4>:
  401ad0:	ff 25 e4 60 40 00    	jmp    DWORD PTR ds:0x4060e4
  401ad6:	90                   	nop
  401ad7:	90                   	nop

00401ad8 <_FreeLibrary@4>:
  401ad8:	ff 25 cc 60 40 00    	jmp    DWORD PTR ds:0x4060cc
  401ade:	90                   	nop
  401adf:	90                   	nop

00401ae0 <_VirtualQuery@12>:
  401ae0:	ff 25 f4 60 40 00    	jmp    DWORD PTR ds:0x4060f4
  401ae6:	90                   	nop
  401ae7:	90                   	nop

00401ae8 <_VirtualProtect@16>:
  401ae8:	ff 25 f0 60 40 00    	jmp    DWORD PTR ds:0x4060f0
  401aee:	90                   	nop
  401aef:	90                   	nop

00401af0 <_EnterCriticalSection@4>:
  401af0:	ff 25 c4 60 40 00    	jmp    DWORD PTR ds:0x4060c4
  401af6:	90                   	nop
  401af7:	90                   	nop

00401af8 <_TlsGetValue@4>:
  401af8:	ff 25 ec 60 40 00    	jmp    DWORD PTR ds:0x4060ec
  401afe:	90                   	nop
  401aff:	90                   	nop

00401b00 <_GetLastError@0>:
  401b00:	ff 25 d0 60 40 00    	jmp    DWORD PTR ds:0x4060d0
  401b06:	90                   	nop
  401b07:	90                   	nop

00401b08 <_LeaveCriticalSection@4>:
  401b08:	ff 25 e0 60 40 00    	jmp    DWORD PTR ds:0x4060e0
  401b0e:	90                   	nop
  401b0f:	90                   	nop

00401b10 <_InitializeCriticalSection@4>:
  401b10:	ff 25 dc 60 40 00    	jmp    DWORD PTR ds:0x4060dc
  401b16:	90                   	nop
  401b17:	90                   	nop

00401b18 <_DeleteCriticalSection@4>:
  401b18:	ff 25 c0 60 40 00    	jmp    DWORD PTR ds:0x4060c0
  401b1e:	90                   	nop
  401b1f:	90                   	nop

00401b20 <_register_frame_ctor>:
  401b20:	55                   	push   ebp
  401b21:	89 e5                	mov    ebp,esp
  401b23:	83 ec 18             	sub    esp,0x18
  401b26:	e8 5d f7 ff ff       	call   401288 <___gcc_register_frame>
  401b2b:	c7 04 24 0f 13 40 00 	mov    DWORD PTR [esp],0x40130f
  401b32:	e8 36 f7 ff ff       	call   40126d <_atexit>
  401b37:	c9                   	leave  
  401b38:	c3                   	ret    
  401b39:	90                   	nop
  401b3a:	90                   	nop
  401b3b:	90                   	nop

00401b3c <__CTOR_LIST__>:
  401b3c:	ff                   	(bad)  
  401b3d:	ff                   	(bad)  
  401b3e:	ff                   	(bad)  
  401b3f:	ff 20                	jmp    DWORD PTR [eax]

00401b40 <.ctors.65535>:
  401b40:	20 1b                	and    BYTE PTR [ebx],bl
  401b42:	40                   	inc    eax
  401b43:	00 00                	add    BYTE PTR [eax],al
  401b45:	00 00                	add    BYTE PTR [eax],al
	...

00401b48 <__DTOR_LIST__>:
  401b48:	ff                   	(bad)  
  401b49:	ff                   	(bad)  
  401b4a:	ff                   	(bad)  
  401b4b:	ff 00                	inc    DWORD PTR [eax]
  401b4d:	00 00                	add    BYTE PTR [eax],al
	...
