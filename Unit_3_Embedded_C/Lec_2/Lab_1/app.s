
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f000c 	ldr	r0, [pc, #12]	; 1c <main+0x1c>
   c:	ebfffffe 	bl	0 <uart_send_string>
  10:	e3a03000 	mov	r3, #0
  14:	e1a00003 	mov	r0, r3
  18:	e8bd8800 	pop	{fp, pc}
  1c:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e492d6e 	cdpvs	13, 4, cr2, cr9, cr14, {3}
   8:	7065442d 	rsbvc	r4, r5, sp, lsr #8
   c:	3c3a6874 	ldccc	8, cr6, [sl], #-464	; 0xfffffe30
  10:	61737241 	cmnvs	r3, r1, asr #4
  14:	4120796e 	teqmi	r0, lr, ror #18
  18:	61726873 	cmnvs	r2, r3, ror r8
  1c:	00003e66 	andeq	r3, r0, r6, ror #28
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000b1 	strheq	r0, [r0], -r1
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000020 	andeq	r0, r0, r0, lsr #32
  10:	00001501 	andeq	r1, r0, r1, lsl #10
  14:	00007100 	andeq	r7, r0, r0, lsl #2
  18:	00000000 	andeq	r0, r0, r0
  1c:	00002000 	andeq	r2, r0, r0
  20:	00000000 	andeq	r0, r0, r0
  24:	07040200 	streq	r0, [r4, -r0, lsl #4]
  28:	000000df 	ldrdeq	r0, [r0], -pc	; <UNPREDICTABLE>
  2c:	c9060102 	stmdbgt	r6, {r1, r8}
  30:	02000000 	andeq	r0, r0, #0
  34:	00550801 	subseq	r0, r5, r1, lsl #16
  38:	02020000 	andeq	r0, r2, #0
  3c:	0000d505 	andeq	sp, r0, r5, lsl #10
  40:	07020200 	streq	r0, [r2, -r0, lsl #4]
  44:	000000b6 	strheq	r0, [r0], -r6
  48:	69050403 	stmdbvs	r5, {r0, r1, sl}
  4c:	0200746e 	andeq	r7, r0, #1845493760	; 0x6e000000
  50:	00000508 	andeq	r0, r0, r8, lsl #10
  54:	08020000 	stmdaeq	r2, {}	; <UNPREDICTABLE>
  58:	00003e07 	andeq	r3, r0, r7, lsl #28
  5c:	05040200 	streq	r0, [r4, #-512]	; 0x200
  60:	00000068 	andeq	r0, r0, r8, rrx
  64:	ec070402 	cfstrs	mvf0, [r7], {2}
  68:	02000000 	andeq	r0, r0, #0
  6c:	002c0704 	eoreq	r0, ip, r4, lsl #14
  70:	01020000 	mrseq	r0, (UNDEF: 2)
  74:	00006308 	andeq	r6, r0, r8, lsl #6
  78:	1b010400 	blne	41008 <main+0x41008>
  7c:	01000000 	mrseq	r0, (UNDEF: 0)
  80:	00004806 	andeq	r4, r0, r6, lsl #16
  84:	00000000 	andeq	r0, r0, r0
  88:	00002000 	andeq	r2, r0, r0
  8c:	00000000 	andeq	r0, r0, r0
  90:	33050100 	movwcc	r0, #20736	; 0x5100
  94:	a2000000 	andge	r0, r0, #0
  98:	06000000 	streq	r0, [r0], -r0
  9c:	00000064 	andeq	r0, r0, r4, rrx
  a0:	0e070063 	cdpeq	0, 0, cr0, cr7, cr3, {3}
  a4:	01000000 	mrseq	r0, (UNDEF: 0)
  a8:	00009204 	andeq	r9, r0, r4, lsl #4
  ac:	03050100 	movweq	r0, #20736	; 0x5100
  b0:	00000000 	andeq	r0, r0, r0
	...

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0b0b0024 	bleq	2c00ac <main+0x2c00ac>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	24030000 	strcs	r0, [r3], #-0
  20:	3e0b0b00 	vmlacc.f64	d0, d11, d0
  24:	0008030b 	andeq	r0, r8, fp, lsl #6
  28:	002e0400 	eoreq	r0, lr, r0, lsl #8
  2c:	0e030c3f 	mcreq	12, 0, r0, cr3, cr15, {1}
  30:	0b3b0b3a 	bleq	ec2d20 <main+0xec2d20>
  34:	01111349 	tsteq	r1, r9, asr #6
  38:	06400112 			; <UNDEFINED> instruction: 0x06400112
  3c:	000c4296 	muleq	ip, r6, r2
  40:	01010500 	tsteq	r1, r0, lsl #10
  44:	13011349 	movwne	r1, #4937	; 0x1349
  48:	21060000 	mrscs	r0, (UNDEF: 6)
  4c:	2f134900 	svccs	0x00134900
  50:	0700000b 	streq	r0, [r0, -fp]
  54:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  58:	0b3b0b3a 	bleq	ec2d48 <main+0xec2d48>
  5c:	0c3f1349 	ldceq	3, cr1, [pc], #-292	; ffffff40 <main+0xffffff40>
  60:	00000a02 	andeq	r0, r0, r2, lsl #20
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000020 	andeq	r0, r0, r0, lsr #32
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000020 	andeq	r0, r0, r0, lsr #32
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000032 	andeq	r0, r0, r2, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4c4c1800 	mcrrmi	8, 0, r1, ip, cr0
  30:	0006022f 	andeq	r0, r6, pc, lsr #4
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
   4:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
   8:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
   c:	74730074 	ldrbtvc	r0, [r3], #-116	; 0x74
  10:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  14:	70706100 	rsbsvc	r6, r0, r0, lsl #2
  18:	6d00632e 	stcvs	3, cr6, [r0, #-184]	; 0xffffff48
  1c:	006e6961 	rsbeq	r6, lr, r1, ror #18
  20:	20554e47 	subscs	r4, r5, r7, asr #28
  24:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
  28:	00322e37 	eorseq	r2, r2, r7, lsr lr
  2c:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
  30:	736e7520 	cmnvc	lr, #32, 10	; 0x8000000
  34:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  38:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
  3c:	6f6c0074 	svcvs	0x006c0074
  40:	6c20676e 	stcvs	7, cr6, [r0], #-440	; 0xfffffe48
  44:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  48:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  4c:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
  50:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
  54:	736e7500 	cmnvc	lr, #0, 10
  58:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  5c:	68632064 	stmdavs	r3!, {r2, r5, r6, sp}^
  60:	63007261 	movwvs	r7, #609	; 0x261
  64:	00726168 	rsbseq	r6, r2, r8, ror #2
  68:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
  6c:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
  70:	5c3a4400 	cfldrspl	mvf4, [sl], #-0
  74:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
  78:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  7c:	74737953 	ldrbtvc	r7, [r3], #-2387	; 0x953
  80:	534b6d65 	movtpl	r6, #48485	; 0xbd65
  84:	696e555c 	stmdbvs	lr!, {r2, r3, r4, r6, r8, sl, ip, lr}^
  88:	5f335f74 	svcpl	0x00335f74
  8c:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
  90:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  94:	4c5c435f 	mrrcmi	3, 5, r4, ip, cr15
  98:	6f737365 	svcvs	0x00737365
  9c:	5c325f6e 	ldcpl	15, cr5, [r2], #-440	; 0xfffffe48
  a0:	69737341 	ldmdbvs	r3!, {r0, r6, r8, r9, ip, sp, lr}^
  a4:	656d6e67 	strbvs	r6, [sp, #-3687]!	; 0xe67
  a8:	4e5c746e 	cdpmi	4, 5, cr7, cr12, cr14, {3}
  ac:	66207765 	strtvs	r7, [r0], -r5, ror #14
  b0:	65646c6f 	strbvs	r6, [r4, #-3183]!	; 0xc6f
  b4:	68730072 	ldmdavs	r3!, {r1, r4, r5, r6}^
  b8:	2074726f 	rsbscs	r7, r4, pc, ror #4
  bc:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  c0:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
  c4:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
  c8:	67697300 	strbvs	r7, [r9, -r0, lsl #6]!
  cc:	2064656e 	rsbcs	r6, r4, lr, ror #10
  d0:	72616863 	rsbvc	r6, r1, #6488064	; 0x630000
  d4:	6f687300 	svcvs	0x00687300
  d8:	69207472 	stmdbvs	r0!, {r1, r4, r5, r6, sl, ip, sp, lr}
  dc:	7500746e 	strvc	r7, [r0, #-1134]	; 0x46e
  e0:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  e4:	2064656e 	rsbcs	r6, r4, lr, ror #10
  e8:	00746e69 	rsbseq	r6, r4, r9, ror #28
  ec:	657a6973 	ldrbvs	r6, [sl, #-2419]!	; 0x973
  f0:	65707974 	ldrbvs	r7, [r0, #-2420]!	; 0x974
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000020 	andeq	r0, r0, r0, lsr #32
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
