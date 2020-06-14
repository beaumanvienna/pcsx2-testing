# PS2 JIT compiler port from i386/32bit to x86_64 code

PCSX2 has 6 recompilers:
* R5900-32	: EE RISC processor ("Emotion Engine")
* R3000A 	: I/O processor
* VIF0 Unpack  : Vector Unit Interface 0
* VIF1 Unpack  : Vector Unit Interface 1

Terms/abbreviations:
* GS		Graphics Synthesizer
* SIMD		Single instruction, multiple data
* ABI		Application Binary Interface (e.g. Kernel to application), either 32-bit or 64-bit
* Abbreviations used in x86 or x86_64 op codes:
  * byte        	(8 bit)		suffix b						Integer
  * word        	(2 bytes)   	suffix w						Integer
  * doubleword  	(4 bytes)   	suffix l                                                Integer
  * quadword    	(8 bytes)   	suffix q  e.g. 	movq 	copies 8 bytes			Integer
  * octword	(16 bytes)	suffix o						Integer
  * suffix z: fill leading bits with zero, e.g. copy 1 byte into 2 byte register
  * suffix s: sign extend upper portion e.g. negative byte copied to word fills with ones
  * cwtl	convert word to doublword
  * cltq 	convert doubleword to quadword
  * cqto	convert quodword to octoword
  * Floating point single 		(S)		4 bytes
  * Floating point double		(D)		8 bytes
  * Imm:		‘immediate’ value (a constant) stored in the instruction itself 
		[e.g. ADDI $1,D0]–The $ indicates the constant/immediate 
* ALU		Arithmetic and Logic Unit (performs arithmetic operations like addition and subtraction along with 
logical operations AND, OR, etc.)


Notes: 

* All processors that support the x86_64 instruction set also support the x86/i386/i686 instruction set. If a processor can run 64-bit code, it can also run 32-bit code. Each process, however, must be homogeneous, so either 32-bit or 64-bit.
* When generating code for 64-bit platforms, the order of operations may be different compared to generating 32-bit code.
* x86_64 CPUs 
  * have two modes of operation in Long Mode, a 64-bit mode and compatibility mode. In compatibility mode, the default address size is 32 bits.
  * still make available x87/MMX registers in 64-bit mode 
  * provide full x86 16-bit and 32-bit instruction sets without intervening emulation

Central files:
* pcsx2/pcsx2/R5900.cpp: EE emulation
* /pcsx2/x86/iCore.cpp
* pcsx2/x86/ix86-32/iR5900-32.cpp: initialization of recLUT and recLutReserve_RAM, recompilation code
* common/src/x86emitter/x86emitter.cpp

Questions to resolve:
* Which instructions have to be ported? --> SIB 32bit does not have a corresponding 64-bit equivalent
* Which modules are affected?

Existing instruction sets on i386:

* MMX: a single instruction, multiple data (SIMD) instruction set 
  * 57 instructions
  * 64-bit wide register file (MM0-MM7)
  * only integer operations
  * not able to mix integer-SIMD ops with any floating-point ops
* SSE1: Streaming SIMD Extension 1
  * 128-bit wide register file (XMM0–XMM7) 
* SSE2: Streaming SIMD Extensions 2
* SSSE3: Supplemental Streaming SIMD Extensions 3
* SSE4: Streaming SIMD Extensions 2
* AVX: 											Floating Point
  * Advanced Vector Extensions (since 2011). AVX provides new features, new instructions and a new coding scheme.
  * AVX uses sixteen YMM registers to perform a Single Instruction on Multiple pieces of Data (see SIMD). 
  * The AVX instructions support both 128-bit and 256-bit SIMD
  * Each YMM register can hold and do simultaneous operations (math) on: 
   * eight 32-bit single-precision floating point numbers or 
   * four 64-bit double-precision floating point numbers.
* AVX2 expands most integer commands to 256 bits and introduces fused multiply-accumulate (FMA) operations



Primary opcode maps:			(Escape sequences allow for different maps)
http://sparksandflames.com/files/x86InstructionChart.html


Registers on x86_64:

| 8-byte register | Byte 3-0 | Byte 1-0 | Byte 0 |
| --------------- | -------- | -------- | ------ |
| rax | Eax | ax | al |
| rcx | ecx | cx | cl |
| rdx | edx | dx | dl |
| rbx | ebx | bx | bl |
| rsi | esi | si | sil |
| rdi | edi | di | dil |
| rsp | esp | sp | spl |
| rbp | ebp | bp | bpl |
| r8 | r8d | r8w | r8b |
| r9 | r9d | r9w | r9b |
| r10 | r10d | r10w | r10b |
| r11 | r11d | r11w | r11b |
| r12 | r12d | r12w | r12b |
| r13 | r13d | r13w | r13b |
| r14 | r14d | r14w | r14b |
| r15 | r15d | r15w | r15b |

Instruction encoding on AMD64:

<img src="processingFlow.png" />
<img src="operand-size.png" />

