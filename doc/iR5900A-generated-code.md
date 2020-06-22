   |// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x631ac27b <m+38601339>|  nop|   0x55556499e399 <m+77202329>|  nop|-
   0x631ac27c <m+38601340>|  addl   $0xffffffa0,0x60cd5270|   0x55556499e39a <m+77202330>|  movabs 0x55555fff6670,%eax|-
   0x631ac283 <m+38601347>|  lahf   |   0x55556499e3a3 <m+77202339>|  add    $0xffffffffffffffa0,%rax|-
   0x631ac284 <m+38601348>|  sar    $0xf,%ax|   0x55556499e3a7 <m+77202343>|  movabs %rax,0x55555fff6670|-
   0x631ac288 <m+38601352>|  cwtl   |   0x55556499e3b1 <m+77202353>||-
   0x631ac289 <m+38601353>|  mov    %eax,0x60cd5274|   0x55556499e3b2 <m+77202354>||-
   0x631ac28e <m+38601358>|  nop|   0x55556499e3b3 <m+77202355>|  nop|-
   0x631ac28f <m+38601359>|  nop|   0x55556499e3bd <m+77202365>|  nop|-
   0x631ac290 <m+38601360>|  mov    $0x60cd5290,%edx|   0x55556499e3c4 <m+77202372>|  movabs $0x55555fff6690,%rdx|-
   0x631ac295 <m+38601365>|  mov    0x60cd5270,%ecx|   0x55556499e3c7 <m+77202375>|  mov    -0x49a7d54(%rip),%rcx        # 0x55555fff6670 <cpuRegs+464>|-
   0x631ac29b <m+38601371>|  add    $0x50,%ecx|   0x55556499e3c9 <m+77202377>|  add    $0x50,%ecx|-
   0x631ac29e <m+38601374>|  mov    %ecx,%eax|   0x55556499e3cc <m+77202380>|  mov    %ecx,%eax|-
   0x631ac2a0 <m+38601376>|  shr    $0xc,%eax|   0x55556499e3d0 <m+77202384>|  shr    $0xc,%eax|-
||   0x55556499e3da <m+77202394>|  shl    $0x3,%rax|-
||   0x55556499e3dd <m+77202397>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac2a3 <m+38601379>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499e3e7 <m+77202407>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac2aa <m+38601386>|  mov    $0x631ac2bd,%ebx|   0x55556499e3e9 <m+77202409>|  movabs $0x55556499e3f5,%rbx|-
   0x631ac2af <m+38601391>|  add    %eax,%ecx|   0x55556499e3ef <m+77202415>|  add    %eax,%ecx|-
   0x631ac2b1 <m+38601393>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499e3f2 <m+77202418>|  js     0x55556899e140 <m+144310592>|-
   0x631ac2b7 <m+38601399>|  movlps (%edx),%xmm0|   0x55556499e3f5 <m+77202421>|  movlps (%rdx),%xmm0|-
   0x631ac2ba <m+38601402>|  movlps %xmm0,(%ecx)|   0x55556499e3f6 <m+77202422>|  movlps %xmm0,(%rcx)|-
   0x631ac2bd <m+38601405>|  nop|   0x55556499e3f7 <m+77202423>|  nop|-
   0x631ac2be <m+38601406>|  nop|   0x55556499e401 <m+77202433>|  nop|-
   0x631ac2bf <m+38601407>|  mov    $0x60cd51c0,%edx|   0x55556499e408 <m+77202440>|  movabs $0x55555fff65c0,%rdx|-
   0x631ac2c4 <m+38601412>|  mov    0x60cd5270,%ecx|   0x55556499e40b <m+77202443>|  mov    -0x49a7d98(%rip),%rcx        # 0x55555fff6670 <cpuRegs+464>|-
   0x631ac2ca <m+38601418>|  add    $0x40,%ecx|   0x55556499e40d <m+77202445>|  add    $0x40,%ecx|-
   0x631ac2cd <m+38601421>|  mov    %ecx,%eax|   0x55556499e410 <m+77202448>|  mov    %ecx,%eax|-
   0x631ac2cf <m+38601423>|  shr    $0xc,%eax|   0x55556499e414 <m+77202452>|  shr    $0xc,%eax|-
