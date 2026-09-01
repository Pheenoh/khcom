.syntax unified
	.align 2, 0
	.global func_080CE960
	.thumb
	.thumb_func
	.type func_080CE960, %function
func_080CE960: @ 080CE960
	push {r4, lr}
	add sp, #-0x008
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	asrs r0, r0, #0x08
	ldr r3, _080CE9A4 @ =0x0203C40C
	ldrh r3, [r3, #0x00]
	subs r0, r0, r3
	asrs r1, r1, #0x08
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080CE9A8 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x18
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x78
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CE9B6
	cmp r4, #0x00
	beq _080CE9B0
	ldr r0, _080CE9AC @ =0x000003C1
	bl m4aSongNumStart
	b _080CE9B6
_080CE9A4: .4byte 0x0203C40C
_080CE9A8: .4byte 0x0203C3F8
_080CE9AC: .4byte 0x000003C1
_080CE9B0:
	ldr r0, _080CE9C0 @ =0x000003B9
	bl m4aSongNumStart
_080CE9B6:
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CE9C0: .4byte 0x000003B9
.syntax divided
