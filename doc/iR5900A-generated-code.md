   |// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x631ac27b <m+38601339>|  nop|   0x5555649a1370 <m+77202288>|  nop|-
   0x631ac27c <m+38601340>|  addl   $0xffffffa0,0x60cd5270|   0x5555649a1371 <m+77202289>|  addq   $0xffffffffffffffa0,-0x49a7d08(%rip)        # 0x55555fff9671 <cpuRegs+465>|-
   0x631ac283 <m+38601347>|  lahf   |   0x5555649a1379 <m+77202297>|  lahf   |-
   0x631ac284 <m+38601348>|  sar    $0xf,%ax|   0x5555649a137a <m+77202298>|  sar    $0xf,%ax|-
   0x631ac288 <m+38601352>|  cwtl   |   0x5555649a137e <m+77202302>|  cwtl   |-
   0x631ac289 <m+38601353>|  mov    %eax,0x60cd5274|   0x5555649a137f <m+77202303>|  movabs %eax,0x55555fff9674|-
   0x631ac28e <m+38601358>|  nop|   0x5555649a1388 <m+77202312>|  nop|-
   0x631ac28f <m+38601359>|  nop|   0x5555649a1389 <m+77202313>|  nop|-
   0x631ac290 <m+38601360>|  mov    $0x60cd5290,%edx|   0x5555649a138a <m+77202314>|  mov    $0x5fff9690,%edx|-
   0x631ac295 <m+38601365>|  mov    0x60cd5270,%ecx|   0x5555649a138f <m+77202319>|  mov    -0x49a7d26(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac29b <m+38601371>|  add    $0x50,%ecx|   0x5555649a1396 <m+77202326>|  add    $0x50,%ecx|-
   0x631ac29e <m+38601374>|  mov    %ecx,%eax|   0x5555649a1399 <m+77202329>|  mov    %ecx,%eax|-
   0x631ac2a0 <m+38601376>|  shr    $0xc,%eax|   0x5555649a139b <m+77202331>|  shr    $0xc,%eax|-
   0x631ac2a3 <m+38601379>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a139e <m+77202334>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac2aa <m+38601386>|  mov    $0x631ac2bd,%ebx|   0x5555649a13a5 <m+77202341>|  movabs $0x5555649a13bd,%rbx|-
   0x631ac2af <m+38601391>|  add    %eax,%ecx|   0x5555649a13af <m+77202351>|  add    %eax,%ecx|-
   0x631ac2b1 <m+38601393>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a13b1 <m+77202353>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac2b7 <m+38601399>|  movlps (%edx),%xmm0|   0x5555649a13b7 <m+77202359>|  movlps (%rdx),%xmm0|-
   0x631ac2ba <m+38601402>|  movlps %xmm0,(%ecx)|   0x5555649a13ba <m+77202362>|  movlps %xmm0,(%rcx)|-
   0x631ac2bd <m+38601405>|  nop|   0x5555649a13bd <m+77202365>|  nop|-
   0x631ac2be <m+38601406>|  nop|   0x5555649a13be <m+77202366>|  nop|-
   0x631ac2bf <m+38601407>|  mov    $0x60cd51c0,%edx|   0x5555649a13bf <m+77202367>|  mov    $0x5fff95c0,%edx|-
   0x631ac2c4 <m+38601412>|  mov    0x60cd5270,%ecx|   0x5555649a13c4 <m+77202372>|  mov    -0x49a7d5b(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac2ca <m+38601418>|  add    $0x40,%ecx|   0x5555649a13cb <m+77202379>|  add    $0x40,%ecx|-
   0x631ac2cd <m+38601421>|  mov    %ecx,%eax|   0x5555649a13ce <m+77202382>|  mov    %ecx,%eax|-
   0x631ac2cf <m+38601423>|  shr    $0xc,%eax|   0x5555649a13d0 <m+77202384>|  shr    $0xc,%eax|-
   0x631ac2d2 <m+38601426>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a13d3 <m+77202387>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac2d9 <m+38601433>|  mov    $0x631ac2ec,%ebx|   0x5555649a13da <m+77202394>|  movabs $0x5555649a13f2,%rbx|-
   0x631ac2de <m+38601438>|  add    %eax,%ecx|   0x5555649a13e4 <m+77202404>|  add    %eax,%ecx|-
   0x631ac2e0 <m+38601440>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a13e6 <m+77202406>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac2e6 <m+38601446>|  movlps (%edx),%xmm1|   0x5555649a13ec <m+77202412>|  movlps (%rdx),%xmm1|-
   0x631ac2e9 <m+38601449>|  movlps %xmm1,(%ecx)|   0x5555649a13ef <m+77202415>|  movlps %xmm1,(%rcx)|-
   0x631ac2ec <m+38601452>|  nop|   0x5555649a13f2 <m+77202418>|  nop|-
   0x631ac2ed <m+38601453>|  nop|   0x5555649a13f3 <m+77202419>|  nop|-
   0x631ac2ee <m+38601454>|  mov    $0x60cd51b0,%edx|   0x5555649a13f4 <m+77202420>|  mov    $0x5fff95b0,%edx|-
   0x631ac2f3 <m+38601459>|  mov    0x60cd5270,%ecx|   0x5555649a13f9 <m+77202425>|  mov    -0x49a7d90(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac2f9 <m+38601465>|  add    $0x30,%ecx|   0x5555649a1400 <m+77202432>|  add    $0x30,%ecx|-
   0x631ac2fc <m+38601468>|  mov    %ecx,%eax|   0x5555649a1403 <m+77202435>|  mov    %ecx,%eax|-
   0x631ac2fe <m+38601470>|  shr    $0xc,%eax|   0x5555649a1405 <m+77202437>|  shr    $0xc,%eax|-
   0x631ac301 <m+38601473>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a1408 <m+77202440>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac308 <m+38601480>|  mov    $0x631ac31b,%ebx|   0x5555649a140f <m+77202447>|  movabs $0x5555649a1427,%rbx|-
   0x631ac30d <m+38601485>|  add    %eax,%ecx|   0x5555649a1419 <m+77202457>|  add    %eax,%ecx|-
   0x631ac30f <m+38601487>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a141b <m+77202459>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac315 <m+38601493>|  movlps (%edx),%xmm2|   0x5555649a1421 <m+77202465>|  movlps (%rdx),%xmm2|-
   0x631ac318 <m+38601496>|  movlps %xmm2,(%ecx)|   0x5555649a1424 <m+77202468>|  movlps %xmm2,(%rcx)|-
   0x631ac31b <m+38601499>|  nop|   0x5555649a1427 <m+77202471>|  nop|-
   0x631ac31c <m+38601500>|  nop|   0x5555649a1428 <m+77202472>|  nop|-
   0x631ac31d <m+38601501>|  mov    $0x60cd51a0,%edx|   0x5555649a1429 <m+77202473>|  mov    $0x5fff95a0,%edx|-
   0x631ac322 <m+38601506>|  mov    0x60cd5270,%ecx|   0x5555649a142e <m+77202478>|  mov    -0x49a7dc5(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac328 <m+38601512>|  add    $0x20,%ecx|   0x5555649a1435 <m+77202485>|  add    $0x20,%ecx|-
   0x631ac32b <m+38601515>|  mov    %ecx,%eax|   0x5555649a1438 <m+77202488>|  mov    %ecx,%eax|-
   0x631ac32d <m+38601517>|  shr    $0xc,%eax|   0x5555649a143a <m+77202490>|  shr    $0xc,%eax|-
   0x631ac330 <m+38601520>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a143d <m+77202493>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac337 <m+38601527>|  mov    $0x631ac34a,%ebx|   0x5555649a1444 <m+77202500>|  movabs $0x5555649a145c,%rbx|-
   0x631ac33c <m+38601532>|  add    %eax,%ecx|   0x5555649a144e <m+77202510>|  add    %eax,%ecx|-
   0x631ac33e <m+38601534>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a1450 <m+77202512>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac344 <m+38601540>|  movlps (%edx),%xmm3|   0x5555649a1456 <m+77202518>|  movlps (%rdx),%xmm3|-
   0x631ac347 <m+38601543>|  movlps %xmm3,(%ecx)|   0x5555649a1459 <m+77202521>|  movlps %xmm3,(%rcx)|-
   0x631ac34a <m+38601546>|  xor    %eax,%eax|   0x5555649a145c <m+77202524>|  xor    %eax,%eax|-
   0x631ac34c <m+38601548>|  mov    %eax,0x60cd50e4|   0x5555649a145e <m+77202526>|  movabs %eax,0x55555fff94e4|-
   0x631ac351 <m+38601553>|  mov    %eax,0x60cd50f4|   0x5555649a1467 <m+77202535>|  movabs %eax,0x55555fff94f4|-
   0x631ac356 <m+38601558>|  mov    %eax,0x60cd5104|   0x5555649a1470 <m+77202544>|  movabs %eax,0x55555fff9504|-
   0x631ac35b <m+38601563>|  mov    %eax,0x60cd5294|   0x5555649a1479 <m+77202553>|  movabs %eax,0x55555fff9694|-
   0x631ac360 <m+38601568>|  movl   $0x1,0x60cd50e0|   0x5555649a1482 <m+77202562>|  movq   $0x1,-0x49a7fa9(%rip)        # 0x55555fff94e4 <cpuRegs+68>|-
   0x631ac36a <m+38601578>|  movl   $0x2,0x60cd50f0|   0x5555649a148d <m+77202573>|  movq   $0x2,-0x49a7fa4(%rip)        # 0x55555fff94f4 <cpuRegs+84>|-
   0x631ac374 <m+38601588>|  movl   $0x1,0x60cd5100|   0x5555649a1498 <m+77202584>|  movq   $0x1,-0x49a7f9f(%rip)        # 0x55555fff9504 <cpuRegs+100>|-
   0x631ac37e <m+38601598>|  movl   $0x9fc41024,0x60cd5290|   0x5555649a14a3 <m+77202595>|  movq   $0xffffffff9fc41024,-0x49a7e1a(%rip)        # 0x55555fff9694 <cpuRegs+500>|-
   0x631ac388 <m+38601608>|  movl   $0x9fc42ae8,0x60cd5348|   0x5555649a14ae <m+77202606>|  mov    $0x9fc42ae8,%eax|-
   0x631ac392 <m+38601618>|  mov    0x60cd5460,%eax|   0x5555649a14b3 <m+77202611>|  movabs %eax,0x55555fff9748|-
   0x631ac397 <m+38601623>|  add    $0xc,%eax|   0x5555649a14bc <m+77202620>|  movabs 0x55555fff9860,%eax|-
   0x631ac39a <m+38601626>|  mov    %eax,0x60cd5460|   0x5555649a14c5 <m+77202629>|  add    $0x19,%eax|-
-|-|   0x5555649a14c8 <m+77202632>|  movabs %eax,0x55555fff9860|-
-|-|   0x5555649a14d1 <m+77202641>|  mov    %eax,%ebx|-
-|-|   0x5555649a14d3 <m+77202643>|  movabs 0x555557e03ac0,%eax|-
   0x631ac39f <m+38601631>|  sub    0x58b61820,%eax|   0x5555649a14dc <m+77202652>|  sub    %eax,%ebx|-
-|-|   0x5555649a14de <m+77202654>|  mov    %ebx,%eax|-
   0x631ac3a5 <m+38601637>|  js     0x6319c019 <m+38535193>|   0x5555649a14e0 <m+77202656>|  js     0x55556498103b <m+77070395>|-
   0x631ac3ab <m+38601643>|  jmp    0x6319c000 <m+38535168>|   0x5555649a14e6 <m+77202662>|  jmpq   0x555564981000 <m+77070336>|-

