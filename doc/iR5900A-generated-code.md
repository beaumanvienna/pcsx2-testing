   |// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x631ac27b <m+38601339>|  nop|   0x55556499f34c <m+77202252>|  nop|-
   0x631ac27c <m+38601340>|  addl   $0xffffffa0,0x60cd5270|   0x55556499f34d <m+77202253>|  addq   $0xffffffffffffffa0,-0x49a7ce4(%rip)        # 0x55555fff7671 <cpuRegs+465>|-
   0x631ac283 <m+38601347>|  lahf   |   0x55556499f355 <m+77202261>|  lahf   |-
   0x631ac284 <m+38601348>|  sar    $0xf,%ax|   0x55556499f356 <m+77202262>|  sar    $0xf,%ax|-
   0x631ac288 <m+38601352>|  cwtl   |   0x55556499f35a <m+77202266>|  cwtl   |-
   0x631ac289 <m+38601353>|  mov    %eax,0x60cd5274|   0x55556499f35b <m+77202267>|  movabs %eax,0x55555fff7674|-
   0x631ac28e <m+38601358>|  nop|   0x55556499f364 <m+77202276>|  nop|-
   0x631ac28f <m+38601359>|  nop|   0x55556499f365 <m+77202277>|  nop|-
   0x631ac290 <m+38601360>|  mov    $0x60cd5290,%edx|   0x55556499f366 <m+77202278>|  mov    $0x5fff7690,%edx|-
   0x631ac295 <m+38601365>|  mov    0x60cd5270,%ecx|   0x55556499f36b <m+77202283>|  mov    -0x49a7d02(%rip),%rcx        # 0x55555fff7670 <cpuRegs+464>|-
   0x631ac29b <m+38601371>|  add    $0x50,%ecx|   0x55556499f372 <m+77202290>|  add    $0x50,%ecx|-
   0x631ac29e <m+38601374>|  mov    %ecx,%eax|   0x55556499f375 <m+77202293>|  mov    %ecx,%eax|-
   0x631ac2a0 <m+38601376>|  shr    $0xc,%eax|   0x55556499f377 <m+77202295>|  shr    $0xc,%eax|-
   0x631ac2a3 <m+38601379>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499f37a <m+77202298>|  shl    $0x3,%rax|-
   0x631ac2aa <m+38601386>|  mov    $0x631ac2bd,%ebx|   0x55556499f37e <m+77202302>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac2af <m+38601391>|  add    %eax,%ecx|   0x55556499f388 <m+77202312>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac2b1 <m+38601393>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499f38b <m+77202315>|  movabs $0x55556499f3a3,%rbx|-
   0x631ac2b7 <m+38601399>|  movlps (%edx),%xmm0|   0x55556499f395 <m+77202325>|  add    %eax,%ecx|-
   0x631ac2ba <m+38601402>|  movlps %xmm0,(%ecx)|   0x55556499f397 <m+77202327>|  js     0x55556899f140 <m+144310592>|-
-|-|   0x55556499f39d <m+77202333>|  movlps (%rdx),%xmm0|-
-|-|   0x55556499f3a0 <m+77202336>|  movlps %xmm0,(%rcx)|-
   0x631ac2bd <m+38601405>|  nop|   0x55556499f3a3 <m+77202339>|  nop|-
   0x631ac2be <m+38601406>|  nop|   0x55556499f3a4 <m+77202340>|  nop|-
   0x631ac2bf <m+38601407>|  mov    $0x60cd51c0,%edx|   0x55556499f3a5 <m+77202341>|  mov    $0x5fff75c0,%edx|-
   0x631ac2c4 <m+38601412>|  mov    0x60cd5270,%ecx|   0x55556499f3aa <m+77202346>|  mov    -0x49a7d41(%rip),%rcx        # 0x55555fff7670 <cpuRegs+464>|-
   0x631ac2ca <m+38601418>|  add    $0x40,%ecx|   0x55556499f3b1 <m+77202353>|  add    $0x40,%ecx|-
   0x631ac2cd <m+38601421>|  mov    %ecx,%eax|   0x55556499f3b4 <m+77202356>|  mov    %ecx,%eax|-
   0x631ac2cf <m+38601423>|  shr    $0xc,%eax|   0x55556499f3b6 <m+77202358>|  shr    $0xc,%eax|-
