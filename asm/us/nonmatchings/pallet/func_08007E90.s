.syntax unified
	.align 2, 0
	.global func_08007E90
	.thumb
	.thumb_func
	.type func_08007E90, %function
func_08007E90: @ 08007E90
	push {r4, lr}
	add sp, #-0x004
	ldr r0, _08007EC0 @ =0x08121714
	bl func_08000AE4
	ldr r4, _08007EC4 @ =0x0300756C
	movs r0, #0x88
	lsls r0, r0, #0x03
	bl IwramAlloc
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _08007EC8 @ =0x05000110
	mov r0, sp
	bl CpuSet
	bl func_08007EE0
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
_08007EC0: .4byte 0x08121714
_08007EC4: .4byte 0x0300756C
_08007EC8: .4byte 0x05000110
	.byte 0x00, 0xB5, 0x03, 0x48, 0x00, 0x68, 0xF8, 0xF7, 0x7F, 0xFD, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x6C, 0x75, 0x00, 0x03
.syntax divided
