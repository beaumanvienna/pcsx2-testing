|// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x30000000|  nop|   0x555564983000 <_ZL18memReserve_iR5900A+77074432>|  nop|-
   0x30000001|  mov    0x58b7e82c,%eax|   0x555564983001 <_ZL18memReserve_iR5900A+77074433>|  movabs 0x55555fff9e9c,%eax|-
   0x30000006|  cltd   |   0x55556498300a <_ZL18memReserve_iR5900A+77074442>|  cltd   |-
   0x30000007|  mov    %eax,0x58b7e770|   0x55556498300b <_ZL18memReserve_iR5900A+77074443>|  movabs %eax,0x55555fff9de0|-
   0x3000000c|  mov    %edx,0x58b7e774|   0x555564983014 <_ZL18memReserve_iR5900A+77074452>|  mov    %edx,%eax|-
-|-|   0x555564983016 <_ZL18memReserve_iR5900A+77074454>|  movabs %eax,0x55555fff9de4|-
   0x30000012|  nop|   0x55556498301f <_ZL18memReserve_iR5900A+77074463>|  nop|-
   0x30000013|  nop|   0x555564983020 <_ZL18memReserve_iR5900A+77074464>|  nop|-
-|-|   0x555564983021 <_ZL18memReserve_iR5900A+77074465>|  movabs 0x55555fff9de4,%eax|-
   0x30000014|  cmpl   $0x0,0x58b7e774|   0x55556498302a <_ZL18memReserve_iR5900A+77074474>|  cmp    $0x0,%eax|-
   0x3000001b|  mov    $0x1,%eax|   0x55556498302d <_ZL18memReserve_iR5900A+77074477>|  mov    $0x1,%eax|-
   0x30000020|  jl     0x3000002f|   0x555564983032 <_ZL18memReserve_iR5900A+77074482>|  jl     0x55556498304b <_ZL18memReserve_iR5900A+77074507>|-
   0x30000022|  jg     0x3000002d|   0x555564983034 <_ZL18memReserve_iR5900A+77074484>|  jg     0x555564983049 <_ZL18memReserve_iR5900A+77074505>|-
-|-|   0x555564983036 <_ZL18memReserve_iR5900A+77074486>|  movabs 0x55555fff9de0,%eax|-
   0x30000024|  cmpl   $0x59,0x58b7e770|   0x55556498303f <_ZL18memReserve_iR5900A+77074495>|  cmp    $0x59,%eax|-
-|-|   0x555564983042 <_ZL18memReserve_iR5900A+77074498>|  mov    $0x1,%eax|-
   0x3000002b|  jb     0x3000002f|   0x555564983047 <_ZL18memReserve_iR5900A+77074503>|  jb     0x55556498304b <_ZL18memReserve_iR5900A+77074507>|-
   0x3000002d|  xor    %eax,%eax|   0x555564983049 <_ZL18memReserve_iR5900A+77074505>|  xor    %eax,%eax|-
   0x3000002f|  mov    %eax,0x58b7e5e0|   0x55556498304b <_ZL18memReserve_iR5900A+77074507>|  movabs %eax,0x55555fff9c50|-
-|-|   0x555564983054 <_ZL18memReserve_iR5900A+77074516>|  xor    %eax,%eax|-
   0x30000034|  movl   $0x0,0x58b7e5e4|   0x555564983056 <_ZL18memReserve_iR5900A+77074518>|  movabs %eax,0x55555fff9c54|-
   0x3000003e|  nop|   0x55556498305f <_ZL18memReserve_iR5900A+77074527>|  nop|-