-|-|   0x55556499f3b9 <m+77202361>|  shl    $0x3,%rax|-
-|-|   0x55556499f3bd <m+77202365>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac2d2 <m+38601426>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499f3c7 <m+77202375>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac2d9 <m+38601433>|  mov    $0x631ac2ec,%ebx|   0x55556499f3ca <m+77202378>|  movabs $0x55556499f3e2,%rbx|-
   0x631ac2de <m+38601438>|  add    %eax,%ecx|   0x55556499f3d4 <m+77202388>|  add    %eax,%ecx|-
   0x631ac2e0 <m+38601440>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499f3d6 <m+77202390>|  js     0x55556899f140 <m+144310592>|-
   0x631ac2e6 <m+38601446>|  movlps (%edx),%xmm1|   0x55556499f3dc <m+77202396>|  movlps (%rdx),%xmm1|-
   0x631ac2e9 <m+38601449>|  movlps %xmm1,(%ecx)|   0x55556499f3df <m+77202399>|  movlps %xmm1,(%rcx)|-
   0x631ac2ec <m+38601452>|  nop|   0x55556499f3e2 <m+77202402>|  nop|-
   0x631ac2ed <m+38601453>|  nop|   0x55556499f3e3 <m+77202403>|  nop|-
   0x631ac2ee <m+38601454>|  mov    $0x60cd51b0,%edx|   0x55556499f3e4 <m+77202404>|  mov    $0x5fff75b0,%edx|-
   0x631ac2f3 <m+38601459>|  mov    0x60cd5270,%ecx|   0x55556499f3e9 <m+77202409>|  mov    -0x49a7d80(%rip),%rcx        # 0x55555fff7670 <cpuRegs+464>|-
   0x631ac2f9 <m+38601465>|  add    $0x30,%ecx|   0x55556499f3f0 <m+77202416>|  add    $0x30,%ecx|-
   0x631ac2fc <m+38601468>|  mov    %ecx,%eax|   0x55556499f3f3 <m+77202419>|  mov    %ecx,%eax|-
   0x631ac2fe <m+38601470>|  shr    $0xc,%eax|   0x55556499f3f5 <m+77202421>|  shr    $0xc,%eax|-
-|-|   0x55556499f3f8 <m+77202424>|  shl    $0x3,%rax|-
-|-|   0x55556499f3fc <m+77202428>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac301 <m+38601473>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499f406 <m+77202438>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac308 <m+38601480>|  mov    $0x631ac31b,%ebx|   0x55556499f409 <m+77202441>|  movabs $0x55556499f421,%rbx|-
   0x631ac30d <m+38601485>|  add    %eax,%ecx|   0x55556499f413 <m+77202451>|  add    %eax,%ecx|-
   0x631ac30f <m+38601487>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499f415 <m+77202453>|  js     0x55556899f140 <m+144310592>|-
   0x631ac315 <m+38601493>|  movlps (%edx),%xmm2|   0x55556499f41b <m+77202459>|  movlps (%rdx),%xmm2|-
   0x631ac318 <m+38601496>|  movlps %xmm2,(%ecx)|   0x55556499f41e <m+77202462>|  movlps %xmm2,(%rcx)|-
   0x631ac31b <m+38601499>|  nop|   0x55556499f421 <m+77202465>|  nop|-
   0x631ac31c <m+38601500>|  nop|   0x55556499f422 <m+77202466>|  nop|-
   0x631ac31d <m+38601501>|  mov    $0x60cd51a0,%edx|   0x55556499f423 <m+77202467>|  mov    $0x5fff75a0,%edx|-
   0x631ac322 <m+38601506>|  mov    0x60cd5270,%ecx|   0x55556499f428 <m+77202472>|  mov    -0x49a7dbf(%rip),%rcx        # 0x55555fff7670 <cpuRegs+464>|-
   0x631ac328 <m+38601512>|  add    $0x20,%ecx|   0x55556499f42f <m+77202479>|  add    $0x20,%ecx|-
   0x631ac32b <m+38601515>|  mov    %ecx,%eax|   0x55556499f432 <m+77202482>|  mov    %ecx,%eax|-
   0x631ac32d <m+38601517>|  shr    $0xc,%eax|   0x55556499f434 <m+77202484>|  shr    $0xc,%eax|-
   0x631ac330 <m+38601520>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499f437 <m+77202487>|  shl    $0x3,%rax|-
   0x631ac337 <m+38601527>|  mov    $0x631ac34a,%ebx|   0x55556499f43b <m+77202491>|  movabs $0x7fff8919f010,%rbx|-
