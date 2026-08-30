.syntax unified
	.align 2, 0
	.global func_0804F9A0
	.thumb
	.thumb_func
	.type func_0804F9A0, %function
func_0804F9A0: @ 0804F9A0
	mov r12, r0
	movs r0, #0xAE
	lsls r0, r0, #0x01
	add r0, r12
	str r1, [r0, #0x00]
	movs r0, #0xE4
	lsls r0, r0, #0x01
	add r0, r12
	movs r3, #0x00
	strh r2, [r0, #0x00]
	movs r1, #0xB8
	lsls r1, r1, #0x01
	add r1, r12
	movs r0, #0x13
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	add r0, r12
	strh r3, [r0, #0x00]
	bx lr
.syntax divided
