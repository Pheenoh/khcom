.syntax unified
	.align 2, 0
	.global func_08006B4C
	.thumb
	.thumb_func
	.type func_08006B4C, %function
func_08006B4C: @ 08006B4C
	push {lr}
	ldr r1, _08006B68 @ =0x02034040
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r1, _08006B6C @ =0x02034054
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08006B70 @ =0x02034048
	ldr r0, [r0, #0x00]
	bl func_0800501C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006B68: .4byte 0x02034040
_08006B6C: .4byte 0x02034054
_08006B70: .4byte 0x02034048
.syntax divided