-|-|   0x55556499e41e <m+77202462>|  shl    $0x3,%rax|-
-|-|   0x55556499e421 <m+77202465>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac2d2 <m+38601426>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499e42b <m+77202475>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac2d9 <m+38601433>|  mov    $0x631ac2ec,%ebx|   0x55556499e42d <m+77202477>|  movabs $0x55556499e439,%rbx|-
   0x631ac2de <m+38601438>|  add    %eax,%ecx|   0x55556499e433 <m+77202483>|  add    %eax,%ecx|-
   0x631ac2e0 <m+38601440>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499e436 <m+77202486>|  js     0x55556899e140 <m+144310592>|-
   0x631ac2e6 <m+38601446>|  movlps (%edx),%xmm1|   0x55556499e439 <m+77202489>|  movlps (%rdx),%xmm1|-
   0x631ac2e9 <m+38601449>|  movlps %xmm1,(%ecx)|   0x55556499e43a <m+77202490>|  movlps %xmm1,(%rcx)|-
   0x631ac2ec <m+38601452>|  nop|   0x55556499e43b <m+77202491>|  nop|-
   0x631ac2ed <m+38601453>|  nop|   0x55556499e445 <m+77202501>|  nop|-
   0x631ac2ee <m+38601454>|  mov    $0x60cd51b0,%edx|   0x55556499e44c <m+77202508>|  movabs $0x55555fff65b0,%rdx|-
   0x631ac2f3 <m+38601459>|  mov    0x60cd5270,%ecx|   0x55556499e44f <m+77202511>|  mov    -0x49a7ddc(%rip),%rcx        # 0x55555fff6670 <cpuRegs+464>|-
   0x631ac2f9 <m+38601465>|  add    $0x30,%ecx|   0x55556499e451 <m+77202513>|  add    $0x30,%ecx|-
   0x631ac2fc <m+38601468>|  mov    %ecx,%eax|   0x55556499e454 <m+77202516>|  mov    %ecx,%eax|-
   0x631ac2fe <m+38601470>|  shr    $0xc,%eax|   0x55556499e458 <m+77202520>|  shr    $0xc,%eax|-
-|-|   0x55556499e462 <m+77202530>|  shl    $0x3,%rax|-
-|-|   0x55556499e465 <m+77202533>|  movabs $0x7fff8919f010,%rbx|-
   0x631ac301 <m+38601473>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499e46f <m+77202543>|  mov    (%rax,%rbx,1),%eax|-
   0x631ac308 <m+38601480>|  mov    $0x631ac31b,%ebx|   0x55556499e471 <m+77202545>|  movabs $0x55556499e47d,%rbx|-
   0x631ac30d <m+38601485>|  add    %eax,%ecx|   0x55556499e477 <m+77202551>|  add    %eax,%ecx|-
   0x631ac30f <m+38601487>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499e47a <m+77202554>|  js     0x55556899e140 <m+144310592>|-
   0x631ac315 <m+38601493>|  movlps (%edx),%xmm2|   0x55556499e47d <m+77202557>|  movlps (%rdx),%xmm2|-
   0x631ac318 <m+38601496>|  movlps %xmm2,(%ecx)|   0x55556499e47e <m+77202558>|  movlps %xmm2,(%rcx)|-
   0x631ac31b <m+38601499>|  nop|   0x55556499e47f <m+77202559>|  nop|-
   0x631ac31c <m+38601500>|  nop|   0x55556499e489 <m+77202569>|  nop|-
   0x631ac31d <m+38601501>|  mov    $0x60cd51a0,%edx|   0x55556499e490 <m+77202576>|  movabs $0x55555fff65a0,%rdx|-
   0x631ac322 <m+38601506>|  mov    0x60cd5270,%ecx|   0x55556499e493 <m+77202579>|  mov    -0x49a7e20(%rip),%rcx        # 0x55555fff6670 <cpuRegs+464>|-
   0x631ac328 <m+38601512>|  add    $0x20,%ecx|   0x55556499e495 <m+77202581>|  add    $0x20,%ecx|-
   0x631ac32b <m+38601515>|  mov    %ecx,%eax|   0x55556499e498 <m+77202584>|  mov    %ecx,%eax|-
   0x631ac32d <m+38601517>|  shr    $0xc,%eax|   0x55556499e49c <m+77202588>|  shr    $0xc,%eax|-
   0x631ac330 <m+38601520>|  mov    -0x48600ff0(,%eax,4),%eax|   0x55556499e4a6 <m+77202598>|  shl    $0x3,%rax|-
   0x631ac337 <m+38601527>|  mov    $0x631ac34a,%ebx|   0x55556499e4a9 <m+77202601>|  movabs $0x7fff8919f010,%rbx|-