-|-|   0x555564983060 <_ZL18memReserve_iR5900A+77074528>|  movabs 0x55555fff9120,%eax|-
-|-|   0x555564983069 <_ZL18memReserve_iR5900A+77074537>|  mov    %eax,%ebx|-
-|-|   0x55556498306b <_ZL18memReserve_iR5900A+77074539>|  movabs 0x55555fff9c50,%eax|-
   0x3000003f|  cmpl   $0x0,0x58b7e5e0|   0x555564983074 <_ZL18memReserve_iR5900A+77074548>|  cmp    %ebx,%eax|xCMP(ptr32[&cpuRegs.GPR.r[ _Rs_ ].UL[ 0 ]], g_cpuConstRegs[_Rt_].UL[0] ); //iR5900Branch.cpp
   0x30000046|  jne    0x30000055|   0x555564983076 <_ZL18memReserve_iR5900A+77074550>|  jne    0x555564983094 <_ZL18memReserve_iR5900A+77074580>|-
-|-|   0x555564983078 <_ZL18memReserve_iR5900A+77074552>|  movabs 0x55555fff9124,%eax|-
-|-|   0x555564983081 <_ZL18memReserve_iR5900A+77074561>|  mov    %eax,%ebx|-
-|-|   0x555564983083 <_ZL18memReserve_iR5900A+77074563>|  movabs 0x55555fff9c54,%eax|-
   0x30000048|  cmpl   $0x0,0x58b7e5e4|   0x55556498308c <_ZL18memReserve_iR5900A+77074572>|  cmp    %ebx,%eax|-
   0x3000004f|  je     0x3000007e|   0x55556498308e <_ZL18memReserve_iR5900A+77074574>|  je     0x5555649830d2 <_ZL18memReserve_iR5900A+77074642>|-
   0x30000055|  nop|   0x555564983094 <_ZL18memReserve_iR5900A+77074580>|  nop|-
   0x30000056|  movl   $0xbfc00024,0x58b7e878|   0x555564983095 <_ZL18memReserve_iR5900A+77074581>|  mov    $0xbfc00024,%eax|-
   0x30000060|  mov    0x58b7e990,%eax|   0x55556498309a <_ZL18memReserve_iR5900A+77074586>|  movabs %eax,0x55555fff9ee8|-
-|-|   0x5555649830a3 <_ZL18memReserve_iR5900A+77074595>|  movabs 0x55555fffa000,%eax|-
   0x30000065|  add    $0xb,%eax|   0x5555649830ac <_ZL18memReserve_iR5900A+77074604>|  add    $0xb,%eax|-
   0x30000068|  mov    %eax,0x58b7e990|   0x5555649830af <_ZL18memReserve_iR5900A+77074607>|  movabs %eax,0x55555fffa000|-
-|-|   0x5555649830b8 <_ZL18memReserve_iR5900A+77074616>|  mov    %eax,%ebx|-
-|-|   0x5555649830ba <_ZL18memReserve_iR5900A+77074618>|  movabs 0x555557e03ac0,%eax|-
   0x3000006d|  sub    0x58b7db40,%eax|   0x5555649830c3 <_ZL18memReserve_iR5900A+77074627>|  sub    %eax,%ebx|-
-|-|   0x5555649830c5 <_ZL18memReserve_iR5900A+77074629>|  mov    %ebx,%eax|-
   0x30000073|  js     0x58d79019 <_ZL16eeRecDispatchers+25>|   0x5555649830c7 <_ZL18memReserve_iR5900A+77074631>|  js     0x55556498203b <_ZL18memReserve_iR5900A+77070395>|-
   0x30000079|  jmp    0x58d79000 <_ZL16eeRecDispatchers>|   0x5555649830cd <_ZL18memReserve_iR5900A+77074637>|  jmpq   0x555564982000 <_ZL18memReserve_iR5900A+77070336>|-
   0x3000007e|  nop|   0x5555649830d2 <_ZL18memReserve_iR5900A+77074642>|  nop|-
   0x3000007f|  movl   $0xbfc00014,0x58b7e878|   0x5555649830d3 <_ZL18memReserve_iR5900A+77074643>|  mov    $0xbfc00014,%eax|-
   0x30000089|  mov    0x58b7e990,%eax|   0x5555649830d8 <_ZL18memReserve_iR5900A+77074648>|  movabs %eax,0x55555fff9ee8|-
