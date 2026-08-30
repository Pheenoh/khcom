.syntax unified
	.align 2, 0
	.global task_bos_ga_0
	.thumb
	.thumb_func
	.type task_bos_ga_0, %function
task_bos_ga_0: @ 080FB608
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	ldr r0, _080FB61C @ =0x02034FE8
	str r6, [r0, #0x00]
	cmp r7, #0x00
	bne _080FB620
	movs r0, #0x01
	b _080FB622
	.byte 0x00, 0x00
_080FB61C: .4byte 0x02034FE8
_080FB620:
	movs r0, #0x00
_080FB622:
	str r0, [r6, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x04]
	movs r0, #0x00
	movs r4, #0x00
	strh r4, [r6, #0x0E]
	str r4, [r6, #0x08]
	strh r4, [r6, #0x10]
	strh r4, [r6, #0x12]
	strh r4, [r6, #0x14]
	str r4, [r6, #0x18]
	strb r0, [r6, #0x1C]
	ldr r1, _080FB6FC @ =0x00000A4C
	adds r0, r6, r1
	str r4, [r0, #0x00]
	movs r0, #0xA5
	lsls r0, r0, #0x04
	adds r1, r6, r0
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	ldr r5, _080FB700 @ =0x02039B84
	ldr r0, [r5, #0x00]
	adds r0, #0x40
	ldr r1, _080FB704 @ =0x09EDB338
	ldr r2, _080FB708 @ =0x0999202C
	bl func_08000E14
	ldr r2, [r5, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xCC
	movs r0, #0xE2
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xD0
	movs r1, #0xAF
	lsls r1, r1, #0x09
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r4, [r0, #0x00]
	movs r0, #0x82
	lsls r0, r0, #0x08
	movs r2, #0x00
	bl func_0801BCC0
	adds r5, r6, #0x0
	adds r5, #0x20
_080FB680:
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	bl func_080F80FC
	adds r4, #0x01
	cmp r4, #0x05
	bls _080FB680
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_0801C2DC
	movs r1, #0xE4
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0x01
	bl func_0801C2DC
	ldr r0, _080FB70C @ =0x09A3C89C
	movs r1, #0x20
	bl func_08002A14
	movs r1, #0xA3
	lsls r1, r1, #0x04
	adds r4, r6, r1
	str r0, [r4, #0x00]
	ldr r0, _080FB710 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _080FB714 @ =0x00000A34
	adds r5, r6, r1
	str r0, [r5, #0x00]
	ldr r0, [r4, #0x00]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	bl func_0801C298
	ldr r0, [r5, #0x00]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	bl func_0801C298
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	ands r0, r1
	adds r0, #0x01
	bl func_08083900
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FB6FC: .4byte 0x00000A4C
_080FB700: .4byte 0x02039B84
_080FB704: .4byte 0x09EDB338
_080FB708: .4byte 0x0999202C
_080FB70C: .4byte 0x09A3C89C
_080FB710: .4byte 0x08F69BC4
_080FB714: .4byte 0x00000A34
.syntax divided
