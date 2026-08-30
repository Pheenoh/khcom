.syntax unified
	.align 2, 0
	.global func_080DBC00
	.thumb
	.thumb_func
	.type func_080DBC00, %function
func_080DBC00: @ 080DBC00
	push {r4, r5, r6, lr}
	adds r2, r0, #0x0
	adds r6, r2, #0x0
	adds r6, #0x24
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r1, r2, r0
	movs r0, #0x00
	ldsh r3, [r1, r0]
	cmp r3, #0x00
	bne _080DBC32
	movs r0, #0x20
	strh r0, [r1, #0x00]
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080DBC30
	ldr r0, _080DBC2C @ =0xFFFFFC00
	str r0, [r1, #0x00]
	b _080DBC32
_080DBC2C: .4byte 0xFFFFFC00
_080DBC30:
	str r3, [r1, #0x00]
_080DBC32:
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r5, r2, r1
	adds r1, #0x04
	adds r0, r2, r1
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r4, r2, r0
	ldrh r2, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_080058FC
	ldr r0, _080DBC64 @ =0x0203C580
	ldr r0, [r0, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r0, r1
	str r0, [r6, #0x0C]
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DBC64: .4byte 0x0203C580
.syntax divided