Understanding the tables recLUT and recLutReserve_RAM, the macro PC_GETBLOCK, and the pseudo assembler code in _DynGen_DispatcherReg and _DynGen_JITCompile:

 * Ram is mirrored.
 * 0x8000_0000 area is physical and cached. Kernel
 * 0 is virtual memory which is often mapped 1:1 to the physical mem
 * 0xa000_0000 iirc is for supervisor mode (middle between kernel and user)
 * 0xb000_0000 is uncached (rom)
 
 * Ps2MemSize::MainRam / 4 = 0x00800000; MainRam = 32MB (i386) / 64MB (x64)
 * Ps2MemSize::Rom / 4  = 0x00100000;     Rom    = 4MB (i386) / 8MB (x64)
 * Ps2MemSize::Rom1 / 4 = 0x00010000      Rom1	 = 256kB (i386) / 512MB (x64)

Each entry in recLUT is used to jump into 64k elements (one page) of recLutReserve_RAM according to the program counter of the PS2 cpu.
```
uptr* fp = reclut[ pc >> 16] + pc*sizeof(uptr)/4;
jump fp[0];
```
This is how a recLUT entry is generated:
```C++

recLUT_SetPage(recLUT, hwLUT, recROM, 0xa000, i, i - 0x1fc0); // i=0x1fc0
// --> pagebase+pageidx=0xbfc00000= start value of pc


// 32-bits
d                       = -bfc0 = 0xFFFF4040;
e                       = trunc32(0xFFFF4040 << 14) = trunc32(0x3FFFD0100000) = 0xD0100000;
u                       = recLutReserve_RAM+ 32Mb + 4*0xD0100000;
                        = 0xb35bc000 + 0x2000000 + 4*0xD0100000;
0xb35bc000 + 0x2000000 + 4*0xD0100000 + 0xbfc00000
0xb35bc000 + 0x2000000 + trunc32(340400000) + 0xbfc00000
0xb35bc000 + 0x2000000 + 0x40400000 + 0xbfc00000
trunc32(u + 0xbfc00000) = recLutReserve_RAM+ 32MB;
                        = 0xb35bc000 + 0x2000000;
                        = 0xB55BC000;
// 64-bits
d                       = 0x0 -(bfc0 * sizeof(uptr)/4) = -(bfc0 << 1) = 0xFFFFFFFFFFFE8080;
e                       = trunc64(0xFFFFFFFFFFFE8080 << 13) = 0xffffFFFFD0100000;
u                       = recLutReserve_RAM + 64MB + 8*0xffffFFFFD0100000;
                        = 0x7fff6777f000 + 0x4000000 + 8*0x0xffffFFFFD0100000;
0x7fff6777f000 + 0x4000000 + 8*0xffffFFFFD0100000 + (0xbfc00000 << 1)           = 0x7fff6777f000 + 0x4000000
0x7fff6777f000 + 0x4000000 + trunc64(7FFFFFFFE80800000) + 0x17F800000           = 0x7fff6777f000 + 0x4000000
 
0x7fff6777f000 + 0x4000000 + 0xFFFFFFFE80800000 +         0x17F800000           = 0x7fff6777f000 + 0x4000000
<--------------  recLUT[0xbfc0] -------------->   <-0xbfc00000*sizeof(uptr)/4->  <-recLutReserve_RAM + 64MB->

--> recLUT[0xbfc0] = 0x7fff6777f000 + 0x4000000 + 0xFFFFFFFE80800000 
                   = 0x7FFDEBF7F000
--> recLUT[0xbfc0] + (0xbfc00000 << 1) = recLutReserve_RAM+ 64MB

```


|// i386 address | i386 jitted assembler | x64 address | x64 jitted assembler |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
   0x30000000|  nop|   0x210000000|  nop
   0x30000001|  mov    0x58b7e82c,%eax|   0x210000001|  movabs 0x555557e1eb0c,%rax
   0x30000006|  cltd   |   0x21000000b|  cltd   
   0x30000007|  mov    %eax,0x58b7e770|   0x21000000c|  movabs %rax,0x555557e1ea54
   0x3000000c|  mov    %edx,0x58b7e774|   0x210000016|  mov    %rdx,%rax
-|-|   0x210000019|  movabs %rax,0x555557e1ea50
   0x30000012|  nop|   0x210000023|  nop
   0x30000013|  nop|   0x210000024|  nop
   0x30000014|  cmpl   $0x0,0x58b7e774|   0x210000025|  movabs 0x555557e1ea54,%rax
   0x3000001b|  mov    $0x1,%eax|   0x21000002f|  cmp    $0x0,%rax
-|-|   0x210000033|  movabs $0x1,%rax
   0x30000020|  jl     0x3000002f|   0x21000003d|  jl     0x21000005e
   0x30000022|  jg     0x3000002d|   0x21000003f|  jg     0x21000005b
   0x30000024|  cmpl   $0x59,0x58b7e770|   0x210000041|  movabs 0x555557e1ea50,%rax
