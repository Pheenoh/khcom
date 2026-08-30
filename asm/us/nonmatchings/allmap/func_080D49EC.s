.syntax unified
	.align 2, 0
	.global func_080D49EC
	.thumb
	.thumb_func
	.type func_080D49EC, %function
func_080D49EC: @ 080D49EC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4A24
	movs r6, #0x00
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bge _080D4A24
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r7, r5, r2
_080D4A12:
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08098670
	adds r4, #0x34
	adds r6, #0x01
	ldrh r0, [r7, #0x00]
	cmp r6, r0
	blt _080D4A12
_080D4A24:
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r2, #0x84
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	adds r2, r5, #0x0
	adds r2, #0xF8
	ldr r2, [r2, #0x00]
	adds r3, r5, #0x0
	adds r3, #0xF0
	ldr r3, [r3, #0x00]
	adds r4, r5, #0x0
	adds r4, #0xF4
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x14
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
