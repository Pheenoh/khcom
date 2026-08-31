.syntax unified
	.align 2, 0
	.global func_0801CA88
	.thumb
	.thumb_func
	.type func_0801CA88, %function
func_0801CA88: @ 0801CA88
	push {r4, r5, lr}
	add sp, #-0x004
	movs r5, #0x00
	str r5, [sp, #0x000]
	ldr r4, _0801CAF0 @ =0x02039BB0
	ldr r2, _0801CAF4 @ =0x05000084
	mov r0, sp
	adds r1, r4, #0x0
	bl CpuSet
	ldr r0, _0801CAF8 @ =0x03006C10
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0801CAB6
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	orrs r0, r1
	movs r1, #0x20
	orrs r0, r1
	str r0, [r4, #0x08]
_0801CAB6:
	movs r0, #0x04
	strb r0, [r4, #0x0C]
	movs r0, #0x01
	strb r0, [r4, #0x0D]
	bl func_0800F9A0
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0801CAFC @ =0x0000FFFF
	strh r0, [r1, #0x00]
	bl func_080DFB2C
	adds r0, r4, #0x0
	adds r0, #0xF8
	ldrh r0, [r0, #0x00]
	strh r0, [r4, #0x32]
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r0, #0x2D
	strb r0, [r1, #0x00]
	movs r1, #0xDC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	str r5, [r0, #0x00]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_0801CAF0: .4byte 0x02039BB0
_0801CAF4: .4byte 0x05000084
_0801CAF8: .4byte 0x03006C10
_0801CAFC: .4byte 0x0000FFFF
.syntax divided
