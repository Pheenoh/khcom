.syntax unified
	.align 2, 0
	.global task_status_bar_2
	.thumb
	.thumb_func
	.type task_status_bar_2, %function
task_status_bar_2: @ 080D7AFC
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, [r4, #0x1C]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _080D7B6C @ =0x097A18CC
	ldr r3, [r4, #0x00]
	ldr r1, [r4, #0x04]
	str r1, [sp, #0x000]
	movs r6, #0x00
	str r6, [sp, #0x004]
	movs r5, #0xC0
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	movs r1, #0x1D
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl DrawSprite
	ldr r0, _080D7B70 @ =0x0203C550
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _080D7B64
	ldr r1, [r4, #0x0C]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D7B74 @ =0x097A1864
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r0, #0x1E
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
	ldr r1, [r4, #0x14]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D7B78 @ =0x097A1898
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r0, #0x1F
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
_080D7B64:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D7B6C: .4byte 0x097A18CC
_080D7B70: .4byte 0x0203C550
_080D7B74: .4byte 0x097A1864
_080D7B78: .4byte 0x097A1898
.syntax divided
