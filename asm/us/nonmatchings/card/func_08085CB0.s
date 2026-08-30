.syntax unified
	.align 2, 0
	.global func_08085CB0
	.thumb
	.thumb_func
	.type func_08085CB0, %function
func_08085CB0: @ 08085CB0
	push {lr}
	ldr r1, _08085CF4 @ =0x02034AB0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bl func_08083FE0
	bl func_08085160
	bl func_080AB228
	movs r0, #0x00
	bl func_080AB334
	movs r0, #0x01
	bl func_080AB22C
	movs r0, #0x02
	bl func_080AB4AC
	ldr r1, _08085CF8 @ =0x09EE4AC8
	movs r0, #0x00
	bl func_08085788
	ldr r1, _08085CFC @ =0x09EE4AD6
	movs r0, #0x01
	bl func_08085788
	ldr r1, _08085D00 @ =0x09EE4AE4
	movs r0, #0x02
	bl func_08085788
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08085CF4: .4byte 0x02034AB0
_08085CF8: .4byte 0x09EE4AC8
_08085CFC: .4byte 0x09EE4AD6
_08085D00: .4byte 0x09EE4AE4
.syntax divided
