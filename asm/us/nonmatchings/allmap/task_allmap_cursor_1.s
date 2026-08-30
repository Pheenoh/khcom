.syntax unified
	.align 2, 0
	.global task_allmap_cursor_1
	.thumb
	.thumb_func
	.type task_allmap_cursor_1, %function
task_allmap_cursor_1: @ 080D3BC8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _080D3BF0 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080D3C24
	ldr r3, _080D3BF4 @ =0x0203C508
	ldrh r2, [r3, #0x00]
	adds r0, r2, #0x0
	cmp r0, #0x06
	bls _080D3BF8
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	subs r2, #0x07
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080058FC
	b _080D3C24
_080D3BF0: .4byte 0x0203C4E0
_080D3BF4: .4byte 0x0203C508
_080D3BF8:
	cmp r0, #0x03
	bls _080D3C18
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	ldr r3, _080D3C14 @ =0xFFFFF800
	adds r1, r1, r3
	subs r2, #0x03
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_0800592C
	b _080D3C24
	.byte 0x00, 0x00
_080D3C14: .4byte 0xFFFFF800
_080D3C18:
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	ldrh r2, [r3, #0x00]
	bl func_0800592C
_080D3C24:
	ldr r0, _080D3C34 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	beq _080D3C3C
	ldr r0, _080D3C38 @ =0x09EF64B4
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x08]
	b _080D3CB0
_080D3C34: .4byte 0x0203C4E0
_080D3C38: .4byte 0x09EF64B4
_080D3C3C:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3CB8 @ =0x0203C540
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x10
	subs r1, r1, r0
	lsls r2, r1, #0x08
	ldrh r0, [r4, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3CBC @ =0x0203C53C
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x0B
	subs r1, r1, r0
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x34]
	cmp r2, r0
	bne _080D3C7E
	ldr r0, [r4, #0x38]
	adds r5, r4, #0x0
	adds r5, #0x44
	cmp r1, r0
	beq _080D3C8C
_080D3C7E:
	str r2, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0x0
	adds r1, #0x44
	movs r0, #0x04
	strh r0, [r1, #0x00]
	adds r5, r1, #0x0
_080D3C8C:
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D3CB0
	adds r0, r4, #0x0
	adds r0, #0x3C
	ldr r1, [r4, #0x34]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x40
	ldr r1, [r4, #0x38]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
_080D3CB0:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_080D3CB8: .4byte 0x0203C540
_080D3CBC: .4byte 0x0203C53C
.syntax divided
