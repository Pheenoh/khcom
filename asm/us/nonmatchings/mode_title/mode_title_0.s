.syntax unified
	.align 2, 0
	.global mode_title_0
	.thumb
	.thumb_func
	.type mode_title_0, %function
mode_title_0: @ 080D5B70
	push {r4, lr}
	add sp, #-0x008
	ldr r1, _080D5BD0 @ =0x02034ECA
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bl func_0801CB44
	bl func_08008C58
	bl func_08093BB4
	bl func_08093C04
	ldr r1, _080D5BD4 @ =0x02034EC2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r4, _080D5BD8 @ =0x02034EC4
	movs r0, #0x80
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r4, #0x00]
	bl func_08004E64
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r0, _080D5BDC @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D5BE4
	ldr r1, _080D5BE0 @ =0x09840798
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	b _080D5BF0
_080D5BD0: .4byte 0x02034ECA
_080D5BD4: .4byte 0x02034EC2
_080D5BD8: .4byte 0x02034EC4
_080D5BDC: .4byte 0x02039BB0
_080D5BE0: .4byte 0x09840798
_080D5BE4:
	ldr r1, _080D5C30 @ =0x0983E398
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
_080D5BF0:
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x03
	bl func_080055C8
	ldr r0, _080D5C34 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D5C44
	ldr r1, _080D5C38 @ =0x097D3658
	ldr r2, _080D5C3C @ =0x00007FA0
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _080D5C40 @ =0x09840F98
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl func_0800510C
	b _080D5C5A
_080D5C30: .4byte 0x0983E398
_080D5C34: .4byte 0x02039BB0
_080D5C38: .4byte 0x097D3658
_080D5C3C: .4byte 0x00007FA0
_080D5C40: .4byte 0x09840F98
_080D5C44:
	ldr r1, _080D5D08 @ =0x097C77B8
	ldr r2, _080D5D0C @ =0x00007FA0
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _080D5D10 @ =0x0983EB98
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl func_0800510C
_080D5C5A:
	movs r0, #0x01
	bl func_0800501C
	bl func_080C736C
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_080C73A4
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x1F
	movs r3, #0x0B
	bl func_08005074
	movs r1, #0x80
	lsls r1, r1, #0x07
	movs r0, #0x02
	bl func_080055EC
	movs r0, #0x02
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _080D5D14 @ =0x097CF758
	movs r2, #0xFC
	lsls r2, r2, #0x06
	movs r0, #0x02
	bl func_080050B8
	ldr r1, _080D5D18 @ =0x0984A618
	movs r0, #0x02
	movs r2, #0xA0
	bl func_080050DC
	ldr r1, _080D5D1C @ =0x0983FB98
	movs r2, #0x80
	lsls r2, r2, #0x03
	movs r0, #0x02
	bl func_0800510C
	ldr r0, _080D5D20 @ =0x0203C548
	movs r2, #0xF0
	lsls r2, r2, #0x07
	str r2, [r0, #0x00]
	ldr r0, _080D5D24 @ =0x0203C54C
	movs r1, #0xB4
	lsls r1, r1, #0x07
	str r1, [r0, #0x00]
	ldr r0, _080D5D28 @ =0x0203C544
	movs r3, #0x80
	lsls r3, r3, #0x05
	str r3, [r0, #0x00]
	asrs r3, r3, #0x04
	str r2, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x02
	movs r1, #0x00
	adds r2, r3, #0x0
	bl func_08005690
	ldr r0, _080D5D2C @ =0x02034EA0
	movs r1, #0x04
	bl func_08000E64
	ldr r0, _080D5D30 @ =0x02034EB8
	movs r4, #0x00
	str r4, [r0, #0x00]
	ldr r0, _080D5D34 @ =0x02034EBC
	str r4, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x4C
	bl func_08006120
	ldr r0, _080D5D38 @ =0x02034E98
	str r4, [r0, #0x00]
	movs r0, #0x00
	bl func_0811FE70
	ldr r1, _080D5D3C @ =0x02034EC0
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
_080D5D08: .4byte 0x097C77B8
_080D5D0C: .4byte 0x00007FA0
_080D5D10: .4byte 0x0983EB98
_080D5D14: .4byte 0x097CF758
_080D5D18: .4byte 0x0984A618
_080D5D1C: .4byte 0x0983FB98
_080D5D20: .4byte 0x0203C548
_080D5D24: .4byte 0x0203C54C
_080D5D28: .4byte 0x0203C544
_080D5D2C: .4byte 0x02034EA0
_080D5D30: .4byte 0x02034EB8
_080D5D34: .4byte 0x02034EBC
_080D5D38: .4byte 0x02034E98
_080D5D3C: .4byte 0x02034EC0
.syntax divided