-|-|   0x5555649830e1 <_ZL18memReserve_iR5900A+77074657>|  movabs 0x55555fffa000,%eax|-
   0x3000008e|  add    $0xb,%eax|   0x5555649830ea <_ZL18memReserve_iR5900A+77074666>|  add    $0xb,%eax|-
   0x30000091|  mov    %eax,0x58b7e990|   0x5555649830ed <_ZL18memReserve_iR5900A+77074669>|  movabs %eax,0x55555fffa000|-
-|-|   0x5555649830f6 <_ZL18memReserve_iR5900A+77074678>|  mov    %eax,%ebx|-
-|-|   0x5555649830f8 <_ZL18memReserve_iR5900A+77074680>|  movabs 0x555557e03ac0,%eax|-
   0x30000096|  sub    0x58b7db40,%eax|   0x555564983101 <_ZL18memReserve_iR5900A+77074689>|  sub    %eax,%ebx|-
-|-|   0x555564983103 <_ZL18memReserve_iR5900A+77074691>|  mov    %ebx,%eax|-
   0x3000009c|  js     0x58d79019 <_ZL16eeRecDispatchers+25>|   0x555564983105 <_ZL18memReserve_iR5900A+77074693>|  js     0x55556498203b <_ZL18memReserve_iR5900A+77070395>|-
   0x300000a2|  jmp    0x58d79000 <_ZL16eeRecDispatchers>|   0x55556498310b <_ZL18memReserve_iR5900A+77074699>|  jmpq   0x555564982000 <_ZL18memReserve_iR5900A+77070336>|-
