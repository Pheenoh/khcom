.syntax unified
	.align 2, 0
	.global task_tutorial_0
	.thumb
	.thumb_func
	.type task_tutorial_0, %function
task_tutorial_0: @ 0805DB38
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	ldr r1, _0805DB70 @ =0x0300750C
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x02
	movs r2, #0x1C
	movs r3, #0x0E
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r0, #0x00
	strh r0, [r7, #0x00]
	strh r0, [r7, #0x0C]
	str r0, [r7, #0x04]
	movs r0, #0x78
	strh r0, [r7, #0x0E]
	cmp r4, #0x00
	bne _0805DB74
	movs r0, #0x05
	b _0805DB76
	.byte 0x00, 0x00
_0805DB70: .4byte 0x0300750C
_0805DB74:
	movs r0, #0x2B
_0805DB76:
	str r0, [r7, #0x08]
	ldr r0, _0805DC04 @ =0x02039B84
	ldr r6, [r0, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _0805DC08 @ =0x00000000
	ldr r3, _0805DC0C @ =0x00000010
	orrs r1, r3
	ldr r4, _0805DC10 @ =0x00000000
	ldr r5, _0805DC14 @ =0x00001000
	adds r2, r0, #0x0
	adds r3, r1, #0x0
	orrs r3, r5
	ldr r4, _0805DC18 @ =0x00000000
	ldr r5, _0805DC1C @ =0x00002000
	adds r1, r3, #0x0
	orrs r1, r5
	ldr r4, _0805DC20 @ =0x00000000
	ldr r5, _0805DC24 @ =0x00000020
	adds r3, r1, #0x0
	orrs r3, r5
	ldr r4, _0805DC28 @ =0x00000000
	ldr r5, _0805DC2C @ =0x00000040
	adds r1, r3, #0x0
	orrs r1, r5
	ldr r4, _0805DC30 @ =0x00000000
	ldr r5, _0805DC34 @ =0x00000080
	adds r3, r1, #0x0
	orrs r3, r5
	ldr r0, _0805DC38 @ =0x00000000
	ldr r1, _0805DC3C @ =0x00040000
	adds r4, r2, #0x0
	adds r5, r3, #0x0
	orrs r5, r1
	ldr r2, _0805DC40 @ =0x00000000
	ldr r3, _0805DC44 @ =0x00000100
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	orrs r1, r3
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	movs r0, #0x80
	lsls r0, r0, #0x01
	ldr r1, _0805DC48 @ =0x08B263D2
	bl func_080028F8
	str r0, [r7, #0x18]
	ldr r0, _0805DC4C @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x1C]
	adds r4, r7, #0x0
	adds r4, #0x20
	ldr r1, _0805DC50 @ =0x09EE15F0
	ldr r2, _0805DC54 @ =0x09EE15C0
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	movs r0, #0x02
	bl func_08006578
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805DC04: .4byte 0x02039B84
_0805DC08: .4byte 0x00000000
_0805DC0C: .4byte 0x00000010
_0805DC10: .4byte 0x00000000
_0805DC14: .4byte 0x00001000
_0805DC18: .4byte 0x00000000
_0805DC1C: .4byte 0x00002000
_0805DC20: .4byte 0x00000000
_0805DC24: .4byte 0x00000020
_0805DC28: .4byte 0x00000000
_0805DC2C: .4byte 0x00000040
_0805DC30: .4byte 0x00000000
_0805DC34: .4byte 0x00000080
_0805DC38: .4byte 0x00000000
_0805DC3C: .4byte 0x00040000
_0805DC40: .4byte 0x00000000
_0805DC44: .4byte 0x00000100
_0805DC48: .4byte 0x08B263D2
_0805DC4C: .4byte 0x08F69BA4
_0805DC50: .4byte 0x09EE15F0
_0805DC54: .4byte 0x09EE15C0
.syntax divided
