.syntax unified
	.align 2, 0
	.global func_08050F10
	.thumb
	.thumb_func
	.type func_08050F10, %function
func_08050F10: @ 08050F10
	push {r4, r5, lr}
	add sp, #-0x020
	mov r12, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	mov r3, r12
	adds r3, #0x40
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _08050F46
	lsls r1, r4, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x04]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	mov r1, sp
	movs r0, #0x01
	strh r0, [r1, #0x12]
	b _08050F54
_08050F46:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x04]
	subs r1, r1, r0
	str r1, [sp, #0x000]
	mov r0, sp
	strh r2, [r0, #0x12]
_08050F54:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x0C]
	adds r0, r0, r1
	str r0, [sp, #0x008]
	ldr r0, [r3, #0x08]
	str r0, [sp, #0x004]
	movs r0, #0xCA
	lsls r0, r0, #0x01
	add r0, r12
	ldr r1, _08050F78 @ =0x09EDB668
	mov r2, sp
	bl func_08000E14
	add sp, #0x020
	pop {r4, r5}
	pop {r0}
	bx r0
_08050F78: .4byte 0x09EDB668
.syntax divided
