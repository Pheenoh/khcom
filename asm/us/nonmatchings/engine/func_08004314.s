.syntax unified
	.align 2, 0
	.global func_08004314
	.thumb
	.thumb_func
	.type func_08004314, %function
func_08004314: @ 08004314
	push {r4, lr}
	add sp, #-0x004
	ldr r0, _08004340 @ =0x08121680
	bl func_08000AE4
	ldr r4, _08004344 @ =0x03007574
	ldr r0, _08004348 @ =0x000010B0
	bl IwramAlloc
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _0800434C @ =0x0500042C
	mov r0, sp
	bl CpuSet
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08004340: .4byte 0x08121680
_08004344: .4byte 0x03007574
_08004348: .4byte 0x000010B0
_0800434C: .4byte 0x0500042C
	.byte 0x00, 0xB5, 0x03, 0x48, 0x00, 0x68, 0xFC, 0xF7, 0x3D, 0xFB, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x74, 0x75, 0x00, 0x03
.syntax divided
