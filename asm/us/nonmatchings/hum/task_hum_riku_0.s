.syntax unified
	.align 2, 0
	.global task_hum_riku_0
	.thumb
	.thumb_func
	.type task_hum_riku_0, %function
task_hum_riku_0: @ 08057F98
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r1, _080580C4 @ =0x0813FD24
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r2, _080580C8 @ =0x0813FD40
	adds r0, r5, #0x0
	bl func_0800E314
	movs r1, #0xE2
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	str r2, [r0, #0x00]
	movs r3, #0xE5
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strh r2, [r0, #0x00]
	movs r6, #0xDE
	lsls r6, r6, #0x01
	adds r3, r5, r6
	ldrh r1, [r3, #0x00]
	movs r0, #0x03
	orrs r0, r1
	strh r0, [r3, #0x00]
	movs r1, #0xE6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strh r2, [r0, #0x00]
	ldr r0, _080580CC @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0xA1
	beq _08057FF2
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldr r0, _080580D0 @ =0x0813FBBC
	str r0, [r1, #0x00]
_08057FF2:
	movs r6, #0xE8
	lsls r6, r6, #0x01
	adds r4, r5, r6
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_08057E2C
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0x8C
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0x98
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0xA4
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0xB0
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0xBC
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0xC8
	lsls r0, r0, #0x02
	adds r1, r5, r0
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r1, #0xD4
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldm r4!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r4!, {r1, r2, r3}
	stm r0!, {r1, r2, r3}
	ldm r4!, {r1, r2, r6}
	stm r0!, {r1, r2, r6}
	ldm r4!, {r1, r3, r6}
	stm r0!, {r1, r3, r6}
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080580C4: .4byte 0x0813FD24
_080580C8: .4byte 0x0813FD40
_080580CC: .4byte 0x02039B84
_080580D0: .4byte 0x0813FBBC
.syntax divided
