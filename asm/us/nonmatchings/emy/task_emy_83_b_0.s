.syntax unified
	.align 2, 0
	.global task_emy_83_b_0
	.thumb
	.thumb_func
	.type task_emy_83_b_0, %function
task_emy_83_b_0: @ 0803E920
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	movs r0, #0x00
	mov r8, r0
	str r0, [r4, #0x2C]
	ldr r0, _0803E984 @ =0x08F69B84
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	ldr r1, _0803E988 @ =0x08B1B854
	movs r0, #0x80
	bl AllocObjTiles
	str r0, [r4, #0x00]
	adds r5, r4, #0x0
	adds r5, #0x08
	ldr r1, _0803E98C @ =0x09EE10A4
	ldr r2, _0803E990 @ =0x09EE1090
	adds r0, r5, #0x0
	bl AnimInit
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	ldr r0, [r6, #0x00]
	str r0, [r4, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r4, #0x28]
	mov r0, r8
	strh r0, [r4, #0x30]
	adds r4, #0x34
	adds r0, r4, #0x0
	movs r1, #0x0C
	movs r2, #0x04
	movs r3, #0x10
	bl func_080122AC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0803E984: .4byte 0x08F69B84
_0803E988: .4byte 0x08B1B854
_0803E98C: .4byte 0x09EE10A4
_0803E990: .4byte 0x09EE1090
.syntax divided
