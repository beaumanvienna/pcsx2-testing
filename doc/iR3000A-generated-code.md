|// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- | ------------------------- |
   0x34000000|  mov    0x58b61824,%eax|   0x555558d79000 <_ZL18memReserve_iR3000A+14159872>|  movabs 0x555557ff70e4,%eax
   0x34000005|  mov    %eax,0x58b617c8|   0x555558d79009 <_ZL18memReserve_iR3000A+14159881>|  movabs %eax,0x555557ff7088
   0x3400000a|  xor    %eax,%eax|   0x555558d79012 <_ZL18memReserve_iR3000A+14159890>|  xor    %eax,%eax
-|-|   0x555558d79014 <_ZL18memReserve_iR3000A+14159892>|  movabs 0x555557ff7088,%eax
   0x3400000c|  cmpl   $0x59,0x58b617c8|   0x555558d7901d <_ZL18memReserve_iR3000A+14159901>|  cmp    $0x59,%eax
   0x34000013|  setl   %al|   0x555558d79020 <_ZL18memReserve_iR3000A+14159904>|  setl   %al
   0x34000016|  mov    %eax,0x58b61764|   0x555558d79023 <_ZL18memReserve_iR3000A+14159907>|  movabs %eax,0x555557ff7024
-|-|   0x555558d7902c <_ZL18memReserve_iR3000A+14159916>|  movabs 0x555557ff7024,%eax
-|-|   0x555558d79035 <_ZL18memReserve_iR3000A+14159925>|  mov    %eax,%ebx
-|-|   0x555558d79037 <_ZL18memReserve_iR3000A+14159927>|  movabs 0x555557e03a20,%eax
   0x3400001b|  cmpl   $0x0,0x58b61764|   0x555558d79040 <_ZL18memReserve_iR3000A+14159936>|  cmp    %ebx,%eax
   0x34000022|  jne    0x34000070|   0x555558d79042 <_ZL18memReserve_iR3000A+14159938>|  jne    0x555558d790b0 <_ZL18memReserve_iR3000A+14160048>
   0x34000028|  movl   $0xbfc00014,0x58b61968|   0x555558d79048 <_ZL18memReserve_iR3000A+14159944>|  mov    $0xbfc00014,%eax
   0x34000032|  mov    0x58b61970,%eax|   0x555558d7904d <_ZL18memReserve_iR3000A+14159949>|  movabs %eax,0x555557ff7228
-|-|   0x555558d79056 <_ZL18memReserve_iR3000A+14159958>|  movabs 0x555557ff7230,%eax
   0x34000037|  add    $0x5,%eax|   0x555558d7905f <_ZL18memReserve_iR3000A+14159967>|  add    $0x5,%eax
   0x3400003a|  mov    %eax,0x58b61970|   0x555558d79062 <_ZL18memReserve_iR3000A+14159970>|  movabs %eax,0x555557ff7230
-|-|   0x555558d7906b <_ZL18memReserve_iR3000A+14159979>|  mov    $0x28,%ebx
   0x3400003f|  subl   $0x28,0x56b222a4|   0x555558d79070 <_ZL18memReserve_iR3000A+14159984>|  sub    %ebx,%eax
-|-|   0x555558d79072 <_ZL18memReserve_iR3000A+14159986>|  movabs %eax,0x555555dc0478
   0x34000046|  jle    0x58d54045 <_ZL17iopRecDispatchers+69>|   0x555558d7907b <_ZL18memReserve_iR3000A+14159995>|  jle    0x555558d7808d <_ZL18memReserve_iR3000A+14155917>
-|-|   0x555558d79081 <_ZL18memReserve_iR3000A+14160001>|  mov    %eax,%ebx
-|-|   0x555558d79083 <_ZL18memReserve_iR3000A+14160003>|  movabs 0x555557e03a08,%eax
   0x3400004c|  sub    0x58b61a80,%eax|   0x555558d7908c <_ZL18memReserve_iR3000A+14160012>|  sub    %eax,%ebx
   0x34000052|  js     0x34000069|   0x555558d7908e <_ZL18memReserve_iR3000A+14160014>|  js     0x555558d790ab <_ZL18memReserve_iR3000A+14160043>
   0x34000054|  call   0x56629550 <iopEventTest()>|   0x555558d79090 <_ZL18memReserve_iR3000A+14160016>|  callq  0x5555556afb30 <iopEventTest()>
-|-|   0x555558d79095 <_ZL18memReserve_iR3000A+14160021>|  movabs 0x555557ff7228,%eax
-|-|   0x555558d7909e <_ZL18memReserve_iR3000A+14160030>|  mov    $0xbfc00014,%ebx
   0x34000059|  cmpl   $0xbfc00014,0x58b61968|   0x555558d790a3 <_ZL18memReserve_iR3000A+14160035>|  cmp    %ebx,%eax
   0x34000063|  jne    0x58d54005 <_ZL17iopRecDispatchers+5>|   0x555558d790a5 <_ZL18memReserve_iR3000A+14160037>|  jne    0x555558d78005 <_ZL18memReserve_iR3000A+14155781>
   0x34000069|  jmp    0x58d54019 <_ZL17iopRecDispatchers+25>|   0x555558d790ab <_ZL18memReserve_iR3000A+14160043>|  jmpq   0x555558d7803b <_ZL18memReserve_iR3000A+14155835>
