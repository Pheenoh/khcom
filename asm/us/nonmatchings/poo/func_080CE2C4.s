.syntax unified
	.align 2, 0
	.global func_080CE2C4
	.thumb
	.thumb_func
	.type func_080CE2C4, %function
func_080CE2C4: @ 080CE2C4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	adds r2, r6, #0x0
	adds r2, #0xA8
	ldr r0, [r2, #0x00]
	cmp r0, r1
	beq _080CE302
	str r1, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r4, _080CE30C @ =0x096FD50C
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
_080CE302:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CE30C: .4byte 0x096FD50C
.syntax divided
