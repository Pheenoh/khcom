.syntax unified
	.align 2, 0
	.global func_080D5A4C
	.thumb
	.thumb_func
	.type func_080D5A4C, %function
func_080D5A4C: @ 080D5A4C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080D5A78 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r5, #0x80
	lsls r5, r5, #0x02
	ands r0, r5
	cmp r0, #0x00
	beq _080D5A80
	ldr r4, _080D5A7C @ =0x0984A818
	movs r0, #0x01
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080050DC
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080D5978
	b _080D5A96
_080D5A78: .4byte 0x02039BB0
_080D5A7C: .4byte 0x0984A818
_080D5A80:
	ldr r4, _080D5AEC @ =0x0984A418
	movs r0, #0x01
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080050DC
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080D5978
_080D5A96:
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_0800501C
	movs r0, #0x02
	bl func_0800501C
	ldr r4, _080D5AF0 @ =0x02034EB8
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D5AC2
	ldr r0, _080D5AF4 @ =0x02034EA0
	ldr r1, _080D5AF8 @ =0x09EF4E60
	movs r2, #0x00
	bl func_08000E14
	str r0, [r4, #0x00]
_080D5AC2:
	ldr r4, _080D5AFC @ =0x02034EBC
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D5ADC
	ldr r0, _080D5AF4 @ =0x02034EA0
	ldr r1, _080D5B00 @ =0x09EF4E78
	movs r2, #0x00
	bl func_08000E14
	str r0, [r4, #0x00]
_080D5ADC:
	movs r0, #0x02
	adds r1, r6, #0x0
	bl func_08006120
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D5AEC: .4byte 0x0984A418
_080D5AF0: .4byte 0x02034EB8
_080D5AF4: .4byte 0x02034EA0
_080D5AF8: .4byte 0x09EF4E60
_080D5AFC: .4byte 0x02034EBC
_080D5B00: .4byte 0x09EF4E78
.syntax divided
