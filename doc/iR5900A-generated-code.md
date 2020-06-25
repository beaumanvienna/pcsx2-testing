   |// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x631895e0 |  nop|   0x555566e344ce |  nop
   0x631895e1 |  mov    $0x9fc42b08,%eax||???
   0x631895e6 |  nop|   0x555566e344cf |  nop
   0x631895e7 |  mov    $0x9fc42b0c,%eax|   0x555566e344d0 |  mov    -0xf002bf6(%rip),%eax        # 0x555557e318e0 <cpuRegs+48>
   0x631895ec |  addl   $0xffffffff,0x60cb20d0|   0x555566e344d6 |  shl    $0x20,%rax
   0x631895f3 |  lahf   |   0x555566e344da |  movabs $0xffffffff00000000,%rbx
   0x631895f4 |  sar    $0xf,%ax|   0x555566e344e4 |  add    %rbx,%rax
   0x631895f8 |  cwtl   |   0x555566e344e7 |  sar    $0x20,%rax
   0x631895f9 |  mov    %eax,0x60cb20d4|   0x555566e344eb |  mov    %rax,-0xf002c12(%rip)        # 0x555557e318e0 <cpuRegs+48>
   0x631895fe |  nop|   0x555566e344f2 |  nop
   0x631895ff |  mov    $0x9fc42b10,%eax|   0x555566e344f3 |???
   0x63189604 |  nop|   0x555566e344f4 |  nop
   0x63189605 |  mov    $0x9fc42b14,%eax|   0x555566e344f5 |???
   0x6318960a |  nop|   0x555566e344f6 |  nop
   0x6318960b |  mov    $0x9fc42b18,%eax|   0x555566e344fd |???
   0x63189610 |  nop|   0x555566e34503 |  nop
   0x63189611 |  mov    $0x9fc42b1c,%eax|   0x555566e34504 |???
   0x63189616 |  cmpl   $0x0,0x60cb20d4|   0x555566e34506 |  cmpl   $0x0,-0xf002c18(%rip)        # 0x555557e318e5 <cpuRegs+53>
   0x6318961d |  jl     0x63189662 <_ZL18memReserve_iR5900A+38602338>|   0x555566e3450c |  jl     0x555566e34540 <_ZN13HostMemoryMap5EErecE+1344>
   0x63189623 |  nop|   0x555566e34516 |  nop
   0x63189624 |  mov    $0x9fc42b20,%eax|   0x555566e34520 |???
   0x63189629 |  xor    %eax,%eax|   0x555566e34526 |  xor    %eax,%eax
   0x6318962b |  mov    %eax,0x60cb20e4|   0x555566e34529 |  mov    %eax,-0xf002c18(%rip)        # 0x555557e318f4 <cpuRegs+68>
   0x63189630 |  movl   $0x20,0x60cb20e0|   0x555566e3452f |  movl   $0x20,-0xf002c26(%rip)        # 0x555557e318f0 <cpuRegs+64>
   0x6318963a |  movl   $0x9fc42b08,0x60cb2348|   0x555566e34535 |  movl   $0x9fc42b08,-0xf0029c8(%rip)        # 0x555557e31b58 <cpuRegs+680>
   0x63189644 |  mov    0x60cb2460,%eax|   0x555566e3453b |  mov    -0xf0028b6(%rip),%eax        # 0x555557e31c70 <cpuRegs+960>
   0x63189649 |  add    $0x8,%eax|   0x555566e34540 |  add    $0x8,%eax
   0x6318964c |  mov    %eax,0x60cb2460|   0x555566e34541 |  mov    %eax,-0xf0028bf(%rip)        # 0x555557e31c70 <cpuRegs+960>
   0x63189651 |  sub    0x58b3e820,%eax|   0x555566e34543 |  sub    -0xf003755(%rip),%eax        # 0x555557e30de0 <g_nextEventCycle>
   0x63189657 |  js     0x631895e0 <_ZL18memReserve_iR5900A+38602208>|   0x555566e34549 |  js     0x555566e344ce <_ZN13HostMemoryMap5EErecE+1230>
   0x6318965d |  jmp    0x63179000 <_ZL18memReserve_iR5900A+38535168>|   0x555566e34553 |  jmpq   0x55556e396000 <_ZL16eeRecDispatchers>
   0x63189662 |  nop|   0x555566e3455d |  nop
   0x63189663 |  mov    $0x9fc42b20,%eax|   0x555566e34563 |???
   0x63189668 |  xor    %eax,%eax|   0x555566e34566 |  xor    %eax,%eax
   0x6318966a |  mov    %eax,0x60cb20e4|   0x555566e3456c |  mov    %eax,-0xf002c55(%rip)        # 0x555557e318f4 <cpuRegs+68>
   0x6318966f |  movl   $0x20,0x60cb20e0||  movl   $0x20,-0xf002c63(%rip)        # 0x555557e318f0 <cpuRegs+64>
   0x63189679 |  movl   $0x9fc42b24,0x60cb2348||  movl   $0x9fc42b24,-0xf002a05(%rip)        # 0x555557e31b58 <cpuRegs+680>
   0x63189683 |  mov    0x60cb2460,%eax||  mov    -0xf0028f3(%rip),%eax        # 0x555557e31c70 <cpuRegs+960>
   0x63189688 |  add    $0x8,%eax||  add    $0x8,%eax
   0x6318968b |  mov    %eax,0x60cb2460||  mov    %eax,-0xf0028fc(%rip)        # 0x555557e31c70 <cpuRegs+960>
   0x63189690 |  sub    0x58b3e820,%eax||  sub    -0xf003792(%rip),%eax        # 0x555557e30de0 <g_nextEventCycle>
   0x63189696 |  js     0x63179020 <_ZL18memReserve_iR5900A+38535200>|   0x555566e34572 |  js     0x55556e39601e <_ZL16eeRecDispatchers+30>
   0x6318969c |  jmp    0x63179000 <_ZL18memReserve_iR5900A+38535168>|   0x555566e34578 |  jmpq   0x55556e396000 <_ZL16eeRecDispatchers>