-|-|-|-|-
-|-|-|-|-
   0x631ac27b <_ZL18memReserve_iR5900A+38601339>|  nop|   0x5555649a1370 <_ZL18memReserve_iR5900A+77202288>|  nop|-
   0x631ac27c <_ZL18memReserve_iR5900A+38601340>|  addl   $0xffffffa0,0x60cd5270|   0x5555649a1371 <_ZL18memReserve_iR5900A+77202289>|  addq   $0xffffffffffffffa0,-0x49a7d08(%rip)        # 0x55555fff9671 <cpuRegs+465>|-
   0x631ac283 <_ZL18memReserve_iR5900A+38601347>|  lahf   |   0x5555649a1379 <_ZL18memReserve_iR5900A+77202297>|  lahf   |-
   0x631ac284 <_ZL18memReserve_iR5900A+38601348>|  sar    $0xf,%ax|   0x5555649a137a <_ZL18memReserve_iR5900A+77202298>|  sar    $0xf,%ax|-
   0x631ac288 <_ZL18memReserve_iR5900A+38601352>|  cwtl   |   0x5555649a137e <_ZL18memReserve_iR5900A+77202302>|  cwtl   |-
   0x631ac289 <_ZL18memReserve_iR5900A+38601353>|  mov    %eax,0x60cd5274|   0x5555649a137f <_ZL18memReserve_iR5900A+77202303>|  movabs %eax,0x55555fff9674|-
   0x631ac28e <_ZL18memReserve_iR5900A+38601358>|  nop|   0x5555649a1388 <_ZL18memReserve_iR5900A+77202312>|  nop|-
   0x631ac28f <_ZL18memReserve_iR5900A+38601359>|  nop|   0x5555649a1389 <_ZL18memReserve_iR5900A+77202313>|  nop|-
   0x631ac290 <_ZL18memReserve_iR5900A+38601360>|  mov    $0x60cd5290,%edx|   0x5555649a138a <_ZL18memReserve_iR5900A+77202314>|  mov    $0x5fff9690,%edx|-
   0x631ac295 <_ZL18memReserve_iR5900A+38601365>|  mov    0x60cd5270,%ecx|   0x5555649a138f <_ZL18memReserve_iR5900A+77202319>|  mov    -0x49a7d26(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac29b <_ZL18memReserve_iR5900A+38601371>|  add    $0x50,%ecx|   0x5555649a1396 <_ZL18memReserve_iR5900A+77202326>|  add    $0x50,%ecx|-
   0x631ac29e <_ZL18memReserve_iR5900A+38601374>|  mov    %ecx,%eax|   0x5555649a1399 <_ZL18memReserve_iR5900A+77202329>|  mov    %ecx,%eax|-
   0x631ac2a0 <_ZL18memReserve_iR5900A+38601376>|  shr    $0xc,%eax|   0x5555649a139b <_ZL18memReserve_iR5900A+77202331>|  shr    $0xc,%eax|-
   0x631ac2a3 <_ZL18memReserve_iR5900A+38601379>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a139e <_ZL18memReserve_iR5900A+77202334>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac2aa <_ZL18memReserve_iR5900A+38601386>|  mov    $0x631ac2bd,%ebx|   0x5555649a13a5 <_ZL18memReserve_iR5900A+77202341>|  movabs $0x5555649a13bd,%rbx|-
   0x631ac2af <_ZL18memReserve_iR5900A+38601391>|  add    %eax,%ecx|   0x5555649a13af <_ZL18memReserve_iR5900A+77202351>|  add    %eax,%ecx|-
   0x631ac2b1 <_ZL18memReserve_iR5900A+38601393>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a13b1 <_ZL18memReserve_iR5900A+77202353>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac2b7 <_ZL18memReserve_iR5900A+38601399>|  movlps (%edx),%xmm0|   0x5555649a13b7 <_ZL18memReserve_iR5900A+77202359>|  movlps (%rdx),%xmm0|-
   0x631ac2ba <_ZL18memReserve_iR5900A+38601402>|  movlps %xmm0,(%ecx)|   0x5555649a13ba <_ZL18memReserve_iR5900A+77202362>|  movlps %xmm0,(%rcx)|-
   0x631ac2bd <_ZL18memReserve_iR5900A+38601405>|  nop|   0x5555649a13bd <_ZL18memReserve_iR5900A+77202365>|  nop|-
   0x631ac2be <_ZL18memReserve_iR5900A+38601406>|  nop|   0x5555649a13be <_ZL18memReserve_iR5900A+77202366>|  nop|-
   0x631ac2bf <_ZL18memReserve_iR5900A+38601407>|  mov    $0x60cd51c0,%edx|   0x5555649a13bf <_ZL18memReserve_iR5900A+77202367>|  mov    $0x5fff95c0,%edx|-
   0x631ac2c4 <_ZL18memReserve_iR5900A+38601412>|  mov    0x60cd5270,%ecx|   0x5555649a13c4 <_ZL18memReserve_iR5900A+77202372>|  mov    -0x49a7d5b(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac2ca <_ZL18memReserve_iR5900A+38601418>|  add    $0x40,%ecx|   0x5555649a13cb <_ZL18memReserve_iR5900A+77202379>|  add    $0x40,%ecx|-
   0x631ac2cd <_ZL18memReserve_iR5900A+38601421>|  mov    %ecx,%eax|   0x5555649a13ce <_ZL18memReserve_iR5900A+77202382>|  mov    %ecx,%eax|-
   0x631ac2cf <_ZL18memReserve_iR5900A+38601423>|  shr    $0xc,%eax|   0x5555649a13d0 <_ZL18memReserve_iR5900A+77202384>|  shr    $0xc,%eax|-
   0x631ac2d2 <_ZL18memReserve_iR5900A+38601426>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a13d3 <_ZL18memReserve_iR5900A+77202387>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac2d9 <_ZL18memReserve_iR5900A+38601433>|  mov    $0x631ac2ec,%ebx|   0x5555649a13da <_ZL18memReserve_iR5900A+77202394>|  movabs $0x5555649a13f2,%rbx|-
   0x631ac2de <_ZL18memReserve_iR5900A+38601438>|  add    %eax,%ecx|   0x5555649a13e4 <_ZL18memReserve_iR5900A+77202404>|  add    %eax,%ecx|-
   0x631ac2e0 <_ZL18memReserve_iR5900A+38601440>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a13e6 <_ZL18memReserve_iR5900A+77202406>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac2e6 <_ZL18memReserve_iR5900A+38601446>|  movlps (%edx),%xmm1|   0x5555649a13ec <_ZL18memReserve_iR5900A+77202412>|  movlps (%rdx),%xmm1|-
   0x631ac2e9 <_ZL18memReserve_iR5900A+38601449>|  movlps %xmm1,(%ecx)|   0x5555649a13ef <_ZL18memReserve_iR5900A+77202415>|  movlps %xmm1,(%rcx)|-
   0x631ac2ec <_ZL18memReserve_iR5900A+38601452>|  nop|   0x5555649a13f2 <_ZL18memReserve_iR5900A+77202418>|  nop|-
   0x631ac2ed <_ZL18memReserve_iR5900A+38601453>|  nop|   0x5555649a13f3 <_ZL18memReserve_iR5900A+77202419>|  nop|-
   0x631ac2ee <_ZL18memReserve_iR5900A+38601454>|  mov    $0x60cd51b0,%edx|   0x5555649a13f4 <_ZL18memReserve_iR5900A+77202420>|  mov    $0x5fff95b0,%edx|-
   0x631ac2f3 <_ZL18memReserve_iR5900A+38601459>|  mov    0x60cd5270,%ecx|   0x5555649a13f9 <_ZL18memReserve_iR5900A+77202425>|  mov    -0x49a7d90(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac2f9 <_ZL18memReserve_iR5900A+38601465>|  add    $0x30,%ecx|   0x5555649a1400 <_ZL18memReserve_iR5900A+77202432>|  add    $0x30,%ecx|-
   0x631ac2fc <_ZL18memReserve_iR5900A+38601468>|  mov    %ecx,%eax|   0x5555649a1403 <_ZL18memReserve_iR5900A+77202435>|  mov    %ecx,%eax|-
   0x631ac2fe <_ZL18memReserve_iR5900A+38601470>|  shr    $0xc,%eax|   0x5555649a1405 <_ZL18memReserve_iR5900A+77202437>|  shr    $0xc,%eax|-
   0x631ac301 <_ZL18memReserve_iR5900A+38601473>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a1408 <_ZL18memReserve_iR5900A+77202440>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac308 <_ZL18memReserve_iR5900A+38601480>|  mov    $0x631ac31b,%ebx|   0x5555649a140f <_ZL18memReserve_iR5900A+77202447>|  movabs $0x5555649a1427,%rbx|-
   0x631ac30d <_ZL18memReserve_iR5900A+38601485>|  add    %eax,%ecx|   0x5555649a1419 <_ZL18memReserve_iR5900A+77202457>|  add    %eax,%ecx|-
   0x631ac30f <_ZL18memReserve_iR5900A+38601487>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a141b <_ZL18memReserve_iR5900A+77202459>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac315 <_ZL18memReserve_iR5900A+38601493>|  movlps (%edx),%xmm2|   0x5555649a1421 <_ZL18memReserve_iR5900A+77202465>|  movlps (%rdx),%xmm2|-
   0x631ac318 <_ZL18memReserve_iR5900A+38601496>|  movlps %xmm2,(%ecx)|   0x5555649a1424 <_ZL18memReserve_iR5900A+77202468>|  movlps %xmm2,(%rcx)|-
   0x631ac31b <_ZL18memReserve_iR5900A+38601499>|  nop|   0x5555649a1427 <_ZL18memReserve_iR5900A+77202471>|  nop|-
   0x631ac31c <_ZL18memReserve_iR5900A+38601500>|  nop|   0x5555649a1428 <_ZL18memReserve_iR5900A+77202472>|  nop|-
   0x631ac31d <_ZL18memReserve_iR5900A+38601501>|  mov    $0x60cd51a0,%edx|   0x5555649a1429 <_ZL18memReserve_iR5900A+77202473>|  mov    $0x5fff95a0,%edx|-
   0x631ac322 <_ZL18memReserve_iR5900A+38601506>|  mov    0x60cd5270,%ecx|   0x5555649a142e <_ZL18memReserve_iR5900A+77202478>|  mov    -0x49a7dc5(%rip),%rcx        # 0x55555fff9670 <cpuRegs+464>|-
   0x631ac328 <_ZL18memReserve_iR5900A+38601512>|  add    $0x20,%ecx|   0x5555649a1435 <_ZL18memReserve_iR5900A+77202485>|  add    $0x20,%ecx|-
   0x631ac32b <_ZL18memReserve_iR5900A+38601515>|  mov    %ecx,%eax|   0x5555649a1438 <_ZL18memReserve_iR5900A+77202488>|  mov    %ecx,%eax|-
   0x631ac32d <_ZL18memReserve_iR5900A+38601517>|  shr    $0xc,%eax|   0x5555649a143a <_ZL18memReserve_iR5900A+77202490>|  shr    $0xc,%eax|-
   0x631ac330 <_ZL18memReserve_iR5900A+38601520>|  mov    -0x48600ff0(,%eax,4),%eax|   0x5555649a143d <_ZL18memReserve_iR5900A+77202493>|  mov    -0x76e7eff0(,%rax,4),%eax|-
   0x631ac337 <_ZL18memReserve_iR5900A+38601527>|  mov    $0x631ac34a,%ebx|   0x5555649a1444 <_ZL18memReserve_iR5900A+77202500>|  movabs $0x5555649a145c,%rbx|-
   0x631ac33c <_ZL18memReserve_iR5900A+38601532>|  add    %eax,%ecx|   0x5555649a144e <_ZL18memReserve_iR5900A+77202510>|  add    %eax,%ecx|-
   0x631ac33e <_ZL18memReserve_iR5900A+38601534>|  js     0x70cde140 <_ZL21m_IndirectDispatchers+320>|   0x5555649a1450 <_ZL18memReserve_iR5900A+77202512>|  js     0x555570003140 <_ZL21m_IndirectDispatchers+320>|-
   0x631ac344 <_ZL18memReserve_iR5900A+38601540>|  movlps (%edx),%xmm3|   0x5555649a1456 <_ZL18memReserve_iR5900A+77202518>|  movlps (%rdx),%xmm3|-
   0x631ac347 <_ZL18memReserve_iR5900A+38601543>|  movlps %xmm3,(%ecx)|   0x5555649a1459 <_ZL18memReserve_iR5900A+77202521>|  movlps %xmm3,(%rcx)|-
   0x631ac34a <_ZL18memReserve_iR5900A+38601546>|  xor    %eax,%eax|   0x5555649a145c <_ZL18memReserve_iR5900A+77202524>|  xor    %eax,%eax|-
   0x631ac34c <_ZL18memReserve_iR5900A+38601548>|  mov    %eax,0x60cd50e4|   0x5555649a145e <_ZL18memReserve_iR5900A+77202526>|  movabs %eax,0x55555fff94e4|-
   0x631ac351 <_ZL18memReserve_iR5900A+38601553>|  mov    %eax,0x60cd50f4|   0x5555649a1467 <_ZL18memReserve_iR5900A+77202535>|  movabs %eax,0x55555fff94f4|-
   0x631ac356 <_ZL18memReserve_iR5900A+38601558>|  mov    %eax,0x60cd5104|   0x5555649a1470 <_ZL18memReserve_iR5900A+77202544>|  movabs %eax,0x55555fff9504|-
   0x631ac35b <_ZL18memReserve_iR5900A+38601563>|  mov    %eax,0x60cd5294|   0x5555649a1479 <_ZL18memReserve_iR5900A+77202553>|  movabs %eax,0x55555fff9694|-
   0x631ac360 <_ZL18memReserve_iR5900A+38601568>|  movl   $0x1,0x60cd50e0|   0x5555649a1482 <_ZL18memReserve_iR5900A+77202562>|  movq   $0x1,-0x49a7fa9(%rip)        # 0x55555fff94e4 <cpuRegs+68>|-
   0x631ac36a <_ZL18memReserve_iR5900A+38601578>|  movl   $0x2,0x60cd50f0|   0x5555649a148d <_ZL18memReserve_iR5900A+77202573>|  movq   $0x2,-0x49a7fa4(%rip)        # 0x55555fff94f4 <cpuRegs+84>|-
   0x631ac374 <_ZL18memReserve_iR5900A+38601588>|  movl   $0x1,0x60cd5100|   0x5555649a1498 <_ZL18memReserve_iR5900A+77202584>|  movq   $0x1,-0x49a7f9f(%rip)        # 0x55555fff9504 <cpuRegs+100>|-
   0x631ac37e <_ZL18memReserve_iR5900A+38601598>|  movl   $0x9fc41024,0x60cd5290|   0x5555649a14a3 <_ZL18memReserve_iR5900A+77202595>|  movq   $0xffffffff9fc41024,-0x49a7e1a(%rip)        # 0x55555fff9694 <cpuRegs+500>|-
   0x631ac388 <_ZL18memReserve_iR5900A+38601608>|  movl   $0x9fc42ae8,0x60cd5348|   0x5555649a14ae <_ZL18memReserve_iR5900A+77202606>|  mov    $0x9fc42ae8,%eax|-
   0x631ac392 <_ZL18memReserve_iR5900A+38601618>|  mov    0x60cd5460,%eax|   0x5555649a14b3 <_ZL18memReserve_iR5900A+77202611>|  movabs %eax,0x55555fff9748|-
   0x631ac397 <_ZL18memReserve_iR5900A+38601623>|  add    $0xc,%eax|   0x5555649a14bc <_ZL18memReserve_iR5900A+77202620>|  movabs 0x55555fff9860,%eax|-
   0x631ac39a <_ZL18memReserve_iR5900A+38601626>|  mov    %eax,0x60cd5460|   0x5555649a14c5 <_ZL18memReserve_iR5900A+77202629>|  add    $0x19,%eax|-
-|-|   0x5555649a14c8 <_ZL18memReserve_iR5900A+77202632>|  movabs %eax,0x55555fff9860|-
-|-|   0x5555649a14d1 <_ZL18memReserve_iR5900A+77202641>|  mov    %eax,%ebx|-
-|-|   0x5555649a14d3 <_ZL18memReserve_iR5900A+77202643>|  movabs 0x555557e03ac0,%eax|-
   0x631ac39f <_ZL18memReserve_iR5900A+38601631>|  sub    0x58b61820,%eax|   0x5555649a14dc <_ZL18memReserve_iR5900A+77202652>|  sub    %eax,%ebx|-
-|-|   0x5555649a14de <_ZL18memReserve_iR5900A+77202654>|  mov    %ebx,%eax|-
   0x631ac3a5 <_ZL18memReserve_iR5900A+38601637>|  js     0x6319c019 <_ZL18memReserve_iR5900A+38535193>|   0x5555649a14e0 <_ZL18memReserve_iR5900A+77202656>|  js     0x55556498103b <_ZL18memReserve_iR5900A+77070395>|-
   0x631ac3ab <_ZL18memReserve_iR5900A+38601643>|  jmp    0x6319c000 <_ZL18memReserve_iR5900A+38535168>|   0x5555649a14e6 <_ZL18memReserve_iR5900A+77202662>|  jmpq   0x555564981000 <_ZL18memReserve_iR5900A+77070336>|-