-|-|   0x55556499e4b3 <m+77202611>|  mov    (%rax,%rbx,1),%eax|-
-|-|   0x55556499e4b5 <m+77202613>|  movabs $0x55556499e4c1,%rbx|-
   0x631ac33c <m+38601532>|  add    %eax,%ecx|   0x55556499e4bb <m+77202619>|  add    %eax,%ecx|-
   0x631ac33e <m+38601534>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x55556499e4be <m+77202622>|  js     0x55556899e140 <m+144310592>|-
   0x631ac344 <m+38601540>|  movlps (%edx),%xmm3|   0x55556499e4c1 <m+77202625>|  movlps (%rdx),%xmm3|-
   0x631ac347 <m+38601543>|  movlps %xmm3,(%ecx)|   0x55556499e4c3 <m+77202627>|  movlps %xmm3,(%rcx)|-
   0x631ac34a <m+38601546>|  xor    %eax,%eax|   0x55556499e4cc <m+77202636>|  xor    %eax,%ea|-
   0x631ac34c <m+38601548>|  mov    %eax,0x60cd50e4|   0x55556499e4d5 <m+77202645>|  movabs %eax,0x55555fff64e4|-
   0x631ac351 <m+38601553>|  mov    %eax,0x60cd50f4|   0x55556499e4de <m+77202654>|  movabs %eax,0x55555fff64f4|-
   0x631ac356 <m+38601558>|  mov    %eax,0x60cd5104|   0x55556499e4e7 <m+77202663>|  movabs %eax,0x55555fff6504|-
   0x631ac35b <m+38601563>|  mov    %eax,0x60cd5294|   0x55556499e4f0 <m+77202672>|  movabs %eax,0x55555fff6694|-
   0x631ac360 <m+38601568>|  movl   $0x1,0x60cd50e0|   0x55556499e4f9 <m+77202681>|  movabs 0x55555fef3160,%eax|-
   0x631ac36a <m+38601578>|  movl   $0x2,0x60cd50f0|   0x55556499e502 <m+77202690>|  movabs %eax,0x55555fff64e0|-
   0x631ac374 <m+38601588>|  movl   $0x1,0x60cd5100|   0x55556499e50b <m+77202699>|  movabs 0x55555fef3168,%eax|-
   0x631ac37e <m+38601598>|  movl   $0x9fc41024,0x60cd5290|   0x55556499e514 <m+77202708>|  movabs %eax,0x55555fff64f0|-
   0x631ac388 <m+38601608>|  movl   $0x9fc42ae8,0x60cd5348|   0x55556499e51d <m+77202717>|  movabs 0x55555fef3170,%eax|-
   0x631ac392 <m+38601618>|  mov    0x60cd5460,%eax|   0x55556499e526 <m+77202726>|  movabs %eax,0x55555fff6500|-
-|-|   0x55556499e52f <m+77202735>|  movabs 0x55555fef3238,%eax|-
||   0x55556499e534 <m+77202740>|  movabs %eax,0x55555fff6690|
||   0x55556499e53d <m+77202749>|  mov    $0x9fc42ae8,%eax|
||   0x55556499e546 <m+77202758>|  movabs %eax,0x55555fff6748|
||   0x55556499e549 <m+77202761>|  movabs 0x55555fff6860,%eax|
   0x631ac397 <m+38601623>|  add    $0xc,%eax|   0x55556499e552 <m+77202770>|  add    $0x19,%eax|
   0x631ac39a <m+38601626>|  mov    %eax,0x60cd5460|   0x55556499e558 <m+77202776>|  movabs %eax,0x55555fff6860|
   0x631ac39f <m+38601631>|  sub    0x58b61820,%eax|   0x55556499e55e <m+77202782>|  sub    -0xcb9da98(%rip),%eax        # 0x555557e00ac0 <g_nextEventCycle>|
   0x631ac3a5 <m+38601637>|  js     0x6319c019 <m+38535193>||  js     0x55556497e03b <m+77070395>|
   0x631ac3ab <m+38601643>|  jmp    0x6319c000 <m+38535168>||  jmpq   0x55556497e000 <m+77070336>|
