.syntax unified
	.align 2, 0
	.global task_bos_jf_0
	.thumb
	.thumb_func
	.type task_bos_jf_0, %function
task_bos_jf_0: @ 080BCE8C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	ldr r0, _080BCF10 @ =0x0203AC80
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r0, _080BCF14 @ =0x0203ACB0
	strh r2, [r0, #0x00]
	ldr r0, _080BCF18 @ =0x0203ACB4
	strh r2, [r0, #0x00]
	movs r0, #0x93
	lsls r0, r0, #0x02
	adds r6, r7, r0
	movs r2, #0x00
	strh r2, [r6, #0x00]
	cmp r1, #0x00
	beq _080BCEB8
	movs r0, #0x08
	strh r0, [r6, #0x00]
_080BCEB8:
	ldr r1, _080BCF1C @ =0x0203ACC4
	movs r0, #0x07
	strh r0, [r1, #0x00]
	ldr r0, _080BCF20 @ =0x0203ACD4
	strh r2, [r0, #0x00]
	ldr r0, _080BCF24 @ =0x0203ACC0
	strh r2, [r0, #0x00]
	ldr r4, _080BCF28 @ =0x0203AC90
	ldr r0, _080BCF2C @ =0x0965DC04
	str r0, [r4, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x08
	strh r0, [r4, #0x04]
	ldr r0, _080BCF30 @ =0x096FB404
	str r0, [r4, #0x08]
	movs r0, #0x80
	strh r0, [r4, #0x0C]
	ldr r0, _080BCF34 @ =0x096C4C64
	str r0, [r4, #0x10]
	ldr r0, _080BCF38 @ =0x096C5464
	str r0, [r4, #0x14]
	ldr r0, _080BCF3C @ =0x0203ACE0
	str r0, [r4, #0x18]
	ldr r0, _080BCF40 @ =0x096C6464
	str r0, [r4, #0x1C]
	movs r1, #0x95
	lsls r1, r1, #0x02
	adds r5, r7, r1
	adds r0, r5, #0x0
	movs r1, #0x04
	bl TaskPoolInit
	ldrh r1, [r6, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080BCF48
	ldr r1, _080BCF44 @ =0x09EF27D4
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl TaskCreate
	b _080BCF56
	.byte 0x00, 0x00
_080BCF10: .4byte 0x0203AC80
_080BCF14: .4byte 0x0203ACB0
_080BCF18: .4byte 0x0203ACB4
_080BCF1C: .4byte 0x0203ACC4
_080BCF20: .4byte 0x0203ACD4
_080BCF24: .4byte 0x0203ACC0
_080BCF28: .4byte 0x0203AC90
_080BCF2C: .4byte 0x0965DC04
_080BCF30: .4byte 0x096FB404
_080BCF34: .4byte 0x096C4C64
_080BCF38: .4byte 0x096C5464
_080BCF3C: .4byte 0x0203ACE0
_080BCF40: .4byte 0x096C6464
_080BCF44: .4byte 0x09EF27D4
_080BCF48:
	ldr r0, _080BCF84 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _080BCF88 @ =0x09EF27D4
	adds r2, r4, #0x0
	bl TaskCreate
_080BCF56:
	movs r2, #0x9A
	lsls r2, r2, #0x02
	adds r0, r7, r2
	movs r1, #0x00
	strh r1, [r0, #0x00]
	adds r2, #0x02
	adds r0, r7, r2
	strh r1, [r0, #0x00]
	movs r1, #0x93
	lsls r1, r1, #0x02
	adds r0, r7, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0x00
	beq _080BCF8C
	subs r2, #0x32
	adds r0, r7, r2
	movs r1, #0x0A
	b _080BCF92
	.byte 0x00, 0x00
_080BCF84: .4byte 0x02039B84
_080BCF88: .4byte 0x09EF27D4
_080BCF8C:
	movs r2, #0x8E
	lsls r2, r2, #0x02
	adds r0, r7, r2
_080BCF92:
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	str r1, [r0, #0x00]
	movs r1, #0x90
	lsls r1, r1, #0x02
	adds r0, r7, r1
	movs r3, #0x00
	strh r3, [r0, #0x00]
	ldr r2, _080BD030 @ =0x00000242
	adds r0, r7, r2
	strh r3, [r0, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	strh r3, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	strh r3, [r0, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	movs r1, #0x08
	strh r1, [r0, #0x00]
	ldr r0, _080BD034 @ =0x0000024A
	adds r2, r7, r0
	movs r0, #0x0C
	strh r0, [r2, #0x00]
	ldr r2, _080BD038 @ =0x0000024E
	adds r0, r7, r2
	strh r3, [r0, #0x00]
	adds r2, #0x02
	adds r0, r7, r2
	strh r3, [r0, #0x00]
	subs r2, #0x04
	adds r0, r7, r2
	ldrh r0, [r0, #0x00]
	ands r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r9, r1
	cmp r1, #0x00
	beq _080BD04C
	movs r0, #0x8B
	lsls r0, r0, #0x02
	adds r2, r7, r0
	ldr r0, _080BD03C @ =0x0002A200
	str r0, [r2, #0x00]
	movs r1, #0x8C
	lsls r1, r1, #0x02
	adds r3, r7, r1
	movs r0, #0xAF
	lsls r0, r0, #0x09
	str r0, [r3, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	ldr r4, _080BD040 @ =0xFFFFC800
	str r4, [r0, #0x00]
	ldr r1, _080BD044 @ =0x0961A668
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x00]
	str r4, [sp, #0x000]
	adds r0, r7, #0x0
	bl func_0801B37C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r2, #0x95
	lsls r2, r2, #0x02
	adds r0, r7, r2
	ldr r1, _080BD048 @ =0x09EF2A20
	adds r2, r7, #0x0
	bl TaskCreate
	b _080BD174
	.byte 0x00, 0x00
_080BD030: .4byte 0x00000242
_080BD034: .4byte 0x0000024A
_080BD038: .4byte 0x0000024E
_080BD03C: .4byte 0x0002A200
_080BD040: .4byte 0xFFFFC800
_080BD044: .4byte 0x0961A668
_080BD048: .4byte 0x09EF2A20
_080BD04C:
	movs r0, #0x88
	lsls r0, r0, #0x02
	adds r2, r7, r0
	ldr r0, _080BD184 @ =0x00029600
	str r0, [r2, #0x00]
	movs r1, #0x89
	lsls r1, r1, #0x02
	adds r3, r7, r1
	movs r0, #0xAA
	lsls r0, r0, #0x09
	str r0, [r3, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	ldr r1, _080BD188 @ =0xFFFF4C00
	str r1, [r0, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r6, r7, r0
	ldr r0, _080BD18C @ =0x0961A668
	mov r8, r0
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x00]
	str r1, [sp, #0x000]
	adds r0, r6, #0x0
	mov r1, r8
	bl func_0801B37C
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	ldr r2, _080BD190 @ =0x00000400
	ldr r3, _080BD194 @ =0x00000000
	orrs r0, r2
	ldr r4, _080BD198 @ =0x00000000
	ldr r5, _080BD19C @ =0x00002000
	adds r2, r0, #0x0
	adds r3, r1, #0x0
	orrs r3, r5
	movs r4, #0x05
	negs r4, r4
	ands r0, r4
	adds r1, r3, #0x0
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	mov r1, r9
	str r1, [r6, #0x24]
	movs r2, #0xD9
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x04
	strh r0, [r1, #0x00]
	movs r0, #0x8B
	lsls r0, r0, #0x02
	adds r2, r7, r0
	ldr r0, _080BD1A0 @ =0x0002A200
	str r0, [r2, #0x00]
	movs r1, #0x8C
	lsls r1, r1, #0x02
	adds r3, r7, r1
	movs r0, #0xAF
	lsls r0, r0, #0x09
	str r0, [r3, #0x00]
	adds r1, #0x04
	adds r0, r7, r1
	ldr r1, _080BD1A4 @ =0xFFFFC800
	str r1, [r0, #0x00]
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x00]
	str r1, [sp, #0x000]
	adds r0, r7, #0x0
	mov r1, r8
	bl func_0801B37C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	ldr r4, _080BD1A8 @ =0x00008000
	ldr r5, _080BD1AC @ =0x00000000
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	ldr r4, _080BD1B0 @ =0x00000000
	ldr r5, _080BD1B4 @ =0x00000001
	adds r0, r2, #0x0
	orrs r1, r5
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	adds r1, r7, #0x0
	adds r1, #0x9E
	movs r0, #0x20
	strh r0, [r1, #0x00]
	adds r1, #0x02
	movs r0, #0x28
	strh r0, [r1, #0x00]
	subs r1, #0x04
	movs r0, #0x1C
	strh r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_0801BDD4
	ldr r5, _080BD1B8 @ =0x02039B84
	ldr r0, [r5, #0x00]
	adds r0, #0xD8
	movs r1, #0xFF
	lsls r1, r1, #0x08
	strh r1, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x01
	bl func_0801C298
	ldr r0, _080BD1BC @ =0x00023E00
	movs r4, #0xB4
	lsls r4, r4, #0x09
	ldr r2, _080BD1C0 @ =0xFFFFC000
	adds r1, r4, #0x0
	bl func_0801BCC0
	ldr r0, _080BD1C4 @ =0x00020600
	ldr r2, _080BD1C8 @ =0xFFFFF800
	adds r1, r4, #0x0
	bl func_0801C274
	movs r2, #0x95
	lsls r2, r2, #0x02
	adds r4, r7, r2
	ldr r1, _080BD1CC @ =0x09EF27F4
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl TaskCreate
	ldr r1, _080BD1D0 @ =0x09EF2A20
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl TaskCreate
	ldr r2, [r5, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xCC
	ldr r0, [r6, #0x04]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r6, #0x08]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r6, #0x0C]
	str r0, [r1, #0x00]
_080BD174:
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BD184: .4byte 0x00029600
_080BD188: .4byte 0xFFFF4C00
_080BD18C: .4byte 0x0961A668
_080BD190: .4byte 0x00000400
_080BD194: .4byte 0x00000000
_080BD198: .4byte 0x00000000
_080BD19C: .4byte 0x00002000
_080BD1A0: .4byte 0x0002A200
_080BD1A4: .4byte 0xFFFFC800
_080BD1A8: .4byte 0x00008000
_080BD1AC: .4byte 0x00000000
_080BD1B0: .4byte 0x00000000
_080BD1B4: .4byte 0x00000001
_080BD1B8: .4byte 0x02039B84
_080BD1BC: .4byte 0x00023E00
_080BD1C0: .4byte 0xFFFFC000
_080BD1C4: .4byte 0x00020600
_080BD1C8: .4byte 0xFFFFF800
_080BD1CC: .4byte 0x09EF27F4
_080BD1D0: .4byte 0x09EF2A20
.syntax divided
