.syntax unified
	.align 2, 0
	.global task_poo_wagon_0
	.thumb
	.thumb_func
	.type task_poo_wagon_0, %function
task_poo_wagon_0: @ 080D0290
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _080D02EC @ =0x02034E20
	str r4, [r0, #0x00]
	ldr r0, _080D02F0 @ =0x0002AE00
	str r0, [r4, #0x1C]
	ldr r0, _080D02F4 @ =0x00017700
	str r0, [r4, #0x20]
	movs r5, #0x00
	str r5, [r4, #0x24]
	str r5, [r4, #0x28]
	adds r1, r4, #0x0
	adds r1, #0x2C
	adds r0, r4, #0x0
	adds r0, #0x1C
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D02CC
	ldr r0, [r4, #0x20]
	movs r1, #0xC0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	str r0, [r4, #0x20]
_080D02CC:
	str r5, [r4, #0x04]
	ldr r0, _080D02F8 @ =0x09758C04
	str r0, [r4, #0x08]
	ldr r0, _080D02FC @ =0x09758B70
	str r0, [r4, #0x10]
	ldr r0, _080D0300 @ =0x09758C20
	str r0, [r4, #0x18]
	adds r0, r4, #0x0
	adds r0, #0x3C
	strb r5, [r0, #0x00]
	strh r5, [r4, #0x3E]
	adds r0, #0x04
	strh r5, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D02EC: .4byte 0x02034E20
_080D02F0: .4byte 0x0002AE00
_080D02F4: .4byte 0x00017700
_080D02F8: .4byte 0x09758C04
_080D02FC: .4byte 0x09758B70
_080D0300: .4byte 0x09758C20
.syntax divided
