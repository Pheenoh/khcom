.syntax unified
	.align 2, 0
	.global func_08085C3C
	.thumb
	.thumb_func
	.type func_08085C3C, %function
func_08085C3C: @ 08085C3C
	push {lr}
	ldr r1, _08085C70 @ =0x02034AB0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bl func_08083FE0
	bl func_08085160
	ldr r0, _08085C74 @ =0x03006C10
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _08085C78
	bl func_080AB228
	movs r0, #0x02
	bl func_080AB22C
	movs r0, #0x01
	bl func_080AB334
	movs r0, #0x00
	bl func_080AB4AC
	b _08085C88
_08085C70: .4byte 0x02034AB0
_08085C74: .4byte 0x03006C10
_08085C78:
	bl func_080AB880
	bl func_080AB8E4
	bl func_080AB964
	bl func_080AB968
_08085C88:
	ldr r1, _08085CA4 @ =0x09EE4AC8
	movs r0, #0x00
	bl func_08085788
	ldr r1, _08085CA8 @ =0x09EE4AD6
	movs r0, #0x01
	bl func_08085788
	ldr r1, _08085CAC @ =0x09EE4AE4
	movs r0, #0x02
	bl func_08085788
	pop {r0}
	bx r0
_08085CA4: .4byte 0x09EE4AC8
_08085CA8: .4byte 0x09EE4AD6
_08085CAC: .4byte 0x09EE4AE4
.syntax divided
