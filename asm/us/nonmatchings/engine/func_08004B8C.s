.syntax unified
	.align 2, 0
	.global func_08004B8C
	.thumb
	.thumb_func
	.type func_08004B8C, %function
func_08004B8C: @ 08004B8C
	push {r4, lr}
	add sp, #-0x004
	ldr r0, _08004BB8 @ =0x08121688
	bl func_08000AE4
	ldr r4, _08004BBC @ =0x030074D4
	movs r0, #0x40
	bl IwramAlloc
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _08004BC0 @ =0x05000010
	mov r0, sp
	bl CpuSet
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08004BB8: .4byte 0x08121688
_08004BBC: .4byte 0x030074D4
_08004BC0: .4byte 0x05000010
	.byte 0x00, 0xB5, 0x03, 0x48, 0x00, 0x68, 0xFB, 0xF7, 0x03, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xD4, 0x74, 0x00, 0x03
.syntax divided
