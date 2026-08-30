.syntax unified
	.align 2, 0
	.global task_poo_eeyore_1
	.thumb
	.thumb_func
	.type task_poo_eeyore_1, %function
task_poo_eeyore_1: @ 080CDDF8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r0, #0xAC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CDE1A
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CDE1A
	ldr r1, _080CDEA8 @ =0x0203C3F0
	movs r0, #0x05
	str r0, [r1, #0x00]
_080CDE1A:
	bl func_080CFA70
	lsls r0, r0, #0x18
	adds r5, r4, #0x0
	adds r5, #0xAA
	cmp r0, #0x00
	beq _080CDE46
	adds r1, r4, #0x0
	adds r1, #0xA4
	ldr r0, [r1, #0x00]
	cmp r0, #0x04
	bne _080CDE46
	movs r0, #0x05
	str r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x0C
	movs r1, #0x05
	movs r2, #0x01
	bl func_080059A4
	movs r0, #0xB4
	strh r0, [r5, #0x00]
_080CDE46:
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080CDE9E
	adds r0, r4, #0x0
	adds r0, #0x24
	ldr r1, _080CDEAC @ =0x00080B00
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, _080CDEB0 @ =0x00048C00
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldr r0, [r4, #0x24]
	ldr r1, [r4, #0x28]
	ldr r2, [r4, #0x2C]
	adds r1, r1, r2
	bl func_080C9FA8
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080CDE9E
	movs r0, #0x8C
	bl func_080C7B84
	movs r0, #0x02
	bl func_080D2D3C
	movs r0, #0x51
	bl func_0800FDD0
	adds r0, r4, #0x0
	adds r0, #0xA4
	movs r1, #0x01
	str r1, [r0, #0x00]
	subs r0, #0x98
	movs r2, #0x01
	bl func_080059A4
_080CDE9E:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CDEA8: .4byte 0x0203C3F0
_080CDEAC: .4byte 0x00080B00
_080CDEB0: .4byte 0x00048C00
.syntax divided
