.syntax unified
	.align 2, 0
	.global func_080D2190
	.thumb
	.thumb_func
	.type func_080D2190, %function
func_080D2190: @ 080D2190
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x52
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D21BE
	adds r0, r4, #0x0
	adds r0, #0x20
	ldr r1, [r4, #0x40]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x24
	ldr r1, [r4, #0x44]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
	b _080D21E2
_080D21BE:
	movs r0, #0x60
	strh r0, [r5, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x48
	ldrb r0, [r1, #0x00]
	adds r0, #0x80
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	blt _080D21DA
	ldr r0, [r4, #0x38]
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x3C]
	b _080D21E0
_080D21DA:
	ldr r0, [r4, #0x30]
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x34]
_080D21E0:
	str r0, [r4, #0x44]
_080D21E2:
	adds r0, r4, #0x0
	adds r0, #0x08
	bl func_08005A64
	str r0, [r4, #0x04]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
