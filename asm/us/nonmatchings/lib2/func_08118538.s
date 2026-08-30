.syntax unified
	.align 2, 0
	.global func_08118538
	.thumb
	.thumb_func
	.type func_08118538, %function
func_08118538: @ 08118538
	push {r7, lr}
	mov r7, sp
	ldr r0, _08118560 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119654
	cmp r0, #0x00
	beq _0811854E
	bl func_0811D4CC
_0811854E:
	ldr r0, _08118560 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08118EEC
	pop {r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08118560: .4byte 0x0203C7C4
	.byte 0x80, 0xB5, 0x6F, 0x46, 0x04, 0xF0, 0xEE, 0xFE, 0x00, 0xF0, 0x20, 0xF8, 0x80, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
.syntax divided
