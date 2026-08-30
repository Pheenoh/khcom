.syntax unified
	.align 2, 0
	.global func_08116CEC
	.thumb
	.thumb_func
	.type func_08116CEC, %function
func_08116CEC: @ 08116CEC
	ldr r1, _08116D18 @ =0x040000B0
	ldrh r2, [r1, #0x0A]
	ldr r0, _08116D1C @ =0x0000C5FF
	ands r0, r2
	strh r0, [r1, #0x0A]
	ldrh r2, [r1, #0x0A]
	ldr r0, _08116D20 @ =0x00007FFF
	ands r0, r2
	strh r0, [r1, #0x0A]
	ldrh r0, [r1, #0x0A]
	ldr r1, _08116D24 @ =0x02036028
	movs r0, #0x00
	strb r0, [r1, #0x00]
	strb r0, [r1, #0x01]
	str r0, [r1, #0x04]
	str r0, [r1, #0x08]
	str r0, [r1, #0x0C]
	str r0, [r1, #0x10]
	str r0, [r1, #0x14]
	str r0, [r1, #0x1C]
	bx lr
	.byte 0x00, 0x00
_08116D18: .4byte 0x040000B0
_08116D1C: .4byte 0x0000C5FF
_08116D20: .4byte 0x00007FFF
_08116D24: .4byte 0x02036028
.syntax divided
