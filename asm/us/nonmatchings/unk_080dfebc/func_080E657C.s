.syntax unified
	.align 2, 0
	.global func_080E657C
	.thumb
	.thumb_func
	.type func_080E657C, %function
func_080E657C: @ 080E657C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r1, _080E6624 @ =0x02039BB0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080E65E4
	ldrh r3, [r4, #0x04]
	movs r0, #0x04
	ands r0, r3
	cmp r0, #0x00
	bne _080E65E4
	ldr r0, _080E6628 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	movs r2, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _080E65A8
	adds r0, r2, #0x0
	ands r0, r3
	cmp r0, #0x00
	beq _080E65E4
_080E65A8:
	adds r5, r1, #0x0
	adds r5, #0xE8
	adds r0, r5, #0x0
	bl func_08000D0C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080E65E4
	ldr r0, [r4, #0x00]
	str r0, [r2, #0x30]
	adds r0, r4, #0x0
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x34]
	adds r1, r2, #0x0
	adds r0, r4, #0x0
	adds r0, #0x08
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldrb r0, [r4, #0x1C]
	strb r0, [r2, #0x10]
	ldr r0, [r4, #0x18]
	str r0, [r2, #0x14]
	adds r0, r2, #0x0
	adds r0, #0x1C
	adds r1, r5, #0x0
	bl func_08000BC8
_080E65E4:
	ldr r1, _080E662C @ =0x02034F40
	ldrb r0, [r1, #0x00]
	subs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r2, _080E6630 @ =0x02034F41
	ldr r0, [r4, #0x00]
	ldrb r1, [r0, #0x08]
	ldrb r0, [r2, #0x00]
	subs r0, r0, r1
	strb r0, [r2, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x48
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xBC
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0xE4
	bl TaskPoolDestroy
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E6624: .4byte 0x02039BB0
_080E6628: .4byte 0x0203C7AC
_080E662C: .4byte 0x02034F40
_080E6630: .4byte 0x02034F41
.syntax divided
