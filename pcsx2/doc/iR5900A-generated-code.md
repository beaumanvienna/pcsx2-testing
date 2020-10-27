   |// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler | Comment |
| -------------- | -------------- | -------------- | -------------- | ------------------------- |
   0x631895e0 |  nop|   0x555566e09620 |  nop
   0x631895e1 |  mov    $0x9fc42b08,%eax|   0x555566e09621 |  mov    $0x9fc42b08,%eax
   0x631895e6 |  nop|   0x555566e09626 |  nop
   0x631895e7 |  mov    $0x9fc42b0c,%eax|   0x555566e09627 |  mov    $0x9fc42b0c,%eax
   0x631895ec |  addl   $0xffffffff,0x60cb20d0|   0x555566e0962c |  mov    -0xf002d52(%rip),%eax        # 0x555557e068e0 <cpuRegs+48>
   0x631895f3 |  lahf   |   0x555566e09632 |  shl    $0x20,%rax
   0x631895f4 |  sar    $0xf,%ax|   0x555566e09636 |  movabs $0xffffffff00000000,%rbx
   0x631895f8 |  cwtl   |   0x555566e09640 |  add    %rbx,%rax
   0x631895f9 |  mov    %eax,0x60cb20d4|   0x555566e09643 |  sar    $0x20,%rax
|-|   0x555566e09647 |  mov    %rax,-0xf002d6e(%rip)        # 0x555557e068e0 <cpuRegs+48>
   0x631895fe |  nop|   0x555566e0964e |  nop
   0x631895ff |  mov    $0x9fc42b10,%eax|   0x555566e0964f |  mov    $0x9fc42b10,%eax
   0x63189604 |  nop|   0x555566e09654 |  nop
   0x63189605 |  mov    $0x9fc42b14,%eax|   0x555566e09655 |  mov    $0x9fc42b14,%eax
   0x6318960a |  nop|   0x555566e0965a |  nop
   0x6318960b |  mov    $0x9fc42b18,%eax|   0x555566e0965b |  mov    $0x9fc42b18,%eax
   0x63189610 |  nop|   0x555566e09660 |  nop
   0x63189611 |  mov    $0x9fc42b1c,%eax|   0x555566e09661 |  mov    $0x9fc42b1c,%eax
   0x63189616 |  cmpl   $0x0,0x60cb20d4|   0x555566e09666 |  cmpl   $0x0,-0xf002d88(%rip)        # 0x555557e068e5 <cpuRegs+53>
   0x6318961d |  jl     0x63189662 <_ZL18memReserve_iR5900A+38602338>|   0x555566e0966d |  jl     0x555566e096b5 <_ZN13HostMemoryMap5EErecE+1717>
   0x63189623 |  nop|   0x555566e09673 |  nop
   0x63189624 |  mov    $0x9fc42b20,%eax|   0x555566e09674 |  mov    $0x9fc42b20,%eax
   0x63189629 |  xor    %eax,%eax|   0x555566e09679 |  xor    %eax,%eax
   0x6318962b |  mov    %eax,0x60cb20e4|   0x555566e0967b |  mov    %eax,-0xf002d8d(%rip)        # 0x555557e068f4 <cpuRegs+68>
   0x63189630 |  movl   $0x20,0x60cb20e0|   0x555566e09681 |  movl   $0x20,-0xf002d9b(%rip)        # 0x555557e068f0 <cpuRegs+64>
   0x6318963a |  movl   $0x9fc42b08,0x60cb2348|   0x555566e0968b |  movl   $0x9fc42b08,-0xf002b3d(%rip)        # 0x555557e06b58 <cpuRegs+680>
   0x63189644 |  mov    0x60cb2460,%eax|   0x555566e09695 |  mov    -0xf002a2b(%rip),%eax        # 0x555557e06c70 <cpuRegs+960>
   0x63189649 |  add    $0x8,%eax|   0x555566e0969b |  add    $0x8,%eax
   0x6318964c |  mov    %eax,0x60cb2460|   0x555566e0969e |  mov    %eax,-0xf002a34(%rip)        # 0x555557e06c70 <cpuRegs+960>
   0x63189651 |  sub    0x58b3e820,%eax|   0x555566e096a4 |  sub    -0xf0038ca(%rip),%eax        # 0x555557e05de0 <g_nextEventCycle>
   0x63189657 |  js     0x631895e0 <_ZL18memReserve_iR5900A+38602208>|   0x555566e096aa |  js     0x555566e09620 <_ZN13HostMemoryMap5EErecE+1568>
   0x6318965d |  jmp    0x63179000 <_ZL18memReserve_iR5900A+38535168>|   0x555566e096b0 |  jmpq   0x55556e36b000 <_ZL16eeRecDispatchers>
   0x63189662 |  nop|   0x555566e096b5 |  nop
   0x63189663 |  mov    $0x9fc42b20,%eax|   0x555566e096b6 |  mov    $0x9fc42b20,%eax
   0x63189668 |  xor    %eax,%eax|   0x555566e096bb |  xor    %eax,%eax
   0x6318966a |  mov    %eax,0x60cb20e4|   0x555566e096bd |  mov    %eax,-0xf002dcf(%rip)        # 0x555557e068f4 <cpuRegs+68>
   0x6318966f |  movl   $0x20,0x60cb20e0|   0x555566e096c3 |  movl   $0x20,-0xf002ddd(%rip)        # 0x555557e068f0 <cpuRegs+64>
   0x63189679 |  movl   $0x9fc42b24,0x60cb2348|   0x555566e096cd |  movl   $0x9fc42b24,-0xf002b7f(%rip)        # 0x555557e06b58 <cpuRegs+680>
   0x63189683 |  mov    0x60cb2460,%eax|   0x555566e096d7 |  mov    -0xf002a6d(%rip),%eax        # 0x555557e06c70 <cpuRegs+960>
   0x63189688 |  add    $0x8,%eax|   0x555566e096dd |  add    $0x8,%eax
   0x6318968b |  mov    %eax,0x60cb2460|   0x555566e096e0 |  mov    %eax,-0xf002a76(%rip)        # 0x555557e06c70 <cpuRegs+960>
   0x63189690 |  sub    0x58b3e820,%eax|   0x555566e096e6 |  sub    -0xf00390c(%rip),%eax        # 0x555557e05de0 <g_nextEventCycle>
   0x63189696 |  js     0x63179020 <_ZL18memReserve_iR5900A+38535200>|   0x555566e096ec |  js     0x55556e36b020 <_ZL16eeRecDispatchers+32>
   0x6318969c |  jmp    0x63179000 <_ZL18memReserve_iR5900A+38535168>|   0x555566e096f2 |  jmpq   0x55556e36b000 <_ZL16eeRecDispatchers>
