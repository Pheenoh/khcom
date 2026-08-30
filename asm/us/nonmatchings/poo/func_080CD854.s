.syntax unified
	.align 2, 0
	.global func_080CD854
	.thumb
	.thumb_func
	.type func_080CD854, %function
func_080CD854: @ 080CD854
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldrh r0, [r6, #0x26]
	cmp r0, r1
	beq _080CD88E
	strh r1, [r6, #0x26]
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r4, _080CD898 @ =0x096FD47C
	lsls r5, r1, #0x04
	adds r2, r5, r4
	ldrh r1, [r2, #0x0C]
	ldr r3, [r2, #0x00]
	adds r2, r4, #0x4
	adds r2, r5, r2
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	adds r2, r7, #0x0
	bl func_08005974
	ldr r0, [r6, #0x00]
	adds r4, #0x08
	adds r5, r5, r4
	ldr r1, [r5, #0x00]
	bl func_08002A10
_080CD88E:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD898: .4byte 0x096FD47C
.syntax divided
