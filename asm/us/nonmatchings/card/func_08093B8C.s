.syntax unified
	.align 2, 0
	.global func_08093B8C
	.thumb
	.thumb_func
	.type func_08093B8C, %function
func_08093B8C: @ 08093B8C
	push {r4, lr}
	movs r1, #0x00
	ldr r4, _08093BAC @ =0x0203A8C0
	movs r3, #0x00
	ldr r2, _08093BB0 @ =0x0000010D
_08093B96:
	adds r0, r1, r4
	strb r3, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r2
	bls _08093B96
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08093BAC: .4byte 0x0203A8C0
_08093BB0: .4byte 0x0000010D
.syntax divided
