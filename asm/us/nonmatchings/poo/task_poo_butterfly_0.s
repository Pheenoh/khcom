.syntax unified
	.align 2, 0
	.global task_poo_butterfly_0
	.thumb
	.thumb_func
	.type task_poo_butterfly_0, %function
task_poo_butterfly_0: @ 080D20B8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r4, r7, #0x0
	adds r4, #0xD4
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x00]
	adds r5, r7, #0x0
	adds r5, #0xD8
	ldr r0, [r1, #0x04]
	str r0, [r5, #0x00]
	adds r6, r7, #0x0
	adds r6, #0xDC
	ldr r0, [r1, #0x08]
	ldr r1, _080D217C @ =0xFFFFF200
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldr r0, _080D2180 @ =0x09849C38
	movs r1, #0x20
	bl func_08002A14
	adds r1, r7, #0x0
	adds r1, #0xD0
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x00]
	ldr r1, _080D2184 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r7, #0x20]
	ldr r0, [r5, #0x00]
	str r0, [r7, #0x24]
	ldr r0, [r6, #0x00]
	str r0, [r7, #0x28]
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r7, #0x30]
	ldr r0, [r5, #0x00]
	str r0, [r7, #0x34]
	ldr r0, [r4, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r7, #0x38]
	ldr r0, [r5, #0x00]
	movs r1, #0xE0
	lsls r1, r1, #0x03
	adds r0, r0, r1
	str r0, [r7, #0x3C]
	adds r0, r7, #0x0
	adds r0, #0x48
	movs r3, #0x60
	strb r3, [r0, #0x00]
	adds r0, #0x0A
	strh r3, [r0, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x88
	ldr r0, [r4, #0x00]
	movs r2, #0x90
	lsls r2, r2, #0x05
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r5, #0x00]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	adds r1, #0x10
	ldr r0, [r4, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r5, #0x00]
	str r0, [r1, #0x00]
	subs r1, #0x0C
	ldr r0, [r4, #0x00]
	ldr r2, _080D2188 @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r5, #0x00]
	ldr r2, _080D218C @ =0xFFFFF900
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, #0x14
	movs r0, #0xE0
	strb r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xBA
	strh r3, [r0, #0x00]
	adds r0, r7, #0x0
	bl func_080D206C
	adds r0, r7, #0x0
	adds r0, #0x68
	bl func_080D206C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D217C: .4byte 0xFFFFF200
_080D2180: .4byte 0x09849C38
_080D2184: .4byte 0xFFFFF000
_080D2188: .4byte 0xFFFFFF00
_080D218C: .4byte 0xFFFFF900
.syntax divided
