.syntax unified
	.align 2, 0
	.global task_emy_16_b_0
	.thumb
	.thumb_func
	.type task_emy_16_b_0, %function
task_emy_16_b_0: @ 08038E5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	movs r0, #0x12
	ldsh r1, [r6, r0]
	cmp r1, #0x00
	beq _08038E74
	adds r1, r5, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08038E7A
_08038E74:
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_08038E7A:
	ldr r0, _08038EF0 @ =0x08F699C4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r1, _08038EF4 @ =0x08A23630
	movs r0, #0x80
	bl func_080028F8
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _08038EF8 @ =0x09EE04F4
	ldr r2, _08038EFC @ =0x09EE04E0
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	movs r1, #0x00
	str r1, [r5, #0x38]
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	movs r0, #0x80
	lsls r0, r0, #0x02
	str r0, [r5, #0x34]
	ldr r0, _08038F00 @ =0xFFFFFCB4
	str r0, [r5, #0x30]
	movs r2, #0x00
	strh r1, [r5, #0x3C]
	adds r1, r5, #0x0
	adds r1, #0x9C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x9D
	strb r2, [r0, #0x00]
	adds r4, #0x38
	adds r0, r4, #0x0
	movs r1, #0x0C
	movs r2, #0x04
	movs r3, #0x03
	bl func_080122AC
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08038EF0: .4byte 0x08F699C4
_08038EF4: .4byte 0x08A23630
_08038EF8: .4byte 0x09EE04F4
_08038EFC: .4byte 0x09EE04E0
_08038F00: .4byte 0xFFFFFCB4
.syntax divided