-|-|   0x55556499f445 <m+77202501>|  mov    (%rax,%rbx,1),%eax|-
-|-|   0x55556499f448 <m+77202504>|  movabs $0x55556499f460,%rbx|-
   0x631ac33c <m+38601532>|  add    %eax,%ecx|   0x55556499f452 <m+77202514>|  add    %eax,%ecx|-
   0x631ac33e <m+38601534>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499f454 <m+77202516>|  js     0x55556899f140 <m+144310592>|-
   0x631ac344 <m+38601540>|  movlps (%edx),%xmm3|   0x55556499f45a <m+77202522>|  movlps (%rdx),%xmm3|-
   0x631ac347 <m+38601543>|  movlps %xmm3,(%ecx)|   0x55556499f45d <m+77202525>|  movlps %xmm3,(%rcx)|-
   0x631ac34a <m+38601546>|  xor    %eax,%eax|   0x55556499f460 <m+77202528>|  xor    %eax,%eax|-
   0x631ac34c <m+38601548>|  mov    %eax,0x60cd50e4|   0x55556499f462 <m+77202530>|  movabs %eax,0x55555fff74e4|-
   0x631ac351 <m+38601553>|  mov    %eax,0x60cd50f4|   0x55556499f46b <m+77202539>|  movabs %eax,0x55555fff74f4|-
   0x631ac356 <m+38601558>|  mov    %eax,0x60cd5104|   0x55556499f474 <m+77202548>|  movabs %eax,0x55555fff7504|-
   0x631ac35b <m+38601563>|  mov    %eax,0x60cd5294|   0x55556499f47d <m+77202557>|  movabs %eax,0x55555fff7694|-
   0x631ac360 <m+38601568>|  movl   $0x1,0x60cd50e0|   0x55556499f486 <m+77202566>|  movq   $0x1,-0x49a7fad(%rip)        # 0x55555fff74e4 <cpuRegs+68>|-
   0x631ac36a <m+38601578>|  movl   $0x2,0x60cd50f0|   0x55556499f491 <m+77202577>|  movq   $0x2,-0x49a7fa8(%rip)        # 0x55555fff74f4 <cpuRegs+84>|-
   0x631ac374 <m+38601588>|  movl   $0x1,0x60cd5100|   0x55556499f49c <m+77202588>|  movq   $0x1,-0x49a7fa3(%rip)        # 0x55555fff7504 <cpuRegs+100>|-
   0x631ac37e <m+38601598>|  movl   $0x9fc41024,0x60cd5290|   0x55556499f4a7 <m+77202599>|  movq   $0xffffffff9fc41024,-0x49a7e1e(%rip)        # 0x55555fff7694 <cpuRegs+500>|-
   0x631ac388 <m+38601608>|  movl   $0x9fc42ae8,0x60cd5348|   0x55556499f4b2 <m+77202610>|  mov    $0x9fc42ae8,%eax|-
   0x631ac392 <m+38601618>|  mov    0x60cd5460,%eax|   0x55556499f4b7 <m+77202615>|  movabs %eax,0x55555fff7748|-
-|-|   0x55556499f4c0 <m+77202624>|  movabs 0x55555fff7860,%eax|-
   0x631ac397 <m+38601623>|  add    $0xc,%eax|   0x55556499f4c9 <m+77202633>|  add    $0x19,%eax|
   0x631ac39a <m+38601626>|  mov    %eax,0x60cd5460|   0x55556499f4cc <m+77202636>|  movabs %eax,0x55555fff7860|
   0x631ac39f <m+38601631>|  sub    0x58b61820,%eax|   0x55556499f4d5 <m+77202645>|  sub    -0xcb9da1b(%rip),%eax        # 0x555557e01ac0 <g_nextEventCycle>|
   0x631ac3a5 <m+38601637>|  js     0x6319c019 <m+38535193>|   0x55556499f4db <m+77202651>|  js     0x55556497f03b <m+77070395>|
   0x631ac3ab <m+38601643>|  jmp    0x6319c000 <m+38535168>|   0x55556499f4e1 <m+77202657>|  jmpq   0x55556497f000 <m+77070336>|