-|-|   0x21000004b|  cmp    $0x59,%rax
-|-|   0x21000004f|  movabs $0x1,%rax
   0x3000002b|  jb     0x3000002f|   0x210000059|  jb     0x21000005e
   0x3000002d|  xor    %eax,%eax|   0x21000005b|  xor    %rax,%rax
   0x3000002f|  mov    %eax,0x58b7e5e0|   0x21000005e|  movabs %rax,0x555557e1e8c0
   0x30000034|  movl   $0x0,0x58b7e5e4|   0x210000068|  xor    %rax,%rax
-|-|   0x21000006b|  movabs %rax,0x555557e1e8c4
   0x3000003e|  nop|   0x210000075|  nop
-|-|   0x210000076|  movabs 0x555557e1e8c0,%rax
-|-|   0x210000080|  and    $0xffff,%rax
-|-|   0x210000086|  add    %al,(%rax)
-|-|   0x210000088|  add    %al,(%rax)
-|-|   0x21000008a|  mov    %rax,%rbx
-|-|   0x21000008d|  movabs 0x0,%rax
-|-|   0x210000097|  and    $0xffff,%rax
-|-|   0x21000009d|  add    %al,(%rax)
-|-|   0x21000009f|  add    %al,(%rax)
   0x3000003f|  cmpl   $0x0,0x58b7e5e0|   0x2100000a1|  cmp    %rbx,%rax
   0x30000046|  jne    0x30000055|   0x2100000a4|  jne    0x2100000da
   0x30000048|  cmpl   $0x0,0x58b7e5e4|   0x2100000a6|  movabs 0x555557e1e8c4,%rax
-|-|   0x2100000b0|  and    $0xffff,%rax
-|-|   0x2100000b6|  add    %al,(%rax)
-|-|   0x2100000b8|  add    %al,(%rax)
-|-|   0x2100000ba|  mov    %rax,%rbx
-|-|   0x2100000bd|  movabs 0x0,%rax
-|-|   0x2100000c7|  and    $0xffff,%rax
-|-|   0x2100000cd|  add    %al,(%rax)
-|-|   0x2100000cf|  add    %al,(%rax)
-|-|   0x2100000d1|  cmp    %rbx,%rax
   0x3000004f|  je     0x3000007e|   0x2100000d4|  je     0x21000012d
   0x30000055|  nop|   0x2100000da|  nop
   0x30000056|  movl   $0xbfc00024,0x58b7e878|   0x2100000db|  movabs $0xbfc00024,%rax
   0x30000060|  mov    0x58b7e990,%eax|   0x2100000e5|  movabs %rax,0x555557e1eb58
   0x30000065|  add    $0xb,%eax|   0x2100000ef|  movabs 0x555557e1ec70,%rax
   0x30000068|  mov    %eax,0x58b7e990|   0x2100000f9|  add    $0xb,%rax
-|-|   0x2100000fd|  movabs %rax,0x555557e1ec70
-|-|   0x210000107|  mov    %rax,%rbx
-|-|   0x21000010a|  movabs 0x555557e1dde0,%rax
   0x3000006d|  sub    0x58b7db40,%eax|   0x210000114|  sub    %rax,%rbx
-|-|   0x210000117|  mov    %rbx,%rax
   0x30000073|  js     0x58d79019 <_ZL16eeRecDispatchers+25>|   0x21000011a|  js     0x25811c039
-|-|   0x210000120|  movabs $0x55555811c000,%rax
   0x30000079|  jmp    0x58d79000 <_ZL16eeRecDispatchers>|   0x21000012a|  rex.W jmpq *%rax
   0x3000007e|  nop|   0x21000012d|  nop
   0x3000007f|  movl   $0xbfc00014,0x58b7e878|   0x21000012e|  movabs $0xbfc00014,%rax
   0x30000089|  mov    0x58b7e990,%eax|   0x210000138|  movabs %rax,0x555557e1eb58
-|-|   0x210000142|  movabs 0x555557e1ec70,%rax
   0x3000008e|  add    $0xb,%eax|   0x21000014c|  add    $0xb,%rax
   0x30000091|  mov    %eax,0x58b7e990|   0x210000150|  movabs %rax,0x555557e1ec70
-|-|   0x21000015a|  mov    %rax,%rbx
-|-|   0x21000015d|  movabs 0x555557e1dde0,%rax
   0x30000096|  sub    0x58b7db40,%eax|   0x210000167|  sub    %rax,%rbx
-|-|   0x21000016a|  mov    %rbx,%rax
   0x3000009c|  js     0x58d79019 <_ZL16eeRecDispatchers+25>|   0x21000016d|  js     0x25811c039
-|-|   0x210000173|  movabs $0x55555811c000,%rax
   0x300000a2|  jmp    0x58d79000 <_ZL16eeRecDispatchers>|   0x21000017d|  rex.W jmpq *%rax



