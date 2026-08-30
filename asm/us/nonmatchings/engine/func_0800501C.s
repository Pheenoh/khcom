.syntax unified
	.align 2, 0
	.global func_0800501C
	.thumb
	.thumb_func
	.type func_0800501C, %function
func_0800501C: @ 0800501C
	cmp r0, #0x01
	beq _08005040
	cmp r0, #0x01
	bcc _0800502E
	cmp r0, #0x02
	beq _08005050
	cmp r0, #0x03
	beq _08005060
	b _0800506A
_0800502E:
	ldr r2, _08005038 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _0800503C @ =0x0000FEFF
	b _08005066
	.byte 0x00, 0x00
_08005038: .4byte 0x03007500
_0800503C: .4byte 0x0000FEFF
_08005040:
	ldr r2, _08005048 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _0800504C @ =0x0000FDFF
	b _08005066
_08005048: .4byte 0x03007500
_0800504C: .4byte 0x0000FDFF
_08005050:
	ldr r2, _08005058 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _0800505C @ =0x0000FBFF
	b _08005066
_08005058: .4byte 0x03007500
_0800505C: .4byte 0x0000FBFF
_08005060:
	ldr r2, _0800506C @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _08005070 @ =0x0000F7FF
_08005066:
	ands r0, r1
	strh r0, [r2, #0x00]
_0800506A:
	bx lr
_0800506C: .4byte 0x03007500
_08005070: .4byte 0x0000F7FF
.syntax divided
