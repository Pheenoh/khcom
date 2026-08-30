.syntax unified
	.align 2, 0
	.global task_btl_vslockon_1
	.thumb
	.thumb_func
	.type task_btl_vslockon_1, %function
task_btl_vslockon_1: @ 0805D210
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _0805D22C @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x13
	bne _0805D234
	ldr r2, _0805D230 @ =0x02039B9C
	ldr r1, [r2, #0x00]
	movs r0, #0x00
	b _0805D23A
_0805D22C: .4byte 0x02039B84
_0805D230: .4byte 0x02039B9C
_0805D234:
	ldr r2, _0805D250 @ =0x02039B9C
	ldr r1, [r2, #0x00]
	ldr r0, [r3, #0x7C]
_0805D23A:
	str r0, [r1, #0x78]
	ldr r2, [r2, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x13
	bne _0805D254
	ldr r1, [r5, #0x00]
	movs r0, #0x00
	b _0805D258
	.byte 0x00, 0x00
_0805D250: .4byte 0x02039B9C
_0805D254:
	ldr r1, [r5, #0x00]
	ldr r0, [r2, #0x7C]
_0805D258:
	str r0, [r1, #0x78]
	adds r0, r4, #0x0
	adds r0, #0x08
	bl func_08005A64
	str r0, [r4, #0x20]
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
