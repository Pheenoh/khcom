.syntax unified
	.align 2, 0
	.global func_08005B78
	.thumb
	.thumb_func
	.type func_08005B78, %function
func_08005B78: @ 08005B78
	push {r4, lr}
	add sp, #-0x004
	ldr r0, _08005BA4 @ =0x0812168C
	bl func_08000AE4
	ldr r4, _08005BA8 @ =0x03007568
	movs r0, #0xB3
	lsls r0, r0, #0x03
	bl func_08000928
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _08005BAC @ =0x05000166
	mov r0, sp
	bl func_08117FE8
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
_08005BA4: .4byte 0x0812168C
_08005BA8: .4byte 0x03007568
_08005BAC: .4byte 0x05000166
	.byte 0x00, 0xB5, 0x03, 0x48, 0x00, 0x68, 0xFA, 0xF7, 0x0D, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x68, 0x75, 0x00, 0x03
.syntax divided
