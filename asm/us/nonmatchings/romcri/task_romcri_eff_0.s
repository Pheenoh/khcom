.syntax unified
	.align 2, 0
	.global task_romcri_eff_0
	.thumb
	.thumb_func
	.type task_romcri_eff_0, %function
task_romcri_eff_0: @ 0803F704
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x17
	movs r3, #0x0C
	bl func_08005074
	movs r0, #0x00
	strb r5, [r4, #0x02]
	strh r0, [r4, #0x00]
	movs r0, #0x01
	bl func_0800501C
	movs r0, #0x00
	bl func_08007E68
	ldr r1, _0803F758 @ =0x08F6D9E4
	movs r0, #0x01
	movs r2, #0x20
	bl func_080050DC
	bl func_08007E7C
	movs r0, #0x01
	movs r1, #0x00
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	ldrb r0, [r4, #0x02]
	cmp r0, #0x53
	beq _0803F780
	cmp r0, #0x53
	bgt _0803F75C
	cmp r0, #0x2D
	beq _0803F7CC
	b _0803F7E0
_0803F758: .4byte 0x08F6D9E4
_0803F75C:
	cmp r0, #0xAD
	beq _0803F766
	cmp r0, #0xD3
	beq _0803F7A8
	b _0803F7E0
_0803F766:
	ldr r1, _0803F774 @ =0x08ED21E4
	ldr r2, _0803F778 @ =0x00004AC0
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0803F77C @ =0x0000FFDD
	b _0803F78C
_0803F774: .4byte 0x08ED21E4
_0803F778: .4byte 0x00004AC0
_0803F77C: .4byte 0x0000FFDD
_0803F780:
	ldr r1, _0803F798 @ =0x08ED21E4
	ldr r2, _0803F79C @ =0x00004AC0
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0803F7A0 @ =0x0000FFB3
_0803F78C:
	ldr r2, _0803F7A4 @ =0x0000FFE9
	movs r0, #0x01
	bl func_080054EC
	b _0803F7E0
	.byte 0x00, 0x00
_0803F798: .4byte 0x08ED21E4
_0803F79C: .4byte 0x00004AC0
_0803F7A0: .4byte 0x0000FFB3
_0803F7A4: .4byte 0x0000FFE9
_0803F7A8:
	ldr r1, _0803F7C0 @ =0x08EDBB44
	ldr r2, _0803F7C4 @ =0x00007520
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0803F7C8 @ =0x0000FFD9
	movs r0, #0x01
	movs r2, #0x02
	bl func_080054EC
	b _0803F7E0
	.byte 0x00, 0x00
_0803F7C0: .4byte 0x08EDBB44
_0803F7C4: .4byte 0x00007520
_0803F7C8: .4byte 0x0000FFD9
_0803F7CC:
	ldr r1, _0803F7E8 @ =0x08EDBB44
	ldr r2, _0803F7EC @ =0x00007520
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0803F7F0 @ =0x0000FFB9
	movs r0, #0x01
	movs r2, #0x03
	bl func_080054EC
_0803F7E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803F7E8: .4byte 0x08EDBB44
_0803F7EC: .4byte 0x00007520
_0803F7F0: .4byte 0x0000FFB9
.syntax divided
