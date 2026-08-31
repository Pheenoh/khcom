.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_single_0
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_single_0, %function
task_bos_ursula_bubble_single_0: @ 080DD9E8
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	ldrb r1, [r1, #0x00]
	movs r2, #0x9E
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r5, #0x00
	strh r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _080DDA84 @ =0x00000333
	str r0, [r1, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x24
	ldr r1, _080DDA88 @ =0x096FE324
	ldr r0, _080DDA8C @ =0x02039B84
	ldr r0, [r0, #0x00]
	mov r12, r0
	adds r0, #0xCC
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x05
	adds r3, r3, r0
	mov r0, r12
	adds r0, #0xD4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	bl func_0801B37C
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_0801C2DC
	ldr r0, _080DDA90 @ =0x097A0DE4
	movs r1, #0xA8
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080DDA94 @ =0x0984B0F8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	ldr r0, _080DDA98 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x08]
	subs r4, #0x18
	ldr r1, _080DDA9C @ =0x09EF68D8
	ldr r2, _080DDAA0 @ =0x09EF68C0
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r0, r6, r1
	str r5, [r0, #0x00]
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080DDA84: .4byte 0x00000333
_080DDA88: .4byte 0x096FE324
_080DDA8C: .4byte 0x02039B84
_080DDA90: .4byte 0x097A0DE4
_080DDA94: .4byte 0x0984B0F8
_080DDA98: .4byte 0x08F69BC4
_080DDA9C: .4byte 0x09EF68D8
_080DDAA0: .4byte 0x09EF68C0
.syntax divided
