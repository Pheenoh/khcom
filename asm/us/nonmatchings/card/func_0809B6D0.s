.syntax unified
	.align 2, 0
	.global func_0809B6D0
	.thumb
	.thumb_func
	.type func_0809B6D0, %function
func_0809B6D0: @ 0809B6D0
	push {r4, r5, lr}
	add sp, #-0x010
	ldr r4, [sp, #0x01C]
	lsls r4, r4, #0x10
	ldr r5, _0809B708 @ =0x09EE275C
	lsrs r4, r4, #0x0E
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x08
	str r1, [sp, #0x000]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x08
	str r2, [sp, #0x004]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x08
	str r3, [sp, #0x008]
	ldr r1, [r4, #0x00]
	str r1, [sp, #0x00C]
	ldr r1, _0809B70C @ =0x09EE77A4
	mov r2, sp
	bl TaskCreate
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0809B708: .4byte 0x09EE275C
_0809B70C: .4byte 0x09EE77A4
.syntax divided
