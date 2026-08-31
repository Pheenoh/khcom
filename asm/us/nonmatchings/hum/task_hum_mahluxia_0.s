.syntax unified
	.align 2, 0
	.global task_hum_mahluxia_0
	.thumb
	.thumb_func
	.type task_hum_mahluxia_0, %function
task_hum_mahluxia_0: @ 0804FC28
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	ldr r1, _0804FD68 @ =0x0813F450
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r2, _0804FD6C @ =0x0813F448
	adds r0, r5, #0x0
	bl func_0800E314
	movs r1, #0xE8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r3, #0x00
	strh r3, [r0, #0x00]
	movs r2, #0xE2
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, _0804FD70 @ =0xFFFFFD00
	str r0, [r1, #0x00]
	movs r6, #0xDE
	lsls r6, r6, #0x01
	adds r2, r5, r6
	ldrh r1, [r2, #0x00]
	movs r0, #0x03
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r1, #0xEC
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strh r3, [r0, #0x00]
	ldr r0, _0804FD74 @ =0x0813F368
	adds r1, r5, #0x0
	adds r1, #0x14
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	movs r2, #0xEE
	lsls r2, r2, #0x01
	adds r4, r5, r2
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0804FA70
	movs r3, #0x83
	lsls r3, r3, #0x02
	adds r1, r5, r3
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r6, #0x8F
	lsls r6, r6, #0x02
	adds r1, r5, r6
	adds r0, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r0, #0x9B
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
	movs r0, #0xA7
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
	movs r0, #0xB3
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
	movs r0, #0xBF
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
	movs r0, #0xCB
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
	movs r1, #0xD7
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
	movs r2, #0xE4
	lsls r2, r2, #0x02
	adds r0, r5, r2
	movs r1, #0x16
	bl TaskPoolInit
	movs r3, #0xC2
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldr r0, _0804FD78 @ =0x0813F35C
	str r0, [r1, #0x00]
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0804FD68: .4byte 0x0813F450
_0804FD6C: .4byte 0x0813F448
_0804FD70: .4byte 0xFFFFFD00
_0804FD74: .4byte 0x0813F368
_0804FD78: .4byte 0x0813F35C
.syntax divided
