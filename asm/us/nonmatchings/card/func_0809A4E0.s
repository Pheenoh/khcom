.syntax unified
	.align 2, 0
	.global func_0809A4E0
	.thumb
	.thumb_func
	.type func_0809A4E0, %function
func_0809A4E0: @ 0809A4E0
	push {r4, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x01
	bne _0809A4F8
	movs r1, #0xF0
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x07
	b _0809A4FE
_0809A4F8:
	movs r1, #0x00
	movs r2, #0xA0
	lsls r2, r2, #0x08
_0809A4FE:
	ldr r0, [r4, #0x38]
	subs r0, r1, r0
	str r0, [sp, #0x000]
	ldr r0, [r4, #0x3C]
	subs r0, r2, r0
	str r0, [sp, #0x004]
	add r1, sp, #0x004
	mov r0, sp
	bl func_0805F5A4
	movs r2, #0xD6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	str r0, [r1, #0x00]
	movs r0, #0xD8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [sp, #0x000]
	negs r0, r0
	str r0, [r1, #0x00]
	adds r2, #0x08
	adds r1, r4, r2
	ldr r0, [sp, #0x004]
	negs r0, r0
	str r0, [r1, #0x00]
	movs r0, #0xD4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0xC0
	lsls r0, r0, #0x02
	str r0, [r1, #0x00]
	subs r2, #0x10
	adds r1, r4, r2
	movs r0, #0x02
	str r0, [r1, #0x00]
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
